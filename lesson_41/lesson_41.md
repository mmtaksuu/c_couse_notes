# Lesson 41

## Command Line Arguments (Komut Satırı Argümanları)


```c
// prog ali veli hasan

// copy ali.c veli.c

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("argc = %d\n", argc);

	for (int i = 0; i < argc; ++i) {
		printf("argv[%d] = %s\n", i, argv[i]);
	}
}
```

```c
copy ali.txt  veli.txt

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//copy ali.c veli.c

int main(int argc, char *argv[])
{
	if (argc != 3) {
		fprintf(stderr, "usage: <copyf> <source file name> <dest file name>\n");
		return 1;
	}
	///
	printf("%s dosyasinin %s isimli kopyasi olusturuldu\n", argv[1], argv[2]);
}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#include "date.h"

/*--------------------------------------------------------------------
	komut satirindan asagidaki gibi calistirlacak c prog.ini yaziniz

	negun 12 5 1987
	carsamba
----------------------------------------------------------------------*/

int main(int argc, char *argv[])
{
	if (argc != 4) {
		fprintf(stderr, "kullanim: <negun><gg><aa><yyyy>\n");
		return 1;
	}
	Date x;
	set_date(&x, atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
	print_date(&x);
}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#include "date.h"

/*--------------------------------------------------------------------
	komut satirindan asagidaki gibi calistirlacak c prog.ini yaziniz

	hes 12 * 6
	72
	hes 3 / 7

----------------------------------------------------------------------*/

int main(int argc, char *argv[])
{
	if (argc != 4) {
		fprintf(stderr, "kullanim: <hes><op1><operator+-*/><op2>\n");
		return 1;
	}
	int op1 = atoi(argv[1]);
	int op2 = atoi(argv[3]);

	switch (*argv[2]) {
	case '+': printf("%d\n", op1 + op2); break;
	case '-': printf("%d\n", op1 - op2); break;
	case '/': 
		if (op2 == 0)
			printf("sifira bolme ayip oluyor!\n");
		else
			printf("%f\n", (double)op1 / op2); 
		break;
	case '*':  printf("%d\n", op1 * op2); break;
	default: printf("(%c) gecersiz bir operator", *argv[2]); break;
	}

}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nutility.h"

#include "date.h"

/*--------------------------------------------------------------------
	komut satirindan asagidaki gibi calistirlacak c prog.ini yaziniz

	hes 12 * 6
	72
	hes 3 / 7
----------------------------------------------------------------------*/

int main()
{
	char command_entry[100];

	for (;;) {
		printf("emret patron > ");
		sgets(command_entry);
		if (!strcmp(command_entry, "bitti"))
			break;
		system(command_entry);
	}
}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int i = 0;

	while (argv[i] != NULL) {
		printf("argv[%d] = %s\n", i, argv[i]);
		++i;
	}
}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//fcopy ali.exe veli.exe

int main(int argc, char *argv[])
{
	char source_file_name[80];
	char dest_file_name[80];

	if (argc != 3) {
		printf("kaynak dosya ismi: ");
		scanf("%s", source_file_name);
		printf("hedef dosya ismi : ");
		scanf("%s", dest_file_name);
	}
	else {
		strcpy(source_file_name, argv[1]);
		strcpy(dest_file_name, argv[2]);
	}
	////....

	printf("%s dosyasinin %s isimli kopyasi olusturuldu\n", argv[1], argv[2]);
}
```

# FILE OPERATIONS (DOSYA ISLEMLERI)

## Dosya Acma Modlari


```text
	MOD				     varsa/yoksa						Ne yapabilir
-------------------------------------------------------------------------------------------------
okuma (read)		    varsa açılır/                  dosyadan okuyabilirim / 
                        yoksa açılmaz                  dosyaya yazamam
-------------------------------------------------------------------------------------------------
yazma (write)			varsa sıfırlanır / 	           dosyaya yazabilirim / 
						yoksa oluşturulur              dosyadan okuyamam
-------------------------------------------------------------------------------------------------
son ekleme (append)     varsa açılır /				   dosya sonuna yazabilirim / 
						yoksa oluşturulur              dosyadan okuyamam
-------------------------------------------------------------------------------------------------
okuma+ (read)		    varsa açılır/                  dosyadan okuyabilirim / 
                        yoksa açılmaz                  dosyaya yazabilirim
-------------------------------------------------------------------------------------------------
yazma+ (write)			varsa sıfırlanır / 	           dosyaya yazabilirim / 
						yoksa oluşturulur              dosyadan okuyabilirim
-------------------------------------------------------------------------------------------------
son ekleme+ (append)    varsa açılır /				   dosya sonuna yazabilirim / 
						yoksa oluşturulur              dosyadan okuyabilirim
-------------------------------------------------------------------------------------------------
```


```text
    MOD               text-mod      binary-mod
------------------------------------------------------
okuma (read)            "r"         "rb"		 
------------------------------------------------------
yazma (write)		    "w"         "wb"
------------------------------------------------------
sona ekleme (append)    "a"         "ab"
------------------------------------------------------
okuma+ (read)		    "r+"        "rb+"  yada "r+b"
------------------------------------------------------
yazma+ (write)		    "w+"        "wb+"  yada "w+b"			
------------------------------------------------------
sona ekleme+ (append)   "a+"        "ab+"   yada "a+b"					
------------------------------------------------------
```

