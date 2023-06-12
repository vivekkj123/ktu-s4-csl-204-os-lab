#include<stdio.h>
#include<stdlib.h>
int n, len[20], Idx[20];
struct Block{
	int data[20];
}blk[20];
void input(){
	printf("Enter no. of Files: ");
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		int item;
		printf("\nEnter index of file %d: ", i+1);
		scanf("%d", &Idx[i]);
		printf("\nEnter no. of blocks occupied by file %d: ", i+1);
		scanf("%d", &len[i]);
		printf("\nEnter the blocks: ");
		for(int j=0; j<len[i]; j++){
			scanf("%d", &blk[Idx[i]].data[j]);
		}
	}
}
void printAllocTable(){
	printf("\n\nFile Name\t\t Length\t\t Index");
	for(int i=0; i<n; i++){
		printf("\n%d\t\t\t %d\t\t \t\t%d",i+1, len[i], Idx[i]);
	}
}
void showAlloc(){
	int fn;
	printf("\nEnter file name (0 for exit ): ");
	scanf("%d", &fn);
	if(fn!=0){	
		printf("\nFile name is: %d", fn);
		printf("\nLength is: %d", len[fn-1]);
		printf("\nIndex is: %d", Idx[fn-1]);
		printf("\nBlocks occupied: ");
		for(int i=0; i<len[fn-1]; i++){
			printf("\t %d", blk[Idx[fn-1]].data[i]);
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

