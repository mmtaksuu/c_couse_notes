# LESSON 33

```c
#include <stdio.h>
#include "nutility.h"

int main()
{
	int a[10][64];
	int(*ptr)[64] = a;

	for (int i = 0; i < 10; ++i) {
		printf("%p %p %p\n", a + i, &a[i], ptr++);
	}
}
```


# initialization of multidimensional arrays

```c
#include <stdio.h>
#include "nutility.h"

// trailing comma

int main()
{
	int a[4][6] = {
		{1, 2, 3, 6, 8, 12},
		{1, 4, 6, 2, 6},
		{12, 41, 67, 26, 68},
		{2, 2, 2, 2, 2, 2},
	};

	for (int i = 0; i < 4; ++i) {
		for (int k = 0; k < 6; ++k) {
			printf("%4d ", a[i][k]);
		}
		printf("\n");
	}
}
```

```c
#include <stdio.h>
#include "nutility.h"


int main()
{
	int a[4][6] = {
		{1, 2, 3, 6, 8, 12},
		{1, 4, 6, 2, 6},
		{12, 41, 67, 26, 68},
		
	};

	for (int i = 0; i < 4; ++i) {
		for (int k = 0; k < 6; ++k) {
			printf("%4d ", a[i][k]);
		}
		printf("\n");
	}
}
```

```c
#include <stdio.h>
#include "nutility.h"


int main()
{
	int a[4][6] = {
		{1, 2, 3,},
		{1, 4,},
		{12, 41, 67, 26, 68},
		{2, 2, 2, 2, },
	};

	for (int i = 0; i < 4; ++i) {
		for (int k = 0; k < 6; ++k) {
			printf("%4d ", a[i][k]);
		}
		printf("\n");
	}

}
```

```c
#include <stdio.h>
#include "nutility.h"

int main()
{
	int a[4][6] = {
		[1] = {1, 56, 89},
		[3] = {2, 3, 4, 5, 6, 7},
	};

	for (int i = 0; i < 4; ++i) {
		for (int k = 0; k < 6; ++k) {
			printf("%4d ", a[i][k]);
		}
		printf("\n");
	}

}
```

```c
#include <stdio.h>
#include "nutility.h"


int main()
{
	int a[4][6] = {1, 2, 3, 4, 5, 6, 7, 12, 345, 52, 12, 9, 77	};

	for (int i = 0; i < 4; ++i) {
		for (int k = 0; k < 6; ++k) {
			printf("%4d ", a[i][k]);
		}
		printf("\n");
	}

}
```



```c
int main()
{
	int a[][] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
	int b[][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Dogru, turu int [3]
	int c[3][] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "nutility.h"

int main()
{
	int a[][] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };  // yanlis, tur belirsiz
	int b[][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9};        // Dogru, turu int [3]
	int c[3][] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };  // yanlis, tur belirsiz

	printf("size b = %zu\n", asize(b));
}
```


```c
#include <stdio.h>
#include "nutility.h"
#include <conio.h>


int main()
{
	int a[5][6] = {
		{1, 2, 3, 6, 8, 12},
		{-1, -4, -6, -2, -6},
		{12, 41, 67, 26, 68},
		{2, 2, 2, 2, 1, 6},
		{8, 10, 12, 14, 17, 236},
	};

	for (int i = 0; i < 5; ++i) {
		for (int k = 0; k < 6; ++k) {
			printf("%4d ", a[i][k]);
		}
		printf("\n");
	}
	printf("\n\n\n");
	int n = 5 * 6;
	int *p = &a[0][0];

	while (n--) {
		printf("%d ", *p++);
		_getch();
	}
}
```

```c
#include <stdio.h>
#include "nutility.h"
#include <conio.h>


int main()
{
	int a[5][6] = {
		{1, 2, 3, 6, 8, 12},
		{-1, -4, -6, -2, -6},
		{12, 41, 67, 26, 68},
		{2, 2, 2, 2, 1, 6},
		{8, 10, 12, 14, 17, 236},
	};

	int(*p)[6] = a;
	//int(*p)[6] = &a[0]
	int n = 5;

	while (n--) {
		display_array(*p++, 6);
	}
}
```

