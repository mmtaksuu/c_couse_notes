Lesson 30
---------

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "nutility.h"


int main()
{
	char str[100];

	printf("bir yazi girin: ");
	sgets(str);
	printf("(%s)\n", str);
	int ival = atoi(str);

	printf("ival = %d\n", ival);
}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "nutility.h"


int main()
{
	char str[100];
	int day, mon, year;

	printf("bir tarih girin gg-aa-yyyy: "); //05-02-1987
	scanf("%s", str); 
	printf("(%s)\n", str);

	day = atoi(str);
	mon = atoi(str + 3);
	year = atoi(str + 6);

	printf("%d yilinin %d. ayinin %d.gunu\n", year, mon, day);

}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "nutility.h"


int main()
{
	char str[100];
	int day, mon, year;

	printf("bir tarih girin gg-aa-yyyy: "); //05-02-1987
	scanf("%s", str); 
	printf("(%s)\n", str);

	day = atoi(str);
	mon = atoi(str + 3);
	year = atoi(str + 6);

	printf("%d yilinin %d. ayinin %d.gunu\n", year, mon, day);

}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "nutility.h"


int main()
{
	char str[100];
	
	printf("bir yazi girin: ");
	scanf("%s", str);

	int ival = atoi(str);
	double dval = atof(str);

	printf("ival = %d\n", ival);
	printf("dval = %f\n", dval);

}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "nutility.h"


int main()
{
	char str[100];
	
	printf("bir yazi girin: ");
	scanf("%s", str);

	int ival = atoi(str);

	printf("ival = %d\n", ival);

}
```



```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "nutility.h"

#define   SIZE      100

int main()
{
	int x;

	printf("bir tamsayi giriniz: ");
	scanf("%d", &x);

	char str[SIZE];
	int idx = 0;

	int temp = x;
	while (temp) {
		str[idx++] = temp % 10 + '0';
		temp /= 10;
	}

	str[idx] = '\0';
	_strrev(str);
	printf("(%s)\n", str);

}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "nutility.h"

#define   SIZE      100

void print(int ival)
{
	if (ival < 0) {
		ival = -ival;
		putchar('-');
	}

	if (ival)
		print(ival / 10);
	else
		return;


	putchar(ival % 10 + '0');
}

int main()
{
	int x;

	printf("bir tamsayi giriniz: ");
	scanf("%d", &x);

	print(x);

}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "nutility.h"

#define   SIZE      100

int main()
{
	int x;
	char str[SIZE];

	printf("bir tamsayi giriniz: ");
	scanf("%d", &x);
	printf("ONLUK sayi sisteminde\n");
	_itoa(x, str, 10);
	printf("[%s]\n", str);

	printf("ONALTILIK sayi sisteminde\n");
	_itoa(x, str, 16);
	printf("[%s]\n", str);

	printf("SEKIZLIK sayi sisteminde\n");
	_itoa(x, str, 8);
	printf("[%s]\n", str);

	printf("ikilik sayi sisteminde\n");
	_itoa(x, str, 2);
	printf("[%s]\n", str);

}
```



Pointer to Pointer 
------------------

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "nutility.h"

#define   SIZE      100

int main()
{
	int x = 10;
	int *ptr = &x;
	int **p = &ptr;

	printf("x    = %d\n", x);
	printf("&x   = %p\n", &x);
	printf("ptr  = %p\n", ptr);
	printf("&ptr = %p\n", &ptr);
	printf("p    = %p\n", p);


}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "nutility.h"

#define   SIZE      100

int main()
{
	int x = 10;
	int y = 20;
	int *ptr = &x;
	int **p = &ptr;

	printf("*ptr = %d\n", *ptr);
	*p = &y; //ptr = &y;
	printf("*ptr = %d\n", *ptr);


}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "nutility.h"

#define   SIZE      100

int main()
{
	int a[] = { 1, 3, 7, 9, 4 };
	int *ptr = a;
	int **p = &ptr;

	++*p;
	++**p;

	display_array(a, asize(a));

}
```



