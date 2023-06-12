#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int nr, requests[40], sortedReq[40], satisfied[40], sequence[40], size, dir, inPos, pos, loc, dist=0, sp=0;
void input(){
	printf("Enter size of cylinder: ");
	scanf("%d",&size);
	printf("Enter no. of Requests: ");
	scanf("%d", &nr);
	printf("Enter Requests Sequence: ");
	for(int i=0; i<nr; i++){
		scanf("%d", &requests[i]);
	}
	printf("Enter Initial head position: ");
	scanf("%d", &pos);
	inPos = pos;
	printf("Input Direction: (0 to beginning / 1 to end track): ");
	scanf("%d", &dir);
}
void CSCAN(){
	if(dir==0){
		for(int i=nr-1; i>=0; i--){
			if(sortedReq[i]<pos){
				dist = dist + abs(pos-sortedReq[i]);
				pos = sortedReq[i];
				sequence[sp] = sortedReq[i];
				satisfied[i]=1;
				sp++;
			}
			if(i==0){
				dist = dist + pos;
				sequence[sp] = 0;
				sp++;
				pos = 0;
				dist=dist+(size-1);
				sequence[sp]=size-1;
				sp++;
				pos=size-1;
			}
			
		}
		for(int i=nr-1; i>=0; i--){
			if(!satisfied[i]){
				dist = dist + abs(pos-sortedReq[i]);
				pos = sortedReq[i];
				sequence[sp] = sortedReq[i];
				satisfied[i]=1;
				sp++;
			}
		}
		
	}else{
		for(int i=0; i<nr; i++){
			if(sortedReq[i]>pos){
				dist = dist + abs(pos-sortedReq[i]);
				pos = sortedReq[i];
				sequence[sp] = sortedReq[i];
				satisfied[i]=1;
				sp++;
			}
			if(i==nr-1){
				dist = dist + abs(size-pos-1);
				sequence[sp] = size-1;
				sp++;
				pos = size-1;
				dist=dist+(size-1);
				sequence[sp]=0;
				sp++;
				pos=0;
			}
		}
		for(int i=0; i<nr; i++){
			if(!satisfied[i]){
				dist = dist + abs(pos-sortedReq[i]);
				pos = sortedReq[i];
				sequence[sp] = sortedReq[i];
				satisfied[i]=1;
				sp++;
			}
		}
	}
}
void output(){
	printf("Total seek distance is %d", dist);
	printf("\n Seek Movement sequece:");
	printf("%d", inPos);
	for(int i=0; i<sp; i++){
		printf("-> %d ", sequence[i]);
	}
}
void copy(){
	for(int i=0; i<nr; i++){
		sortedReq[i] = requests[i];
	}
}
void sort(){
	int temp;
	for(int i=0; i<nr; i++){
		for(int j=i+1; j<nr; j++){
			if(sortedReq[j] < sortedReq[i]){
				temp = sortedReq[j];
				sortedReq[j] = sortedReq[i];
				sortedReq[i] = temp;
			}
		}
	}
}
void main(){
	input();
	copy();
	sort();
	CSCAN();
	output();
}
