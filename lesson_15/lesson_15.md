# LESSON 15
 
## Function-like macros or Functional macros


```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define  square(a)		(a) * (a)

int main(void)
{
    int x;
    
    printf("bir tamsayi giriniz: ");
    scanf("%d", &x);
    
    int y = square(x + 1);  //int y = (x + 1) * (x + 1);
    printf("y = %d\n", y);
    
    return 0;
}
```



/**********************************************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define  isleap(y)		((y) % 4 == 0 && ((y) % 100 != 0 || (y) % 400 == 0))

int main()
{
	int year;

	printf("yil degerini girin: ");
	scanf("%d", &year);

	if (isleap(year)) {
		printf("artik yil\n");
	}
	else {
		printf("artik yil degil\n");
	}

}
//----------------------------------------------------------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define  max2(a, b)		((a) > (b) ? (a) : (b))

int main()
{
	int x, y;

	printf("iki tamsayi giriniz: ");
	scanf("%d%d", &x, &y);

	printf("max = %d\n", max2(x, y));
}
//----------------------------------------------------------------------------------------------------------


#include <ctype.h>

int main()
{
	int ch = 'A';

	if isupper(ch)
		printf("evet buyuk harf\n");

}

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define   square(x)    ((x) * (x))

int main()
{
	int a = 10;
	//int b = square(a++);
	int b = ((a++) * (a++)); //Ub
}
//----------------------------------------------------------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define   square(x)    ((x) * (x))

int foo(void);

int main()
{
	int a = 10;
	//int b = square(foo());
	//int b = ((foo()) * (foo()));
}
//----------------------------------------------------------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int square(int x)
{
	printf("square islevi cagrildi\n");
	return x * x;
}


#define   square(a)    ((a) * (a))


int main()
{
	int x = 10;

	int y = square(x);

}
/**********************************************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int square(int x)
{
	printf("square islevi cagrildi\n");
	return x * x;
}


#define   square(a)    ((a) * (a))


int main()
{
	int x = 10;

	int y = (square)(x);
	int z = square(x);

}
/**********************************************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define   square(a)    ((a) * (a))

int (square)(int x)
{
	printf("square islevi cagrildi\n");
	return x * x;
}




int main()
{
	int x = 10;

	int y = (square)(x);

}
/**********************************************************************************************************************/


int a = ({ int y = foo (); int z;
   if (y > 0) z = y;
   else z = - y;
   z; })


#define maxint(a,b)   ({int _a = (a), _b = (b); _a > _b ? _a : _b; })


a = func(x, y);
-----------------------------------------------------


early optimization is evil
Donald Knuth
American computer scientist


 (y * z + a * b - ar[5]) * (y * z + a * b - ar[5]);


---------------------
inline function
inline expansion
---------------------

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>
#include "nutility.h"
#include <stdlib.h>
#include <time.h>


int main()
{
	//srand((unsigned)time(0));
	randomize();

}
/**********************************************************************************************************************/


#include <stddef.h>

typedef int DataType;



typedef struct {
	DataType* pArray;
	size_t rowSize;
	size_t colSize;
}*HMATRIX;

#define elemsize(h)    (h->rowSize * h->colSize)

int main()
{
	HMATRIX hmatrix;
	/////
	elemsize(hmatrix)

}

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define   swap(a, b)   {int temp = a; a = b; b = temp;}

int main()
{
	int x, y;

	printf("iki tamsayi giriniz: ");
	scanf("%d%d", &x, &y);

	swap(x, y);

	printf("x = %d\n", x);
	printf("y = %d\n", y);

}
//----------------------------------------------------------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


#define   swap(a, b)   do {int temp = a; a = b; b = temp;}while(0)

int main()
{
	int x, y;

	printf("iki tamsayi giriniz: ");
	scanf("%d%d", &x, &y);

	if (x > y)
		swap(x, y);
	else
		printf("necati\n");


	printf("x = %d\n", x);
	printf("y = %d\n", y);

}
/**********************************************************************************************************************/



#define  PUBLIC

PUBLIC int square(int x)
{
	return x * x;
}


PUBLIC int multiply(int x, int y)
{
	return x * y;
}
/**********************************************************************************************************************/

## Preprocessor Operators (On Islemci Operatörleri)


önişlemci operatörleri
preprocessor operators
-----------------------

#		stringification (stringizing)
##		token-pasting

defined

#nec

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>



#define iprint(x)    printf("%d\n", x)

int main()
{
	int a = 10;
	int b = 20;
	int c = 30;

	iprint(a + b);
	iprint(a + b + c);
	iprint(a * a + b * b + c * c);
	//printf("%d\n", a + b);
}
//----------------------------------------------------------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define iprint(x)    printf(#x " = %d\n", x)

int main()
{
	int a = 10;
	int b = 20;
	int c = 30;

	iprint(a + b);
	iprint(a + b + c);
	iprint(a * a + b * b + c * c);
	iprint(5 * (a + b) - 3 * (b - c));
	//printf("%d\n", a + b);
}
//----------------------------------------------------------------------------------------------------------


op1##op2

op1op2


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define generate_max_function(t)   t maxarray_##t(const t *ptr, int size) \
{  \
	t max = *ptr;  \
	for (int i = 1; i < size; ++i) \
		if (ptr[i] > max) \
			max = ptr[i]; \
	return max; \
}

generate_max_function(int)
generate_max_function(unsigned)
generate_max_function(double)
generate_max_function(float)

//----------------------------------------------------------------------------------------------------------