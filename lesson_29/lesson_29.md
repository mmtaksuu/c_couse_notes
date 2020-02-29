Lesson 29
---------

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int main()
{
	//puts("\x42URS\x41");
	//puts("\x42abadede");
	//puts("\1015233212");
	puts("\10220\101231\103");

}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int main()
{
	//puts("\x42URS\x41");
	//puts("\x42abadede");
	//puts("\1015233212");
	puts("\10220\101231\103");

}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main()
{

	puts(R"(She blushed, smile on her face.
And this woman wanted him to kiss it off, to stay in a classroom?
Lisa put the phone back to her ear, still watching Yancey cautiously.
The schools were reorganized in 1917 as a result of a " survey."
"Yes", mother," he said, "I will watch her every minute.)");
}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int main()
{
	int a[sizeof "ali"];
	int a[strlen("ali")];

}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int main()
{
	printf("%zu\n", sizeof "ali");
	printf("%zu\n", strlen("ali"));
	printf("%zu\n", sizeof "");
	printf("%zu\n", strlen(""));
}
```



Endianness
----------

```text

int main()
{
	int x = 15; // 4 bytes
}
MSB                                     LSB
  0000 0000 0000 0000 0000 0000 0000 1111
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int x = 1;
	char *p = (char *)&x;

	if (*p != 0)
		printf("little endian\n");
	else
		printf("big endian\n");
}
```

```text
int main()
{
	int x = 1; // 4 bytes
}
MSB                                     LSB
  0000 0000 0000 0000 0000 0000 0000 0001

Sistemde tanimlanan bir degiskenin dusuk anlamli biti "LSB" 
yuksek sayisal adreste tutuluyor ise little endian mimaridir.

Big endian 
4000   0000 0000
4001   0000 0000
4002   0000 0000
4003   0000 0001

Little endian
4000   0000 0001
4001   0000 0000
4002   0000 0000
4003   0000 0000
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int x = 1;

	if (*(char*)&x)
		printf("little endian\n");
	else
		printf("big endian\n");
}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	unsigned int x = 0x12AE23BF;
	unsigned char* p = (unsigned char *)&x;

	printf("%X\n", *p++);
	printf("%X\n", *p++);
	printf("%X\n", *p++);
	printf("%X\n", *p);
}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	unsigned int x = 0x12AE23BF;
	unsigned char* p = (unsigned char *)&x;

	printf("%X\n", *p++);
	printf("%X\n", *p++);
	printf("%X\n", *p++);
	printf("%X\n", *p);
}
```




Pointer Arrays 
--------------

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "nutility.h"

int x = 20;
int y = 30;
int z = 50;

int main()
{
	//ismi p olan diziye x, y, z nesnelerinin adresleri ile ilk değer verin
	int *p[] = { &x, &y, &z };
	printf("boyut p = %zu\n", asize(p));

	//p dizisinin 2 indisli öğesinin gösterdiği nesnenin değerini bir artırın
	++*p[2];
	printf("z = %d\n", z);

}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "nutility.h"

double x = 2.0;
double y = 3.0;
double z = 5.0;

int main()
{
	//ismi p olan diziye x, y, z nesnelerinin adresleri ile ilk değer verin
	double *p[] = { &x, &y, &z };

	printf("%zu\n", sizeof(p));  //12
	printf("%zu\n", sizeof(*p));  //4
	printf("%zu\n", sizeof(**p));  //8
}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "nutility.h"

double x = 2.0;
double y = 3.0;
double z = 5.0;

int main()
{
	//ismi p olan diziye x, y, z nesnelerinin adresleri ile ilk değer verin
	double *p[] = { &x, &y, &z };

	printf("%zu\n", sizeof(p));  //12
	printf("%zu\n", sizeof(*p));  //4
	printf("%zu\n", sizeof(p[0]));  //4
	printf("%zu\n", sizeof(**p));  //8

}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "nutility.h"

int a[5] = { 5, 5, 5, 5, 5 };
int b[4] = { 4, 4, 4, 4};
int c[3] = { 3, 3, 3};

int main()
{
	int *p[] = { a, b, c };

	++p[1];

	++*p[1];
	display_array(a, 5);
	display_array(b, 4);
	display_array(c, 3);
}
```