```c
#include <stdio.h>
#include "nutility.h"
#include <conio.h>


int main()
{
	int a[5][6] = {
		{1, 2, 3, 6, 8, 12},
		{-1, -4, -6, -2, -6},
		{12, 41, 67, 26, 68},
		{2, 2, 2, 2, 1, 6},
		{8, 10, 12, 14, 17, 236},
	};
	int *p = &a[0][0];

	for (int i = 0; i < 30; ++i) {
		if (i && i % 6 == 0)
			printf("\n");

		printf("%d ", p[i]);
	}
}
```

```c
#include <stdio.h>
#include "nutility.h"
#include <conio.h>

int main()
{
	int a[5][6] = {
		{1, 2, 3, 6, 8, 12},
		{-1, -4, -6, -2, -6},
		{12, 41, 67, 26, 68},
		{2, 2, 2, 2, 1, 6},
		{8, 10, 12, 14, 17, 236},
	};
	int *p = &a[0][0];

	for (int i = 0; i < 30; ++i) {
		printf("%3d%c", p[i], i % 6 == 5 ? '\n' : ' ');
	}
}
```


# iki boyutlu dizilerin fonksiyonlara gönderilmesi

```c
#include <stdio.h>
#include "nutility.h"
#include <conio.h>
#include <stdlib.h>

void set_matrix_12(int(*p)[12], size_t size)
{
	for (size_t i = 0; i < size; ++i) {
		for (int k = 0; k < 12; ++k) {
			p[i][k] = rand() % 10;
		}
	}
}


void set_matrix_8(int(*p)[8], size_t size)
{
	for (size_t i = 0; i < size; ++i) {
		for (int k = 0; k < 8; ++k) {
			p[i][k] = rand() % 10;
		}
	}
}
void set_matrix_20(int(*p)[20], size_t size)
{
	for (size_t i = 0; i < size; ++i) {
		for (int k = 0; k < 20; ++k) {
			p[i][k] = rand() % 10;
		}
	}
}


void display_matrix_12(const int(*p)[12], size_t size)
{for (size_t i = 0; i < size; ++i) {
		for (int k = 0; k < 12; ++k) {
			printf("%3d ", p[i][k]);
		}
		printf("\n");

	}
	sl();	
}

void display_matrix_8(const int(*p)[8], size_t size)
{
	for (size_t i = 0; i < size; ++i) {
		for (int k = 0; k < 8; ++k) {
			printf("%3d ", p[i][k]);
		}
		printf("\n");

	}
	sl();
}


void display_matrix_20(const int(*p)[20], size_t size)
{
	for (size_t i = 0; i < size; ++i) {
		for (int k = 0; k < 20; ++k) {
			printf("%3d ", p[i][k]);
		}
		printf("\n");

	}
	sl();
}

int main()
{
	int a[5][12];
	int b[4][8];
	int c[10][20];
	int d[7][12];

	randomize();

	set_matrix_12(a, 5);
	set_matrix_8(b, 4);
	set_matrix_20(c, 10);
	set_matrix_12(d, 7);

	display_matrix_12(a, 5);
	display_matrix_8(b, 4);
	display_matrix_20(c, 10);
	display_matrix_12(d, 7);

}
```

