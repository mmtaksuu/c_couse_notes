# LESSON 19

## Sorting and Searching Algorithms 


```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int a[10]; // Global namespace de tanimli oldugu icin init degeri 0 olur.

int main()
{
	for (int i = 0; i < 10; ++i) {
		printf("%d ", a[i]);
	}

	printf("\n");
}
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int a[10];

int main()
{
	for (int i = 0; i < 10; ++i) {
		a[i] = i;
	}

	printf("\n");

}
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "nutility.h"

#define   SIZE      100

// Array Toplamini Bul
int main()
{
	int a[SIZE];

	randomize();
	for (int i = 0; i < SIZE; ++i) {
		a[i] = rand() % 1000;
		printf("%3d%c", a[i], i % 20 == 19 ? '\n' : ' ');
	}
	printf("\n\n");

	int sum = 0;
	for (int i = 0; i < SIZE; ++i) {
		sum += a[i];
	}

	printf("sum = %d\n", sum);

}
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "nutility.h"

#define   SIZE      100

// Array Ortalamasini bul
int main()
{
	int a[SIZE];

	randomize();
	for (int i = 0; i < SIZE; ++i) {
		a[i] = rand() % 1000;
		printf("%3d%c", a[i], i % 20 == 19 ? '\n' : ' ');
	}
	printf("\n\n");

	int sum = 0;
	for (int i = 0; i < SIZE; ++i) {
		sum += a[i];
	}

	printf("ortalama = %f\n", (double)sum / SIZE);
}
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "nutility.h"

#define   SIZE      3

// Tek sayilarin ortalamasini bul
int main()
{
	int a[SIZE];

	randomize();
	for (int i = 0; i < SIZE; ++i) {
		a[i] = rand() % 1000;
		printf("%3d%c", a[i], i % 20 == 19 ? '\n' : ' ');
	}
	printf("\n\n");
	int sum_odds = 0;
	int odd_cnt = 0;

	for (int i = 0; i < SIZE; ++i) {
		if (a[i] % 2 != 0) {
			sum_odds += a[i];
			++odd_cnt;
		}
	}

	if (odd_cnt)
		printf("teklerin ortalamasi %f\n", (double)sum_odds / odd_cnt);
	else
		printf("dizide hic tek sayi yok\n");

}
```


```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "nutility.h"

#define   SIZE      100

// Standart sapmayi hesapla
int main()
{
	int a[SIZE];

	randomize();
	for (int i = 0; i < SIZE; ++i) {
		a[i] = rand() % 1000;
		printf("%3d%c", a[i], i % 20 == 19 ? '\n' : ' ');
	}
	printf("\n\n");
	int sum = 0;

	for (int i = 0; i < SIZE; ++i) {
		sum += a[i];
	}
	double mean = (double)sum / SIZE;
	double sum_square = 0.;

	for (int i = 0; i < SIZE; ++i) {
		sum_square += (a[i] - mean) * (a[i] - mean);
	}

	printf("std. deviation is %f\n", sqrt(sum_square / SIZE));
}
```


## Linear Search (Dogrusal Arama)

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "nutility.h"

#define   SIZE      100
// Flag kullanilarak yapilir.
int main()
{
	int a[SIZE];

	randomize();
	for (int i = 0; i < SIZE; ++i) {
		a[i] = rand() % 1000;
		printf("%3d%c", a[i], i % 20 == 19 ? '\n' : ' ');
	}
	printf("\n\n");
	int val;

	printf("aranacak degeri girin: ");
	scanf("%d", &val);

	int found = 0;
	int i;

	for (i = 0; i < SIZE; ++i) {
		if (a[i] == val) {
			found = 1;
			break;
		}
	}

	if (found)
		printf("bulundu indis %d\n", i);
	else
		printf("bulunamadi\n");

}
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "nutility.h"

#define   SIZE      100
// break ile fonguden cikilir.
int main()
{
	int a[SIZE];

	randomize();
	for (int i = 0; i < SIZE; ++i) {
		a[i] = rand() % 1000;
		printf("%3d%c", a[i], i % 20 == 19 ? '\n' : ' ');
	}
	printf("\n\n");
	int val;

	printf("aranacak degeri girin: ");
	scanf("%d", &val);

	int i;

	for (i = 0; i < SIZE; ++i) {
		if (a[i] == val) {
			break;
		}
	}

	if (i < SIZE)
		printf("bulundu indis %d\n", i);
	else
		printf("bulunamadi\n");

}
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "nutility.h"

