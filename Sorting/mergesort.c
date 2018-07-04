#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int *arr, int *tmp, int left, int right, int end);
int *mergeSort(int *arr, int length);
void doMergeSort(int *arr, int *tmp, int left, int right);

void main(){
	srand(time(NULL));
	int *iArr = (int *)malloc(sizeof(int)*5);// test with 5 element array
	for(int i = 0; i < 5; i++){
		iArr[i] = rand()%100-50;//5 random numbers from -50 to 50
	}
	int *iArr2 = (int *)malloc(sizeof(int)*6);// test with 4 element array
	for(int i = 0; i < 6; i++){
		iArr2[i] = rand()%100-50;//5 random numbers from -50 to 50
	}
	int *fArr = mergeSort(iArr, 5);
	int *fArr2 = mergeSort(iArr2, 6);
	printf("===== TEST 1 WITH 5 ELEMENT ARRAY =====\n");
	printf("Before sorting, this array contains 5 integers in the following order: [%i, %i, %i, %i, %i]\n", *iArr, *(iArr+1), *(iArr+2), *(iArr+3), *(iArr+4));
	printf("After sorting, this array contains 5 integers in the following order: [%i, %i, %i, %i, %i]\n", *fArr, *(fArr+1), *(fArr+2), *(fArr+3), *(fArr+4));
	printf("===== TEST 2 WITH 6 ELEMENT ARRAY =====\n");
	printf("Before sorting, this array contains 6 integers in the following order: [%i, %i, %i, %i , %i, %i]\n", *iArr2, *(iArr2+1), *(iArr2+2), *(iArr2+3),
		*(iArr2+4),*(iArr2+5));
	printf("After sorting, this array contains 6 integers in the following order: [%i, %i, %i, %i , %i, %i]\n", *fArr2, *(fArr2+1), *(fArr2+2), *(fArr2+3),
		*(fArr2+4),*(fArr2+5));	
	free(iArr);
	free(iArr2);
	free(fArr);
	free(fArr2);
}

int * mergeSort(int *arr, int length) {
	int *tmp = (int*)malloc(sizeof(int) * length);
	doMergeSort(arr, tmp, 0, length - 1); 
	return tmp;
}

void doMergeSort(int *arr, int *tmp, int left, int right) {
	if(left < right) {
		int center = (left + right) / 2; 
		doMergeSort(arr, tmp, left, center);
		doMergeSort(arr, tmp, center + 1, right);
		merge(arr, tmp, left, center + 1, right);
	}
}

void merge(int *arr, int *tmp, int left, int right, int end){
        int *aArr = (int *)malloc(sizeof(int)*(right-left));
        int *bArr = (int *)malloc(sizeof(int)*(end-right+1));
        int aCtr = 0;
        int bCtr = 0;
        for(int i = 0;i < right-left;i++){
		if(right-left == 1){// if this element is being put into tmp for the first time, take from arr
			*(aArr+i) = *(arr+left+i);
		}else{
                	*(aArr+i) = *(tmp+left+i);
		}
        }
        for(int i = 0;i < end-right+1;i++){
                if(end-right == 0){// if this element is being put into tmp for the first time, take from arr
			*(bArr+i) = *(arr+right+i);
		}else{
			*(bArr+i) = *(tmp+right+i);
		}
        }
        while(aCtr+bCtr<end-left+1){
                if(aCtr == right-left){
                        *(tmp+left+aCtr+bCtr) = *(bArr+bCtr);
                        bCtr++;
                }else if(bCtr == end-right+1){
                        *(tmp+left+aCtr+bCtr) = *(aArr+aCtr);
                        aCtr++;
                }else if(*(aArr+aCtr)>*(bArr+bCtr)){
                        *(tmp+left+aCtr+bCtr) = *(bArr+bCtr);
                        bCtr++;
                }else{
                        *(tmp+left+aCtr+bCtr) = *(aArr+aCtr);
                        aCtr++;
                }
        }
        free(aArr);
        free(bArr);
}
