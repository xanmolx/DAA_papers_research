// Take a 10 x 10 matrix (n x n in general) filled with English alphabets. Trace the longest
// sorted partition:-
// a. in each column of the matrix
// b. Trace the longest sorted child of the matrix.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// const int n = 4;

int main(){
	FILE* fptr = fopen("worst.txt","w");
	srand(time(0));
	char alphabets[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
	int n;
	printf("Enter the n for nxn matrix \n");
	scanf("%d", &n);
	char array[100][100];
	for(i=0; i<1000; i+=2){
		for(int j=0; j<n; j++){		// 2 * n+1
			for(int i=0; i<n; i++){		// 2 * n^2+1
				// array[i][j] = alphabets[rand()%26];		// 1 * n^2
				scanf(" %c", &array[j][i]);
			}
		}

		printf("The random array generated is :\n");	// 1
		for(int i=0; i<n; i++){		// 2 * n+1
			for(int j=0; j<n; j++){		// 2* n^2+1
				printf("%c ", array[i][j]);		// 1* n^2
			}
			printf("\n");		// 1 * n
		}

		printf("\n****************** PART A ******************\n");
		long long int t=0;

		t++;
		for(int j=0; j<n; j++){		
			t++;
			int max_inc = 1;	t++;		
			int len = 1;	t++;		
			int max_inc_index = 0;	t++;		
			t++;
			for(int i=1; i<n; i++){	
				t++;
				t+=4;	
				if(array[i][j] >= array[i-1][j]) {		
					len++;
					t+=2;		
				}
				else{
					t++;
					if(max_inc < len){	
						t++;	
						max_inc = len;	
						t+=2;	
						max_inc_index = i - max_inc;		
					}
					t++;
					len = 1;		
				}
				t+=2;
			}
			t++;
			if(max_inc < len){		
				max_inc = len;	t++;	
				max_inc_index = n - max_inc;	t+=2;	
			}

			int max_dec = 1;	t++;	
			len = 1;	t++;		
			int max_dec_index = 0;	t++;
			t++;	
			for(int i=1; i<n; i++){	
				t++;
				t+=4;	 
				if(array[i][j] <= array[i-1][j]) {		
					len++;	t+=2;		
				}
				else{
					t++;
					if(max_dec < len){		
						max_dec = len;	t+=3;	
						max_dec_index = i - max_dec;		
					}
					len = 1;	t++;	
				}
				t+=2;
			}
			t++;
			if(max_dec < len){	
				t+=3;	
				max_dec = len;		
				max_dec_index = n - max_dec;		
			}
			if(max_inc > max_dec){		
				printf("column %d  ", j+1);		
				for(int i=max_inc_index; i<max_inc+max_inc_index; i++){		
					printf("%c ", array[i][j]);		
				}
			}	
			else{   
				printf("column %d  ", j+1);		
				for(int i=max_dec_index; i<max_dec+max_dec_index; i++){		
					printf("%c ", array[i][j]);		
				}	
			}
			t+=2;
			printf("\n");	
			
		}
		printf("%lld",t);
			fprintf(fptr,"%d\t%lld\n",n,t);
	}
}