Bitsel Karsilastirma
--------------------
```text

x &= ~(1 << n); 
x |= (1 << n);
x ^= (1 << n);
if (x & (1 << n))

100101010?01010100101001001010010100010
000000000100000000000000000000000000000
000000000000000000000000000000000000000
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "nutility.h"
#include <stdint.h>

int main()
{
	const char *pmons[] = {
	"Ocak",
	"Subat",
	"Mart",
	"Nisan",
	"Mayis",
	"Haziran",
	"Temmuz",
	"Agustos",
	"Eylul",
	"Ekim",
	"Kasim",
	"Aralik"
	};

	for (size_t i = 0; i < asize(pmons); ++i)
		printf("%s\n", pmons[i]);
}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "nutility.h"
#include <stdint.h>

int main()
{
	const char *pmons[] = {
	"",
	"Ocak",
	"Subat",
	"Mart",
	"Nisan",
	"Mayis",
	"Haziran",
	"Temmuz",
	"Agustos",
	"Eylul",
	"Ekim",
	"Kasim",
	"Aralik"
	};

	int n;

	printf("yilin kacinci ayi : ");
	scanf("%d", &n);
	printf("yilin %d. ayi %s\n", n, pmons[n]);
}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#include "nutility.h"

int main()
{
	const char *pmons[] = {
	"Ocak",
	"Subat",
	"Mart",
	"Nisan",
	"Mayis",
	"Haziran",
	"Temmuz",
	"Agustos",
	"Eylul",
	"Ekim",
	"Kasim",
	"Aralik"
	};

	char entry[40];

	printf("bir ay ismi girin: ");
	scanf("%s", entry);
	size_t i;

	for (i = 0; i < asize(pmons); ++i) {
		if (!_stricmp(pmons[i], entry))
			break;
	}

	if (i < asize(pmons)) {
		printf("%s yilin %d. ayi\n", entry, i + 1);
	}
	else
		printf("%s gecerli bir ay ismi degil\n", entry);

}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <conio.h>
#include "nutility.h"

int main()
{
	const char *pmons[] = {
	"Ocak",
	"Subat",
	"Mart",
	"Nisan",
	"Mayis",
	"Haziran",
	"Temmuz",
	"Agustos",
	"Eylul",
	"Ekim",
	"Kasim",
	"Aralik"
	};

	for (;;) {
		printf("%s ", pmons[rand() % asize(pmons)]);
		_getch();

	}

}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <conio.h>
#include "nutility.h"

int a = 10;
int b = 20;
int c = 56;
int d = 33;

int main()
{
	int *const p[] = { &a, &b, &c, &d };
	int x = 356;

	//p[2] = &x;  //gecersiz
	*p[2] = 666;  //gecerli

}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <conio.h>
#include "nutility.h"

int a = 10;
int b = 20;
int c = 56;
int d = 33;

int main()
{
	int const * p[] = { &a, &b, &c, &d };
	//const int * p[] = { &a, &b, &c, &d };

	int x = 356;

	p[2] = &x;  //gecerli
	*p[2] = 666;  //gecersiz

}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <conio.h>
#include "nutility.h"

int a = 10;
int b = 20;
int c = 56;
int d = 33;

int main()
{
	int const *const p[] = { &a, &b, &c, &d };


	p[2] = &x;  //gecersiz
	*p[2] = 666;  //gecersiz

}
```



