/**
 * @file    : LESSON_41 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 21 / April / 2020
 * @code    : path_splitting.c file
 * @details : 
 */


#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int main( void )
{
    char path_buffer[_MAX_PATH];
    char drive[_MAX_DRIVE];
    char dir[_MAX_DIR];
    char fname[_MAX_FNAME];
    char ext[_MAX_EXT];

//    _makepath( path_buffer, "c", "\\sample\\crt\\", "makepath", "c" ); // C4996
//    // Note: _makepath is deprecated; consider using _makepath_s instead
//    printf( "Path created with _makepath: %s\n\n", path_buffer );

    printf("Enter the full path : \n");
    scanf("%s", path_buffer);

    _splitpath( path_buffer, drive, dir, fname, ext ); // C4996

    printf( "Path extracted with _splitpath:\n" );
    printf( "   Drive: %s\n", drive );
    printf( "   Dir: %s\n", dir );
    printf( "   Filename: %s\n", fname );
    printf( "   Ext: %s\n", ext );


    return 0;
}

