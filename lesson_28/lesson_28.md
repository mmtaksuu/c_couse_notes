<locale.h> header file
----------------------


```c
#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <stdio.h>
#include <locale.h>

int main()
{
	char *p = setlocale(LC_ALL, "turkish");
	if (!p) {
		printf("locale degisikligi yapilamadi\n");
		return 1;
	}

	printf("locale degistirildi yeni locale: (%s)\n", p);

	double d;

	printf("bir gercek sayi giriniz: ");
	scanf("%lf", &d);
	printf("d = %f\n", d);

}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <stdio.h>
#include <locale.h>
#include <time.h>

#define   SIZE      100

int main()
{
	char *p = setlocale(LC_ALL, "polish");
	if (!p) {
		printf("locale degisikligi yapilamadi\n");
		return 1;
	}

	char buffer[SIZE];
	time_t timer;
	time(&timer);
	strftime(buffer, SIZE, "%d %A %B %Y", localtime(&timer));
	puts(buffer);
}
```



```c
#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include "nutility.h"

#define   SIZE      100

//   dogancan  can

int is_at_end(const char *p1, const char *p2)
{
	size_t lenp1 = strlen(p1);
	size_t lenp2 = strlen(p2);
	if (lenp2 > lenp1)
		return 0;

	return !strcmp(p1 + lenp1 - lenp2, p2);
}

int main()
{
	char s1[SIZE];
	char s2[SIZE];

	printf("birinci yaziyi girin: ");
	sgets(s1);
	printf("ikinci yaziyi girin: ");
	sgets(s2);

	printf("(%s) (%s)\n", s1, s2);

	if (is_at_end(s1, s2))
		printf("evet var\n");
	else
		printf("hayir yok\n");

}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include "nutility.h"

#define   SIZE      100

//   dogancan  can


char *trim(char *p);

//trim islevi yazinin basindaki ve sonundak, bosluk karakterlerini siler
//bosluk = isspace(c) ----> true
//işlevin geri dönüş değeri p
//işleve NULL ptr gönderilmesi ub


int main()
{
	char str[SIZE];

	printf("bir yazi giriniz: ");
	sgets(str);
	printf("[%s]\n", str);
	//printf("[%s]\n", trim(str));
}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include "nutility.h"

#define   SIZE      100

//   dogancan  can


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
#include <conio.h>

int main()
{
	FILE *f = fopen("necco.txt", "r");
	///....
	int c;

	while ((c = fgetc(f)) != EOF) {
		printf("%d ", c);
		_getch();
	}

	fclose(f);

}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <string.h>

char *strpbrk1(const char *p1, const char *p2)
{
	while (*p1 != '\0') {
		if (strchr(p2, *p1))
			return (char*)p1;
		++p1;
	}
	return NULL;
}

int main()
{
	char str[1000];
	char s[] = "0123456789";

	printf("bir yazi girin: ");
	sgets(str);
	char *p = strpbrk1(str, s);
	if (!p) {
		printf("bulunamadi\n");
	}
	else {
		printf("BULUNDU idx = %d  (%s)\n", p - str, p);
		*p = '*';
		puts(str);
	}


}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>


int stricmp1(const char *p1, const char *p2)
{
	while (toupper(*p1) == toupper(*p2)) {
		if (*p1 == '\0')
			return 0;
		++p1;
		++p2;
	}

	return toupper(*p1) - toupper(*p2);
}

int strcmp1(const char *p1, const char *p2)
{
	while (*p1 == *p2) {
		if (*p1 == '\0')
			return 0;
		++p1;
		++p2;
	}

	return *p1 - *p2;
}

int main()
{
	char s1[100];
	char s2[100];

	printf("iki kelime girin: ");
	scanf("%s%s", s1, s2);

	if (!_stricmp(s1, s2))
		printf("evet esit\n");
	else
		printf("hayir esit degil\n");



}
```



String Literals
---------------

"mustafa"

C'de bir string literali derleyici tarafından oluşturulan
bir char dizidir. Bu dizinin boyutu literaldeki karakter
sayısı + 1 değeridir.
Bir string literali bir ifade icinde kullanıldığında
"array to pointer conversion" (array decay) kuralı gereği
dizinin ilk öğesinin adresine dönüştürülür
Bu konuda C ve C++ dilleri arasında kural farklılığı var

"kaya" ifadesinin türü C'de char[5]
"kaya" ifadesinin türü dönüşümden sonra char *

"kaya" ifadesinin türü C++'da const char[5]
"kaya" ifadesinin türü dönüşümden sonra const char *

string literalleri statik ömürlü dizilerdir.
string literallerini değiştirme girişimi tanımsız davranıştır

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>