```c
#include <stdio.h>
#include <string.h>

#include "nutility.h"


const char *p[] = {
		"Kamil", "Korhan", "Beril", "Turhan", "Ufuk", "Murathan", "Figen", "Malik", "Bulent", "Cengiz",
"Baran", "Nurullah", "Dilber", "Tuncer", "Recep", "Pelinsu", "Cihan", "Yesim", "Aziz", "Kazim",
"Afacan", "Tevfik", "Sumeyye", "Hande", "Aslihan", "Emine", "Temel", "Gulsah", "Hasan", "Gul",
"Soner", "Ayla", "Cuneyt", "Tekin", "Binnaz", "Emrecan", "Yasar", "Yilmaz", "Feraye", "Tugra",
"Melek", "Garo", "Yurdagul", "Tarik", "Derin", "Handan", "Aytac", "Petek", "Cem", "Aylin",
"Gursel", "Haldun", "Nazife", "Hulusi", "Sevilay", "Sabriye", "Gulden", "Tansel", "Ege", "Turgut",
"Cahit", "Berk", "Nazli", "Aykut", "Kayhan", "Cemre", "Murat", "Kunter", "Gunay", "Cahite",
"Nedim", "Metin", "Kerim", "Utku", "Cumhur", "Kurthan", "Poyraz", "Can", "Candan", "Hikmet",
"Izzet", "Perihan", "Tufan", "Zahide", "Samet", "Melih", "Hakan", "Ayse", "Refik", "Efe",
"Belgin", "Bilal", "Niyazi", "Fugen", "Melike", "Saadet", "Cemile", "Nahit", "Arda", "Ugur",
"Aynur", "Yasin", "Polat", "Naz", "Yusuf", "Gulsen", "Nazif", "Demir", "Egemen", "Necmi",
"Fazilet", "Celal", "Ismail", "Kamile", "Mahir", "Caner", "Suleyman", "Cezmi", "Diana", "Sadullah",
"Atif", "Huseyin", "Necmettin", "Devlet", "Sezen", "Hulya", "Necmiye", "Ece", "Julide", "Onat",
"Emre", "Sinem", "Teoman", "Irmak", "Cihat", "Adem", "Bilgin", "Muzaffer", "Suphi", "Pelin",
"Yalcin", "Kenan", "Atalay", "Akin", "Durmus", "Haluk", "Kelami", "Alparslan", "Busra", "Kasim",
"Durriye", "Tarcan", "Nihal", "Gizem", "Bilge", "Dilek", "Yasemin", "Fahri", "Furkan", "Papatya",
"Hakki", "Fadime", "Devrim", "Abdi", "Tayyip", "Yurdakul", "Zekai", "Nagehan", "Ata", "Naci",
"Mert", "Yelda", "Cebrail", "Rumeysa", "Beyhan", "Azize", "Cemil", "Sezer", "Beste", "Ciler",
"Enes", "Cahide", "Tayyar", "Cansu", "Burak", "Ediz", "Sefa", "Anil", "Alev", "Atil",
"Nefes", "Cetin", "Tansu", "Bora", "Sevim", "Sarp", "Fuat", "Kaya", "Zarife", "Tanju",
"Su", "Kerem", "Handesu", "Jade", "Halime", "Gurbuz", "Okan", "Azmi", "Sevda", "Leyla",
"Galip", "Alican", "Atakan", "Feramuz", "Efecan", "Osman", "Nihat", "Sefer", "Zerrin", "Binnur",
"Taner", "Kayahan", "Nalan", "Tonguc", "Kezban", "Kaan", "Abdulmuttalip", "Dost", "Deniz", "Refika",
"Tijen", "Umit", "Yunus", "Zahit", "Melisa", "Hulki", "Hilmi", "Edip", "Muslum", "Canan",
"Dogan", "Berivan", "Adnan", "Helin", "Fikret", "Derya", "Sidre", "Abdullah", "Billur", "Nurdan",
"Agah", "Engin", "Burhan", "Suheyla", "Esra", "Sadri", "Sezai", "Esen", "Askin", "Rupen",
"Ercument", "Birhan", "Ahmet", "Polathan", "Tayfun", "Mustafa", "Zubeyde", "Pakize", "Nevsin", "Naciye",
"Erdem", "Asim", "Orkun", "Sami", "Sade", "Demet", "Keriman", "Yavuz", "Mehmet", "Muhsin",
"Saniye", "Cesim", "Aydan", "Eda", "Hilal" ,"Burak", "Taylan", "Fedai", "Ilke", "Dogancan",	"Rezzan",
"Ozer", "Tacettin", "Nurettin", "Seyfettin", "Safiye", "Aydin", "Latife", "Sercan", "Benfero"
};

int main()
{
	for (size_t i = 0; i < asize(p); ++i) {
		printf("%-16s %zu\n", p[i], strlen(p[i]));
	}

}
```


```c
#include <stdio.h>
#include <string.h>

#include "nutility.h"


const char *p[] = {
		"Kamil", "Korhan", "Beril", "Turhan", "Ufuk", "Murathan", "Figen", "Malik", "Bulent", "Cengiz",
"Baran", "Nurullah", "Dilber", "Tuncer", "Recep", "Pelinsu", "Cihan", "Yesim", "Aziz", "Kazim",
"Afacan", "Tevfik", "Sumeyye", "Hande", "Aslihan", "Emine", "Temel", "Gulsah", "Hasan", "Gul",
"Soner", "Ayla", "Cuneyt", "Tekin", "Binnaz", "Emrecan", "Yasar", "Yilmaz", "Feraye", "Tugra",
"Melek", "Garo", "Yurdagul", "Tarik", "Derin", "Handan", "Aytac", "Petek", "Cem", "Aylin",
"Gursel", "Haldun", "Nazife", "Hulusi", "Sevilay", "Sabriye", "Gulden", "Tansel", "Ege", "Turgut",
"Cahit", "Berk", "Nazli", "Aykut", "Kayhan", "Cemre", "Murat", "Kunter", "Gunay", "Cahite",
"Nedim", "Metin", "Kerim", "Utku", "Cumhur", "Kurthan", "Poyraz", "Can", "Candan", "Hikmet",
"Izzet", "Perihan", "Tufan", "Zahide", "Samet", "Melih", "Hakan", "Ayse", "Refik", "Efe",
"Belgin", "Bilal", "Niyazi", "Fugen", "Melike", "Saadet", "Cemile", "Nahit", "Arda", "Ugur",
"Aynur", "Yasin", "Polat", "Naz", "Yusuf", "Gulsen", "Nazif", "Demir", "Egemen", "Necmi",
"Fazilet", "Celal", "Ismail", "Kamile", "Mahir", "Caner", "Suleyman", "Cezmi", "Diana", "Sadullah",
"Atif", "Huseyin", "Necmettin", "Devlet", "Sezen", "Hulya", "Necmiye", "Ece", "Julide", "Onat",
"Emre", "Sinem", "Teoman", "Irmak", "Cihat", "Adem", "Bilgin", "Muzaffer", "Suphi", "Pelin",
"Yalcin", "Kenan", "Atalay", "Akin", "Durmus", "Haluk", "Kelami", "Alparslan", "Busra", "Kasim",
"Durriye", "Tarcan", "Nihal", "Gizem", "Bilge", "Dilek", "Yasemin", "Fahri", "Furkan", "Papatya",
"Hakki", "Fadime", "Devrim", "Abdi", "Tayyip", "Yurdakul", "Zekai", "Nagehan", "Ata", "Naci",
"Mert", "Yelda", "Cebrail", "Rumeysa", "Beyhan", "Azize", "Cemil", "Sezer", "Beste", "Ciler",
"Enes", "Cahide", "Tayyar", "Cansu", "Burak", "Ediz", "Sefa", "Anil", "Alev", "Atil",
"Nefes", "Cetin", "Tansu", "Bora", "Sevim", "Sarp", "Fuat", "Kaya", "Zarife", "Tanju",
"Su", "Kerem", "Handesu", "Jade", "Halime", "Gurbuz", "Okan", "Azmi", "Sevda", "Leyla",
"Galip", "Alican", "Atakan", "Feramuz", "Efecan", "Osman", "Nihat", "Sefer", "Zerrin", "Binnur",
"Taner", "Kayahan", "Nalan", "Tonguc", "Kezban", "Kaan", "Abdulmuttalip", "Dost", "Deniz", "Refika",
"Tijen", "Umit", "Yunus", "Zahit", "Melisa", "Hulki", "Hilmi", "Edip", "Muslum", "Canan",
"Dogan", "Berivan", "Adnan", "Helin", "Fikret", "Derya", "Sidre", "Abdullah", "Billur", "Nurdan",
"Agah", "Engin", "Burhan", "Suheyla", "Esra", "Sadri", "Sezai", "Esen", "Askin", "Rupen",
"Ercument", "Birhan", "Ahmet", "Polathan", "Tayfun", "Mustafa", "Zubeyde", "Pakize", "Nevsin", "Naciye",
"Erdem", "Asim", "Orkun", "Sami", "Sade", "Demet", "Keriman", "Yavuz", "Mehmet", "Muhsin",
"Saniye", "Cesim", "Aydan", "Eda", "Hilal" ,"Burak", "Taylan", "Fedai", "Ilke", "Dogancan",	"Rezzan",
"Ozer", "Tacettin", "Nurettin", "Seyfettin", "Safiye", "Aydin", "Latife", "Sercan", "Benfero"
};

int main()
{
	for (size_t i = 0; i < asize(p); ++i) {
		printf("%c ", p[i][0]);
		//printf("%c ", *p[i]);
	}

}
```


