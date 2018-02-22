// Take a 10 x 10 matrix (n x n in general) filled with English alphabets. Trace the longest
// sorted partition:-
// a. in each column of the matrix
// b. Trace the longest sorted child of the matrix.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// const int n = 4;

int main(){
	srand(time(0));
	char alphabets[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
	int n;
	printf("Enter the n for nxn matrix \n");
	scanf("%d", &n);
	char array[100][100];

	for(int j=0; j<n; j++){		// 2 * n+1
		for(int i=0; i<n; i++){		// 2 * n^2+1
			array[i][j] = alphabets[rand()%26];		// 1 * n^2
			// scanf(" %c", &array[j][i]);
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

	for(int j=0; j<n; j++){		// 2 * n+1
		int max_inc = 1;		// 1 * n
		int len = 1;		// 1 * n
		int max_inc_index = 0;		// 1 * n
		for(int i=1; i<n; i++){		// 2 * n * n+1
			if(array[i][j] >= array[i-1][j])		// 1 * n^2
				len++;		// 1 * n^2
			else{
				if(max_inc < len){		// 1 * n^2
					max_inc = len;		// 1 * n^2
					max_inc_index = i - max_inc;		// 1 * n^2
				}
				len = 1;		// 1 * n^2
			}
		}
		if(max_inc < len){		// 1 * n
			max_inc = len;		// 1 * n
			max_inc_index = n - max_inc;		// 2 * n
		}

		int max_dec = 1;		// 1 * n
		len = 1;		// 1 * n
		int max_dec_index = 0;		// 1 * n
		for(int i=1; i<n; i++){		// 2 * n * n+1 
			if(array[i][j] <= array[i-1][j])		// 1 * n^2
				len++;		// 1 * n^2
			else{
				if(max_dec < len){		// 1 * n^2
					max_dec = len;		// 1 * n^2
					max_dec_index = i - max_dec;		// 1 * n^2
				}
				len = 1;		// 1 * n^2
			}
		}
		if(max_dec < len){		// 1 * n
			max_dec = len;		// 1 * n
			max_dec_index = n - max_dec;		// 1 * n
		}

		if(max_inc > max_dec){		// 1 * n
			printf("column %d  ", j+1);		// 1 * n
			for(int i=max_inc_index; i<max_inc+max_inc_index; i++){		// 2 * n+1 * n
				printf("%c ", array[i][j]);		// 1 * n * n
			}
		}
		else{   
			printf("column %d  ", j+1);		// 1 * n
			for(int i=max_dec_index; i<max_dec+max_dec_index; i++){		// 2 * n * n+1
				printf("%c ", array[i][j]);		// 2 * n * n
			}	
		}
		printf("\n");		// 1 * n
	}
}
