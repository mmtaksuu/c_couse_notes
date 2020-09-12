/**
 * @file    : LESSON_34 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 11 / September / 2020
 * @code    : get_allocated_memory.c file
 * @details : 
 */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <basetsd.h>

#define     MEMORY_BLOCK_1_KB   (1024)                /** 1024 Bytes is equal to 1 KB  */
#define     MEMORY_BLOCK_1_MB   (1024 * 1024)         /** 1024 KBytes is equal to 1 MB */
#define     MEMORY_BLOCK_1_GB   (1024 * 1024 * 1024)  /** 1024 MBytes is equal to 1 GB */


char *get_size(UINT64 bytes)
{
    char *suffix[] = {"B", "KB", "MB", "GB", "TB"};
    char length    = sizeof(suffix) / sizeof(suffix[0]);

    int i = 0;
    double dblBytes = bytes;

    if (bytes > 1024) {
        for (i = 0; (bytes / 1024) > 0 && i<length-1; i++, bytes /= 1024)
            dblBytes = bytes / 1024.0;
    }

    if (bytes == 1024) {
        i = 1;
        dblBytes = bytes / 1024.0;
    }

    static char output[200];
    sprintf(output, "%.02lf %s", dblBytes, suffix[i]);
    return output;
}

int main(void)
{
    int *p_arr[2048] = {0};

    size_t i = 0;
    for (i = 0; i < 1792; ++i) {
        p_arr[i] = (int *)malloc(MEMORY_BLOCK_1_MB);
        if (!p_arr[i]) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
    }

    printf("%s memory allocated.\n", get_size(i * MEMORY_BLOCK_1_MB));

    for (size_t j = 0; j < 1792; ++j) {
        free(p_arr[j]);
        p_arr[j] = NULL;
    }

    return 0;
}