```c
#include <stdio.h>
#include <string.h>

#include "nutility.h"


const char *p[] = {
		"Kamil", "Korhan", "Beril", "Turhan", "Ufuk", "Murathan", "Figen", "Malik", "Bulent", "Cengiz",
"Baran", "Nurullah", "Dilber", "Tuncer", "Recep", "Pelinsu", "Cihan", "Yesim", "Aziz", "Kazim",
"Afacan", "Tevfik", "Sumeyye", "Hande", "Aslihan", "Emine", "Temel", "Gulsah", "Hasan", "Gul",
"Soner", "Ayla", "Cuneyt", "Tekin", "Binnaz", "Emrecan", "Yasar", "Yilmaz", "Feraye", "Tugra",
"Melek", "Garo", "Yurdagul", "Tarik", "Derin", "Handan", "Aytac", "Petek", "Cem", "Aylin",
"Gursel", "Haldun", "Nazife", "Hulusi", "Sevilay", "Sabriye", "Gulden", "Tansel", "Ege", "Turgut",
"Cahit", "Berk", "Nazli", "Aykut", "Kayhan", "Cemre", "Murat", "Kunter", "Gunay", "Cahite",
"Nedim", "Metin", "Kerim", "Utku", "Cumhur", "Kurthan", "Poyraz", "Can", "Candan", "Hikmet",
"Izzet", "Perihan", "Tufan", "Zahide", "Samet", "Melih", "Hakan", "Ayse", "Refik", "Efe",
"Belgin", "Bilal", "Niyazi", "Fugen", "Melike", "Saadet", "Cemile", "Nahit", "Arda", "Ugur",
"Aynur", "Yasin", "Polat", "Naz", "Yusuf", "Gulsen", "Nazif", "Demir", "Egemen", "Necmi",
"Fazilet", "Celal", "Ismail", "Kamile", "Mahir", "Caner", "Suleyman", "Cezmi", "Diana", "Sadullah",
"Atif", "Huseyin", "Necmettin", "Devlet", "Sezen", "Hulya", "Necmiye", "Ece", "Julide", "Onat",
"Emre", "Sinem", "Teoman", "Irmak", "Cihat", "Adem", "Bilgin", "Muzaffer", "Suphi", "Pelin",
"Yalcin", "Kenan", "Atalay", "Akin", "Durmus", "Haluk", "Kelami", "Alparslan", "Busra", "Kasim",
"Durriye", "Tarcan", "Nihal", "Gizem", "Bilge", "Dilek", "Yasemin", "Fahri", "Furkan", "Papatya",
"Hakki", "Fadime", "Devrim", "Abdi", "Tayyip", "Yurdakul", "Zekai", "Nagehan", "Ata", "Naci",
"Mert", "Yelda", "Cebrail", "Rumeysa", "Beyhan", "Azize", "Cemil", "Sezer", "Beste", "Ciler",
"Enes", "Cahide", "Tayyar", "Cansu", "Burak", "Ediz", "Sefa", "Anil", "Alev", "Atil",
"Nefes", "Cetin", "Tansu", "Bora", "Sevim", "Sarp", "Fuat", "Kaya", "Zarife", "Tanju",
"Su", "Kerem", "Handesu", "Jade", "Halime", "Gurbuz", "Okan", "Azmi", "Sevda", "Leyla",
"Galip", "Alican", "Atakan", "Feramuz", "Efecan", "Osman", "Nihat", "Sefer", "Zerrin", "Binnur",
"Taner", "Kayahan", "Nalan", "Tonguc", "Kezban", "Kaan", "Abdulmuttalip", "Dost", "Deniz", "Refika",
"Tijen", "Umit", "Yunus", "Zahit", "Melisa", "Hulki", "Hilmi", "Edip", "Muslum", "Canan",
"Dogan", "Berivan", "Adnan", "Helin", "Fikret", "Derya", "Sidre", "Abdullah", "Billur", "Nurdan",
"Agah", "Engin", "Burhan", "Suheyla", "Esra", "Sadri", "Sezai", "Esen", "Askin", "Rupen",
"Ercument", "Birhan", "Ahmet", "Polathan", "Tayfun", "Mustafa", "Zubeyde", "Pakize", "Nevsin", "Naciye",
"Erdem", "Asim", "Orkun", "Sami", "Sade", "Demet", "Keriman", "Yavuz", "Mehmet", "Muhsin",
"Saniye", "Cesim", "Aydan", "Eda", "Hilal" ,"Burak", "Taylan", "Fedai", "Ilke", "Dogancan",	"Rezzan",
"Ozer", "Tacettin", "Nurettin", "Seyfettin", "Safiye", "Aydin", "Latife", "Sercan", "Benfero"
};

int main()
{
	for (size_t i = 0; i < asize(p); ++i) {
		printf("%c ", p[i][strlen(p[i]) - 1]);
	}

}
```



