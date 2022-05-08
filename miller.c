#include<stdio.h>
int gcd(int a, int b){
    while(b!=0){
        int r=a%b;
        a=b;
        b=r;
    }return a;
}
int modp(int a, int b, int p){
    if(b==1){
        return a;
    }
    else{
        int x=modp(a,b/2,p);

        if(b%2==0){
            return (x*x)%p;
        }
        else{
            return (x*x*a)%p;
        }
    }
}
int miller(int n){
    int a= 3;
    if(gcd(a,n) !=1){
        printf("hop so");
    }else if(modp(a,n-1,n) != 1){
        printf("hop so");
    }else
    printf("so nguyen to");

}
int main(){
    int p;
    printf("nhap so p: ");
    scanf("%d", &p);
    miller(p);
}
