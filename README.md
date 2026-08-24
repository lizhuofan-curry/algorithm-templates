# Algorithm Templates

[![Repository checks](https://github.com/lizhuofan-curry/algorithm-templates/actions/workflows/ci.yml/badge.svg)](https://github.com/lizhuofan-curry/algorithm-templates/actions/workflows/ci.yml)

这是我的 C++ 算法模板与学习笔记仓库，主要记录 AcWing 算法基础课中的常用模板、经典题型、解题思路和易错点。

这里不只保存“能通过的代码”，也保留我对算法适用场景、实现细节和常见错误的理解，方便复习、竞赛、考试和面试前快速查阅。

## 快速入口

| 内容 | 用途 | 入口 |
| --- | --- | --- |
| 模板总目录 | 按知识模块查找代码与笔记 | [查看完整目录](CATALOG.md) |
| 基础算法 | 排序、二分、高精度、前缀和、差分等 | [进入目录](basic) |
| 数据结构 | 链表、栈、队列、KMP、Trie、并查集、堆、哈希表 | [进入目录](数据结构) |
| 搜索与图论 | DFS、BFS、最短路、最小生成树、二分图等 | [进入目录](搜索与图论) |
| 动态规划 | 背包、线性 DP、区间 DP、状态压缩 DP 等 | [进入目录](动态规划) |
| 学习笔记 | 与模板配套的讲解和题目总结 | [进入目录](notes) |
| 易错点 | 刷题过程中反复出现的问题 | [查看记录](notes/mistakes.md) |

## 如何使用

1. 在 [模板总目录](CATALOG.md) 中按知识点找到对应条目。
2. 先阅读 `notes/` 下的思路，再独立写一遍代码。
3. 对照模板检查边界、下标、初始化和复杂度。
4. 把新遇到的错误补充到 [易错点记录](notes/mistakes.md)，形成自己的复习清单。

> 模板用于帮助理解和回忆。真正掌握一个算法，仍然需要脱离模板独立实现并通过题目验证。

## 仓库结构

```text
algorithm-templates/
├── basic/              # 基础算法模板
├── 数据结构/           # 常见数据结构与字符串算法
├── 搜索与图论/         # 搜索、最短路、生成树、二分图
├── 动态规划/           # 各类动态规划题型
├── notes/              # 配套学习笔记与易错点
├── scripts/            # 仓库完整性检查工具
├── CATALOG.md          # 完整知识目录
└── CONTRIBUTING.md     # 新增模板时的整理规范
```

## 本地检查

仓库使用 C++17。提交前可以运行：

```bash
python scripts/check_repository.py --compile-cpp
```

该命令会检查 Markdown 本地链接、Windows 不兼容文件名、空 C++ 文件、代码块闭合情况，并逐个验证 C++ 文件能否通过语法编译。GitHub Actions 也会自动执行同样的检查。

## 持续整理

- [x] 建立基础算法、数据结构、搜索与图论、动态规划四个主要模块
- [x] 为代码保留配套学习笔记
- [x] 建立统一目录与自动检查
- [ ] 补充数学知识模块
- [ ] 补充贪心算法模块
- [ ] 为核心模板逐步补齐复杂度、边界条件和示例

新增内容时请参考 [整理规范](CONTRIBUTING.md)。仓库会随着学习进度持续更新。
