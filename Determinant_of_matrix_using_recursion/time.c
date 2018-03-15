#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
long long int t = 0;

int determinant(int arr[N][N], int n){
	int det;
	int temp[N][N];
	int sign = 1; t+=1;

	t+=1;
	if(n==1)
		return arr[0][0];
	else{
		det = 0;	t++;
		t++;
		for(int col=0; col<n; col++){
			t++;
			t+=2;
			if(arr[0][col]==0)
			{
				goto label;
			}
			int a = 0;	t++;
			int b = 0;	t++;
			t++;
			for(int i=0; i<n; i++){
				t++;
				t++;
				for(int j=0; j<n; j++){
					t++;
					t+=3;
					if(i!=0 && j!= col){
						t+=3;
						temp[a][b++] = arr[i][j];
						t+=2;
						if(b==n-1)
						{
							b=0;	t++;
							a++;	t++;
						}
					}
					else{
						temp[i][j] = 0;	t++;
					}
					t+=2;	
				}
				t+=2;	
			}	
		det = det+ sign*(arr[0][col]*determinant(temp, n-1));	t+=4;
		label : sign = sign*(-1);	t+=2;
		t+=2;	
		}
	}
	return det;
}

int main(){
	srand(time(0));
	int arr[N][N];
	printf("Enter the determinant\n");

	FILE* fptr = fopen("average.txt", "a");
	
	printf("\n");
	
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			// scanf("%d ", &arr[i][j]);
			// arr[i][j] = 5;
			arr[i][j] = rand()%10;
		}
		// printf("\n");
	}

	printf("%d\n", determinant(arr, N));
	fprintf(fptr, "%d\t%lld\n" ,N, t);
	
}