```text

int main()
{
	int x = 10;
	int *ptr = &x;
	int **p = &ptr;


expression        data type      value category
-----------       ---------      ---------------
    x             int            L val
    &x            int *          R val
    ptr           int *	         L val
    *ptr          int	         L val
    &ptr          int **         R val
    p             int **         L val
    *p            int *	         L val
    **p           int            L val
    &p	          int ***        R val
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "nutility.h"

int main()
{

	int x = 10;
	int *p1 = &x;
	int **p2 = &p1;
	int ***p3 = &p2;
	int ****p4 = &p3;
	int *****p5 = &p4;
	int ******p6 = &p5;
	int *******p7 = &p6;
	int ********p8 = &p7;
	int *********p9 = &p8;
	int **********p10 = &p9;
	int ***********p11 = &p10;
	int ************p12 = &p11;
	int *************p13 = &p12;
	int **************p14 = &p13;
	int ***************p15 = &p14;
	int ****************p16 = &p15;
	int *****************p17 = &p16;
	int ******************p18 = &p17;
	int *******************p19 = &p18;
	int ********************p20 = &p19;
	int *********************p21 = &p20;
	int **********************p22 = &p21;
	int ***********************p23 = &p22;
	int ************************p24 = &p23;
	int *************************p25 = &p24;
	int **************************p26 = &p25;
	int ***************************p27 = &p26;
	int ****************************p28 = &p27;
	int *****************************p29 = &p28;
	++*****************************p29;

	printf("x = %d\n", x);
}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "nutility.h"

int main()
{
	int x = 10;
	int y = 97;
	int *p1 = &x;
	int *p2 = &y;

	printf("%d   %d\n", *p1, *p2);
	
	int *ptemp = p1;
	p1 = p2;
	p2 = ptemp;
	
	printf("%d   %d\n", *p1, *p2);

}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "nutility.h"


void pswap(int **ptr1, int **ptr2)
{
	int *ptemp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = ptemp;
}


int main()
{
	int x = 10;
	int y = 97;
	int *p1 = &x;
	int *p2 = &y;

	printf("%d   %d\n", *p1, *p2);
	
	/*int *ptemp = p1;
	p1 = p2;
	p2 = ptemp;*/

	pswap(&p1, &p2);
	swap(p1, p2);
	
	printf("%d   %d\n", *p1, *p2);

}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "nutility.h"

#define   SIZE      100

int main()
{
	char str[SIZE];

	printf("bir yazi girin: ");
	scanf("%s", str);
	printf("[%s]\n", str);
	char *p;

	double dval = strtod(str, &p);

	printf("dval = %f\n", dval);
	printf("indeks = %d\n", p - str);
	printf("(%c)\n", *p);

}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include "nutility.h"
#include <stdio.h>
#include <string.h>

void cpswap(char **p1, char **p2)
{
	char *ptemp = *p1;
	*p1 = *p2;
	*p2 = ptemp;
}

void sort_names(char **ptr, size_t size)
{
	for (size_t i = 0; i < size - 1; ++i) {
		for (size_t k = 0; k < size - 1 - i; ++k) {
			if (strcmp(ptr[k], ptr[k + 1]) > 0)
				cpswap(ptr + k, ptr + k + 1);
		}
	}
}


void display_names(char *const *ptr, size_t size)
{
	for (size_t i = 0; i < size; ++i) {
		printf("%s ", ptr[i]);
	}
	printf("\n\n");
}


void display_names2(char **ptr, size_t size)
{
	while (size--) {
		printf("%s ", *ptr++);
		
	}
	printf("\n\n");

}

int main()
{
	char *p[] = {
		"kamil", "korhan", "beril", "turhan", "ufuk", "murathan", "figen", "malik", "bulent", "cengiz",
	"baran", "nurullah", "dilber", "tuncer", "recep", "pelinsu", "cihan", "yesim", "aziz", "kazim",
	"afacan", "tevfik", "sumeyye", "hande", "aslihan", "emine", "temel", "gulsah", "hasan", "gul",
	"soner", "ayla", "cuneyt", "tekin", "binnaz", "emrecan", "yasar", "yilmaz", "feraye", "tugra",
	"melek", "garo", "yurdagul", "tarik", "derin", "handan", "aytac", "petek", "cem", "aylin",
	"gursel", "haldun", "nazife", "hulusi", "sevilay", "sabriye", "gulden", "tansel", "ege", "turgut",
	"cahit", "berk", "nazli", "aykut", "kayhan", "cemre", "murat", "kunter", "gunay", "cahite",
	"nedim", "metin", "kerim", "utku", "cumhur", "kurthan", "poyraz", "can", "candan", "hikmet",
	"izzet", "perihan", "tufan", "zahide", "samet", "melih", "hakan", "ayse", "refik", "efe",
	"belgin", "bilal", "niyazi", "fugen", "melike", "saadet", "cemile", "nahit", "arda", "ugur" };

	display_names(p, asize(p));
	sort_names(p, asize(p));
	display_names2(p, asize(p));

}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int x = 10;
	int y = 20;
	int *p1 = &x;
	int *p2 = &y;

	int ** const ptr = &p1;

	//ptr = &p2; //gecersiz
	*ptr = &y;
	**ptr = 876;

}
```


