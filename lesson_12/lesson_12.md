# Loop Statements (Dongu Deyimleri)

```text
//range-based for loop
for (auto x : vec)

//control expression
while (expr)
        |
        |----> Burasi bos olamaz,
        |----> Buraya if gibi statement yazilamaz,
        |----> Buraya yazilan ifadenin turu void olamaz.
	statement;
```


```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int c;

	printf("Haydi gir bakalim bir seyler: ");

	while ((c = getchar()) != '\n') {
		printf("%d\n", c);
	}
}
```


```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand((unsigned)time(0));
    
    int ival;
    
    while ((ival = rand() % 1000) != 500) {
        printf("%d ", ival);
    }
    printf("\n\n");
    
    printf("ival = %d\n", ival);
}
```


```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int main(void)
{
	int low, high, n;

	printf("bir aralik girin: ");
	scanf("%d%d", &low, &high);
	printf("kaca tam bolunenler : ");
	scanf("%d", &n);

	int temp = low;
	int size = 0;

	while (temp <= high) {
		if (temp % n == 0) {
			printf("%d ", temp);
			++size;
		}
		++temp;
	}
	printf("\n[%d %d] araliginda [%d] ile tam bolunen [%d] sayi yazildi\n", low, high, n, size);
}
```



```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int x = 0;

	while (x++ < 100)
	    ;
	printf("%d ", x); // 101 yazar
}
```


## n kez dönen while döngü idiyomu

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int n;

	printf("kac kez : ");
	scanf("%d", &n);

	while (n-- > 0) {
		printf("necati\n");
	}
    return 0;
}
```


```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int n;

	printf("kac kez : ");
	scanf("%d", &n);

	while (n--) {
		printf("necati\n");
	}
    return 0;
}
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int n;

	printf("kac kez : ");
	scanf("%d", &n);

	//abi, bu ne operatörü??? uzun ok operatörü .d
	while (n --> 0) {
		printf("necati\n");
	}
    return 0;
}
```


```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int power(int base, int exp)
{
	int result = 1;

	while (exp--)
		result *= base;

	return result;
}

int main(void)
{
	int x, y;

	printf("iki tamsayi giriniz: ");
	scanf("%d%d", &x, &y);

	printf("%d --> %d = %d\n", x, y, power(x, y));
}
```


```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>

int64_t factorial_iter(int ival)
{
    int64_t res = 1;

    if (!ival)
        return 0;

    while (ival != 0) {
        res *= ival;
        --ival;
    }
    return res;
}

int64_t factorial_recursive(int ival)
{
    return ival == 0 ? 0 :
           ival == 1 ? 1 :
           ival * factorial_recursive(ival-1);
}

int64_t factorial_look_up(int n)
{
    static const int64_t vals[] = {
                                    1,
                                    1,
                                    2,
                                    6,
                                    24,
                                    120,
                                    720,
                                    5040,
                                    40320,
                                    362880,
                                    3628800,
                                    39916800,
                                    479001600,
                                    6227020800,
                                    87178291200,
                                    1307674368000,
                                    20922789888000,
                                    355687428096000,
                                    6402373705728000,
                                    121645100408832000,
                                    2432902008176640000,
                                    };

    return vals[n];
}


int main(void)
{
    int x;
    printf("Enter a number : ");
    scanf("%d", &x);

    printf("Factorial of %d is %lld\n", x, factorial_iter(x));
    printf("Factorial of %d is %lld\n", x, factorial_recursive(x));
    printf("Factorial of %d is %lld\n", x, factorial_look_up(x));

    /*for (int i = 0; i < 21; ++i) {
        printf("Factorial of %d is %.03f\n", i, factorial_iter(i));
    }*/

    return 0;
}
```


```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int c;
	int sum = 0;

	// Ileri̇de görecegiz
	setvbuf(stdin, NULL, _IOFBF, 4 * BUFSIZ);

	printf("bir sayi girin: ");

	while ((c = getchar()) != '\n')
		sum += c - '0';

	if (sum % 3 == 0)
		printf("evet bolunur\n");
	else
		printf("hayir bolunmez\n");

}
```


```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sumdigit(int val)
{
    int sum = 0;
    
    while (val) {
        sum += val % 10;
        val /= 10;
    }
    
    return sum;
}

int ndigit(int val)
{
    int digit_count = 0;
    
    if (val == 0)
        return 1;
    
    while (val) {
        ++digit_count;
        val /= 10;
    }
    
    return digit_count;
}

int dreverse(int val)
{
    int x = 0;
    
    while (val) {
        x = x * 10 + val % 10;
        val /= 10;
    }
    
    return x;
}

int main(void)
{
    int x;
    
    printf("bir tamsayi giriniz: ");
    scanf("%d", &x);
    
    printf("%d sayisi %d basamakli\n", x, ndigit(x));
    printf("%d sayisi basamaklari toplami %d\n", x, sumdigit(x));
    printf("%d sayisinin basamaksal tersi %d\n", x, dreverse(x));
    
    return 0;
}
```


```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 100 50 25 76 38 19 58 29 88 44 22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1

