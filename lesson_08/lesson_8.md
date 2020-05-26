# Unformatted Input-Output (Formatsiz Girdi - Cikti) 

## getchar() Function
```text
    int getchar(void);
    Standart Input Bufferina girilen karakterlerin karakter kodunu dondurur.
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int ch;

	printf("bir karakter girin: ");
	ch = getchar();
	printf("ch = %d\n", ch);
}
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	printf("bir giris yapin : ");

	int c1 = getchar();
	int c2 = getchar();
	int c3 = getchar();
	int c4 = getchar();

	printf("%d %d %d %d\n", c1, c2, c3, c4);
}
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	printf("bir giris yapin : "); //15*345
	int x, y;

	scanf("%d", &x);   // 15
	int c = getchar(); // *
	scanf("%d", &y);   // 345

	printf("x = %d   y = %d\n", x, y);
}
```

```c
// Standart inputa '\n' karakteri girilene kadar donen dongu idiomu.
int c;
while ((c = getchar()) != '\n')
    ;
```


```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int c;
	int sum = 0;

	printf("bir tamsayi giriniz: ");

	while ((c = getchar()) != '\n')
		sum += c - '0';              // Standart inputa girilen sayinin basamak degerini elde etmek icin yapilir.

	if (sum % 2 == 0)
		printf("evet bolunur\n");
	else
		printf("hayir bolunmez\n");

}
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int x = 0;
	int c;

	printf("bir tamsayi giriniz: ");

	while ((c = getchar()) != '\n')
		x = x * 10 + c - '0';

	printf("x = %d\n", x);
}
```


```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    printf("Enter a number : ");

    int c;
    int digit_sum = 0;
    int input = 0;

    while ((c = getchar()) != '\n') {
        int digit_value = c - '0';    // Standart inputa girilen sayinin basamak degerini elde etmek icin yapilir. '0' = 48'dir.
        digit_sum += digit_value;
        input = input * 10 + digit_value;
    }

    printf("Entered Value is %d\n", input);
    printf("Sum of the entered digits %d\n", digit_sum);

    return 0;
}
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int x;
	int c;

	printf("bir tamsayi giriniz: ");
	//scanf("%d", &x);
	x = 0;

	while ((c = getchar()) != '\n')
		if (c >= '0' && c <= '9')
			x = x * 16 + c - '0';
		else
			x = x * 16 + c - 'A' + 10;

	printf("x = %d\n", x);
}
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	putchar(65);
	putchar('A');

}
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    printf("Prints English Alphabet in Capital\n");
    for (int i = 0; i < 26; ++i)
        putchar(i + 'A'); // 'A' --> 65
    printf("\n\n");

    printf("Prints English Alphabet in Lowercase\n");
    for (int i = 0; i < 26; ++i)
        putchar(i + 'a');  // 'a' --> 97
    printf("\n\n");

    printf("Prints Numbers From 0 to 9\n");
    for (int i = 0; i < 10; ++i)
        putchar(i + '0');  // '0' --> 48
    printf("\n\n");

    return 0;
}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>

int main()
{
	printf("parola : ");
	int c1 = _getch();
	putchar('*');
	int c2 = _getch();
	putchar('*');
	int c3 = _getch();
	putchar('*');
	int c4 = _getch();
	putchar('*');

	printf("\ngirdiginiz parola : %c%c%c%c\n", c1, c2, c3, c4);
}
```


## OPERATORS in C (OPERATÖRLER)

```text
unary operator   ---> Tek operandli
binary operator  ---> Cift operandli
ternary operator ---> Uc operandli (?  :)

prefix           ---> ön ek  konumunda
postfix          ---> son ek konumunda
infix            ---> ara ek konumunda

Side effect : Operatorlerin operandlari uzerinde yaptigi degisikliktir.
```