```c
#include <stdio.h>
#include "nutility.h"
#include <conio.h>
#include <stdlib.h>

#define gsmf(s)    void set_matrix_##s(int(*p)[s], size_t size) \
{ \
	for (size_t i = 0; i < size; ++i) { \
		for (int k = 0; k < s; ++k) { \
			p[i][k] = rand() % 10; \
		} \
	} \
}

#define  gdmf(s)    void display_matrix_##s(const int(*p)[s], size_t size) \
{ \
for (size_t i = 0; i < size; ++i) { \
	for (int k = 0; k < s; ++k) { \
		printf("%3d ", p[i][k]); \
	} \
	printf("\n"); \
}\
sl(); \
}

gsmf(12)
gsmf(8)
gsmf(20)
gdmf(12)
gdmf(8)
gdmf(20)

int main()
{
	int a[5][12];
	int b[4][8];
	int c[10][20];
	int d[7][12];

	randomize();
	

	set_matrix_12(a, 5);
	set_matrix_8(b, 4);
	set_matrix_20(c, 10);
	set_matrix_12(d, 7);

	display_matrix_12(a, 5);
	display_matrix_8(b, 4);
	display_matrix_20(c, 10);
	display_matrix_12(d, 7);

}
```

```c
void f1(int *p, int size);
void f1(int p[], int size);

void f2(int **p, int size);
void f2(int *p[], int size);

void f3(int (*p)[10], int size);
void f3(int p[][10], int size);
```

```c
#include <stdio.h>
#include "nutility.h"
#include <conio.h>
#include <stdlib.h>


void set_random_matrix(int *p, size_t row, size_t col)
{
	size_t n = row * col;
	while (n--)
		*p++ = rand() % 10;
}

void display_matrix(const int *p, size_t row, size_t col)
{
	for (size_t i = 0; i < row; ++i) {
		for (size_t k = 0; k < col; ++k) {
			printf("%d", p[i * col + k]);
		}
		printf("\n");
	}
	sl();
}

int main()
{
	int a[10][20];
	int b[5][10];
	int c[8][4];

	randomize();

	set_random_matrix((int *)a, 10, 20);
	set_random_matrix((int *)b, 5, 10);
	set_random_matrix((int *)c, 8, 4);
	display_matrix((int *)a, 10, 20);
	display_matrix((int *)b, 5, 10);
	display_matrix((int *)c, 8, 4);

}
```

```c
#include <stdio.h>
#include "nutility.h"
#include <conio.h>
#include <stdlib.h>

//işlevin parametresinin void * yapılması
//çağıran kodun tür dönüştürme operatörü kullanmadan doğrudan dizi ismi ile
//çağrı yapması olanağı veriyor<
//ancak derleyicinin yapabileceği tür uyumu kontrolleri devre dışı bırakılıyor
void set_random_matrix(void *vp, size_t row, size_t col)
{
	int *p = vp;
	size_t n = row * col;
	while (n--)
		*p++ = rand() % 10;
}

void display_matrix(const void *vp, size_t row, size_t col)
{
	const int *p = vp;
	for (size_t i = 0; i < row; ++i) {
		for (size_t k = 0; k < col; ++k) {
			printf("%d", p[i * col + k]);
		}
		printf("\n");
	}
	sl();
}

int main()
{
	int a[10][20];
	int b[5][10];
	int c[8][4];
	
	randomize();

	set_random_matrix(a, 10, 20);
	set_random_matrix(b, 5, 10);
	set_random_matrix(c, 8, 4);
	display_matrix(a, 10, 20);
	display_matrix(b, 5, 10);
	display_matrix(c, 8, 4);

}
```


