/**
 * @file    : LESSON_41 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 26 / April / 2020
 * @code    : find_dist_on_the_earth.c file
 * @details : 
 */

#include <math.h>
#include <stdio.h>

/**
 *  41.129460  27.905525
    41.147148  27.932528
 * */

//#define     RADIUS_OF_THE_EARTH_IN_KM   6371.01
#define     RADIUS_OF_THE_EARTH_IN_KM   6.371

typedef struct _Points {
    float lat;
    float lon;
} POINTS_t;



double find_distance(POINTS_t pt1, POINTS_t pt2)
{
    double distance = 0.0;
    float katsayi = acosf( sinf(pt1.lat) * sinf(pt2.lat) + cosf(pt1.lat) * cosf(pt2.lat) * cosf(pt1.lon - pt2.lon) );

    distance = RADIUS_OF_THE_EARTH_IN_KM * katsayi;

    return distance;
}


int main(void)
{
    POINTS_t point1 = {41.129460, 27.905525};
//    printf("Enter the first point as (lat, lon) : \n");
//    scanf("%f%f", &point1.lat, &point1.lon);

    POINTS_t point2 = {41.147148, 27.932528};
//    printf("Enter the second point as (lat, lon) : \n");
//    scanf("%f%f", &point2.lat, &point2.lon);



    double distance = find_distance(point1, point2);
    printf("Distance between the points is %f kilometers.\n", distance);

    return 0;
}


