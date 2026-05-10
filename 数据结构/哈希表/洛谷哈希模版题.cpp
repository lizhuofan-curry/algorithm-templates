#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
const int N=5000010,M=5000011;
int h[N],ne[N],idx;
ULL res,val[N],k[N];
ULL get_and_update(ULL x,ULL y)
{
    int k1=x%M;
    //先来查找是否在里面
    for(int i=h[k1];i!=-1;i=ne[i])
    {
        if(k[i]==x)
        {
            ULL old=val[i];
            val[i]=y;
            return old;
        }
    }
    //如果不存在就插入
    k[idx]=x;
    val[idx]=y;
    ne[idx]=h[k1];
    h[k1]=idx++;
    return 0;
}
char buf[1<<23],*p1=buf,*p2=buf;
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
inline unsigned long long rd() {//读入一个 64 位无符号整数
	unsigned long long x=0;
	char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch)) x=x*10+(ch^48),ch=gc();
	return x;
}

int main()
{
    int n;
    n=rd();
    memset(h,-1,sizeof h);
    for(int i=1;i<=n;i++)
    {
       ULL x,y;
        x=rd();
        y=rd();
        res+=(ULL)i*get_and_update(x,y);
    }
    cout<<res;
    return 0;
}