Pointer to Pointer & const Correctness
--------------------------------------

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int x = 10;
	int y = 20;
	int *p1 = &x;
	int *p2 = &y;

	int *const*  ptr = &p1;

	ptr = &p2; 
	*ptr = &y; //gecersiz
	**ptr = 876;

}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int x = 10;
	int y = 20;
	int *p1 = &x;
	int *p2 = &y;

	const int *const*  const ptr = &p1;

	ptr = &p2; 
	*ptr = &y; //gecersiz
	**ptr = 876;

}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main()

{
	char s1[] = "ali";
	char s2[] = "mehmet";
	char s3[] = "kayhan";
	char s4[] = "cetin";
	char s5[] = "semih";

	char *p[] = { s1, s2, s3, s4, s5 };

	puts(s4);

	p[3][0] = 's';
	p[3][2] = 'l';

	puts(s4);

}
```



```c
// char *p = ?;

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

char *f1(void);
char *f2(void);
char *f3(void);
char *f4(void);
char *f5(void);

int main()

{
	char s1[] = "ali";
	char s2[] = "mehmet";
	char s3[] = "kayhan";
	char s4[] = "cetin";
	char s5[] = "semih";

	//char *p[] = { s1, s2, s3, s4, s5 };
	char *p[] = { f1(), f2(), f3(), f4(), f5() };

	puts(s4);

	p[3][0] = 's';
	p[3][2] = 'l';

	puts(s4);

}
```

void Pointers
-------------

```text
void is a "type";

Bir değişkenin türü void olamaz.
Ancak, bir ifadenin (expression) türü void olabilir
```

```c
int main()
{
	void x; //Gecersiz
	//bir  nesnenin türü void olamaz
}
```

```c
void foo(int);
int func(void);

int main()
{
	//func() //ifadesinin türü int
	foo(12) // ifadesinin türü void
}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	void *vptr;
	int *ptr;
	
	printf("sizeof(int *) = %zu\n", sizeof(int *));
	printf("sizeof(void *) = %zu\n", sizeof(void *));
}
```


```text
void * türünden bir nesneye herhangi türden bir nesnenin adresi atanabilir.
Bu durum geçerli ve doğrudur.
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	void *vptr;
	int ival = 10;
	double dval = 3.4;
	char str[100] = "ali";

	vptr = &ival;
	///code
	vptr = &dval;
	///code
	vptr = str;
	///code
	vptr = &vptr;
}
```


```text
T void olmayan herhangi bir tür olsun
Hem C'de hem C++'da :


T * türünden void * türüne otomatik tür dönüşümü var
void * türünden T * türüne C' otomatik tör dönüşümü var C++ da sentaks hatası
void pointer'lar  tür bilgisi gereken hiçbir yerde kullanilamazlar


void *vp1 = &x;
void *vp2 = NULL;
void *vp3 = 0;
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int x = 10;
	void *vp = &x;
	//int *iptr = vp;  //C'de gecerli ve dogru
	//C++'da gecersiz

	int *iptr = (int*) vp;

}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int x = 10;
	void *vp = &x;
	int *iptr = vp;  //C'de gecerli ve dogru
	                //C++'da gecersiz

	int *iptr = (int*) vp;

}
```


