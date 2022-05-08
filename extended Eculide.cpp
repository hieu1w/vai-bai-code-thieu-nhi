#include<conio.h>
#include<stdio.h>
int main()
{
    int a,b,d,x,y,u,v,x1,x2,y1,y2,q,r;
    printf("Nhap a: "); scanf("%d",&a);
    printf("Nhap b: "); scanf("%d",&b);
    u=a;v=b;
    x1=1;y1=0;x2=0;y2=1;
    while(u!=0)
    {
        q=v/u; r=v-q*u; x=x2-q*x1; y=y2-q*y1;
        v=u; u=r; x2=x1; y2=y1; y1=y;
    }
    d=v;x=x2;y=y2;
    printf("%d    %d      %d",d,x,y);
}
