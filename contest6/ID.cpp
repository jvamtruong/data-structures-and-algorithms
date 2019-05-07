#include <stdio.h>
#include <math.h>

float sumofarray(float a[1000][1000],int m, int n){
	float tong=0.0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			tong += a[i][j];
		}
	}
	return tong;
}

float a[1000][1000];

int main(void) {	
	int m,n,i,j;
	printf("nhap 2 so m,n:\n");
	scanf("%d %d",&m,&n);
	printf("nhap cac phan tu cua mang:\n");
	for(i = 0 ; i < m; i++){
		for(j = 0; j < n; j++){
			scanf("%f",&a[i][j]);
		}
	}
	printf("tong cac phan tu cua mang la: %f",sumofarray(a,m,n));
	// your code goes here
	return 0;
}