```c
#include <stdio.h>
#include <string.h>

#include "nutility.h"


const char *p[] = {
		"Kamil", "Korhan", "Beril", "Turhan", "Ufuk", "Murathan", "Figen", "Malik", "Bulent", "Cengiz",
"Baran", "Nurullah", "Dilber", "Tuncer", "Recep", "Pelinsu", "Cihan", "Yesim", "Aziz", "Kazim",
"Afacan", "Tevfik", "Sumeyye", "Hande", "Aslihan", "Emine", "Temel", "Gulsah", "Hasan", "Gul",
"Soner", "Ayla", "Cuneyt", "Tekin", "Binnaz", "Emrecan", "Yasar", "Yilmaz", "Feraye", "Tugra",
"Melek", "Garo", "Yurdagul", "Tarik", "Derin", "Handan", "Aytac", "Petek", "Cem", "Aylin",
"Gursel", "Haldun", "Nazife", "Hulusi", "Sevilay", "Sabriye", "Gulden", "Tansel", "Ege", "Turgut",
"Cahit", "Berk", "Nazli", "Aykut", "Kayhan", "Cemre", "Murat", "Kunter", "Gunay", "Cahite",
"Nedim", "Metin", "Kerim", "Utku", "Cumhur", "Kurthan", "Poyraz", "Can", "Candan", "Hikmet",
"Izzet", "Perihan", "Tufan", "Zahide", "Samet", "Melih", "Hakan", "Ayse", "Refik", "Efe",
"Belgin", "Bilal", "Niyazi", "Fugen", "Melike", "Saadet", "Cemile", "Nahit", "Arda", "Ugur",
"Aynur", "Yasin", "Polat", "Naz", "Yusuf", "Gulsen", "Nazif", "Demir", "Egemen", "Necmi",
"Fazilet", "Celal", "Ismail", "Kamile", "Mahir", "Caner", "Suleyman", "Cezmi", "Diana", "Sadullah",
"Atif", "Huseyin", "Necmettin", "Devlet", "Sezen", "Hulya", "Necmiye", "Ece", "Julide", "Onat",
"Emre", "Sinem", "Teoman", "Irmak", "Cihat", "Adem", "Bilgin", "Muzaffer", "Suphi", "Pelin",
"Yalcin", "Kenan", "Atalay", "Akin", "Durmus", "Haluk", "Kelami", "Alparslan", "Busra", "Kasim",
"Durriye", "Tarcan", "Nihal", "Gizem", "Bilge", "Dilek", "Yasemin", "Fahri", "Furkan", "Papatya",
"Hakki", "Fadime", "Devrim", "Abdi", "Tayyip", "Yurdakul", "Zekai", "Nagehan", "Ata", "Naci",
"Mert", "Yelda", "Cebrail", "Rumeysa", "Beyhan", "Azize", "Cemil", "Sezer", "Beste", "Ciler",
"Enes", "Cahide", "Tayyar", "Cansu", "Burak", "Ediz", "Sefa", "Anil", "Alev", "Atil",
"Nefes", "Cetin", "Tansu", "Bora", "Sevim", "Sarp", "Fuat", "Kaya", "Zarife", "Tanju",
"Su", "Kerem", "Handesu", "Jade", "Halime", "Gurbuz", "Okan", "Azmi", "Sevda", "Leyla",
"Galip", "Alican", "Atakan", "Feramuz", "Efecan", "Osman", "Nihat", "Sefer", "Zerrin", "Binnur",
"Taner", "Kayahan", "Nalan", "Tonguc", "Kezban", "Kaan", "Abdulmuttalip", "Dost", "Deniz", "Refika",
"Tijen", "Umit", "Yunus", "Zahit", "Melisa", "Hulki", "Hilmi", "Edip", "Muslum", "Canan",
"Dogan", "Berivan", "Adnan", "Helin", "Fikret", "Derya", "Sidre", "Abdullah", "Billur", "Nurdan",
"Agah", "Engin", "Burhan", "Suheyla", "Esra", "Sadri", "Sezai", "Esen", "Askin", "Rupen",
"Ercument", "Birhan", "Ahmet", "Polathan", "Tayfun", "Mustafa", "Zubeyde", "Pakize", "Nevsin", "Naciye",
"Erdem", "Asim", "Orkun", "Sami", "Sade", "Demet", "Keriman", "Yavuz", "Mehmet", "Muhsin",
"Saniye", "Cesim", "Aydan", "Eda", "Hilal" ,"Burak", "Taylan", "Fedai", "Ilke", "Dogancan",	"Rezzan",
"Ozer", "Tacettin", "Nurettin", "Seyfettin", "Safiye", "Aydin", "Latife", "Sercan", "Benfero"
};

int main()
{
	int c;

	printf("bir karakter girin: ");
	c = getchar();

	for (size_t i = 0; i < asize(p); ++i) {
		if (strchr(p[i], c) != NULL)
			printf("%s ", p[i]);
	}
	
}
```


