```c
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define     asize(x)          (sizeof(x) / sizeof (x[0]))
#define     randomize()       (srand((unsigned)time(NULL)))
#define     SIZE              10


void display_array(const int *arr, size_t size)
{
    for (size_t i = 0; i < size; ++i)
        printf("%d%c", arr[i], i%10==9 ? '\n' : ' ');
    printf("------------------------------------\n");
}

void set_rand_array(int *a, size_t size)
{
    for (size_t i = 0; i < size; ++i)
        a[i] = rand()%100;
}


int get_mean(const int *a, size_t size)
{
    int sum  = 0;

    for (size_t i = 0; i < size; ++i)
        sum += a[i];

    return sum / (int)size;
}

int is_odd(size_t val)
{
    return val%2 != 0;
}

int get_median(const int *a, size_t size)
{
    int median = 0;

    if (is_odd(size))
        median = a[(size/2)];
    else
        median = (a[(size/2)-1] + a[(size/2)]) / 2;

    return median;
}

int icmp(const void *vp1, const void *vp2)
{
    const int arg1 = *(const int *)vp1;
    const int arg2 = *(const int *)vp2;

    return (arg1 > arg2) - (arg1 < arg2);
}

int main(void)
{
    randomize();
    int a[SIZE] = {0};

    set_rand_array(a, asize(a));
    display_array(a, asize(a));

    qsort(a, asize(a), sizeof(*a), &icmp);
    printf("\nSorted array is \n");
    display_array(a, asize(a));

    printf("Mean of array is %d\n", get_mean(a, asize(a)));
    printf("Median of array is %d\n", get_median(a, asize(a)));

    int key = 0;
    printf("Enter the for search = ");
    scanf("%d", &key);

    int *p = (int *)bsearch(&key, a, asize(a), sizeof(*a), &icmp);
    if (!p)
        printf("Didn't find!\n");
    else
        printf("Found at %lld index.\n", p-a);

    return 0;
}
```

```text
* Double array sort and find median
```
```c
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define     asize(x)          (sizeof(x) / sizeof (x[0]))
#define     randomize()       (srand((unsigned)time(NULL)))
#define     SIZE              10


void display_array_i(const int *p, size_t size)
{
    for (size_t i = 0; i < size; ++i)
        printf("%d%c", p[i], i%10==9 ? '\n' : ' ');
    printf("------------------------------------\n");
}

void display_array_d(const double *p, size_t size)
{
    for (size_t i = 0; i < size; ++i)
        printf("%.2lf%c", p[i], i%10==9 ? '\n' : ' ');
    printf("-------------------------------------\n");
}


double get_mean_d(const double *a, size_t size)
{
    double sum  = 0;

    for (size_t i = 0; i < size; ++i)
        sum += a[i];

    return sum / size;
}

int is_odd(size_t val)
{
    return val%2 != 0;
}

double get_median_d(const double *a, size_t size)
{
    double median = 0;

    if (is_odd(size))
        median = a[(size/2)];
    else
        median = (a[(size/2)-1] + a[(size/2)]) / 2.0;

    return median;
}

int dcmp(const void *vp1, const void *vp2)
{
    const double arg1 = *(const double *)vp1;
    const double arg2 = *(const double *)vp2;

    return (arg1 > arg2) - (arg1 < arg2);
}

int main(void)
{
    double b[SIZE] = {12.5, 10.3, 52.8, 25.7, 19.3, 12.7, 87.4, 43.2, 11.9, 78.5};

    display_array_d(b, asize(b));

    qsort(b, asize(b), sizeof(*b), &dcmp);
    printf("\nSorted array is \n");
    display_array_d(b, asize(b));

    printf("Mean of array is %.2lf\n", get_mean_d(b, asize(b)));
    printf("Median of array is %.2lf\n", get_median_d(b, asize(b)));

    double key = 0.0;
    printf("Enter the key for search = ");
    scanf("%lf", &key);

    double *p = (double *)bsearch(&key, b, asize(b), sizeof(*b), &dcmp);
    if (!p)
        printf("Didn't find!\n");
    else
        printf("%.2lf Found at %lld index!\n", key, p-b);

    return 0;
}
```