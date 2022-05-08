#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<conio.h>

void tinhMaTran (int t, int a, int w, int maTran[]){
    for(int i = t, j = t-1; i >= 0; i--){
        maTran[j] = a/(pow(2,(i-1)*w));
        a = a - (maTran[j]*(pow(2,(i-1)*w)));
        j--;
    }

}

int congMaTran(int maTran_a[], int maTran_b[], int maTran_c[], int t, int w){
    int e = 0;
    int mu = pow(2,w);
    for(int i = 0 ; i <= t-1 ; i++){
        maTran_c[i] = (maTran_a[i] + maTran_b[i] + e) % mu;
        int tmp = maTran_a[i] + maTran_b[i] + e;
        if(tmp > mu){
            e = 1;
        }
        else{
            e = 0;
        }
    }
    return e;
}

int truMaTran(int maTran_a[], int maTran_b[], int maTran_c[], int t, int w){
    int e = 0;
    int mu = pow(2,w);
    for(int i = 0 ; i <= t-1 ; i++){
        int tmp1 = (maTran_a[i] - maTran_b[i] - e);
        if(tmp1 < 0){
            tmp1 = mu + tmp1;
        }
        maTran_c[i] = tmp1 % mu;
        int tmp2 = maTran_a[i] - maTran_b[i] - e;
        if(tmp2 < 0){
            e = 1;
        }
        else{
            e = 0;
        }
    }
    return e;
}
void hienThiMaTran(int t, int maTran[]){
    for(int i = t-1; i >= 0; i--){
        printf("%d ",maTran[i]);
    }
}
int soSanh(int maTran_c[], int maTran_p[], int t){
    for(int i = t-1 ; i >= 0 ; i++){
        if(maTran_c[i] > maTran_p[i]){
            return 1;
        }
        if(maTran_c[i] < maTran_p[i]){
            return 0;
        }
    }
    return 0;
}
//int congTrenFp(int maTran_c[], int maTran_p[], int maTranKQ[], int t, int w){
//
//    return truMaTran(maTran_c, maTran_p, maTranKQ, t, w);
//}



int main(){
    int p,w,a,b;
    int maTran_a[100], maTran_b[100], maTran_c[100], maTran_p[100], maTranKQ[100];
    printf("P = ");
    scanf("%d",&p);
    printf("W = ");
    scanf("%d",&w);
    printf("a = ");
    scanf("%d",&a);
    printf("b = ");
    scanf("%d",&b);
    float m = ceil(log(p)/log(2));
    float t = ceil(m/w);
    tinhMaTran(t,a,w,maTran_a);
    printf("\nma tran a = ");
    hienThiMaTran(t,maTran_a);
    tinhMaTran(t,b,w,maTran_b);
    printf("\nma tran b = ");
    hienThiMaTran(t,maTran_b);
    tinhMaTran(t,p,w,maTran_p);
//    printf("\nma tran p = ");
//    hienThiMaTran(t,maTran_p);
    int e = congMaTran(maTran_a, maTran_b, maTran_c, t, w);
    if(e == 1 || soSanh(maTran_c, maTran_p, t)){
        printf("\n(e=%d) ma tran Fp = ",truMaTran(maTran_c, maTran_p, maTranKQ, t, w));
        hienThiMaTran(t,maTranKQ);
    }
    else{
        printf("\n(e=%d) ma tran c = ",congMaTran(maTran_a, maTran_b, maTran_c, t, w));
        hienThiMaTran(t,maTran_c);
    }
    return 0;
}


