/**
 * @file    : LESSON_35 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 13 / September / 2020
 * @code    : generate_log_file_name.c file
 * @details : 
 */


#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * gen_log_file_name (const char * path)
{
    time_t timer;
    time(&timer);
    struct tm *p = localtime(&timer);

    size_t len = strlen("%04d_%02d_%02d_%02d_%02d_%02d.log") + strlen(path) + 1;

    char * pd_file_name = (char *)malloc(len * sizeof(char));
    if (!pd_file_name) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    sprintf(pd_file_name, "%s\\%04d_%02d_%02d_%02d_%02d_%02d.log", path,
            p->tm_year+1900, p->tm_mon+1, p->tm_mday, p->tm_hour, p->tm_min, p->tm_sec);

    return pd_file_name;
}

int main(void)
{
    const char * cwd = "C:\\Users\\MehmetAksu\\CLionProjects\\c_programing_course\\lesson_35";
    char * file_name = gen_log_file_name(cwd);

    FILE * file = fopen(file_name, "w");
    if (!file) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    fclose(file);
    free(file_name);

    return 0;
}



