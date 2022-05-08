#include<conio.h>
#include<stdio.h>
#include<math.h>
void chuyenmang(int a,int p,int w,int a1[])
{
     int m,t,i,tg;
     m=log((double)p)/log(2) +1; t=m/w +1;
    for(i=t-1;i>=0;i--)
    {
        tg=a;
        a1[i]=a/(pow(2.0,i*w));
        tg=a-a1[i]*(pow(2.0,i*w));
        a=tg;
        printf("\n\t%d",a1[i]);
    }
}
void congboichinhxac(int a1[],int b1[],int c1[],int w,int p)
{
     int m,t,i,e;
     m=log((double)p)/log(2) +1; t=m/w +1;
     c1[0]=a1[0]+b1[0];
     if(c1[0]>pow(2.0,w))
       {
           c1[0]=c1[0]-pow(2.0,w);
          e=1;
       }
     else
        {
            e=0;
        }
     for(i=1;i<t;i++)
     {
         c1[i]=a1[i]+b1[i]+e;
         if(c1[i]>pow(2.0,w))
         {
             c1[i]=c1[i]-pow(2.0,w);
           e=1;
         }
        else
         {
           e=0;
         }
     }

     printf("\nso e la: %d",e);
     printf("\nMang cong boi chinh xac la:");
    for(i=t-1;i>=0;i--)
    {
       printf("\n\n\t%d",c1[i]);
    }
}
void pheptru(int a1[],int b1[],int c1[],int w,int p)
{
     int m,t,i,e;
     m=log((double)p)/log(2) +1; t=m/w +1;
     c1[0]=a1[0]-b1[0];
     if(c1[0]>=0)
       {
          e=0;
       }
     else
        {
            e=1;
            c1[0]+=pow(2.0,w);
        }
     for(i=1;i<t;i++)
     {
         c1[i]=a1[i]-b1[i]-e;
         if(c1[i]>=0)
         {
           e=0;
         }
        else
         {
           e=1;
           c1[i]+=pow(2.0,w);
         }
     }
     printf("\nso e la: %d",e);
            printf("\n mang hieu la: ");
    for(i=t-1;i>=0;i--)
    {
       printf("\n\n\t%d",c1[i]);
    }
}
void phepcongtrenmodul(int a1[],int b1[],int c1[],int p1[],int w,int p)
{
     int m,t,i,e;
     m=log((double)p)/log(2) +1; t=m/w +1;
     c1[0]=a1[0]+b1[0];
     if(c1[0]>pow(2.0,w))
       {
          c1[0]=c1[0]-pow(2.0,w);
          e=1;
       }
     else
        {
            e=0;
        }
     for(i=1;i<t;i++)
     {
         c1[i]=a1[i]+b1[i]+e;
         if(c1[i]>pow(2.0,w))
         {
           c1[i]=c1[i]-pow(2.0,w);
           e=1;
         }
        else
         {
           e=0;
         }
     }
     if(e==0)
     {
          printf("\nKet qua phep cong modul la: ");
          for(i=t-1;i>=0;i--)
    {
       printf("\n\t%d",c1[i]);
    }
          printf("\n%d",e);
     }
     else
     {
         chuyenmang(p,p,w,p1);
         c1[0]=c1[0]-p1[0];
     if(c1[0]>0)
       {
          e=0;
       }
     else
        {
            e=1;
            c1[0]+=pow(2.0,w);
        }
     for(i=1;i<t;i++)
     {
         c1[i]=c1[i]-p1[i]-e;
         if(c1[i]>0)
         {
           e=0;
         }
        else
         {
           e=1;
           c1[i]+=pow(2.0,w);
         }
     }
     printf("\n so e la: %d",e);
      printf("\n mang tong tren modul p la: ");
    for(i=t-1;i>=0;i--)
    {
       printf("\n\n\t%d",c1[i]);
    }

     }
}
void phepnhan(int a1[],int b1[],int c1[],int w,int p)
{
    int m, t, i, j, tg, tg1, u, v, tich, tong;
    m=log((double)p)/log(2)+1; t=m/w +1;
     for(i=0;i<t;++i)  c1[i]=0;
     for(i=0;i<t;++i) {
        u=0;
        for(j=0;j<t;++j) {
             tich=c1[i+j]+a1[i]*b1[j]+u;
             tg=tich;v=0;
             for(int k=0;k<8;++k) {
                 tong=0;
                 v+= tg%2*(pow(2.0,k));
                 tg=tg/2;
                 u=tg;
             }
             c1[i+j] = v;
         }
         c1[i+t] = u;
      }
        printf("\nmang sau khi nhan la: ");
         for(i=t-1;i>=0;i--)
        {
            for(i=i+t;i>=0;i--)
            {
                printf("\t%d",c1[i]);
            }
        }
}

int main()
{
   int a,p,w,a1[100],b,b1[100],c1[100],p1[100];
   printf("nhap p: ");scanf("%d",&p);
   printf("nhap w: ");scanf("%d",&w);
   printf("nhap a: ");scanf("%d",&a);
   printf("so a sau khi chuyen thanh mang la: \n");
   chuyenmang(a,p,w,a1);
   printf("\nnhap b: ");scanf("%d",&b);
   printf("so b sau khi chuyen thanh mang la: \n");
   chuyenmang(b,p,w,b1);
   congboichinhxac(a1,b1,c1,w,p);
   pheptru(a1,b1,c1,w,p);
   phepcongtrenmodul(a1,b1,c1,p1,w,p);
   phepnhan(a1,b1,c1,w,p);
   getch();
   return 0;


}

