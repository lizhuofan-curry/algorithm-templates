#!/usr/bin/env python3
"""Validate repository structure, local links and C++ syntax."""

from __future__ import annotations

import argparse
import re
import shutil
import subprocess
import sys
from pathlib import Path
from urllib.parse import unquote


ROOT = Path(__file__).resolve().parents[1]
MARKDOWN_LINK = re.compile(r"!?\[[^\]]*\]\(([^)]+)\)")
IGNORED_LINK_PREFIXES = ("#", "/", "http://", "https://", "mailto:", "tel:", "data:")
WINDOWS_RESERVED_NAMES = {
    "CON",
    "PRN",
    "AUX",
    "NUL",
    *(f"COM{i}" for i in range(1, 10)),
    *(f"LPT{i}" for i in range(1, 10)),
}
WINDOWS_INVALID_CHARS = set('<>:"\\|?*')


def relative(path: Path) -> str:
    return path.relative_to(ROOT).as_posix()


def check_windows_paths() -> list[str]:
    problems: list[str] = []
    for path in ROOT.rglob("*"):
        if ".git" in path.parts:
            continue
        for part in path.relative_to(ROOT).parts:
            stem = part.split(".", 1)[0].upper()
            if (
                part.endswith((" ", "."))
                or any(char in WINDOWS_INVALID_CHARS for char in part)
                or stem in WINDOWS_RESERVED_NAMES
            ):
                problems.append(f"Windows-incompatible path: {relative(path)}")
                break
    return problems


def link_target(raw_target: str) -> str:
    target = raw_target.strip()
    if target.startswith("<") and target.endswith(">"):
        target = target[1:-1]
    else:
        target = target.split(maxsplit=1)[0]
    return unquote(target.split("#", 1)[0])


def check_markdown() -> list[str]:
    problems: list[str] = []
    for markdown in ROOT.rglob("*.md"):
        text = markdown.read_text(encoding="utf-8")
        if sum(line.lstrip().startswith("```") for line in text.splitlines()) % 2:
            problems.append(f"Unclosed fenced code block: {relative(markdown)}")
        for raw_target in MARKDOWN_LINK.findall(text):
            target = link_target(raw_target)
            if not target or target.startswith(IGNORED_LINK_PREFIXES):
                continue
            if not (markdown.parent / target).resolve().exists():
                problems.append(f"Broken local link: {relative(markdown)} -> {raw_target}")
    return problems


def check_cpp_files(compile_cpp: bool) -> list[str]:
    problems: list[str] = []
    cpp_files = sorted(ROOT.rglob("*.cpp"))
    for cpp_file in cpp_files:
        if not cpp_file.read_text(encoding="utf-8").strip():
            problems.append(f"Empty C++ file: {relative(cpp_file)}")

    if not compile_cpp:
        return problems

    compiler = shutil.which("g++")
    if compiler is None:
        return problems + ["g++ was not found; C++ syntax was not checked"]

    for cpp_file in cpp_files:
        result = subprocess.run(
            [compiler, "-std=c++17", "-fsyntax-only", str(cpp_file)],
            cwd=ROOT,
            capture_output=True,
            text=True,
            encoding="utf-8",
            errors="replace",
            check=False,
        )
        if result.returncode:
            detail_lines = (result.stderr or result.stdout).strip().splitlines()
            detail = "\n".join(detail_lines[:12])
            if len(detail_lines) > 12:
                detail += "\n... compiler output truncated ..."
            problems.append(f"C++ syntax error: {relative(cpp_file)}\n{detail}")
    return problems


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument(
        "--compile-cpp",
        action="store_true",
        help="compile every C++ file with g++ in C++17 syntax-only mode",
    )
    args = parser.parse_args()

    problems = [
        *check_windows_paths(),
        *check_markdown(),
        *check_cpp_files(args.compile_cpp),
    ]
    if problems:
        print("Repository checks failed:\n")
        print("\n".join(f"- {problem}" for problem in problems))
        return 1

    counts = {
        "C++ templates": len(list(ROOT.rglob("*.cpp"))),
        "Markdown notes": len(list(ROOT.rglob("*.md"))),
        "images": len(list(ROOT.rglob("*.png"))),
    }
    summary = ", ".join(f"{label}: {count}" for label, count in counts.items())
    print(f"Repository checks passed ({summary}).")
    return 0


if __name__ == "__main__":
    sys.exit(main())
