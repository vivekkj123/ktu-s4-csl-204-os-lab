#include<stdio.h>
#include<stdlib.h>
int n, len[20], start[20];
void input(){
	printf("Enter no. of Files: ");
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		printf("\nEnter starting block of file %d: ", i+1);
		scanf("%d", &start[i]);
		printf("\nEnter no. of blocks occupied by file %d: ", i+1);
		scanf("%d", &len[i]);
	}
}
void printAllocTable(){
	printf("\n\nFile Name\t\t Start Block\t\t Length");
	for(int i=0; i<n; i++){
		printf("\n%d\t\t\t %d\t\t\t %d",i+1, start[i], len[i]);
	}
}
void showAlloc(){
	int fn;
	printf("\nEnter file name (0 for exit ): ");
	scanf("%d", &fn);
	if(fn!=0){	
		printf("\nFile name is: %d", fn);
		printf("\nLength is: %d", len[fn-1]);
		printf("\nBlocks occupied: ");
		for(int i=0; i<len[fn-1]; i++){
			printf("\t %d", start[fn-1]+i);
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

