# DİNAMİK BELLEK YÖNETİMİ
### Dynamic Memory Management



```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "nutility.h"

int main()
{
	size_t n;
	printf("kac tamsayi:  ");
	scanf("%zu", &n);
	int *pd = (int *)malloc(n * sizeof(int));
	if (!pd) {
		printf("bellek yetersiz\n");
		exit(EXIT_FAILURE);
	}
	
	set_random_array(pd, n);
	bsort(pd, n);
	display_array(pd, n);
	///
	free(pd);
}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nutility.h"

int main()
{
	size_t n;
	printf("kac tamsayi:  ");
	scanf("%zu", &n);
	int *pd = (int *)malloc(n * sizeof(int));
	if (!pd) {
		printf("bellek yetersiz\n");
		exit(EXIT_FAILURE);
	}
	memset(pd, 0, n * sizeof(int));
	
	display_array(pd, n);
	///
	free(pd);

}
```

# function wrapper (sarmalayıcı)

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nutility.h"



int main()
{
	size_t n;
	printf("kac tamsayi:  ");
	scanf("%zu", &n);
	int *pd = (int *)checked_malloc(n * sizeof(int));
	memset(pd, 0, n * sizeof(int));
	
	display_array(pd, n);
	///
	free(pd);
}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nutility.h"

typedef unsigned long long ullong;

#define   BLOCK_SIZE     (1024 * 1024)

void *vpa[100000];

int main()
{
	size_t n = 0;

	for (;;) {
		void *vp = malloc(BLOCK_SIZE);
		if (!vp)
			break;
		vpa[n++] = vp;
	}

	printf("malloc basarisiz oldu... n = %zu\n", n);

}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#include "nutility.h"


int main()
{
	size_t n;

	printf("kac tamsayi: ");;
	scanf("%zu", &n);
	int *pd = malloc(n * sizeof(int));
	if (pd == NULL) {
		printf("bellek yetersiz\n");
		return 1;
	}
	int *ptr = pd;
	set_random_array(pd, n);
	display_array(pd, n);

	free(pd);
	///
	free(ptr); //ub
	
}
```


```text
1. Asla dinamik bir bellek bloğu adresi olmayan bir adresi free işlevine gönderme. (ub)
2. dangling pointer kullanma!!!!!!!!!
3. free edilen bir bellek bloğunu tekrar free etme!  (double free)
4. free ile bier bellek bloğunu küçültme girişiminde bulunma
5. free etmeyi unutma (memory leak)

free işlevine null pointer gönderilmesi "tanımlı" dvaranıştır. etkisiz koddur.

free(ptr);

void free(void * vptr)
{
	if (!vptr)
		return;

}

malloc işlevine 0 değerinin gönderilmesi tanımsız davranış değildir. Derleyiciye bağlı durumdur
a) malloc bu durumda NULL  pointer döndürebilir.
b) malloc bu durumda NULL  pointer olmayan bir adres döndürebilir.

malloc'un bu durumda döndürdüğü adresi dereference etmek tanımsız davranıştır.
malloc'un bu durumda döndürdüğü adresi free etmek tanımsız davranış değildir.

----------------------------------------------------------------------------------------
int *p1 = str;  // str bir fixed array
int *p2 = malloc();
free(p1); //undefined behavior

----------------------------------------------------------------------------------------
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#include "nutility.h"


int main()
{
	size_t n;

	printf("kac tamsayi: ");;
	scanf("%zu", &n);
	int *pd = malloc(n * sizeof(int));

	if (pd == NULL) {
		printf("malloc NULL pointer döndürdü\n");
	}

	else {
		printf("adres = %p\n", pd);
	}

	free(pd); //tanımlı
	
}
```


```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "nutility.h"

#define			SIZE		100


int main()
{
	char str[SIZE];

	printf("bir yazi girin: ");
	sgets(str);
	char *pd = _strdup(str);

	printf("(%s) (%s)\n", str, pd);
	_strrev(pd);
	printf("(%s) (%s)\n", str, pd);
	free(pd);

}
```


```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "nutility.h"

#define			SIZE		100

char* strdup2(const char *p)
{
	char *pd = (char *)malloc(strlen(p) + 1);
	if (!pd) {
		printf("bellek yetersiz\n");
		exit(EXIT_FAILURE);
	}
	return strcpy(pd, p);	
}

