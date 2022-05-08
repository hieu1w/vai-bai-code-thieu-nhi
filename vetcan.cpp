#include<algorithm>
#include<stdio.h>
using namespace std;
long ss(long x,long y) {return x>y;}
int main()
{
    int n,m,t=1;
    long p[1005];
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++) scanf("%ld",&p[i]);
    sort(p+1,p+1+m,ss);
    if(m>n) m=n;
    for(int i=2;i<=m;i++)
    if(i*p[i]>=t*p[t]) t=i;
    printf("%d %ld",p[t],t*p[t]);
}
