/**
 * @file    : LESSON_31 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 11 / Mayıs / 2020
 * @code    : error_test.c file
 * @details : 
 */

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <windows.h>


void ExitSys(LPCSTR lpszMsg)
{
    DWORD dwLastError = GetLastError();
    LPTSTR lpszErr;

    if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, dwLastError, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpszErr, 0, NULL))
    {
        fprintf(stderr, "%s: %s", lpszMsg, lpszErr);
        LocalFree(lpszErr);
    }

    exit(EXIT_FAILURE);
}

void exit_sys(const char * pmsg)
{
    perror(pmsg);
    exit(EXIT_FAILURE);
}


void Exit_Sys(char *pname)
{
    fprintf(stderr, "%s : %d- %s\n", pname, errno, strerror(errno));
    exit(EXIT_FAILURE);
}

int main(void)
{
    FILE *f;

    if ((f = fopen("text.txt", "r")) == NULL){
        //ExitSys("fopen");
        //Exit_Sys("fopen");
        exit_sys("fopen");
    }

    printf("Dosya okundu\n");

    return 0;
}