#define   SIZE      100
// Idiomatic bir dongu ile arama islemi yapilir ve donguden cikilir.
int main()
{
	int a[SIZE];

	randomize();
	for (int i = 0; i < SIZE; ++i) {
		a[i] = rand() % 1000;
		printf("%3d%c", a[i], i % 20 == 19 ? '\n' : ' ');
	}
	printf("\n\n");
	int val;

	printf("aranacak degeri girin: ");
	scanf("%d", &val);

	int i;

	for (i = 0; i < SIZE && a[i] != val; ++i)
		;

	if (i < SIZE)
		printf("bulundu indis %d\n", i);
	else
		printf("bulunamadi\n");

}
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "nutility.h"

#define   SIZE      100

int main()
{
	int a[SIZE];

	randomize();
	for (int i = 0; i < SIZE; ++i) {
		a[i] = rand() % 1000;
		printf("%3d%c", a[i], i % 20 == 19 ? '\n' : ' ');
	}
	printf("\n\n");
	int val;

	printf("aranacak degeri girin: ");
	scanf("%d", &val);

	int i;

	for (i = 0; i < SIZE; ++i) {
		if (a[i] == val) {
			break;
		}
	}

	if (i < SIZE)
		printf("bulundu indis %d\n", i);
	else
		printf("bulunamadi\n");


}
```


```text
Arama isleminin karmasikliginin 3n'den 2n yapilmasi:
    i < SIZE;
    a[i] == val;
    ++i;
    
Dizinin sonuna aranan degeri koy ve donguyu soyle tanimla:
    for (i = 0; a[i] != val; ++i)
    		;
```
    
```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "nutility.h"

#define   SIZE      100

int main()
{
	int a[SIZE + 1];

	randomize();
	for (int i = 0; i < SIZE; ++i) {
		a[i] = rand() % 1000;
		printf("%3d%c", a[i], i % 20 == 19 ? '\n' : ' ');
	}
	printf("\n\n");
	int val;

	printf("aranacak degeri girin: ");
	scanf("%d", &val);
	a[SIZE] = val;

	int i = SIZE;

	for (i = 0; a[i] != val; ++i)
		;

	if (i < SIZE)
		printf("bulundu indis %d\n", i);
	else
		printf("bulunamadi\n");

}
```




```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "nutility.h"

#define   SIZE      20
// Min Bul
int main()
{
	int a[SIZE];

	randomize();
	for (int i = 0; i < SIZE; ++i) {
		a[i] = rand() % 1000;
		printf("%3d%c", a[i], i % 20 == 19 ? '\n' : ' ');
	}
	printf("\n\n");

	int min = a[0];

	for (int i = 1; i < SIZE; ++i) {
		if (a[i] < min)
			min = a[i];
	}

	printf("min = %d\n", min);

}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "nutility.h"

#define   SIZE      20

int main()
{
	int a[SIZE];

	randomize();
	for (int i = 0; i < SIZE; ++i) {
		a[i] = rand() % 1000;
		printf("%3d%c", a[i], i % 20 == 19 ? '\n' : ' ');
	}
	printf("\n\n");

	int min = a[0];
	int idx_min = 0;

	for (int i = 1; i < SIZE; ++i) {
		if (a[i] < min) {
			min = a[i];
			idx_min = i;
		}
	}

	printf("min = a[%d] ==> %d\n", idx_min, min);

}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "nutility.h"

#define   SIZE      20
// Min-Max Bul
int main()
{
	int a[SIZE];

	randomize();
	for (int i = 0; i < SIZE; ++i) {
		a[i] = rand() % 1000;
		printf("%3d%c", a[i], i % 20 == 19 ? '\n' : ' ');
	}
	printf("\n\n");

	int min = a[0];
	int max = a[0];

	for (int i = 1; i < SIZE; ++i) {
		if (a[i] > max)
			max = a[i];
		else if (a[i] < min)
			min = a[i];
	}

	printf("min = %d\n", min);
	printf("max = %d\n", max);
}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "nutility.h"

#define   SIZE      20

