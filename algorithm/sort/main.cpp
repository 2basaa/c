#include <stdio.h>
//�����ō�������C�u�����ł́A""���g�p���� 
#include "insertion.h"
#include "merge.h"

#define N 9

int main(void) {
    int data[N] = {9,7,6,8,5,10,3,2,56};
    int number;
    int *mergeData;

    printf("\nBefore : ");
    for (number=0; number < N; number++) {
    	printf("%d ", data[number]);
	}
	printf("\n");
	
	merge_sort(data, 0, N-1);
	
	printf("\nAfter : ");
    for (number=0; number < N; number++) {
    	printf("%d ", data[number]);
	}

	return 0;
}
