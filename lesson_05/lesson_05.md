# Fonksiyonlar

```text
to define a function
function definition
fonksiyonu tanımlamak

to call a function
function call
fonksiyonu çağırmak

to declare a function
function declaration
fonksiyonu bildirmek
```



## C dilindeki implicit int kurali

```text
örtülü int
gizli int
kapalı int

Fonksiyona bildiriminde geri donus turu belirtilmez ise 
varsayilan olarak return type'i int olur.
```

```c
//warning C4431: missing type specifier - int assumed.
//Note: C no longer supports default-int

func()
{
	return 1;
}
```


## Statements of C

```text
Expression Statement (ifade deyimi)
    3;
    x;
    ++x;
    x + 5;
    a = b * b + c * c;

Compound Statement  (bileşik deyim)
    {
        temp = x;
        x = y;
        y = temp;
     }

Null Statement  (boş deyim)
    while (expr)
        ;

Control Statement (kontrol deyimi)

```




### Control Statements of C

```text
if statement

while statement
do while statement
for statement

switch statement
goto statement

continue statement
break statement
return statement
```

### Return Statement

```text
return expr;
    return 1;
    return x * x + y * y > 0;
    
return;
    void func(int x)
    {
    	statement1;
    	statement2;
    	
    	if (x > 5)
    		return;
    		
    	statement3;
    	statement4;
    }
```

```c
// Oneliner Func

int sum(int x, int y)
{
	return x + y;
}
```




# Redundant Else Usage

```c
int max2(int x, int y)
{
	if (x > y)
		return x;
	else
		return y;
}
//-----------------------------

int max2(int x, int y)
{
	if (x > y)
		return x;

	return y;
}
//-----------------------------

int max2(int x, int y)
{
	return x > y ? x : y;
}
```

```c
int absolute(int x)
{
	if (x > 0)
		return x;

	return -x;
}
//--------------------------

int absolute(int x)
{
	return x > 0 ? x : -x;
}
//--------------------------
```

```c
int max3(int a, int b, int c)
{
	int max = a;

	if (b > max)
		max = b;

	if (c > max)
		max = c;

	return max;
}
```

```c
// Finding Number of Digits
int ndigit(int x)
{
	int count = 0;

	if (x == 0)
		return 1;

	while (x != 0) {
		++count;
		x /= 10;
	}

	return count;
}
```


```c
int sum_digit(int x)
{
	int sum = 0;

	while (x != 0) {
		sum += x % 10;
		x /= 10;
	}

	return sum;
}
```


```text
C ve C++ dillerinde İngilizcede "nested function" ya da "local function" denilen
fonksiyon modeli yok. Bir fonksiyonun içinde başka bir fonksiyon tanımlanamaz.
Tüm fonksiyonlar birbirlerinin dışında global isim alanında tanımlanmak zorundadir.


C dilinde (varsayılan şekilde) tüm fonksiyon çağrıları (call by value) (değerle çağrı)
modelindedir.

C'de call be reference (referansla çağrı) ancak pointer (adres) semantiği ile yapılabilir:

```

```c
#include <stdio.h>

void func(int x)
{
	x = 9999;
}

int main()
{
	int y = 33;

	func(y);

	printf("y = %d\n", y);
}
```

```c
#include <stdio.h>

void func(int* p)
{
	*p = 9999;
}

int main()
{
	int y = 33;

	func(&y);

	printf("y = %d\n", y);
}
```


## To discard the return value

```text
Fonksiyonun geri dönüş değeri olmasına karşın çağıran kodun
bu geri dönüş değerini kullanmaması
```


```text
1. Fonksiyonun varlık nedeni hesaplanan bir değer
    Dikkat!!! böyle bir fonksiyon çağırdığınızda mutlaka geri dönüş değerini kullanmalısınız

2. Test fonksiyonları
    Geri dönüş değeri bir soruya verilen boolean yanıttir.
    doğru / yanlış
    evet / hayır
    geçerli / geçersiz

    int isprime(int val);
    _Bool isprime(int val);


3. Geri dönüş değeri başarı bilgisi olan fonksiyonlar
    0 --> Basarili
    1 --> Basarisiz
```
