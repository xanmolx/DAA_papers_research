#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double array[10000][10000];
int m, n;
long long int t = 0;

int check(float x, float y){
    t+=3;
    if(abs(x-y)<=1){
        return 1;
    }
    return 0;
}

void compress(){
    t++;
    for(int i = 0 ; i < n ; i++){
        t++;
        t++;
        for(int j = 0 ; j < n ; j++){
            t++;
            t+=14;
            if(i-1>=0 && j>=0 && i-1<n && j<m && check(array[i-1][j] , array[i][j]) == 1){
                double new = (array[i][j] + array[i-1][j]); t+=5;
                array[i][j] = array[i-1][j] = new/2.0;  t+=5; 
            }
            t+=17;
            if(i-1>=0 && j+1>=0 && i-1<n && j+1<m && check(array[i-1][j+1] , array[i][j]) == 1){
                double new = (array[i][j] + array[i-1][j+1]);   t+=6;  
                array[i][j] = array[i-1][j+1] = new/2.0;    t+=6;
            }
            t+=14;
            if(i>=0 && j+1>=0 && i<n && j+1<m && check(array[i][j+1] , array[i][j]) == 1){
                double new = (array[i][j] + array[i][j+1]); t+=5;
                array[i][j] = array[i][j+1] = new/2.0;  t+=5;
            }
            t+=17;
            if(i+1>=0 && j+1>=0 && i+1<n && j+1<m && check(array[i+1][j+1] , array[i][j]) == 1){
                double new = (array[i][j] + array[i+1][j+1]);   t+=6;
                array[i][j] = array[i+1][j+1] = new/2.0;    t+=6;
            }
            t+=14;
            if(i+1>=0 && j>=0 && i+1<n && j<m && check(array[i+1][j] , array[i][j]) == 1){
                double new = (array[i][j] + array[i+1][j]); t+=5;
                array[i][j] = array[i+1][j] = new/2.0;  t+=5;
            }
            t+=17;
            if(i+1>=0 && j-1>=0 && i+1<n && j-1<m && check(array[i+1][j-1] , array[i][j]) == 1){
                double new = (array[i][j] + array[i+1][j-1]);   t+=6;
                array[i][j] = array[i+1][j-1] = new/2.0;    t+=6;
            }
            t+=14;
            if(i>=0 && j-1>=0 && i<n && j-1<m && check(array[i][j-1] , array[i][j]) == 1){
                double new = (array[i][j] + array[i][j-1]); t+=5;
                array[i][j] = array[i][j-1] = new/2.0;  t+=5;
            }
            t+=17;
            if(i-1>=0 && j-1>=0 && i-1<n && j-1<m && check(array[i-1][j-1] , array[i][j]) == 1){
                double new = (array[i][j] + array[i-1][j-1]);   t+=6;
                array[i][j] = array[i-1][j-1] = new/2.0;    t+=6;
            }
            t+=2;
        }
        t+=2;
    }
}

int main(){
    srand(time(0));
    FILE* fptr = fopen("average.txt","w");
    n = 1;
    int test = 0;
    while(test<1000){
    	n++;
    	m = n;
	    // scanf("%d", &n);
	    int x = 0;
	    for(int i = 0; i < n; i++){
	        for(int j = 0; j < n; j++){
	            // scanf("%lf", &array[i][j]);
	            array[i][j] = ((float)rand() / RAND_MAX) * 256;
	            // array[i][j] = 1;
	            // x+=2;   
	        }
	    }
	   
	    // for(int i = 0; i < n; i++){
	    //     for(int j = 0; j < m; j++){
	    //         printf("%0.3f ", array[i][j]);   
	    //     }
	    //     printf("\n");
	    // }

	    compress();
	    // printf("\n");
	    // printf("\n");
	    // for(int i = 0; i < n; i++){
	    //     for(int j = 0; j < m; j++){
	    //         printf("%0.3lf ", array[i][j]);   
	    //     }
	    //     printf("\n");
	    // }
	    // printf("%d",t);
		fprintf(fptr,"%d\t%lld\n",n,t+100);
		test++;
	}
	fclose(fptr);
    return 0;
}
