#include<stdio.h>
int nh, np, process[30], holeSize[30], remHole[30], usedHole[30], allocated[30];
void input(){
	printf("Enter no. of Processes: ");
	scanf("%d", &np);
	for(int i=0; i<np; i++){
		printf("Enter size of Process %d: ", i+1);
		scanf("%d", &process[i]);
	}
	printf("Enter no. of Holes: ");
	scanf("%d", &nh);
	for(int i=0; i<nh; i++){
		printf("Enter size of Hole %d: ", i+1);
		scanf("%d", &holeSize[i]);
	}
}
void allocate(){
	for(int i=0; i<np; i++){
		int bstIdx=-1;
		for(int j=0; j<nh; j++){
			if(remHole[j] >= process[i]){
				if(bstIdx==-1){
					bstIdx = j;
				}else if(remHole[j] < remHole[bstIdx]){
					bstIdx = j;
				}
			}
		}
		if(bstIdx!=-1){
			allocated[i] = 1;
			usedHole[i] = bstIdx+1;
			remHole[bstIdx] -= process[i]; 
		}
	}
}
void print(){
	printf("\tProcess\t\tSize\t\tHole\n");
  	for (int i = 0; i < np; i++) {
    		printf("\tP%d\t\t%d\t\t", i + 1, process[i] );
    		if(allocated[i] != 1){
    			printf("Not Allocated \n");
    		}else{
    			printf("H%d \n", usedHole[i]);
    		}
  	}
  	printf("\n\n");
  	printf("\tHole\t\tActual\t\tAvailable\n");
  	for (int i = 0; i < nh; i++) {
    		printf("\tH%d\t\t%d\t\t%d \n", i + 1, holeSize[i], remHole[i] );
  	}
}
void copy(){
	for(int i=0; i<nh; i++){
		remHole[i] = holeSize[i];
	}
}
void main(){
	input();
	copy();
	allocate();
	print();
}
