#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int n;
int arr[100000];
int temp_arr[100000];

struct node{
	int data;
	struct node* next;
}*brr[200000], *crr[100000];
struct node* push_end(struct node* head, int x){
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = x;
	if(head == NULL){
		temp->next = head;
		head = temp;
		return head;
	}
	else{
		struct node* temp1 = head;
		while(temp1->next != NULL)
			temp1 = temp1->next;
		temp1->next = temp;
		temp->next = NULL;
		return head;
	}
}


void print(struct node* head){
	struct node* temp;
	temp = head;
	while(temp != NULL){
		printf("%d ", temp->data);
		temp = temp->next;
	// printf("\n");
	}
	printf("\n");
}

void swap(int j){
	int temp;
	temp = arr[j];
	arr[j] = arr[j+1];
	arr[j+1] = temp;
	temp = temp_arr[j+1];
	temp_arr[j+1] = temp_arr[j];
	temp_arr[j] = temp;
}

void bubble_sort(){
	for(int i=0; i<n; i++){
		brr[temp_arr[i]] = push_end(brr[temp_arr[i]], i);
		// crr[i] = push_end(crr[i], i);
	}

	// for(int i=0; i<n; i++){
	// 	print(brr[i]);
	// }
	

	for(int i=0; i<n-1; i++) {
		for(int j=0; j<n-i-1; j++){

			if(arr[j] > arr[j+1]){
				
				brr[temp_arr[j+1]] = push_end(brr[temp_arr[j+1]], j);
			//	printf("%d %d --- %d %d\n", arr[j+1], j, arr[j], j+1);
				brr[temp_arr[j]] = push_end(brr[temp_arr[j]], j+1);
				swap(j);
			}
			for(int k=0; k<n; k++){
				crr[k] = push_end(crr[k], arr[k]);
			}
			// for(int i=0; i<n; i++){
			// }
		}
	}
	printf("Path of Elements\n");
	for(int i=0;i<200000;i++)
	{
		if(brr[i]!=NULL){
			printf("%d-> ", i);
			print(brr[i]);	
			printf("\n");
		}
		// printf("\n");
	}
	printf("\n");

	printf("Value of Indices\n");
	for(int i=0; i<n; i++)
	{
		printf("%d-> ", i);
		print(crr[i]);
		printf("\n");
	}
}

int main(){
	srand(time(0));
	scanf("%d", &n);

	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
		temp_arr[i] = i;
		// arr[i] = rand();
	}

	bubble_sort();
	
	
	for(int i=0; i<n; i++){
		printf("%d ", arr[i]);
	}
}