// RUNNER_UP Bul
int main()
{
	int a[SIZE];

	randomize();
	for (int i = 0; i < SIZE; ++i) {
		a[i] = rand() % 1000;
		printf("%3d%c", a[i], i % 20 == 19 ? '\n' : ' ');
	}
	printf("\n\n");

	int max = a[0];
	int runner_up = a[1];

	for (int i = 1; i < SIZE; ++i) {
		if (a[i] > max) {
			runner_up = max;
			max = a[i];
		}
		else if (a[i] > runner_up) {
			runner_up = a[i];
		}
	}

	printf("runner_up = %d\n", runner_up);
}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "nutility.h"

#define   SIZE      20

// Swap Islemi
int main()
{
	int a[SIZE];

	randomize();
	for (int i = 0; i < SIZE; ++i) {
		a[i] = rand() % 1000;
		printf("%3d%c", a[i], i % 20 == 19 ? '\n' : ' ');
	}
	printf("\n\n");


	for (int i = 0; i < SIZE / 2; ++i) {
		int temp = a[i];
		a[i] = a[SIZE - 1 - i];
		a[SIZE - 1 - i] = temp;
	}

	for (int i = 0; i < SIZE; ++i) {
		printf("%3d%c", a[i], i % 20 == 19 ? '\n' : ' ');
	}
	printf("\n\n");
}
```


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "nutility.h"

#define   SIZE      20
int main()
{
	int a[SIZE];
	int b[SIZE] = { 0 };

	randomize();
	for (int i = 0; i < SIZE; ++i) {
		a[i] = rand() % 10;
		printf("%3d%c", a[i], i % 20 == 19 ? '\n' : ' ');
	}
	printf("\n\n");
	int val;
	printf("bir sayi giriniz: ");
	scanf("%d", &val);
	int size = 0;

	for (int i = 0; i < SIZE; ++i) {
		if (a[i] != val) {
			b[size++] = a[i];
		}
	}


	for (int i = 0; i < size; ++i) {
		printf("%3d ", b[i]);
	}
	printf("\n");

	for (int i = 0; i < SIZE; ++i) {
		printf("%3d ", b[i]);
	}
	printf("\n");

}

/**********************************************************************************************************************/

65554433887125552719203339
65438712527192039

  0   2   3   0   3   2   3   1   0   2   1   3   1   0   1   3   1   1   3   1

02302310213

  1   1   1   0   1   0   0   0   1   2   1   2   0   2   2   2   1   1   0   1
1010121202101???????


 16 369 818 943 916  61 896 787 828 484 655 134 203 953 997 644 330 727 547 941



array subsequence

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "nutility.h"

#define   SIZE      100

//asagidaki dizinin max-subsequence değerini bulunuz

int main()
{
	int a[SIZE];

	int a[] = {
		395, -135, 652, 126, -247, 766, 173, -333, 312, 307, 82, 737, 635, 706, 442, 897, 934, 3, 637, -54,
	-508, -866, -504, -991, 461, -840, -653, -975, 171, 304, 712, 194, -478, -683, 756, 203, 737, 61, 292, -321,
	-963, -813, 722, -654, -151, -489, 364, 526, 772, -256, -882, -166, 822, 46, 649, -90, 507, -267, -603, 446,
	-487, 228, -724, 590, -912, 345, -694, -390, -235, -61, -191, 459, -901, 713, -38, -648, -210, 801, 697, -546,
	418, -422, 842, -787, -103, 426, -805, -51, 537, -744, -44, -554, 778, 801, -851, -248, -90, 735, 940, 734, };

}

/**********************************************************************************************************************/


dizilere ilk değer verilmesi

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "nutility.h"

#define   SIZE      100


int main()
{
	int a[10] = { 1, 6, 7, 2, 6, 9, 3, 23, 45, 19 };

	for (int i = 0; i < 10; ++i) {
		printf("%d ", a[i]);
	}


}

/**********************************************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "nutility.h"

#define   SIZE      100


int main()
{
	int a[10] = { 1, 6, 7, 2, 6, 9, 3, 23, 45, 19, 67 }; //gecersiz

	for (int i = 0; i < 10; ++i) {
		printf("%d ", a[i]);
	}


}

/**********************************************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "nutility.h"

#define   SIZE      100


int main()
{
	int a[10] = { 1, 6, 7, 2, 6 };

	for (int i = 0; i < 10; ++i) {
		printf("%d ", a[i]);
	}


}

/**********************************************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "nutility.h"

#define   SIZE      100


int main()
{
	int a[100] = { 0};

	for (int i = 0; i < 100; ++i) {
		printf("%d ", a[i]);
	}


}

/**********************************************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "nutility.h"

#define   SIZE      100


int main()
{
	int a[100] = {}; //C'de gecersiz

	for (int i = 0; i < 100; ++i) {
		printf("%d ", a[i]);
	}


}

/**********************************************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "nutility.h"

#define   SIZE      100


int main()
{
	int a[5] = { 1, 4, 6, 6, 9, }; //trailing comma
	int b[5] = { 1, 2, }; //trailing comma


}

/**********************************************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "nutility.h"

#define   SIZE      100


int main()
{
	int a[] = { 1, 5, 8, 9, 3, 3, 5,  };

}

/**********************************************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "nutility.h"

#define   SIZE      100

//C99
//designated initializer

int main()
{
	int a[SIZE] = { [23] = 230,[45] = 450,[11] = 110, [88] = 880 };

	for (int i = 0; i < SIZE; ++i) {
		printf("%3d ", a[i]);
	}

	printf("\n");


}

/**********************************************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "nutility.h"

#define   SIZE      100

//C99
//designated initializer

int main()
{
	//a dizisinin boyutu 89
	//max ddesignated init idx + 1

	int a[] = { [23] = 230,[45] = 450,[11] = 110, [88] = 880 };

	for (int i = 0; i < 89; ++i) {
		printf("%3d ", a[i]);
	}

	printf("\n");


}

/**********************************************************************************************************************/

urand işlevinin implementasyonu

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "nutility.h"

#define   URAND_MAX      20

//urand her çağrıldığında 0 dahil URAND_MAX hariç yani [0 URAND_MAX) araliginde rastgele sayi uretecek
//eger fonksiyon URAND_MAX KEZ çağrıdan sonra tekrar çağrılırsa hata kodu olarak -1 değeri dönmeli
//asagidaki test koduna bakınız

int urand(void)
{
	static int flags[URAND_MAX] = { 0 };
	static int size = 0;

	if (size == URAND_MAX)
		return - 1;

	int val;

	while (flags[val = rand() % URAND_MAX])
		;

	++size;
	flags[val] = 1;

	return val;
}

int main()
{
	randomize();

	for (int i = 0; i < URAND_MAX; ++i) {
		printf("%3d%c", urand(), i % 20 == 19 ? '\n' : ' ');
	}

	printf("\n");
	printf("%d\n", urand());

}

/**********************************************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "nutility.h"

#define   URAND_MAX      20

//urand her çağrıldığında 0 dahil URAND_MAX hariç yani [0 URAND_MAX) araliginde rastgele sayi uretecek
//eger fonksiyon URAND_MAX KEZ çağrıdan sonra tekrar çağrılırsa hata kodu olarak -1 değeri dönmeli
//asagidaki test koduna bakınız

int urand(void)
{
	static int flags[URAND_MAX] = { 0 };
	static int size = 0;

	if (size == URAND_MAX)
		return - 1;

	int val;

	while (flags[val = rand() % URAND_MAX])
		;

	++size;
	flags[val] = 1;

	return val;
}

int main()
{
	randomize();

	for (int i = 0; i < URAND_MAX; ++i) {
		printf("%3d%c", urand(), i % 20 == 19 ? '\n' : ' ');
	}

	printf("\n");
	printf("%d\n", urand());

}

/**********************************************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "nutility.h"

#define   URAND_MAX      20

//urand her çağrıldığında 0 dahil URAND_MAX hariç yani [0 URAND_MAX) araliginde rastgele sayi uretecek
//eger fonksiyon URAND_MAX KEZ çağrıdan sonra tekrar çağrılırsa hata kodu olarak -1 değeri dönmeli
//asagidaki test koduna bakınız

int urand(void)
{
	static int flags[URAND_MAX] = { 0 };
	static int size = 0;

	if (size == URAND_MAX) {
		size = 0;

		/*for (int i = 0; i < URAND_MAX; ++i)
			flags[i] = 0;*/

		memset(flags, 0, URAND_MAX * sizeof(int));
	}

	int val;

	while (flags[val = rand() % URAND_MAX])
		;

	++size;
	flags[val] = 1;

	return val;
}

int main()
{
	randomize();

	for (int i = 0; i < URAND_MAX; ++i) {
		printf("%3d%c", urand(), i % 20 == 19 ? '\n' : ' ');
	}

	printf("\n");
	printf("%d\n", urand());

}

/**********************************************************************************************************************/

sizeof operatörü (fonksiyon değil)

sizeof (char)
sizeof (int)
sizeof (long)

sizeof(_Bool) = 1
sizeof(char) = 1
sizeof(short) = 2
sizeof(int) = 4
sizeof(long) = 4
sizeof(long long) = 8
sizeof(float) = 4
sizeof(double) = 8
sizeof(long double) = 8

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "nutility.h"

int main()
{
	printf("sizeof(_Bool) = %zu\n", sizeof(_Bool));
	printf("sizeof(char) = %zu\n", sizeof(char));
	printf("sizeof(short) = %zu\n", sizeof(short));
	printf("sizeof(int) = %zu\n", sizeof(int));
	printf("sizeof(long) = %zu\n", sizeof(long));
	printf("sizeof(long long) = %zu\n", sizeof(long long));
	printf("sizeof(float) = %zu\n", sizeof(float));
	printf("sizeof(double) = %zu\n", sizeof(double));
	printf("sizeof(long double) = %zu\n", sizeof(long double));
}

sizeof(_Bool) = 1
sizeof(char) = 1
sizeof(short) = 2
sizeof(int) = 4
sizeof(long) = 8
sizeof(long long) = 8
sizeof(float) = 4
sizeof(double) = 8
sizeof(long double) = 16
0
Finish

sizeof exp

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "nutility.h"

int main()
{
	int x = 10;

	printf("%zu\n", sizeof x + 2);
	printf("%zu\n", sizeof (x + 2));
	printf("%zu\n", sizeof (x + 2.));
}
/**********************************************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "nutility.h"

//unevaluated context

int main()
{
	int x = 99;

	printf("%zu\n", sizeof ++x);

	printf("x = %d\n", x); //

}
/**********************************************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "nutility.h"

//unevaluated context

int foo(void)
{
	printf("fooooooooooooo\n");
	return 1;
}

int main()
{
	int x = sizeof(foo());

	printf("x = %d\n", x);

}
/**********************************************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "nutility.h"

//unevaluated context

void foo(void)
{
	printf("fooooooooooooo\n");

}

int main()
{
	int x = sizeof(foo()); //gecersiz

}
/**********************************************************************************************************************/

sizeof operatörünün operandı void türden olamaz


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "nutility.h"

int main()
{
	char str[20];
	int a[15];
	double b[50];

	printf("%zu\n", sizeof str);
	printf("%zu\n", sizeof a);
	printf("%zu\n", sizeof b);


}

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "nutility.h"

int main()
{
	char str[20];
	int a[15];
	double b[50];

	printf("%zu\n", sizeof str / sizeof str[0]);
	printf("%zu\n", sizeof a / sizeof a[0]);
	printf("%zu\n", sizeof b / sizeof b[0]);


}
/**********************************************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "nutility.h"

int main()
{
	int a[] = { 2, 6, 7, 1, 8, 9, 2, 13, 19, 29, 33, 78, 90, 123 };

	for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i)
		printf("%d ", a[i]);

	printf("\n");



}
/**********************************************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "nutility.h"

int main()
{
	int a[] = { 2, 6, 7, 1, 8, 9, 2, 13, 19, 29, 33, 78, 90, 123 };
	int b[2 * (sizeof(a) / sizeof(a[0]))];




}
/**********************************************************************************************************************/
#include<stdio.h>
#include "nutility.h"


int a[] = { 1, 2, 3, 4, 5 };

int main()
{
	for (int k = -1; k <= asize(a) - 2; ++k)
		printf("%d\n", a[k + 1]);

	return 0;
}

#include <stdio.h>

int main()
{
	int x = 3;
	int y = 5;
	int z = x + sizeof(++x) - sizeof(++y);

	printf("%d\n", x + y + z);

	return 0;
}

#include <stdio.h>

int main()
{
	int x = 10;
	int ival = 20;
	double dval = 3.4;

	printf("%zu\n", sizeof(x > 5 ? ival : dval));

	return 0;
}
/**********************************************************************************************************************/
#include <stdio.h>
#include "nutility.h"
#include <stdlib.h>


#define   SIZE      20

int main()
{
	randomize();
	int a[SIZE];

	for (int i = 0; i < SIZE; ++i) {
		a[i] = rand() % 20 + 1;
		printf("%3d ", a[i]);
	}
	printf("\n\n");

	for (int i = 0; i < SIZE; ++i) {
		for (int k = 0; k < a[i]; ++k) {
			putchar('*');
		}
		putchar('\n');
	}
}
/**********************************************************************************************************************/