### Okuma Modunda Dosya Acma Islemi

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	FILE *f;

	if ((f = fopen("cenk.txt", "r")) == NULL) {
		fprintf(stderr, "dosya acilamadi\n");
		return 1;
	}

	printf("dosya acildi\n");
	//...
}
```

### Yazma Modunda Dosya Acma Islemi

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	FILE *f;

	if ((f = fopen("cenk.txt", "w")) == NULL) {
		fprintf(stderr, "dosya olusturulamadi\n");
		return 1;
	}

	printf("dosya olusturuldu\n");
	//...
}
```

# Dosyalar ile Yapilan Islemler

```text
1) okuma
2) yazma
3) DKG (Dosya Konum Gostericisi) işlemleri
```

```text
-1 Sayisinin 16 bit ve 8 bit ile binary ifadesi (Hepsi bir eksi bir)

16 Bit : 1111 1111 1111 1111
8  Bit : 0000 0000 1111 1111
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	FILE *f = fopen("date.h", "r");
	if (!f) {
		fprintf(stderr, "dosya acilamadi\n");
		return 1;
	}

	int c;

	while ((c = fgetc(f)) != EOF) {
		putchar(c);
	}

	fclose(f);
}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>

int main()
{
	FILE *f = fopen("date.h", "r");
	if (!f) {
		fprintf(stderr, "dosya acilamadi\n");
		return 1;
	}

	int c;

	while ((c = fgetc(f)) != EOF) {
		putchar(toupper(c));
	}

	fclose(f);
}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main(int argc, char **argv)
{
	if (argc != 2) {
		fprintf(stderr, "kullanim: <dyaz> <dosya ismi>\n");
		return 1;
	}

	FILE *f = fopen(argv[1], "r");
	if (!f) {
		fprintf(stderr, "%s dosyasi acilamadi\n", argv[1]);
		return 2;
	}

	int c;

	while ((c = fgetc(f)) != EOF)
		putchar(c);

	fclose(f);
}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//csay ali.txt  r

int main(int argc, char **argv)
{
	if (argc != 3) {
		printf("kullanim: <csay> <dosya ismi> <karakter>\n");
		return 1;
	}

	FILE *f = fopen(argv[1], "r");
	if (f == NULL) {
		fprintf(stderr, "dosya acilamadi\n");
		return 1;
	}
	int c;
	int cnt = 0;

	while ((c = fgetc(f)) != EOF) {
		if (c == *argv[2])
			++cnt;
	}

	fclose(f);
	printf("%d\n", cnt);
}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>

//asay ali.txt ali

int main(int argc, char **argv)
{
	if (argc != 2) {
		printf("kullanim: <asay> <dosya ismi>\n");
		return 1;
	}

	FILE *f = fopen(argv[1], "r");
	if (f == NULL) {
		fprintf(stderr, "dosya acilamadi\n");
		return 1;
	}

	int cnt[26] = { 0 };
	int c;

	while ((c = fgetc(f)) != EOF) {
		if (isalpha(c)) {
			++cnt[toupper(c) - 'A'];
		}
	}

	fclose(f);

	for (int i = 0; i < 26; ++i) {
		if (cnt[i]) {
			printf("%c   %d\n", 'A' + i, cnt[i]);
		}
	}
}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

//asay ali.txt ali

typedef struct {
	int c;
	int cnt;
}Data;

int mycmp(const void *vp1, const void *vp2)
{
	//return ((const Data *)vp2)->cnt - ((const Data *)vp1)->cnt;
	if (((const Data *)vp1)->cnt > ((const Data *)vp2)->cnt)
		return -1;

	if (((const Data *)vp1)->cnt < ((const Data *)vp2)->cnt)
		return 1;

	return 0;
}

int main(int argc, char **argv)
{
	if (argc != 2) {
		printf("kullanim: <asay> <dosya ismi>\n");
		return 1;
	}

	FILE *f = fopen(argv[1], "r");
	if (f == NULL) {
		fprintf(stderr, "dosya acilamadi\n");
		return 1;
	}

	Data a[26];
	for (int i = 0; i < 26; ++i) {
		a[i].cnt = 0; a[i].c = 'A' + i;
	}

	int c;

	while ((c = fgetc(f)) != EOF) {
		if (isalpha(c)) {
			++a[toupper(c) - 'A'].cnt;
		}
	}
	fclose(f);

	qsort(a, 26, sizeof(*a), &mycmp);

	for (int i = 0; i < 26; ++i) {
		if (a[i].cnt) {
			printf("%c   %d\n", a[i].c, a[i].cnt);
		}
	}
}
```

```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>


void print_cset(const char *pname)
{
	FILE *f = fopen(pname, "w");
	if (!f) {
		fprintf(stderr, "%s dosyasi olusturulamadi\n", pname);
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < 128; ++i)
		if (isalnum(i))
			fputc(i, f);

	fclose(f);
}

int main()
{
	print_cset("cset.txt");

}
```


