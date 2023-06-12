#include<stdio.h>
int refString[30], frame[30], allocated[30], pageFaults, nr, nf,hit, flag, k=0;
void input(){
	printf("Enter no. of Reference Strings: ");
	scanf("%d", &nr);
	printf("Enter Reference String sizes:");
	for(int i=0; i<nr; i++){
		scanf("%d", &refString[i]);
	}
	printf("Enter no. of Frames: ");
	scanf("%d", &nf);
}
void print(){
	printf("\n No. of Page Faults: %d \n No. of Page hits: %d \n", pageFaults, hit);
	printf(" Final Frame Status: \n");
	for(int i=nf-1; i>=0; i--){
		printf("%d \n", frame[i]);
	}
}
void printFrm(int str, int hit){
	// if hit=0 MISS, hit=1 HIT
	printf("\n\t%d\t",str);
	if(hit==1){
		printf("\tHIT");
	}else{
		for(int i=nf-1; i>=0; i--){
			printf("\t%d", frame[i]);
		}
	}
}
void opt(){
	int done=0;
	for(int i=0; i<nf; i++){
		frame[i] = -1;
	}
	for(int i=0; i<nr; i++){
		int flag=0;
		for(int j=0; j<nf; j++){
			if(frame[j] == refString[i]){
				flag=1;
				done++;
				hit++;
				printFrm(refString[i], 1);
				break;
			}
		}
		if(flag==0){
			if(done<nf){
				frame[k]=refString[i];
				// k=(k+1)%nf;
				printFrm(refString[i], 0);
			}else{
				int future[30], temp=0;
					for(int n=0; n<nf; n++){
							future[n] = 0;
					}
				for(int p=i+1; p<nr; p++){
					for(int q=0; q<nf; q++){
						if(frame[q] == refString[p]){
							if(!future[q]){
								future[q]=1;
								temp++;
							}
							if(temp==nf){
								frame[q] = refString[i];
								q=nf;
								p=nr;
								break;							
							}
						}
					}
				}
				for(int p=nf-1; p>=0; p--){
					if(future[p] == 0){
						frame[p] = refString[i];
						break;
					}
				}
				printFrm(refString[i], 0);
			}
				k=(k+1)%nf;
				done++;
				pageFaults++;
		}
	}
}
void main(){
	input();
	opt();
	print();
}