void print_collatz(unsigned long long int uval)
{
    while (uval != 1) {
        printf("%llu ", uval);
        if (uval % 2 == 0)
            uval /= 2;
        else
            uval = uval * 3 + 1;
    }
    
    printf("1\n");
}


int main()
{
    print_collatz(100ull);
    
    return 0;
}
```








## Bir döngüdeyim nasıl çıkabilirim?

```text
1) kontrol ifadesinin yanlış olması ile
    while (i < size && a[i] != sval) {
    	++i;
    }

2) return deyimi ile
    döngü () {
    	////statement
    	////statement
    	if (exp)
    		return x;
    	////statement
    	////statement
    }

3) break statement ile
    döngü (expr) {
    	statement1;
    	statement2;
    	statement3;
    	if (c_exp)
    		break;
    	statement4;
    	statement5;
    }

4) goto statement ile
    int g;
    
    int main()
    {
    	while (1) {
    		////code
    		while (1) {
    		////code
    			while (1) {
    				if (g > 1000)
    					goto OUT;
    			}
    			///A
    		}
    		///B
    	}
    OUT:
    	//c
    
    }
5) exit / quick_exit / abort
```


```c
#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <stdio.h>

int main()
{
	int c;

	printf("soyle bana evet mi (e) hayir mi (h) : ");

	while (1) {
		c = _getch();
		if (c == 'e' || c == 'h')
			break;
	}

	printf("\n%c\n", c);

	if (c == 'e')
		printf("evettttt dediniz...\n");
	else
		printf("hayirrr dediniz...\n");
}
```


```c
#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <stdio.h>

int main()
{
	int c;

	printf("soyle bana evet mi (e) hayir mi (h) : ");

	while ((c = _getch()), c != 'e' && c != 'h')
            ; //null statement

	printf("\n%c\n", c);

	if (c == 'e')
		printf("evettttt dediniz...\n");
	else
		printf("hayirrr dediniz...\n");
}
```



## Noktali Virgul Kullanmadan Ekrana "merhaba dunya!" Yazdirin.


```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    if (printf("merhaba dunya!\n")) {}
}


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    while (!printf("merhaba dunya!\n")) {}
}


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    switch(printf("merhaba dunya!\n")) {}
}
```


```text
tamsayı girecek misiniz? e h  e
tamsayiyi girin: 345

tamsayı girecek misiniz? e h  e
tamsayiyi girin: -123

tamsayı girecek misiniz? e h  e
tamsayiyi girin: 987

tamsayı girecek misiniz? e h  e
tamsayiyi girin: 11


tamsayı girecek misiniz? e h  h

toplam 123 sayi girdiniz...
max = 9876
min = -1246
ort = 765
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

int main()
{
	int c;
	int ival;
	int size = 0;

	srand((unsigned)time(0));

	int max = INT_MIN;
	int min = INT_MAX;

	while (1) {
		printf("bir sayi girecek misiniz? (e) (h) ");
		while ((c = toupper(_getch())) != 'E' && c != 'H')
			;
		printf("%c\n", c);
		if (c == 'H')
			break;

		printf("tamsayiyi girin: ");
		//scanf("%d", &ival);
		ival = (rand() % 2 ? 1 : -1) * rand();

		if (ival > max)
			max = ival;
		else if (ival < min)
			min = ival;
		++size;
		printf("%d\n", ival);

	}

	if (size) {
		printf("toplam %d sayi girildi\n", size);
		printf("max = %d\n", max);
		printf("min = %d\n", min);
	}
	else {
		printf("hic giris yapilmadi\n");
	}
}
```


```text
While ve do-while loop arasindaki iliski

while (1) {            do {         
	//statement1;      	//statement1;          
	//statement1;      	//statement1;         
	//statement1;      	//statement1;         
	//statement1;      	//statement1;         
	//statement1;      	//statement1;         
	if (!exp)          }while (exp);         
		break;                   
}                
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int ival;

	do {
		printf("bir tamsayi girin: ");
		scanf("%d", &ival);
	} while (ival <= 0 || ival > 100);

	printf("girilen sayi = %d\n", ival);
    
    return 0;
}
```


```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int ival;

	while (1) {
		printf("bir tamsayi girin: ");
		scanf("%d", &ival);
		if (ival > 0 && ival <= 100)
			break;
	}

	printf("girilen sayi = %d\n", ival);
    
    return 0;
}
```

## Continue Statement

```text
döngü (expr) {
	statement1;
	statement2;
	statement3;
	if (!c_expr) {
		statement4;
		statement5;
		statement6;
	}
}


while (expr) {
	statement1;
	statement2;
	statement3;
	if (c_expr)
		continue;

	statement4;
	statement5;
	statement6;

	if (c_expr2)
		continue;

	statement7;
	statement8;
	statement9;
}
```

## GoTo Statement


```text
while (exp) {

	if (cexp)
		goto out;

out:
}


do {
	if (cexp)
		goto out;

out:
} while (expr);


for (int i = 0; i < 100; ++i) {
	if (expr)
		goto out;

out:

}
```
