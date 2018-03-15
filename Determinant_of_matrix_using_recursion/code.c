#include <stdio.h>
#include <stdlib.h>

#define N 3

int determinant(int arr[N][N], int n){
	int det;
	int temp[N][N];
	int sign = 1;

	if(n==1)
		return arr[0][0];
	else{
		det = 0;
		for(int col=0; col<n; col++){
			if(arr[0][col]==0)
			{
				goto label;
			}
			int a = 0;
			int b = 0;
			for(int i=0; i<n; i++){
				for(int j=0; j<n; j++){
					if(i!=0 && j!= col){
						temp[a][b++] = arr[i][j];
						if(b==n-1)
						{
							b=0;
							a++;
						}
					}
					else{
						temp[i][j] = 0;
					}
				}
				
			}
			
			det = det+ sign*(arr[0][col]*determinant(temp, n-1));
			label : sign = sign*(-1);
			
		}
	}
	return det;
}

int main(){
	int arr[N][N];
	printf("Enter the determinant\n");
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			scanf("%d", &arr[i][j]);
			//temp[i][j]=arr[i][j];
		}
	}

	printf("\n");
	
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("%d\n", determinant(arr, N));
}
