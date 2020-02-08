#ifndef  NUTILITY_INCLUDED
#define  NUTILITY_INCLUDED

#define		isleap(y)     ((y) % 4 == 0 && ((y) % 100 != 0 || (y) % 400 == 0))
#define     asize(x)      (sizeof(x) / sizeof(x[0]))

int isprime(int val);
int ndigit(int val);
void sl(void);
void sleep(double sec);
void swap(int *p1, int *p2);
int day_of_the_week(int d, int m, int y); //sakomoto
void randomize(void);
char *sgets(char *p);
void display_array(const int *ptr, int size);
void set_random_array(int *ptr, int size);
void bsort(int *p, int size);


#endif