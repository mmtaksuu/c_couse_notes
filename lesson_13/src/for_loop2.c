/*
  Project Name: LESSON_13
  Author: MEHMET AKSU
  Author Email: mmtaksu.25@gmail.com
  Date: 02 / Ocak / 2020
  Description: for_loop2.c file
*/

#include <stdio.h>

#define    SIZE    10


int main(void) {
    int arr[SIZE];

    printf("Please fill the array with 10 numbers.\n");

    for (int i = 0; i < SIZE; ++i) {
        printf("[%d] : ", i);
        scanf("%d", &arr[i]);
    }


    printf("\nUnique numbers in this array are:\n");

    int j;
    for (int i = 0; i < SIZE; ++i) {
        for (j = 0; j < SIZE; ++j) {
            if (arr[i] == arr[j] && i != j)
				break;
		}

		if(j == SIZE)
			printf("%d ", arr[i]);
	}
	printf("\n");


	return 0;
}