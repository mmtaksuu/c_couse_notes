<string.h> header file
----------------------

```c
size_t strlen(const char *p);
char * strchr(const char *p, int ch);
char * strrchr(const char *p, int ch);
char * strstr(char *pdest, const char *psource);
strpbrk
strspn
strcspn
char * strcpy(char *pdest, const char *psource);
char * strcat(char *pdest, const char *psource);
strcmp
strcoll
stncpy(char *pdest, const char *psource, size_t n);
strncat(char *pdest, const char *psource, size_t n);
strncmp
strtok
strerror
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define   SIZE      100

int main()
{
    char str[SIZE];
    
    printf("bir isim girin: ");
    scanf("%s", str);
    size_t  len = strlen(str);
    
    printf("uzunluk = %zu\n", len);

}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "nutility.h"


#define   SIZE      100

void rputs2(const char *p)
{
	const char *pe = p + strlen(p);

	while (pe != p)
		putchar(*--pe);

	putchar('\n');
}

void rputs1(const char *p)
{
	for (size_t i = strlen(p); i; )
		putchar(p[--i]);
	putchar('\n');
}

int main()
{
	char str[SIZE];

	printf("bir yazi girin: ");
	sgets(str);
	puts(str);
	rputs1(str);
	rputs2(str);

}
```



```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "nutility.h"

#define   SIZE      100

int main()
{
	char str[SIZE];

	printf("bir yazi girin: ");
	sgets(str);
	size_t len = strlen(str);

	for (size_t i = 0; i < len; ++i)
		puts(str + i);

}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "nutility.h"

#define   SIZE      100

size_t strlen4(const char *p)
{
	const char *pe = p;

	while (*pe)
		++pe;

	return (size_t)(pe - p);
}


size_t strlen3(const char *p)
{
	size_t len = 0;

	while (*p++)
		++len;

	return len;
}

size_t strlen2(const char *p)
{
	size_t len = 0;

	for (; p[len] != '\0'; ++len)
		;

	return len;
}

int main()
{
	char str[SIZE];

	printf("bir yazi girin: ");
	sgets(str);
	size_t len1 = strlen(str);
	size_t len2 = strlen2(str);
	size_t len3 = strlen3(str);
	size_t len4 = strlen4(str);

	printf("%zu %zu %zu %zu\n", len1, len2, len3, len4);

}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "nutility.h"

#define   SIZE      100

char* strchr1(const char *p, int c)
{
	while (*p) {
		if (*p == c)
			return (char *)p;
		++p;
	}

	if (c == '\0')
		return (char *)p;

	return NULL;
}

int main()
{
	char str[SIZE];

	printf("bir yazi girin: ");
	sgets(str);
	printf("aranacak karakteri girin: ");
	int ch = getchar();
	char *p = strchr(str, ch);
	if (p != NULL) {
		printf("bulundu... yazinin %d indisli karakteri (%s)\n", p - str, p);
	}
	else {
		printf("bulunamadi\n");
	}


	p = strchr(str, '\0');
	*p++ = 'X';
	*p = '\0';

	puts(str);

}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "nutility.h"

#define   SIZE      100


char *strrchr1(const char *p, int c)
{
	char *ptr = NULL;
	while (*p) {
		if (*p == c)
			ptr = (char *)p;
		++p;
	}
	if (c == '\0')
		return (char *)p;

	return ptr;
}

char* strchr1(const char *p, int c)
{
	while (*p) {
		if (*p == c)
			return (char *)p;
		++p;
	}

	if (c == '\0')
		return (char *)p;

	return NULL;
}

int main()
{
	char str[SIZE];

	printf("bir yazi girin: ");
	sgets(str);
	printf("aranacak karakteri girin: ");
	int ch = getchar();
	char *p = strchr(str, ch);
	if (p != NULL) {
		printf("strchr bulundu... yazinin %d indisli karakteri (%s)\n", p - str, p);
		*p = '*';
	}
	else {
		printf("bulunamadi\n");
	}

	p = strrchr(str, ch);
	if (p != NULL) {
		printf("strRchr bulundu... yazinin %d indisli karakteri (%s)\n", p - str, p);
		*p = '!';
	}
	else {
		printf("bulunamadi\n");
	}
	puts(str);
}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "nutility.h"

#define   SIZE      100

int main()
{
	double a[10] = { 0 };
	double *p = a;
	char str[] = "dun cicekciler gunuydu";
	char *cp = str;

	printf("%zu\n", sizeof a); //80
	printf("%zu\n", sizeof *a);  //8
	printf("%zu\n", sizeof p); //4
	printf("%zu\n", sizeof *p); //8

	printf("%zu\n", sizeof str);  //23
	printf("%zu\n", sizeof *str); //1
	printf("%zu\n", sizeof cp); //4
	printf("%zu\n", sizeof *cp);  //1

}
```

