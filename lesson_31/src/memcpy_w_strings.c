/**
 * @file    : LESSON_31 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 10 / May / 2020
 * @code    : memcpy_w_strings.c file
 * @details : 
 */


#include <stdio.h>
#include <string.h>
#include "helper.h"


int main(void)
{
    char *src = "A lot of people infacted by corana virus died in the world!\n"
                "Turkey has developed medical ventilator system as domesticus\n";

    printf("Source Array : \n");
    printf("%s \n", src);

    size_t start_idx, end_idx, n_of_items;
    printf("Enter start_idx, end_idx = ");
    scanf("%u%u", &start_idx, &end_idx);
    n_of_items = end_idx - start_idx;

    char *pdest = (char *)malloc(n_of_items*sizeof(*src) + 1);
    if (!pdest){
        fprintf(stderr, "Out of Memory!\n");
        exit(EXIT_FAILURE);
    }

    memcpy(pdest, src+start_idx, n_of_items*sizeof(*src));

    *(pdest + n_of_items) = '\0';

    printf("Destination Array : \n");
    printf("%s \n", pdest);

    free(pdest);

    return 0;
}