int main()
{
	putchar(*"dogancan");
	putchar("ibrahim"[3]);
}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	printf("%d\n", 3["coders"] - 2["coders"]);
	printf("%d\n", "coders"[3] - "coders"[2]);
}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	printf("%zu\n", strlen("cenk"));
}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	char str[10] = { 0 };
	for (int i = 0; i < 10; ++i) {
		printf("%p\n", "neco");
		//printf("%p\n", str);
	}
}
```

```c
#define _CRT_SECURE_NO_WARNINGS


int main()
{
	//C++ dilinde

	//"kaya"[0] = 'm'; //gecersiz (const dizi)
	char *p = "mustafa"; //gecersiz const char * -----> char * dönüşümü yok

}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main()
{
	char *p = "dert";

	*p = 'M'; //ub

	puts(p);
}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>


int main()
{
	char str[100];
	int x = 10;


	//
	x = 5;
	strcpy(str, "ayberk");


}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>


int main()
{
	char str[100] = "nur";
	char *p = "seda";

	strcat(p, str); //ub

}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>


int main()
{
	char *p = "alican";

	_strrev(p); //ub

}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>


int main()
{
	char s[100] = "cenk";
	char *p = "han";

	strcat(s, p);

}
```


```c
void func()
{
	//char str[] = "nurcan";
	const char *p = "nurdan";

}

int main()
{

}
```


```c
#include <stdio.h>

const char *get_day_name(int weekday)
{
	switch (weekday) {
	case 1: return "pazartesi";
	case 2: return "sali";
	case 3: return "carsamba";
	case 4: return "persembe";
	case 5: return "cuma";
	case 6: return "cumartesi";
	case 7: return "pazar";
	}

	return NULL;
}


int main()
{
	int n;

	printf("haftanin kacinci gunu: ");
	scanf("%d", &n);
	printf("haftanin %d. gunu %s\n", n, get_day_name(n));

}
```


```c
#include <stdio.h>

int get_hexchar(int val)
{
	return "0123456789ABCDEF"[val];
}

//int get_hexchar(int val)
//{
//	if (val < 10)
//		return '0' + val;
//
//	return val - 10 + 'A';
//}


int main()
{
	for (int i = 0; i < 16; ++i) {
		putchar(get_hexchar(i));
	}

}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main()
{
	char *p1 = "serafettin";
	///

	char *p2 = "serafettin";

	if (p1 == p2)
		printf("dogru\n");
	else
		printf("yanlis\n");
}
```



char str[100];


if (str == "necati")

'a'    "a"

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>


#define   SIZE      100

int main()
{
	char old_file_name[SIZE];
	char new_file_name[SIZE];

	printf("dosya ismi : ");
	scanf("%s", old_file_name);
	strcpy(new_file_name, old_file_name);
	///eger dosya isminin uzantisi yok ise uzantisi .txt yapilacak [1]
	///eger dosya isminin uzantisi .jpg  uzantisi .gif yapilacak [2]
	///eger dosya isminin uzantisi .dat  ise uzantisi silinecek [3]
	///eger dosya isminin uzantisi yuk. farkli ise uzantisi .xls yapilacak [4]
	char *ptr = strrchr(new_file_name, '.');
	if (!ptr) {
		strcat(new_file_name, ".txt");
	}
	else if (!strcmp(ptr, ".jpg")) {
		strcpy(ptr, ".gif");
	}
	else if (!strcmp(ptr, ".dat")) {
		*ptr = '\0';
	}
	else {
		strcpy(ptr, ".xls");
	}



	printf("(%s)  (%s)\n", old_file_name, new_file_name);
}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>


#define   SIZE      100

int main()
{
	char old_file_name[SIZE];
	char new_file_name[SIZE];

	printf("dosya ismi : ");
	scanf("%s", old_file_name);


	strcpy(new_file_name, old_file_name);
	char *ptr = strrchr(new_file_name, '.');
	if (!ptr) {
		strcat(new_file_name, ".txt");
	}
	else if (!strcmp(ptr, ".jpg")) {
		strcpy(ptr, ".gif");
	}
	else if (!strcmp(ptr, ".dat")) {
		*ptr = '\0';
	}
	else {
		strcpy(ptr, ".xls");
	}



	printf("(%s)  (%s)\n", old_file_name, new_file_name);
}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>


#define   SIZE      100

int main()
{
	const char *pmsg = "su anda tum hatalarimiz dolu oldugundan \
musteri temsilcilerimiz size yanit veremiyor en erken bes dakika icinde \
hizmet alabileceksiniz. simdi ayni mesaji ";

	puts(pmsg);

}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>


int main()
{
	char *p = "dogancan"
		"ahmet"
		"hilal"
		"murat"
		"necati";

	puts(p);

}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int main()
{

	printf("[1] Kayit Ekle\n"
		"[2] Kayit sil\n"
		"[3] Kayit Degistir\n"
		"[4] Kayit Yoket\n"
		"[5] Kayit Ara\n"
		"[6] Programdan Cik\n");

}
```
