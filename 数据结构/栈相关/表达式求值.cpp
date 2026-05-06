//利用栈来实现加减乘除括号运算
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int num_stk[N],tt=-1,top=-1;
char op_stk[N];
int panduan(char a)
{
  if(a=='+' || a=='-') return 1;
  if(a=='*' || a=='/') return 2;
  return 0;
}
void eval()
{
  int b=num_stk[tt--];
  int a=num_stk[tt--];
  int res=0;
  char op=op_stk[top--];
  if(op=='+') res=a+b;
  if(op=='-') res=a-b;
  if(op=='*') res=a*b;
  if(op=='/') res=a/b;
  num_stk[++tt]=res;
}
int main()
{
  string s;
  cin>>s;
  for(int i=0;i<s.size();i++)
  {
      if(isdigit(s[i]))
      {
        int x=0,j=i;
        while(j<s.size() && isdigit(s[j]))
        {
          x=x*10+(s[j]-'0');
          j++;
        }
         num_stk[++tt]=x;
         i=j-1;
      }
      //处理遇到（的情况
      else if(s[i]=='(') 
      {
        op_stk[++top]='(';
      }  
      else if(s[i]==')' )
      {
        while(op_stk[top]!='(')
          eval();
        top--;
      }
        else
      {
        while(top>=0 && panduan(op_stk[top])>=panduan(s[i]))
        {
          eval();
        }
         op_stk[++top]=s[i];
      }
    }
    while(top>=0) eval();
    cout<<num_stk[tt];
  return 0;
}
