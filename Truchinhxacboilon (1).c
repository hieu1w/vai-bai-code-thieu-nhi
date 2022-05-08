#include<conio.h>
#include<stdio.h>
#include<math.h>
#include <Windows.h>
int delta;
void ChuyenMang(unsigned long long  a,int w,unsigned long long  a1[], unsigned long long p)
{
     int i,m,t;
     m=log((double)p)/log(2.0) +1;
	 t=m/w +1;
    for(i=t-1; i>=0; i--)
    {
        unsigned long long  tg=a;
        a1[i]=a/(pow(2.0,i*w));
        tg=a-a1[i]*(pow(2.0,i*w));
        a=tg;
        printf("\n\t%I64u",a1[i]);
    }
}
void TruChinhXacBoi(unsigned long long a1[],unsigned long long  b1[],unsigned long long c1[],int w,unsigned long long  p)
{
    int i,m,t;
    long long e;
     m=log((double)p)/log(2.0) +1;
     t=m/w +1;
     c1[0]=a1[0]-b1[0];
     if(c1[0]>=0)
       {
          e=0;
       }
     else
        {
            e=1;
            c1[0]=pow(2.0,w);
        }
     for(i=1;i<t;i++);
     {
         c1[i]=a1[i]-b1[i]-e;
         if(c1[i]>=0)
         {
           e=0;
         }
        else
         {
           e=1;
           c1[i]=pow(2.0,w);
         }
     }
     printf("\nSo e la: %I64u",e);
            printf("\n Mang hieu la: ");
    for(i=t-1;i>=0;i--)
    {
       printf("\n\n\t%I64u",c1[i]);
    }
}
int main()
{
   unsigned long long  a,p,w,a1[100],b,b1[100],c1[100];
   printf("Nhap p: ");scanf("%I64u",&p);
   printf("Nhap w: ");scanf("%I64u",&w);
   printf("Nhap a: ");scanf("%I64u",&a);
   printf("So a sau khi chuyen thanh mang la: \n");
   ChuyenMang(a,w,a1,p);
   printf("\n Nhap b: ");scanf("%I64u",&b);
   printf("So b sau khi chuyen thanh mang la: \n");
   ChuyenMang(b,w,b1,p);
   TruChinhXacBoi(a1,b1,c1,w,p);
   getch();
   return 0;
}
