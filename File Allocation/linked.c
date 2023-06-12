#include<stdio.h>
#include<stdlib.h>
int n, len[20], start[20];
struct Block{
	int data;
	struct Block *next;
};
struct Block * head[20];
void input(){
	printf("Enter no. of Files: ");
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		int item;
		struct Block *new;
		struct Block *temp;
		head[i]=NULL;
		new = (struct Block *)malloc(sizeof (struct Block));
		printf("\nEnter starting block of file %d: ", i+1);
		scanf("%d", &item);
		new->data = item;
		new->next = NULL;
		head[i] = new;
		printf("\nEnter no. of blocks occupied by file %d: ", i+1);
		scanf("%d", &len[i]);
		printf("\nEnter the blocks: ");
		for(int j=0; j<len[i]-1; j++){
			scanf("%d", &item);
			struct Block *new;
			struct Block *temp;
			new = (struct Block *)malloc(sizeof (struct Block));
			new->data = item;
			new->next = NULL;
			temp = head[i];
			while(temp->next != NULL){
				temp = temp->next;
			}
			temp->next = new;
		}
	}
}
void printAllocTable(){
	printf("\n\nFile Name\t\t Start Block\t\t Length\t\t Block");
	for(int i=0; i<n; i++){
		struct Block * temp;
		temp = head[i];
		printf("\n%d\t\t\t %d\t\t\t %d\t\t",i+1, temp->data, len[i]);
		while(temp->next != NULL){
			printf("%d->", temp->data);
			temp = temp->next;
		}
		printf("%d", temp->data);
	}
}
void showAlloc(){
	int fn;
	printf("\nEnter file name (0 for exit ): ");
	scanf("%d", &fn);
	struct Block * temp;
	if(fn!=0){	
		temp = head[fn-1];
		printf("\nFile name is: %d", fn);
		printf("\nLength is: %d", len[fn-1]);
		printf("\nBlocks occupied: ");
		for(int i=0; i<len[fn-1]; i++){
			printf("\t %d", temp->data);
			temp = temp->next;
		}
		while(fn!=0){
			showAlloc();
		}
	}else{
		exit(0);
	}
}
void main(){
	input();
	printAllocTable();
	showAlloc();
}