int main()
{
	char str[SIZE];

	printf("bir yazi girin: ");
	sgets(str);
	char *pd = _strdup(str);

	printf("(%s) (%s)\n", str, pd);
	_strrev(pd);
	printf("(%s) (%s)\n", str, pd);
	free(pd);

}
```

```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "nutility.h"
#include <conio.h>


#define			SIZE		100

void sort2(char *p)
{
	size_t len = strlen(p);
	for (size_t i = 0; i < len - 1; ++i) {
		for (size_t k = 0; k < len - 1 - i; ++k) {
			if (p[k] < p[k + 1]) {
				char c = p[k];
				p[k] = p[k + 1];
				p[k + 1] = c;
			}
		}
	}
}

void sort1(char *p)
{
	size_t len = strlen(p);
	for (size_t i = 0; i < len - 1; ++i) {
		for (size_t k = 0; k < len - 1 - i; ++k) {
			if (p[k] > p[k + 1]) {
				char c = p[k];
				p[k] = p[k + 1];
				p[k + 1] = c;
			}
		}
	}
}
		
int main()
{
	char str[SIZE];

	for (;;) {
		printf("bir yazi girin ");
		sgets(str);
		char *p1 = _strdup(str);
		char *p2 = _strdup(str);
		char *p3 = _strdup(str);
		_strrev(p1);
		sort1(p2);
		sort2(p3);
		system("cls");
		puts(str);
		puts(p1);
		puts(p2);
		puts(p3);
		_getch();
		free(p1);
		free(p2);
		free(p3);
	}

}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "nutility.h"
#include <conio.h>


#define			SIZE		100

char *strcon(const char *p1, const char *p2)
{
	char *pd = (char *)malloc(strlen(p1) + strlen(p2) + 1);
	if (!pd) {
		printf("bellek yetersiz\n");
		exit(EXIT_FAILURE);
	}
	return strcat(strcpy(pd, p1), p2);
}


int main()
{

	char s1[SIZE];
	char s2[SIZE];

	printf("bir yazi girin: ");
	sgets(s1);
	printf("bir yazi daha girin: ");
	sgets(s2);

	char *pd = strcon(s1, s2);
	printf("(%s) + (%s) = (%s)\n", s1, s2, pd);
	_strrev(pd);
	printf("(%s) + (%s) = (%s)\n", s1, s2, pd);

	free(pd);
	
}
```

```c
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#include "nutility.h"


int get_random_char()
{
	int ch;

	while (!isalnum(ch = rand() % 128))
		;

	return ch;
}

char *create_random_psw1(char *p)
{
	char *ptemp = p;
	size_t len = rand() % 10 + 5;

	while (len--) {
		*p++ = get_random_char();
	}

	*p = '\0';
	return ptemp;
}

char *create_random_psw2(void)
{
	static char str[100];
	size_t idx = 0;

	size_t len = rand() % 10 + 5;

	while (len--) {
		str[idx++] = get_random_char();
	}

	str[idx] = '\0';
	return str;
}

#define			SIZE	5

int main()
{
	char *p[SIZE];

	randomize();
	for (int i = 0; i < SIZE; ++i) {
		p[i] = create_random_psw2();

	}
	printf("\n");

	for (int i = 0; i < SIZE; ++i) {
		printf("%s\n", p[i]);
	}

}
```

```c
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#include "nutility.h"


int get_random_char()
{
	int ch;

	while (!isalnum(ch = rand() % 128))
		;

	return ch;
}

char *create_random_psw1(char *p)
{
	char *ptemp = p;
	size_t len = rand() % 10 + 5;

	while (len--) {
		*p++ = get_random_char();
	}

	*p = '\0';
	return ptemp;
}

char *create_random_psw2(void)
{
	static char str[100];
	size_t idx = 0;

	size_t len = rand() % 10 + 5;

	while (len--) {
		str[idx++] = get_random_char();
	}

	str[idx] = '\0';
	return str;
}

char *create_random_psw3(void)
{
	char str[100];
	size_t idx = 0;

	size_t len = rand() % 10 + 5;

	while (len--) {
		str[idx++] = get_random_char();
	}

	str[idx] = '\0';
	
	return _strdup(str);
}


#define			SIZE	5

