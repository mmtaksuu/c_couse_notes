/**
 * @file    : LESSON_17 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 18 / April / 2020
 * @code    : mersenne_twister.h file
 * @details : This is a Mersenne Twister pseudorandom number generator header file.
 */

#ifndef MERSENNE_TWISTER_H
#define MERSENNE_TWISTER_H

/* Period parameters */
#define     N           624
#define     M           397
#define     MATRIX_A    0x9908b0dfUL   /* constant vector a */
#define     UPPER_MASK  0x80000000UL /* most significant w-r bits */
#define     LOWER_MASK  0x7fffffffUL /* least significant r bits */


static unsigned long mt[N]; /* the array for the state vector  */
static int mti = N + 1;         /* mti==N+1 means mt[N] is not initialized */

/* initializes mt[N] with a seed */
void init_genrand(unsigned long s);

/* initialize by an array with array-length */
void init_by_array(const unsigned long init_key[], int key_length);

/* generates a random number on [0,0xffffffff]-interval */
unsigned long genrand_int32(void);

/* generates a random number on [0,0x7fffffff]-interval */
long genrand_int31(void);

/* generates a random number on [0,1]-real-interval */
double genrand_real1(void);

/* generates a random number on [0,1)-real-interval */
double genrand_real2(void);

/* generates a random number on (0,1)-real-interval */
double genrand_real3(void);

/* generates a random number on [0,1) with 53-bit resolution*/
double genrand_res53(void);


#endif //MERSENNE_TWISTER_H