```text
Bir pointer değişkeni gösterdiği yazının sonuna ötelemek

while (*p)
	++p;

----------------------------------
while (*p++)
	;
--p;
----------------------------------
while (*++p)  //asla
	;
----------------------------------
p += strlen(p);
----------------------------------
p = strchr(p, '\0');
----------------------------------

NULL pointer / NUll character

'\0'


p geçerli bir gösterici

ve şu kontrolü yapmamız gerekiyor

p bir yazıyı gösteriyor ise ve p'nin gösterdiği yazı boş değil ise

if (p != NULL && *p != '\0')

if (p && *p)

p bir yazıyı göstermiyor ise veya p'nin gösterdiği yazı boş ise

if (p == NULL || *p == '\0')

if (!p || !*p)
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "nutility.h"

#define   SIZE      1000

int main()
{
	char s1[SIZE];
	char s2[SIZE];

	printf("bir yazi girin: ");
	sgets(s1);
	strcpy(s2, s1);
	printf("(%s) (%s)\n", s1, s2);
}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "nutility.h"

#define   SIZE      1000

int main()
{
	char s1[SIZE];
	char s2[SIZE];
	char s3[SIZE];

	printf("bir yazi girin: ");
	sgets(s1);
	strcpy(s3, strcpy(s2, s1));
	printf("(%s) (%s) (%s)\n", s1, s2, s3);

}
```



```text
Iki char turden arrayi birbirine null karakter ile birlikte kopyalamak icin kullanilan C 
idiomu :

while (*p1++ = *p2++)
	;
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "nutility.h"

#define   SIZE      1000


char* strcpy1(char *pdest, const char *psource)
{
	char *ptemp = pdest;

	while (*pdest++ = *psource++)
		;

	return ptemp;
}


char* strcpy2(char *pdest, const char *psource)
{
	char *ptemp = pdest;

	while (*psource != '\0') {
		*pdest = *psource;
		++pdest;
		++psource;
	}
  *pdest = '\0';
	return ptemp;
}


int main()
{
	char s1[SIZE];
	char s2[SIZE];

	printf("bir yazi girin: ");
	sgets(s1);
	strcpy(s2, s1);
	printf("(%s) (%s)\n", s1, s2);

}
```


pointer aliasing
----------------

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "nutility.h"

#define   SIZE      1000


int main()
{
	char str[100] = "gulden";
	
	strcpy(str + 3, str); //ub (strcpy işlevini overlapped bloklar üstünde kullanmamlısınız)

	puts(str);

}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "nutility.h"

#define   SIZE      1000

int main()
{
	char s1[SIZE];
	char s2[SIZE];

	printf("iki isim girin: ");
	scanf("%s%s", s1, s2);

	printf("(%s) (%s)\n", s1, s2);
	strcat(s1, s2);

	printf("(%s) (%s)\n", s1, s2);

}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "nutility.h"

#define   SIZE      1000


char* strcat1(char *pdest, const char *psource)
{
	char *ptemp = pdest;

	while (*pdest)
		++pdest;

	while (*pdest++ = *psource++)
		;

	return ptemp;
}

char* strcat2(char *pdest, const char *psource)
{
	strcpy(pdest + strlen(pdest), psource);

	return pdest;
}

char* strcat3(char *pdest, const char *psource)
{
	strcpy(strchr(pdest, '\0'), psource);

	return pdest;
}


int main()
{
	char s1[SIZE];
	char s2[SIZE];
	char s3[SIZE];

	printf("iki isim girin: ");
	scanf("%s%s", s1, s2); //hilal altuntas

	strcpy(s3, s1);
	strcat(s3, s2);

	printf("(%s) + (%s) = (%s)\n", s1, s2, s3); //(hilal) + (altuntas) = (hilalaltuntas)

}
```



```c
#include <string.h>
#include "nutility.h"

#define   SIZE      100

int main()
{
	char s1[SIZE];
	char s2[SIZE];

	printf("icinde arama yapilacak yaziyi girin: ");
	sgets(s1);
	printf("aranacak yaziyi girin: ");
	sgets(s2);

	char *p = strstr(s1, s2);
	if (!p) {
		printf("bulunamadi\n");
	}
	else {
		printf("bulundu... indis = %d  (%s)\n", p - s1, p);
	}

}
```


Yazıların Karşılaştırılması
--------------------------

```text
Container - collection

lexicographical compare

1 3 5 7 12
1 3 5 7 12

1 2 5
1 2 5 7

masa
MASA

KUCUK MASA
BUYUK MASA
```