```c
#include <stdio.h>
#include "nutility.h"
#include <conio.h>
#include <stdlib.h>

int main()
{
	int a[64] = { 0 };

	printf("%p  %p\n", a, a + 1);
	printf("%p  %p\n", &a, &a + 1);
}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "nutility.h"

void swap_str(char *p1, char *p2)
{
	char temp[20];
	strcpy(temp, p1);
	strcpy(p1, p2);
	strcpy(p2, temp);
}

int main()
{
	char names[][20] = {
		"kamil", "korhan", "beril", "turhan", "ufuk", "murathan", "figen", "malik", "bulent", "cengiz",
		"baran", "nurullah", "dilber", "tuncer", "recep", "pelinsu", "cihan", "yesim", "aziz", "kazim",
		"afacan", "tevfik", "sumeyye", "hande", "aslihan", "emine", "temel", "gulsah", "hasan", "gul",
		"soner", "ayla", "cuneyt", "tekin", "binnaz", "emrecan", "yasar", "yilmaz", "feraye", "tugra",
		"melek", "garo", "yurdagul", "tarik", "derin", "handan", "aytac", "petek", "cem", "aylin",
		"gursel", "haldun", "nazife", "hulusi", "sevilay", "sabriye", "gulden", "tansel", "ege", "turgut",
		"cahit", "berk", "nazli", "aykut", "kayhan", "cemre", "murat", "kunter", "gunay", "cahite",
		"nedim", "metin", "kerim", "utku", "cumhur", "kurthan", "poyraz", "can", "candan", "hikmet",
		"izzet", "perihan", "tufan", "zahide", "samet", "melih", "hakan", "ayse", "refik", "efe",
		"belgin", "bilal", "niyazi", "fugen", "melike", "saadet", "cemile", "nahit", "arda", "ugur",
		"aynur", "yasin", "polat", "naz", "yusuf", "gulsen", "nazif", "demir", "egemen", "necmi",
		"fazilet", "celal", "ismail", "kamile", "mahir", "caner", "suleyman", "cezmi", "diana", "sadullah",
		"atif", "huseyin", "necmettin", "devlet", "sezen", "hulya", "necmiye", "ece", "julide", "onat",
		"emre", "sinem", "teoman", "irmak", "cihat", "adem", "bilgin", "muzaffer", "suphi", "pelin",
		"yalcin", "kenan", "atalay", "akin", "durmus", "haluk", "kelami", "alparslan", "busra", "kasim",
		"durriye", "tarcan", "nihal", "gizem", "bilge", "dilek", "yasemin", "fahri", "furkan", "papatya",
		"hakki", "fadime", "devrim", "abdi", "tayyip", "yurdakul", "zekai", "nagehan", "ata", "naci",
		"mert", "yelda", "cebrail", "rumeysa", "beyhan", "azize", "cemil", "sezer", "beste", "ciler",
		"enes", "cahide", "tayyar", "cansu", "burak", "ediz", "sefa", "anil", "alev", "atil",
		"nefes", "cetin", "tansu", "bora", "sevim", "sarp", "fuat", "kaya", "zarife", "tanju",
		"su", "kerem", "handesu", "jade", "halime", "gurbuz", "okan", "azmi", "sevda", "leyla",
		"galip", "alican", "atakan", "feramuz", "efecan", "osman", "nihat", "sefer", "zerrin", "binnur",
		"taner", "kayahan", "nalan", "tonguc", "kezban", "kaan", "abdulmuttalip", "dost", "deniz", "refika",
		"tijen", "umit", "yunus", "zahit", "melisa", "hulki", "hilmi", "edip", "muslum", "canan",
		"dogan", "berivan", "adnan", "helin", "fikret", "derya", "sidre", "abdullah", "billur", "nurdan",
		"agah", "engin", "burhan", "suheyla", "esra", "sadri", "sezai", "esen", "askin", "rupen",
		"ercument", "birhan", "ahmet", "polathan", "tayfun", "mustafa", "zubeyde", "pakize", "nevsin", "naciye",
		"erdem", "asim", "orkun", "sami", "sade", "demet", "keriman", "yavuz", "mehmet", "muhsin",
		"saniye", "cesim", "aydan", "eda", "hilal", "burak", "taylan", "fedai", "ilke", "dogancan",
		"rezzan", "ozer", "tacettin", "nurettin", "seyfettin", "safiye", "aydin", "latife", "sercan", "benfero", };

	
	for (size_t i = 0; i < asize(names) - 1; ++i) {
		for (size_t k = 0; k < asize(names) - 1 - i; ++k) {
			if (strcmp(names[k], names[k + 1]) > 0) {
				swap_str(names[k], names[k + 1]);
			}
		}
	}

	for (size_t i = 0; i < asize(names); ++i) {
		printf("%s ", names[i]);
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


int scmp(const void *vp1, const void *vp2)
{
	return strcmp(*(char **)vp1, *(char**)vp2);
}
int main()
{
	char names[][20] = {
		"kamil", "korhan", "beril", "turhan", "ufuk", "murathan", "figen", "malik", "bulent", "cengiz",
		"baran", "nurullah", "dilber", "tuncer", "recep", "pelinsu", "cihan", "yesim", "aziz", "kazim",
		"afacan", "tevfik", "sumeyye", "hande", "aslihan", "emine", "temel", "gulsah", "hasan", "gul",
		"soner", "ayla", "cuneyt", "tekin", "binnaz", "emrecan", "yasar", "yilmaz", "feraye", "tugra",
		"melek", "garo", "yurdagul", "tarik", "derin", "handan", "aytac", "petek", "cem", "aylin",
		"gursel", "haldun", "nazife", "hulusi", "sevilay", "sabriye", "gulden", "tansel", "ege", "turgut",
		"cahit", "berk", "nazli", "aykut", "kayhan", "cemre", "murat", "kunter", "gunay", "cahite",
		"nedim", "metin", "kerim", "utku", "cumhur", "kurthan", "poyraz", "can", "candan", "hikmet",
		"izzet", "perihan", "tufan", "zahide", "samet", "melih", "hakan", "ayse", "refik", "efe",
		"belgin", "bilal", "niyazi", "fugen", "melike", "saadet", "cemile", "nahit", "arda", "ugur",
		"aynur", "yasin", "polat", "naz", "yusuf", "gulsen", "nazif", "demir", "egemen", "necmi",
		"fazilet", "celal", "ismail", "kamile", "mahir", "caner", "suleyman", "cezmi", "diana", "sadullah",
		"atif", "huseyin", "necmettin", "devlet", "sezen", "hulya", "necmiye", "ece", "julide", "onat",
		"emre", "sinem", "teoman", "irmak", "cihat", "adem", "bilgin", "muzaffer", "suphi", "pelin",
		"yalcin", "kenan", "atalay", "akin", "durmus", "haluk", "kelami", "alparslan", "busra", "kasim",
		"durriye", "tarcan", "nihal", "gizem", "bilge", "dilek", "yasemin", "fahri", "furkan", "papatya",
		"hakki", "fadime", "devrim", "abdi", "tayyip", "yurdakul", "zekai", "nagehan", "ata", "naci",
		"mert", "yelda", "cebrail", "rumeysa", "beyhan", "azize", "cemil", "sezer", "beste", "ciler",
		"enes", "cahide", "tayyar", "cansu", "burak", "ediz", "sefa", "anil", "alev", "atil",
		"nefes", "cetin", "tansu", "bora", "sevim", "sarp", "fuat", "kaya", "zarife", "tanju",
		"su", "kerem", "handesu", "jade", "halime", "gurbuz", "okan", "azmi", "sevda", "leyla",
		"galip", "alican", "atakan", "feramuz", "efecan", "osman", "nihat", "sefer", "zerrin", "binnur",
		"taner", "kayahan", "nalan", "tonguc", "kezban", "kaan", "abdulmuttalip", "dost", "deniz", "refika",
		"tijen", "umit", "yunus", "zahit", "melisa", "hulki", "hilmi", "edip", "muslum", "canan",
		"dogan", "berivan", "adnan", "helin", "fikret", "derya", "sidre", "abdullah", "billur", "nurdan",
		"agah", "engin", "burhan", "suheyla", "esra", "sadri", "sezai", "esen", "askin", "rupen",
		"ercument", "birhan", "ahmet", "polathan", "tayfun", "mustafa", "zubeyde", "pakize", "nevsin", "naciye",
		"erdem", "asim", "orkun", "sami", "sade", "demet", "keriman", "yavuz", "mehmet", "muhsin",
		"saniye", "cesim", "aydan", "eda", "hilal", "burak", "taylan", "fedai", "ilke", "dogancan",
		"rezzan", "ozer", "tacettin", "nurettin", "seyfettin", "safiye", "aydin", "latife", "sercan", "benfero", };

	
	//yukaridaki diziyi 
	// değiştirmeden sirali bicimde yazdirin
	char *p[asize(names)];

	for (size_t i = 0; i < asize(p); ++i)
		p[i] = names[i];

	qsort(p, asize(p), sizeof(*p), &scmp);
	size_t n;

	printf("kacinci oge: ");
	scanf("%zu", &n);
	printf("%zu. eleman %s\n", n, p[n]);

	for (size_t i = 0; i < asize(p); ++i)
		printf("%s ", p[i]);
	_getch();
	system("cls");

}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "nutility.h"
#include <conio.h>


int scmp(const void *vp1, const void *vp2)
{
	return strcmp(*(char **)vp1, *(char**)vp2);
}
int main()
{
	char names[][20] = {
		"kamil", "korhan", "beril", "turhan", "ufuk", "murathan", "figen", "malik", "bulent", "cengiz",
		"baran", "nurullah", "dilber", "tuncer", "recep", "pelinsu", "cihan", "yesim", "aziz", "kazim",
		"afacan", "tevfik", "sumeyye", "hande", "aslihan", "emine", "temel", "gulsah", "hasan", "gul",
		"soner", "ayla", "cuneyt", "tekin", "binnaz", "emrecan", "yasar", "yilmaz", "feraye", "tugra",
		"melek", "garo", "yurdagul", "tarik", "derin", "handan", "aytac", "petek", "cem", "aylin",
		"gursel", "haldun", "nazife", "hulusi", "sevilay", "sabriye", "gulden", "tansel", "ege", "turgut",
		"cahit", "berk", "nazli", "aykut", "kayhan", "cemre", "murat", "kunter", "gunay", "cahite",
		"nedim", "metin", "kerim", "utku", "cumhur", "kurthan", "poyraz", "can", "candan", "hikmet",
		"izzet", "perihan", "tufan", "zahide", "samet", "melih", "hakan", "ayse", "refik", "efe",
		"belgin", "bilal", "niyazi", "fugen", "melike", "saadet", "cemile", "nahit", "arda", "ugur",
		"aynur", "yasin", "polat", "naz", "yusuf", "gulsen", "nazif", "demir", "egemen", "necmi",
		"fazilet", "celal", "ismail", "kamile", "mahir", "caner", "suleyman", "cezmi", "diana", "sadullah",
		"atif", "huseyin", "necmettin", "devlet", "sezen", "hulya", "necmiye", "ece", "julide", "onat",
		"emre", "sinem", "teoman", "irmak", "cihat", "adem", "bilgin", "muzaffer", "suphi", "pelin",
		"yalcin", "kenan", "atalay", "akin", "durmus", "haluk", "kelami", "alparslan", "busra", "kasim",
		"durriye", "tarcan", "nihal", "gizem", "bilge", "dilek", "yasemin", "fahri", "furkan", "papatya",
		"hakki", "fadime", "devrim", "abdi", "tayyip", "yurdakul", "zekai", "nagehan", "ata", "naci",
		"mert", "yelda", "cebrail", "rumeysa", "beyhan", "azize", "cemil", "sezer", "beste", "ciler",
		"enes", "cahide", "tayyar", "cansu", "burak", "ediz", "sefa", "anil", "alev", "atil",
		"nefes", "cetin", "tansu", "bora", "sevim", "sarp", "fuat", "kaya", "zarife", "tanju",
		"su", "kerem", "handesu", "jade", "halime", "gurbuz", "okan", "azmi", "sevda", "leyla",
		"galip", "alican", "atakan", "feramuz", "efecan", "osman", "nihat", "sefer", "zerrin", "binnur",
		"taner", "kayahan", "nalan", "tonguc", "kezban", "kaan", "abdulmuttalip", "dost", "deniz", "refika",
		"tijen", "umit", "yunus", "zahit", "melisa", "hulki", "hilmi", "edip", "muslum", "canan",
		"dogan", "berivan", "adnan", "helin", "fikret", "derya", "sidre", "abdullah", "billur", "nurdan",
		"agah", "engin", "burhan", "suheyla", "esra", "sadri", "sezai", "esen", "askin", "rupen",
		"ercument", "birhan", "ahmet", "polathan", "tayfun", "mustafa", "zubeyde", "pakize", "nevsin", "naciye",
		"erdem", "asim", "orkun", "sami", "sade", "demet", "keriman", "yavuz", "mehmet", "muhsin",
		"saniye", "cesim", "aydan", "eda", "hilal", "burak", "taylan", "fedai", "ilke", "dogancan",
		"rezzan", "ozer", "tacettin", "nurettin", "seyfettin", "safiye", "aydin", "latife", "sercan", "benfero", };

	
	//yukaridaki diziyi 
	// değiştirmeden sirali bicimde yazdirin
	char *p[asize(names)];

	for (size_t i = 0; i < asize(p); ++i)
		p[i] = names[i];

	qsort(p, asize(p), sizeof(*p), &scmp);
	size_t n;

	printf("kacinci oge: ");
	scanf("%zu", &n);
	printf("%zu. eleman %s\n", n, p[n]);

	for (size_t i = 0; i < asize(p); ++i)
		printf("%s ", p[i]);
	_getch();
	system("cls");

}
```




