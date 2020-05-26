# Character Literals (Karakter Sabitleri)

```text
C dilinde karakter sabitlerinin türü int türüdür
C++ dilinde karakter sabitlerinin türü char türüdür

'A'   bu bir sabit
'A'   bu bir karakter sabiti
'A'   bu sabitin türü int
'A'   bu sabitin değeri

'A'    // int
'0x1A' // hex
'012'  // Binary

Asagidaki bildirimlerin turu double turudur.
    564.
    5.
    5.0
    0.5
    .5

34F //gecersiz
34.F //gecerli türü float
34.f //gecerli türü float
```


```c++
#include <iostream>

// int türü 4 byte long türü 4 byte

int main()
{
	using namespace std;

	cout << typeid(3.4f).name() << "\n";	//float
	cout << typeid(3.4F).name() << "\n";	//float
	cout << typeid(3.F).name() << "\n";		//float
	cout << typeid(3f).name() << "\n";	//gecersiz
}
```


```text
34    ---> int      
34u   ---> unsigned int 
34L   ---> long  
34LU  ---> unsigned long  
34LL  ---> long long  
34LLU ---> unsigned long long  
-----------------------------
3.4   ---> double  
3.4F  ---> float
3.4L  ---> long double 
```

```text
0    ---> int 
0U   ---> unsigned int
0L   ---> long 
0LU  ---> unsigned long
-----------------------
0.   ---> double
0.F  ---> float
0.L  ---> long double
```


```text
Matematiksel Gosterim
    2.3e4 ---> 2.3 x 10^4
```


## Character Encoding

```text
66 65 66 65
B  A  B  A
```

```c
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    FILE * f;

    if ((f = fopen("../src/ascii.txt", "w")) == NULL){
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < 128; ++i) {
        if (iscntrl(i))
            fprintf(f, "0x%02X  %3d  Control Character\n", i, i); //Control Characters are not printable
        else
            fprintf(f, "0x%02X  %3d   %c\n", i, i, i);
    }

    fclose(f);

    return 0;
}
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    printf("null character  = 0x%02X %3d %c\n", '\0', '\0', '\0');
    printf("alert           = 0x%02X %3d %c\n", '\a', '\a', '\a');
    printf("newline         = 0x%02X %3d %c\n", '\n', '\n', '\n');
    printf("horizontal  tab = 0x%02X %3d %c\n", '\t', '\t', '\t');
    printf("vertical tab    = 0x%02X %3d %c\n", '\v', '\v', '\v');
    printf("carriage return = 0x%02X %3d %c\n", '\r', '\r', '\r');
    printf("backspace       = 0x%02X %3d %c\n", '\b', '\b', '\b');
    printf("form feed       = 0x%02X %3d %c\n", '\f', '\f', '\f');
    printf("back slash      = 0x%02X %3d %c\n", '\\', '\\', '\\');
    printf("single quote    = 0x%02X %3d %c\n", '\'', '\'', '\'');
    printf("double quote    = 0x%02X %3d %c\n", '\"', '\"', '\"');
    printf("double quote    = 0x%02X %3d %c\n", '"' , '"' , '"' );
    printf("question mark   = 0x%02X %3d %c\n", '\?', '\?', '\?');
    printf("question mark   = 0x%02X %3d %c\n", '?' , '?' , '?' );

    return 0;
}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main()
{
	int ival = 652131324;
	int ival = 652'131'324;
	int ival = 0b0101'1111'0101;
}
```


# Input - Output Operations

```text
Standard input

prog > ali.txt
prog < ali.txt

formatted input / output
unformatted input / output
```

## Endianness
```text
little endian

0000 0001		4000
0000 0000		4001
0000 0000		4002
0000 0000		4003

0x41A291F5

little endian
f5
91
a2
41

big endian
41
a2
91
f5
```

```c
#include <stdio.h>

void check_system_endianness(void)
{
    unsigned int uval = 1u;

    char * p = (char *)&uval;

    if (*p == 1)
        printf("Your system is Little endian\n");
    else
        printf("Your system is Big endian\n");
}

int main(void)
{
    check_system_endianness();

    return 0;
}
```


## Printf Fonksiyonu

```text
    void func(int x, int y, ...);

Formatli olarak ciktiyi standart outputa yazdirir.

sayı sistemi
tür
showbase
showpos
uppercase
output width (yazma alanı genisligi)
fill character
left/right/internal

nokta yazilacak  showpoint
noktadan sonra kaç basamak yazilacak
fixed / scientific
```


```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	printf("\x42URS\x41");            // Prints BURSA
	printf("\102\101\102\101\012");   // Prints BURSA
	printf("\tahmet\n\tmehmet\n\thasan\n");
}
```


## Conversion Specifiers
```text
%d  ---> decimal
%x  ---> hex
%X  ---> HEX
%o  ---> Octal
%ld ---> double
%f  ---> float
%u  ---> unsigned
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	INT16 x = -1;
    printf("x = %hd\n", x); // x = -1
    printf("x = %hu\n", x); // x = 65535
}
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int x = 111264;

	printf("x as decimal = %d\n", x);
	printf("x as hex     = %x\n", x);
	printf("x as HEX     = %X\n", x);
	printf("x as octal   = %o\n", x);
}
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int x = 9187321;

	printf("%d\n%o\n%x\n", x, x, x);
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

	printf("%d * %d + %d * %d = %d\n", x, x, y, y, x * x + y * y);
}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

int main()
{
	for (int i = 0; i <= 100; ++i) {
		printf("%3d  %f\n", i, sqrt(i));
	}
}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

int main()
{
	int x;

	printf("bir tamsayi giriniz: ");
	scanf("%d", &x);

	int n = printf("deger = %d\n", x);
	printf("n = %d\n", n);

}
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int x = 98765;

	printf("%d", printf("%d", printf("%d", x)));

}
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int max2(int x, int y)
{
	return x > y ? x : y;
}

int main()
{
	int x, y, z, t;

	printf("4 sayi girin: ");
	scanf("%d%d%d%d", &x, &y, &z, &t);
	printf("%d\n", max2(max2(x, y), max2(z, t)));

}
```

## Scanf Function

```text
Scanf is a line buffered input function
Yani girdinin tamamlanmasi icin standard input bufferina newline ('\n') gelmesini  bekler.

>> BABA -->Enter
66 'B' 
65 'A'
66 'B'
65 'A'
0  '\n'
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int x, y, z, t;

	printf("bir giris yapin: ");
	scanf("%d", &x);
	scanf("%d", &y);
	scanf("%d", &z);
	scanf("%d", &t);

	printf("x = %d\n", x);
	printf("y = %d\n", y);
	printf("z = %d\n", z);
	printf("t = %d\n", t);
}
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int x;

	for (int i = 0; i < 4; ++i) {
		scanf("%d", &x);
		printf("girilen sayi : %d\n", x);
	}
}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int main()
{
	int x, y, z;

	printf("uc tamsayi giriniz: ");
	int retval = scanf("%d%d%d", &x, &y, &z);

	printf("retval = %d\n", retval);
}
```