```text
TABLO
-------------------------------------------
1    ()  []   .  ->
-------------------------------------------
2    + -  ++ --  ! ~ &  * sizeof  (type)    from right to left precedence
-------------------------------------------
3	 * /  %
-------------------------------------------
4	  + -
-------------------------------------------
5	 >>  <<
-------------------------------------------
6     > < >= <=
-------------------------------------------
7     ==  !=
-------------------------------------------
8      &
-------------------------------------------
9      ^
-------------------------------------------
10     |
-------------------------------------------
11		&&
-------------------------------------------
12		||
-------------------------------------------
13     ? :	                                from right to left precedence
-------------------------------------------
14    = += *= -= /= %=  >>= <<= &= ^=  |=   from right to left precedence
-------------------------------------------
15   ,
-------------------------------------------
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int x, y;

	printf("iki tamsayi giriniz: ");
	scanf("%d%d", &x, &y);

	printf("%d + %d = %d\n", x, y, x + y);
	printf("%d - %d = %d\n", x, y, x - y);
}
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int x = 5;
	int y = 3;

	int z = -x - y;
	printf("z = %d\n", z);
}
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int x, y;

	printf("iki tamsayi giriniz: ");
	scanf("%d%d", &x, &y);

	printf("%d * %d = %d\n", x, y, x * y);
	printf("%d / %d = %d\n", x, y, x / y);
	printf("%d %% %d = %d\n", x, y, x % y);
}
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int hour;
	int n;

	printf("saat kac: ");
	scanf("%d", &hour);
	printf("kac saat sonra: ");
	scanf("%d", &n);
	printf("saat : %d\n", (hour + n) % 12);
}
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//4569
int main()
{
	int x;

	printf("dort basamakli bir tamsayi giriniz: ");
	scanf("%d", &x);

	printf("binler basamagi = %d\n", x / 1000);
	printf("yuzler basamagi = %d\n", x % 1000 / 100);
	printf("yuzler basamagi = %d\n", x / 100 % 10);
	printf("onlar  basamagi = %d\n", x % 100 / 10);
	printf("onlar  basamagi = %d\n", x / 10 % 10);
	printf("birler basamagi = %d\n", x % 10);
}
```


```c
void prints_digits(int ival, int nOfdigit)
{
    for (int i = 0; i < nOfdigit; ++i) {
        printf("%-10d basamagi %d\n", power(10, i), ((ival/power(10, i))%10));
    }
}
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//4569
int main()
{
	int x;

	printf("dort basamakli bir tamsayi giriniz: ");
	scanf("%d", &x);

	printf("%d sayisinin tersi %d\n", x, x / 1000 + x % 1000 / 100 * 10 + x / 10 % 10 * 100 + x % 10 * 1000);
}
```



```c
// 1234
// returns 4321
int reverse_number(int ival)
{
    int nOfdigit = ndigit(ival);
    int reversed_number = 0;

    for (int i = 0; i < nOfdigit; ++i) {
        int digit_val = (ival / power(10, i)) % 10;
        reversed_number += digit_val * power(10, nOfdigit-i-1);
    }

    return reversed_number;
}
```



```text
++	increment plus plus
--  decrement minus minus

++x     y++
--a     a--

üretilen değer

++x    ---> nesnenin değerinin 1 fazlası
y++    ---> nesnenin değeri

--x    ---> nesnenin değerinin 1 eksiği
y--    ---> nesnenin değeri
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int x = 25;

	printf("x = %d\n", x);
	++x;
	printf("x = %d\n", x);
	x++;
	printf("x = %d\n", x);
	x = x + 1; //kullanma
	printf("x = %d\n", x);
	x += 1; //kullanma
	printf("x = %d\n", x);
}
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int x = 25;

	printf("x = %d\n", x);
	--x;
	printf("x = %d\n", x);
	x--;
	printf("x = %d\n", x);
	x = x - 1; //kullanma
	printf("x = %d\n", x);
	x -= 1; //kullanma
	printf("x = %d\n", x);
}
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int x = 25;

	printf("%d\n", ++x);
	printf("%d\n", x++);
}
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void func(int a)
{
	printf("a = %d\n", a);
}

int main()
{
	int b = 90;
	func(b++);
}
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int x = 20;
	int y;

	/*y = x;
	x = x + 1;*/
	y = x++;

	printf("y = %d\n", y);
	printf("x = %d\n", x);
}
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int x = 20;

	printf("%d\n", x++);  //20
	printf("%d\n", ++x);  //22
	printf("%d\n", x++);  //22
	printf("%d\n", ++x);  //24
	printf("x = %d\n", x);
}
```