```c
#include <stdio.h>
#include <string.h>

#include "nutility.h"


const char *p[] = {
		"Kamil", "Korhan", "Beril", "Turhan", "Ufuk", "Murathan", "Figen", "Malik", "Bulent", "Cengiz",
"Baran", "Nurullah", "Dilber", "Tuncer", "Recep", "Pelinsu", "Cihan", "Yesim", "Aziz", "Kazim",
"Afacan", "Tevfik", "Sumeyye", "Hande", "Aslihan", "Emine", "Temel", "Gulsah", "Hasan", "Gul",
"Soner", "Ayla", "Cuneyt", "Tekin", "Binnaz", "Emrecan", "Yasar", "Yilmaz", "Feraye", "Tugra",
"Melek", "Garo", "Yurdagul", "Tarik", "Derin", "Handan", "Aytac", "Petek", "Cem", "Aylin",
"Gursel", "Haldun", "Nazife", "Hulusi", "Sevilay", "Sabriye", "Gulden", "Tansel", "Ege", "Turgut",
"Cahit", "Berk", "Nazli", "Aykut", "Kayhan", "Cemre", "Murat", "Kunter", "Gunay", "Cahite",
"Nedim", "Metin", "Kerim", "Utku", "Cumhur", "Kurthan", "Poyraz", "Can", "Candan", "Hikmet",
"Izzet", "Perihan", "Tufan", "Zahide", "Samet", "Melih", "Hakan", "Ayse", "Refik", "Efe",
"Belgin", "Bilal", "Niyazi", "Fugen", "Melike", "Saadet", "Cemile", "Nahit", "Arda", "Ugur",
"Aynur", "Yasin", "Polat", "Naz", "Yusuf", "Gulsen", "Nazif", "Demir", "Egemen", "Necmi",
"Fazilet", "Celal", "Ismail", "Kamile", "Mahir", "Caner", "Suleyman", "Cezmi", "Diana", "Sadullah",
"Atif", "Huseyin", "Necmettin", "Devlet", "Sezen", "Hulya", "Necmiye", "Ece", "Julide", "Onat",
"Emre", "Sinem", "Teoman", "Irmak", "Cihat", "Adem", "Bilgin", "Muzaffer", "Suphi", "Pelin",
"Yalcin", "Kenan", "Atalay", "Akin", "Durmus", "Haluk", "Kelami", "Alparslan", "Busra", "Kasim",
"Durriye", "Tarcan", "Nihal", "Gizem", "Bilge", "Dilek", "Yasemin", "Fahri", "Furkan", "Papatya",
"Hakki", "Fadime", "Devrim", "Abdi", "Tayyip", "Yurdakul", "Zekai", "Nagehan", "Ata", "Naci",
"Mert", "Yelda", "Cebrail", "Rumeysa", "Beyhan", "Azize", "Cemil", "Sezer", "Beste", "Ciler",
"Enes", "Cahide", "Tayyar", "Cansu", "Burak", "Ediz", "Sefa", "Anil", "Alev", "Atil",
"Nefes", "Cetin", "Tansu", "Bora", "Sevim", "Sarp", "Fuat", "Kaya", "Zarife", "Tanju",
"Su", "Kerem", "Handesu", "Jade", "Halime", "Gurbuz", "Okan", "Azmi", "Sevda", "Leyla",
"Galip", "Alican", "Atakan", "Feramuz", "Efecan", "Osman", "Nihat", "Sefer", "Zerrin", "Binnur",
"Taner", "Kayahan", "Nalan", "Tonguc", "Kezban", "Kaan", "Abdulmuttalip", "Dost", "Deniz", "Refika",
"Tijen", "Umit", "Yunus", "Zahit", "Melisa", "Hulki", "Hilmi", "Edip", "Muslum", "Canan",
"Dogan", "Berivan", "Adnan", "Helin", "Fikret", "Derya", "Sidre", "Abdullah", "Billur", "Nurdan",
"Agah", "Engin", "Burhan", "Suheyla", "Esra", "Sadri", "Sezai", "Esen", "Askin", "Rupen",
"Ercument", "Birhan", "Ahmet", "Polathan", "Tayfun", "Mustafa", "Zubeyde", "Pakize", "Nevsin", "Naciye",
"Erdem", "Asim", "Orkun", "Sami", "Sade", "Demet", "Keriman", "Yavuz", "Mehmet", "Muhsin",
"Saniye", "Cesim", "Aydan", "Eda", "Hilal" ,"Burak", "Taylan", "Fedai", "Ilke", "Dogancan",	"Rezzan",
"Ozer", "Tacettin", "Nurettin", "Seyfettin", "Safiye", "Aydin", "Latife", "Sercan", "Benfero"
};

int main()
{
	for (int c = 'a'; c <= 'z'; ++c) {
		printf("icinde %c karakteri olanlar\n", c);
		int cnt = 0;
		for (size_t i = 0; i < asize(p); ++i) {
			if (strchr(p[i], c) != NULL) {
				printf("%s ", p[i]);
				++cnt;
			}
		}
		printf("\ntoplam %d tane\n\n", cnt);
	}

}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>


#include "nutility.h"


const char *p[] = {
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
	"rezzan", "ozer", "tacettin", "nurettin", "seyfettin", "safiye", "aydin", "latife", "sercan", "benfero",

};

int main()
{
	for (size_t i = 0; i < asize(p); ++i) {
		if (i && i % 10 == 0)
			printf("\n");
		char str[100];
		strcpy(str, p[i]);
		str[0] = tolower(str[0]);
		printf("\"%s\", ", str);
	}

}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>


#include "nutility.h"

const char *p[] = {
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
	"rezzan", "ozer", "tacettin", "nurettin", "seyfettin", "safiye", "aydin", "latife", "sercan", "benfero",

};

int main()
{
	char str[100];

	printf("bir yazi girin: ");
	scanf("%s", str);

	for (size_t i = 0; i < asize(p); ++i) {
		if (strstr(p[i], str))
			printf("%s ", p[i]);
	}
}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "nutility.h"


const char *p[] = {
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
	"rezzan", "ozer", "tacettin", "nurettin", "seyfettin", "safiye", "aydin", "latife", "sercan", "benfero",

};

int main()
{
	char str[100];

	printf("bir yazi girin: ");
	scanf("%s", str);

	for (size_t i = 0; i < asize(p); ++i) {
		if (strpbrk(p[i], str))
			printf("%s ", p[i]);
	}
}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "nutility.h"

int is_all_unique(const char *p)
{
	if (!*p)
		return 1;

	for (int i = 0; p[i] != '\0'; ++i) {
		for (int k = i + 1; p[k] != '\0'; ++k) { 
			if (p[k] == p[i])
				return 0;
		}
	}
	return 1;
}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "nutility.h"

const char *p[] = {
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
	"rezzan", "ozer", "tacettin", "nurettin", "seyfettin", "safiye", "aydin", "latife", "sercan", "benfero",

};

int main()
{
	char str[100];

	for (size_t i = 0; i < asize(p); ++i) {
		if (!is_all_unique(p[i]))
			printf("%s ", p[i]);
	}

}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "nutility.h"

const char *p[] = {
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
	"rezzan", "ozer", "tacettin", "nurettin", "seyfettin", "safiye", "aydin", "latife", "sercan", "benfero",

};

int main()
{
	for (size_t i = 0; i < asize(p); ++i) {
		printf("%s ", p[i]);
	}
	printf("\n\n");
	
	for (size_t i = 0; i < asize(p) - 1; ++i) {
		for (size_t k = 0; k < asize(p) - 1 - i; ++k) {
			if (strcmp(p[k], p[k + 1]) < 0) {
				const char *ptemp = p[k];
				p[k] = p[k + 1];
				p[k + 1] = ptemp;
			}
		}
	}

	for (size_t i = 0; i < asize(p); ++i) {
		printf("%s ", p[i]);
	}
	printf("\n\n");

}
```


