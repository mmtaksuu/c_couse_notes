/**
 * @file    : LOG_FILE_GENERATOR project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 19 / April / 2020
 * @code    : log_file_name_generator.h file
 * @details : 
 */

#ifndef LOG_FILE_NAME_GENERATOR_H
#define LOG_FILE_NAME_GENERATOR_H

#define FILE_NAME_LEN     100
#define TIME_LABEL_LEN    50


char * get_time_label(char * p_time);

char* generate_log_file_name(char *p_fname, const char *p_extension);


#endif //LOG_FILE_NAME_GENERATOR_H