int main()
{
	char *p[SIZE];

	randomize();
	for (int i = 0; i < SIZE; ++i) {
		p[i] = create_random_psw3();

	}
	printf("\n");

	for (int i = 0; i < SIZE; ++i) {
		printf("%s\n", p[i]);
	}

	////////////////////////
	for (int i = 0; i < SIZE; ++i) {
		free(p[i]);
	} 

}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>

int main()
{
	size_t n;

	printf("kac pointer:  ");
	scanf("%zu", &n);
	
	int **p = (int **)malloc(n * sizeof(*p));

}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

#include "nutility.h"


int main()
{
	size_t row, col;

	printf("matristeki satir ve sutun sayisi: ");
	scanf("%zu%zu", &row, &col);

	int **pd = (int **)malloc(row * sizeof(int *));
	if (!pd) {
		printf("bellek yetersiz\n");
		return 1;
	}

	for (size_t i = 0; i < row; ++i) {
		pd[i] = (int*)malloc(col * sizeof(int));
		if (!pd[i]) {
			printf("bellek yetersiz\n");
			return 1;
		}
	}

	//////
	randomize();
	for (size_t i = 0; i < row; ++i) {
		for (size_t k = 0; k < col; ++k) {
			pd[i][k] = rand() % 10;
		}
	}

	////////
	for (size_t i = 0; i < row; ++i) {
		for (size_t k = 0; k < col; ++k) {
			printf("%d", pd[i][k]);
		}
		printf("\n");
	}

	printf("\n\n");

	/*int *ptr = &pd[0][0];
	size_t n = row * col;
	while (n--) {
		printf("%d", *ptr++);
		_getch();
	}*/


	for (size_t i = 0; i < row; ++i) {
		free(pd[i]);
	}

	free(pd);
}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

#include "nutility.h"


int main()
{
	size_t row, col;

	printf("matristeki satir ve sutun sayisi: ");
	scanf("%zu%zu", &row, &col);

	int *pd = malloc(row * col * sizeof(int));
	if (!pd) {
		printf("bellek yetersiz\n");
		return 1;
	}

	for (size_t i = 0; i < row; ++i) {
		for (size_t k = 0; k < col; ++k) {
			pd[i * col + k] = rand() % 10;
		}
	}

	/////
	for (size_t i = 0; i < row; ++i) {
		for (size_t k = 0; k < col; ++k) {
			printf("%d", pd[i * col + k]);
		}
		printf("\n");
	}

	int *ptr = pd;
	int n = row * col;
	printf("\n\n");

	/*while(n--) {
		printf("%d ", *ptr++);
		_getch();
	}*/

	free(pd);
}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

#include "nutility.h"


int main()
{
	size_t row, col;

	printf("matristeki satir ve sutun sayisi: ");
	scanf("%zu%zu", &row, &col);

	int *pd = malloc(row * col * sizeof(int));
	if (!pd) {
		printf("bellek yetersiz\n");
		return 1;
	}

	for (size_t i = 0; i < row; ++i) {
		for (size_t k = 0; k < col; ++k) {
			pd[i * col + k] = rand() % 10;
		}
	}

	int **ptr = (int **)malloc(row * sizeof(int *));
	///check
	for (size_t i = 0; i < row; ++i) {
		ptr[i] = pd + i * col;
	}

	for (size_t i = 0; i < row; ++i) {
		for (size_t k = 0; k < col; ++k) {
			printf("%d", ptr[i][k]);
		}
		printf("\n");

	}
	
	free(ptr);
	free(pd);
}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

#include "nutility.h"


int main()
{
	size_t n;

	randomize();

	printf("kac tamsayi: ");
	scanf("%zu", &n);
	//int *pd = (int *)malloc(n * sizeof(int));
	int *pd = (int *)calloc(n, sizeof(int));
	///check
	display_array(pd, n);

	free(pd);
}
```



# realloc fonksiyonu

```text
reallocation takes time!
reallocation invalidates pointers