```c
// p[k]      p[k + 1]
// p[k] p[k + 1] den daha uzun ise 

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "nutility.h"

const char *p[] = {
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
	"rezzan", "ozer", "tacettin", "nurettin", "seyfettin", "safiye", "aydin", "latife", "sercan", "benfero",

};

int main()
{
	for (size_t i = 0; i < asize(p); ++i) {
		printf("%s ", p[i]);
	}
	printf("\n\n");
	
	for (size_t i = 0; i < asize(p) - 1; ++i) {
		for (size_t k = 0; k < asize(p) - 1 - i; ++k) {
			size_t len1 = strlen(p[k]);
			size_t len2 = strlen(p[k + 1]);
			if (len1 > len2 || (len1 == len2 && strcmp(p[k], p[k + 1]) > 0)) {
				const char *ptemp = p[k];
				p[k] = p[k + 1];
				p[k + 1] = ptemp;
			}
		}
	}

	for (size_t i = 0; i < asize(p); ++i) {
		printf("%s ", p[i]);
	}
	printf("\n\n");
}
```



```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "nutility.h"

const char *p[] = {
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
	"rezzan", "ozer", "tacettin", "nurettin", "seyfettin", "safiye", "aydin", "latife", "sercan", "benfero",
	NULL

	};

int main()
{
	int i = 0;

	while (p[i])
		printf("%s ", p[i++]);

}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "nutility.h"

#define   SIZE      300

//dikkat leyla ve su arasinda olmasi gereken virgul karakteri yok

const char *p[SIZE] = {
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
	"kerem", "handesu", "jade", "halime", "gurbuz", "okan", "azmi", "sevda", "leyla" "su",
	"galip", "alican", "atakan", "feramuz", "efecan", "osman", "nihat", "sefer", "zerrin", "binnur",
	"taner", "kayahan", "nalan", "tonguc", "kezban", "kaan", "abdulmuttalip", "dost", "deniz", "refika",
	"tijen", "umit", "yunus", "zahit", "melisa", "hulki", "hilmi", "edip", "muslum", "canan",
	"dogan", "berivan", "adnan", "helin", "fikret", "derya", "sidre", "abdullah", "billur", "nurdan",
	"agah", "engin", "burhan", "suheyla", "esra", "sadri", "sezai", "esen", "askin", "rupen",
	"ercument", "birhan", "ahmet", "polathan", "tayfun", "mustafa", "zubeyde", "pakize", "nevsin", "naciye",
	"erdem", "asim", "orkun", "sami", "sade", "demet", "keriman", "yavuz", "mehmet", "muhsin",
	"saniye", "cesim", "aydan", "eda", "hilal", "burak", "taylan", "fedai", "ilke", "dogancan",
	"rezzan", "ozer", "tacettin", "nurettin", "seyfettin", "safiye", "aydin", "latife", "sercan", "benfero",
	};

int main()
{
	for (int i = 0; i < SIZE; ++i)
		puts(p[i]);
}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define   SIZE      100

int main()
{
	char s1[SIZE] = "ATAKAN";
	char s2[SIZE];
	size_t n;

	printf("kac karakter kopyalamak istiyorsunuz: ");
	scanf("%zu", &n);
	strncpy(s2, s1, n);

	printf("%s\n", s2);
}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define   SIZE      100

int main()
{
	char s1[SIZE] = "ATAKAN";
	char s2[SIZE];
	size_t n;

	printf("kac karakter kopyalamak istiyorsunuz: ");
	scanf("%zu", &n);
	strncpy(s2, s1, n);
	s2[n] = '\0';

	printf("%s\n", s2);
}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define   SIZE      100

int main()
{
	char s1[SIZE] = "ATAKAN";
	char s2[SIZE];
	size_t n;

	printf("kac karakter kopyalamak istiyorsunuz: ");
	scanf("%zu", &n);
	strncpy(s2, s1, n)[n] = '\0';
	

	printf("%s\n", s2);
}
```


```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define   SIZE      100

int main()
{
	char s1[SIZE] = "ATAKAN";
	char s2[SIZE] = "mehmet";
	size_t n;

	printf("kac karakter eklemek istiyorsunuz: ");
	scanf("%zu", &n);

	strncat(s2, s1, n);

	printf("(%s)\n", s2);

}
```


```c
// necatiergin2019@gmail.com
// dogancan_ergin34@yahoo.com
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define   SIZE      100

//erkancan
//aykansu

int main()
{
	char s1[SIZE];
	char s2[SIZE];

	printf("iki isim girin: ");
	scanf("%s%s", s1, s2);
	if (!strncmp(s1 + 2, s2 + 2, 3))
		printf("esit\n");
	else
		printf("esit degil\n");

}
```