# C Programlarının (standart yollar ile) sonlandırılması

```text
normal termination   (exit)
abnormal termination (abort)
```

```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void f4()
{
	printf("f4 basladi\n");

	printf("f4 sona erdi\n");
}

void f3()
{
	printf("f3 basladi\n");
	f4();
	printf("f3 sona erdi\n");
}

void f2()
{
	printf("f2 basladi\n");
	f3();
	printf("f2 sona erdi\n");
}


void f1()
{
	printf("f1 basladi\n");
	f2();
	printf("f1 sona erdi\n");
}




int main()
{
	printf("main basladi\n");
	f1();
	printf("main sona erdi\n");
}
```


```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void f4()
{
	printf("f4 basladi\n");
	exit(EXIT_FAILURE);
	printf("f4 sona erdi\n");
}

void f3()
{
	printf("f3 basladi\n");
	f4();
	printf("f3 sona erdi\n");
}

void f2()
{
	printf("f2 basladi\n");
	f3();
	printf("f2 sona erdi\n");
}


void f1()
{
	printf("f1 basladi\n");
	f2();
	printf("f1 sona erdi\n");
}


int main()
{
	printf("main basladi\n");
	f1();
	printf("main sona erdi\n");
}
```

```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

void f4()
{
	printf("f4 cagrildi cleanup islemleri yapildi\n");
}

void f3()
{
	printf("f3 cagrildi cleanup islemleri yapildi\n");

}

void f2()
{
	printf("f2 cagrildi cleanup islemleri yapildi\n");

}


void f1()
{
	printf("f1 cagrildi cleanup islemleri yapildi\n");
}


int main()
{
	atexit(f1);
	atexit(f2);
	atexit(f3);
	atexit(f4);
	_getch();
	//exit(EXIT_FAILURE);

}
```


```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>


void f4(int val)
{
	assert(val != 0);
	int x = 10;
	x /= val;
}

void f3()
{
	printf("f3 basladi\n");
	f4(0);
	printf("f3 sona erdi\n");
}

void f2()
{
	printf("f2 basladi\n");
	f3();
	printf("f2 sona erdi\n");
}


void f1()
{
	printf("f1 basladi\n");
	f2();
	printf("f1 sona erdi\n");
}

int main()
{
	printf("main basladi\n");
	f1();
	printf("main sona erdi\n");
}
```
