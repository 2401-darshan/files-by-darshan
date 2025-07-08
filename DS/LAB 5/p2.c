#include <stdio.h>
void main() {
    int a[3][2], b[2][3], ans[3][3];
    int i, j, k;

    for(i=0;i<3;i++) {
        for(j=0;j<2;j++) {
            printf("Enter element a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    for(i=0;i<2;i++) {
        for(j=0;j<3;j++) {
            printf("Enter element b[%d][%d]: ", i, j);
            scanf("%d", &b[i][j]);
        }
    }


    for(i=0;i<3;i++) {
        for(j=0;j<3;j++) { 
            ans[i][j] = 0; 
            for(k=0;k<2;k++) { 
                ans[i][j] += a[i][k] * b[k][j];
            }
        }
    }
	printf("\nMultiplication of 2D Matrix : \n");
    for(i=0;i<3;i++) {
        for(j=0;j<3;j++) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
}

