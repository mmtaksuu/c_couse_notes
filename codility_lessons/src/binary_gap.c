/**
 * @file    : codility project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 08 / March / 2020
 * @code    : binary_gap.c file
 * @details : 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define     SIZE              100

int solution(int N);

int main()
{
    int x;

    printf("bir tamsayi giriniz: ");
    scanf("%d", &x);

    int binary_gap = solution(x);
    printf("The largest binary gap is %d\n", binary_gap);

}

int solution(int N)
{
    char str[SIZE] = {0};

    printf("ikilik sayi sisteminde\n");
    _itoa(N, str, 2);
    printf("[%s]\n", str);

    size_t len = strlen(str);
    printf("len %zu\n", len);

    int length = 0;

    char *p1 = NULL;
    char *p2 = NULL;

    for (int i = 0; i < len; ++i) {
        p1 = strchr(str+i, '1');
        if (p1 != NULL) {
            p2 = strchr(p1+1, '1');
        } else{
            return 0;
        }

        if (p2 != NULL){
            length = (int)((p2-p1) - 1);
            return length;
        }

    }


}
