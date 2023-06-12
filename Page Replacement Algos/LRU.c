#include<stdio.h>
int refString[30], frame[30], allocated[30], pageFaults, nr, nf,hit, flag, k=0, done=0;
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
void lru(){
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
		
		// If value doesn't exist
		if(flag==0){
			if(done < nf){
				frame[k] = refString[i];
				printFrm(refString[i], 0);
				k++;
			}else{
				int visited[30], temp=0;
				for(int p=0; p<nf; p++){
					visited[p]=0;
				}
				for(int p=i-1; p>=0; p--){
					for(int q=0; q<nf ; q++){
						if(refString[p] == frame[q] && !visited[q]){
							visited[q]=1;
							temp++;
							if(temp==nf){
								k=q;
								break;
							}
						}
					}
				}
				frame[k] = refString[i];
				printFrm(refString[i], 0);
			}
			done++;
			pageFaults++;
		}
	}
}

void print(){
	printf("\n No. of Page Faults: %d \n No. of Page hits: %d \n", pageFaults, hit);
	printf(" Final Frame Status: \n");
	for(int i=nf-1; i>=0; i--){
		printf("%d \n", frame[i]);
	}
}
void main(){
	input();
	lru();
	print();
}
