
	

// Take a 10 x 10 matrix (n x n in general) filled with English alphabets. Trace the longest
// sorted partition:-
// a. in each column of the matrix
// b. Trace the longest sorted child of the matrix.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
const int n = 4;


int max(int a, int b){
	if(a>b)
		return a;
	else
		return b;
}

struct node
{
	int x , y;
}ans[101] , temp[101];

int vis[100][100];
int res;
char ans1[100000];

void longestpath(char array[100][100], int i, int j, int level){

	int flag = 0;

	vis[i][j] = 1;

	temp[level].x = i;

	temp[level].y = j;

	if(j>0 && array[i][j-1] <= array[i][j] && !vis[i][j-1]) {
		flag = 1;
		longestpath(array , i,j-1,level+1);		// left
    }

    if(j<n-1 && array[i][j+1] <= array[i][j] && !vis[i][j+1]) {
		flag = 1;
		longestpath(array , i,j+1,level+1);		// right
    }

    if(i>0 && array[i-1][j] <= array[i][j] && !vis[i-1][j]) {
		flag = 1;
		longestpath(array , i-1,j,level+1);		//up
    }

    if(i < n-1 && array[i+1][j] <= array[i][j] && !vis[i+1][j]) {
		flag = 1;
		longestpath(array , i+1,j,level+1);		// down
    }

    if(!flag && level > res) {
    	res = level;
    	for(int p=0;p<=level;p++) {
    		ans[p].x = temp[p].x;
    		ans[p].y = temp[p].y;
		}
    }
    vis[i][j] = 0;
}


void longestIncreasingPath(char array[100][100]){
	for(int i=0; i<n; i++){		
		for(int j=0; j<n; j++){		
			temp[0].x = i;
			temp[0].y = j;
			longestpath(array , i , j , 0);
		}
	}
	for(int i=0;i<=res;i++)
		ans1[i] = array[ans[i].x][ans[i].y];
}



int main(){
	srand(time(0));
	char alphabets[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
	// int n;
	// printf("Enter the n for nxn matrix \n");
	// scanf("%d", &n);
	char array[100][100];

	for(int j=0; j<n; j++){		
		for(int i=0; i<n; i++){		
			//array[i][j] = alphabets[rand()%26];		
			   scanf(" %c", &array[j][i]);
		}
	}

	printf("The random array generated is :\n");	
	for(int i=0; i<n; i++){		
		for(int j=0; j<n; j++){		
			printf("%c ", array[i][j]);		
		}
		printf("\n");		
	}

	
	printf("\n****************** PART B ******************\n");
	longestIncreasingPath(array);
	printf("Maximum sorted path length is: %d\n", res+1);
	printf("%s ", ans1);


}
