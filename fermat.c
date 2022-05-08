#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
int Fermat(int a, int k, int n) {
	int b = 1;
	a %= n;
	while (k > 0) {
		if (k % 2 == 1)
			b = b*a % n;
		k = (int)(k/2);
		a = a*a % n;
	}
	return b;
}

int main()
{
    int b,k,a,n;
    printf("Nhap he so a:");scanf("%d",&a);
    printf("Nhap so n:");scanf("%d",&n);
    printf("\nNhap so mu k: "); scanf("%d", &k);
    printf("so du cua phep chia la:%d\n", Fermat(a, k, n));
    if(Fermat(a, k, n)!=1)
    {
        printf("hop so");
    }
    else
    {
        printf(" snt ");
    }
        getch();
	return 0;
}
