#include "../includes/nutility.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


/*
	function isprime
	tests primality of an integer
	returns non-zero if integer is prime
	returns 0 otherwise
*/

int isprime(int val)
{
	if (val == 0 || val == 1)
		return 0;

	if (val % 2 == 0)
		return val == 2;

	if (val % 3 == 0)
		return val == 3;

	if (val % 5 == 0)
		return val == 5;

	for (int k = 7; k * k <= val; k += 2)
		if (val % k == 0)
			return 0;

	return 1;
}

/**********************************************************************************************************************/


int ndigit(int val)
{
	if (val == 0)
		return 1;

	int digit_count = 0;

	while (val) {
		++digit_count;
		val /= 10;
	}

	return digit_count;
}

/**********************************************************************************************************************/


void sl(void)
{
	printf("\n----------------------------------------------------------\n");
}

/**********************************************************************************************************************/



void sleep(double sec)
{
	clock_t start = clock();

	while ((double)(clock() - start) / CLOCKS_PER_SEC < sec)
		;
}

/**********************************************************************************************************************/
void swap(int *p1, int *p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

/**********************************************************************************************************************/
int day_of_the_week(int d, int m, int y)
{
	static const int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };

	// if month is less than 3 reduce year by 1 
	if (m < 3)
		y -= 1;

	return ((y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7);
}


void randomize(void)
{
	srand((unsigned)time(NULL));
}



char *sgets(char *p)
{
	int c;
	char *ptemp = p;

	while ((c = getchar()) != '\n')
		*p++ = c;

	*p = '\0';

	return ptemp;
}


void display_array(const int *ptr, int size)
{
	for (int i = 0; i < size; ++i) {
		printf("%3d%c", ptr[i], i % 20 == 19 ? '\n' : ' ');
	}
	printf("\n-----------------------------------------------------------------\n");
}

void set_random_array(int *ptr, int size)
{
	while (size--) {
		*ptr = rand() % 1000;
		++ptr;
	}

}


//void bsort(int *p, int size)
//{
//	for (int i = 0; i < size - 1; ++i) {
//		for (int k = 0; k < size - 1 - i; ++k) {
//			if (p[k] > p[k + 1])
//				swap(p + k, p + k + 1);
//		}
//	}
//}