```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "nutility.h"


int main()
{
	size_t n;  //bu dizinin ilk boyutu olacak;
	size_t n_plus;  //dizinin bu kadar artacak

	printf("kac elemanli bir dizi :  ");
	scanf("%zu", &n);
	int *pd = (int *)malloc(n * sizeof(int));
	if (!pd) {
		printf("bellek yetersiz\n");
		return 1;
	}

	randomize();
	set_random_array(pd, n);
	display_array(pd, n);
	printf("kac eleman daha ekleyelim abime: ");
	scanf("%zu", &n_plus);

	pd = (int *)realloc(pd, (n + n_plus) * sizeof(int));
	if (!pd) {
		printf("bellek yetersiz\n ");
		return 1;
	}
	set_random_array(pd + n, n_plus);
	display_array(pd, n + n_plus);

	free(pd);

}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "nutility.h"


int main()
{
	size_t n;  //bu dizinin ilk boyutu olacak;
	size_t n_plus;  //dizinin bu kadar artacak

	printf("kac elemanli bir dizi :  ");
	scanf("%zu", &n);
	int *pd = (int *)malloc(n * sizeof(int));
	if (!pd) {
		printf("bellek yetersiz\n");
		return 1;
	}

	printf("malloc tarafindan verilen adres: (%p)\n", pd);

	randomize();
	set_random_array(pd, n);
	//display_array(pd, n);
	printf("kac eleman daha ekleyelim abime: ");
	scanf("%zu", &n_plus);

	pd = (int *)realloc(pd, (n + n_plus) * sizeof(int));
	if (!pd) {
		printf("bellek yetersiz\n ");
		return 1;
	}
	printf("realloc tarafindan verilen adres: (%p)\n", pd);

	set_random_array(pd + n, n_plus);
	//display_array(pd, n + n_plus);

	free(pd);
}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "nutility.h"


int main()
{
	size_t n;  //bu dizinin ilk boyutu olacak;
	size_t n_plus;  //dizinin bu kadar artacak

	printf("kac elemanli bir dizi :  ");
	scanf("%zu", &n);
	int *pd = (int *)malloc(n * sizeof(int));
	if (!pd) {
		printf("bellek yetersiz\n");
		return 1;
	}

	randomize();
	set_random_array(pd, n);
	//display_array(pd, n);
	printf("kac eleman daha ekleyelim abime: ");
	scanf("%zu", &n_plus);

	pd = (int *)realloc(pd, (n + n_plus) * sizeof(int));
	if (!pd) {
		printf("bellek yetersiz\n ");
		return 1;
	}

	//set_random_array(pd + n, n_plus);
	display_array(pd, n + n_plus);

	free(pd);
}
```

```text
realloc fonksiyonunun birinci parametresine NULL pointer geçilirse realloc, malloc gibi davranır.

realloc(ptr, n)
eğer burada ptr nin değeri NULL ptr ise
malloc(n)
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "nutility.h"


int main()
{
	size_t n;  //bu dizinin ilk boyutu olacak;
	size_t n_plus;  //dizinin bu kadar artacak

	printf("kac elemanli bir dizi :  ");
	scanf("%zu", &n);
	int *pd = (int *)malloc(n * sizeof(int));
	if (!pd) {
		printf("bellek yetersiz\n");
		return 1;
	}

	randomize();
	set_random_array(pd, n);
	//display_array(pd, n);
	printf("kac eleman daha ekleyelim abime: ");
	scanf("%zu", &n_plus);

	pd = (int *)realloc(pd, (n + n_plus) * sizeof(int));
	if (!pd) {
		printf("bellek yetersiz\n ");
		return 1;
	}

	//set_random_array(pd + n, n_plus);
	display_array(pd, n + n_plus);

	free(pd);
}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "nutility.h"

#define		SIZE	20

int main()
{
	int c;

	randomize();

	int *pd = NULL;
	int cnt = 0;

	while (1) {
		printf("evet mi (e)  hayir mi (h) "); 
		while ((c = _getch()) != 'e' && c != 'h')
			;
		printf("\n%c\n", c);

		if (c == 'h')
			break;

		pd = (int *)realloc(pd, (cnt + SIZE) * sizeof(int));
		if (!pd) {
			printf(" bellek yetersiz\n");
			return 1;
		}

		set_random_array(pd + cnt, SIZE);
		display_array(pd, cnt + SIZE);
		cnt += SIZE;
		
		
	}

	printf("su anda dizinin boyutu: %d\n", cnt);
	bsort(pd, cnt);
	display_array(pd, cnt);
	free(pd);
}
```
