formatsız okuma yazma fonksiyonları

int ival



#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "nutility.h"



int main()
{
	FILE *f = fopen("prime.dat", "wb");
	if (!f) {
		fprintf(stderr, "dosya olusmadi\n");
		return 1;
	}
	int prime_count = 0;
	int x = 2;

	while (prime_count < 10'000'000) {
		if (isprime(x)) {
			fwrite(&x, sizeof(x), 1, f);
			++prime_count;
		}
		++x;
	}

	fclose(f);



}
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "nutility.h"

int main()
{
	FILE *f = fopen("prime.dat", "rb");
	if (!f) {
		fprintf(stderr, "dosya acilamadi\n");
		return 1;
	}

	int x;

	while (fread(&x, sizeof(int), 1, f)) {
		printf("%d ", x);
		_getch();
	}

	fclose(f);


}
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "nutility.h"

#define			SIZE		100


int main()
{
	int a[SIZE];
	FILE *f = fopen("prime.dat", "rb");
	if (!f) {
		fprintf(stderr, "dosya acilamadi\n");
		return 1;
	}

	size_t n;

	while ((n = fread(a, sizeof(int), SIZE, f)) != 0) {
		display_array(a, n);
		_getch();
	}

	fclose(f);
}
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------



#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define			BUFFER_SIZE		1024

//fcopy  ali.exe veli.exe

int main(int argc, char **argv)
{
	unsigned char buffer[BUFFER_SIZE];
	FILE *fs, *fd;
	size_t n;

	if (argc != 3) {
		fprintf(stderr, "kullanim: <fcopy> <kaynak dosya> <hedef dosya>\n");
		return 1;
	}

	if ((fs = fopen(argv[1], "rb")) == NULL) {
		fprintf(stderr, "%s dosyasi acilamadi\n", argv[1]);
		return 2;
	}

	if ((fd = fopen(argv[2], "wb")) == NULL) {
		fprintf(stderr, "%s dosyasi olusturulamadi\n", argv[2]);
		return 2;
	}

	while ((n = fread(buffer, 1, BUFFER_SIZE, fs)) != 0) {
		fwrite(buffer, 1, n, fd);
	}
	fclose(fs);
	fclose(fd);
}
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "student.h"

// 7'200'000

int main()
{
	FILE *f = fopen("students.dat", "wb");
	if (f == NULL) {
		printf("dosya olusturulamadi\n");
		return 1;
	}

	Student s;
	for (int i = 0; i < 100'000; ++i) {
		set_random_student(&s);
		fwrite(&s, sizeof(s), 1, f);
	}

	fclose(f);
}
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "student.h"
#include <conio.h>


// 7'200'000

int main()
{
	FILE *f = fopen("students.dat", "rb");
	if (f == NULL) {
		printf("dosya olusturulamadi\n");
		return 1;
	}

	Student s;

	while (fread(&s, sizeof(s), 1, f)) {
		print_student(&s);
		_getch();
	}


	fclose(f);
}
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "student.h"
#include <conio.h>
#include <string.h>



// 7'200'000

int main()
{
	FILE *f = fopen("students.dat", "rb");
	if (f == NULL) {
		printf("dosya olusturulamadi\n");
		return 1;
	}

	Student s;

	char name[40];
	char town[40];

	printf("isim sehir:  ");
	scanf("%s%s", name, town);

	while (fread(&s, sizeof(s), 1, f)) {
		if (!strcmp(s.name_, name) && !strcmp(s.town_, town)) {
			print_student(&s);
		}
	}


	fclose(f);
}
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

Dosya konum göstericisi fonksiyonları

file pointer
============


fseek(f, 0L, SEEK_SET);

fseek(f, 0L, SEEK_END);

fseek(f, 0L, SEEK_CUR);




rewind(f);


kacinci asal sayi: 7777777
7777777. asal sayi = 137478503
kacinci asal sayi: 1000000
1000000. asal sayi = 15485863
kacinci asal sayi: 20000000
20000000. asal sayi = 15485863
kacinci asal sayi: 3000000
3000000. asal sayi = 49979687
kacinci asal sayi: 4000000
4000000. asal sayi = 67867967
kacinci asal sayi: 10000000
10000000. asal sayi = 179424673



#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "student.h"
#include <conio.h>
#include <string.h>


int main()
{
	FILE *f;

	if ((f = fopen("prime.dat", "rb")) == NULL) {
		printf("dosya acilamadi\n");
		return 1;
	}
	
	for (int i = 0; i < 10; ++i) {
		int n;
		int ival;
		printf("kacinci asal sayi: ");
		scanf("%d", &n);
		fseek(f, (long)sizeof(int) * (n - 1), SEEK_SET);
		fread(&ival, sizeof(int), 1, f);
		printf("%d. asal sayi = %d\n", n, ival);
	}

	fclose(f);

}


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "student.h"
#include <conio.h>
#include <string.h>


int main()
{
	FILE *f;

	if ((f = fopen("students.dat", "rb")) == NULL) {
		printf("dosya acilamadi\n");
		return 1;
	}
	Student s;
	
	for (int i = 0; i < 10; ++i) {
		int n;
		printf("kacinci ogrenci: ");
		scanf("%d", &n);
		fseek(f, (long)sizeof(Student) * (n - 1), SEEK_SET);
		fread(&s, sizeof(Student), 1, f);
		print_student(&s);
	}

	fclose(f);

}
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "student.h"
#include <conio.h>
#include <string.h>


int main()
{
	FILE *f;

	if ((f = fopen("students.dat", "rb")) == NULL) {
		printf("dosya acilamadi\n");
		return 1;
	}

	printf("%ld\n", ftell(f));
	fseek(f, 0L, SEEK_END);
	printf("%ld\n", ftell(f));

	fclose(f);

}
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "student.h"
#include <conio.h>
#include <string.h>


int main()
{
	FILE *f;

	if ((f = fopen("prime.dat", "rb")) == NULL) {
		printf("dosya acilamadi\n");
		return 1;
	}

	printf("%ld\n", ftell(f));
	fseek(f, 0L, SEEK_END);
	printf("%ld\n", ftell(f));

	fclose(f);

}
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

18:40'de devam edeceğiz

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "student.h"
#include <conio.h>
#include <string.h>
#include <stdlib.h>

void display_recs(const char *pfname)
{
	FILE *f = fopen(pfname, "rb");
	if (!f) {
		fprintf(stderr, "cannot open file %s\n", pfname);
		exit(EXIT_FAILURE);
	}
	Student s;
	int rec_cnt = 0;

	while (fread(&s, sizeof(s), 1, f)) {
		print_student(&s);
		++rec_cnt;
	}
	printf("toplam %d kayit listelendi\n", rec_cnt);
	fclose(f);
}


int main()
{
	display_recs("students.dat");
}
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "student.h"
#include <conio.h>
#include <string.h>
#include <stdlib.h>


void display_recs_by_name(const char *pfname, const char *psname)
{
	FILE *f = fopen(pfname, "rb");
	if (!f) {
		fprintf(stderr, "cannot open file %s\n", pfname);
		exit(EXIT_FAILURE);
	}
	Student s;
	int rec_cnt = 0;

	while (fread(&s, sizeof(s), 1, f)) {
		if (!strcmp(s.name_, psname)) {
			print_student(&s);
			++rec_cnt;
		}
	}
	printf("toplam %d kayit listelendi\n", rec_cnt);
	fclose(f);
}

void display_recs(const char *pfname)
{
	FILE *f = fopen(pfname, "rb");
	if (!f) {
		fprintf(stderr, "cannot open file %s\n", pfname);
		exit(EXIT_FAILURE);
	}
	Student s;
	int rec_cnt = 0;

	while (fread(&s, sizeof(s), 1, f)) {
		print_student(&s);
		++rec_cnt;
	}
	printf("toplam %d kayit listelendi\n", rec_cnt);
	fclose(f);
}

void replace_recs(const char *pfname, const char *poldname, const char *pnewname)
{
	FILE *f = fopen(pfname, "rb+");
	Student s;

	if (!f) {
		fprintf(stderr, "cannot open file %s\n", pfname);
		exit(EXIT_FAILURE);
	}

	int replaced_rec_cnt = 0;
	while (fread(&s, sizeof(s), 1, f)) {
		if (!strcmp(poldname, s.name_)) {
			strcpy(s.name_, pnewname);
			fseek(f, -(long)sizeof(s), SEEK_CUR);
			fwrite(&s, sizeof(s), 1, f);
			fseek(f, 0L, SEEK_CUR);
			++replaced_rec_cnt;
		}		
	}
	fclose(f);
	printf("%d kayit degistirildi\n", replaced_rec_cnt);
}

int main()
{
	replace_recs("students.dat", "leonard", "muhsincan");
	//_getch();
	display_recs_by_name("students.dat", "muhsincan");
}
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "student.h"
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include "nutility.h"




static const char* const ptowns[] = {
"izmir", "afyonkarahisar", "kilis", "bolu", "yalova", "giresun", "tunceli", "manisa", "cankiri", "canakkale",
"mugla", "isparta", "ankara", "kahramanmaras", "nigde", "kirklareli", "artvin", "kirikkale", "bursa", "bingol",
"sirnak", "erzincan", "gaziantep", "bayburt", "tekirdag", "trabzon", "ardahan", "elazig", "karabuk",
"samsun", "malatya", "aksaray", "van", "kars", "amasya", "kirsehir", "balikesir", "sanliurfa",
"adiyaman", "mardin", "bilecik", "hakkari", "mus", "kayseri", "agri", "sinop", "istanbul", "mersin",
"aydin", "sivas", "yozgat", "igdir", "sakarya", "osmaniye", "konya", "tokat",
"zonguldak", "corum", "batman", "adana", "usak", "denizli", "karaman", "ordu", "diyarbakir",
"siirt", "kutahya", "bitlis", "bartin", "nevsehir", "rize", "kastamonu", "duzce", "erzurum", "gumushane",
"hatay", };



void del_recs(const char *pfname, const char *ptown)
{
	FILE *fsource = fopen(pfname, "rb");
	if (!fsource) {
		fprintf(stderr, "cannot open file %s\n", pfname);
		exit(EXIT_FAILURE);
	}
	char temp_file_name[L_tmpnam];
	tmpnam(temp_file_name);

	FILE *fdest = fopen(temp_file_name, "wb");
	if (!fdest) {
		fprintf(stderr, "cannot create temporary file\n");
		exit(EXIT_FAILURE);
	}

	Student s;
	
	int read_count = 0;
	int write_count = 0;

	while (fread(&s, sizeof(s), 1, fsource)) {
		++read_count;
		if (strcmp(s.town_, ptown)) {
			fwrite(&s, sizeof(s), 1, fdest);
			++write_count;
		}
	}

	fclose(fsource);
	fclose(fdest);
	if (remove(pfname)) {
		fprintf(stderr, "dosya silinemedi");
		exit(EXIT_FAILURE);
	}

	if (rename(temp_file_name, pfname)) {
		fprintf(stderr, "dosya ismi degistirilemedi");
		exit(EXIT_FAILURE);
	}
	printf("%s sehrinde dogan %d kisinin kaydi silindi\n", ptown, read_count- write_count);
	_getch();
}


void display_recs_by_name(const char *pfname, const char *psname)
{
	FILE *f = fopen(pfname, "rb");
	if (!f) {
		fprintf(stderr, "cannot open file %s\n", pfname);
		exit(EXIT_FAILURE);
	}
	Student s;
	int rec_cnt = 0;

	while (fread(&s, sizeof(s), 1, f)) {
		if (!strcmp(s.name_, psname)) {
			print_student(&s);
			++rec_cnt;
		}
	}
	printf("toplam %d kayit listelendi\n", rec_cnt);
	fclose(f);
}

void display_recs(const char *pfname)
{
	FILE *f = fopen(pfname, "rb");
	if (!f) {
		fprintf(stderr, "cannot open file %s\n", pfname);
		exit(EXIT_FAILURE);
	}
	Student s;
	int rec_cnt = 0;

	while (fread(&s, sizeof(s), 1, f)) {
		print_student(&s);
		++rec_cnt;
	}
	printf("toplam %d kayit listelendi\n", rec_cnt);
	fclose(f);
}

void replace_recs(const char *pfname, const char *poldname, const char *pnewname)
{
	FILE *f = fopen(pfname, "rb+");
	Student s;

	if (!f) {
		fprintf(stderr, "cannot open file %s\n", pfname);
		exit(EXIT_FAILURE);
	}

	int replaced_rec_cnt = 0;
	while (fread(&s, sizeof(s), 1, f)) {
		if (!strcmp(poldname, s.name_)) {
			strcpy(s.name_, pnewname);
			fseek(f, -(long)sizeof(s), SEEK_CUR);
			fwrite(&s, sizeof(s), 1, f);
			fseek(f, 0L, SEEK_CUR);
			++replaced_rec_cnt;
		}		
	}
	fclose(f);
	printf("%d kayit degistirildi\n", replaced_rec_cnt);
}

int main()
{
	for (size_t i = 0; i < asize(ptowns); ++i) {
		del_recs("students.dat", ptowns[i]);
	}
	_getch();
	display_recs("students.dat");

}
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "student.h"
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include "nutility.h"
#include <time.h>




static const char* const ptowns[] = {
"izmir", "afyonkarahisar", "kilis", "bolu", "yalova", "giresun", "tunceli", "manisa", "cankiri", "canakkale",
"mugla", "isparta", "ankara", "kahramanmaras", "nigde", "kirklareli", "artvin", "kirikkale", "bursa", "bingol",
"sirnak", "erzincan", "gaziantep", "bayburt", "tekirdag", "trabzon", "ardahan", "elazig", "karabuk",
"samsun", "malatya", "aksaray", "van", "kars", "amasya", "kirsehir", "balikesir", "sanliurfa",
"adiyaman", "mardin", "bilecik", "hakkari", "mus", "kayseri", "agri", "sinop", "istanbul", "mersin",
"aydin", "sivas", "yozgat", "igdir", "sakarya", "osmaniye", "konya", "tokat",
"zonguldak", "corum", "batman", "adana", "usak", "denizli", "karaman", "ordu", "diyarbakir",
"siirt", "kutahya", "bitlis", "bartin", "nevsehir", "rize", "kastamonu", "duzce", "erzurum", "gumushane",
"hatay", };


typedef int(*Fcmp)(const void *, const void *);

void del_recs(const char *pfname, const char *ptown)
{
	FILE *fsource = fopen(pfname, "rb");
	if (!fsource) {
		fprintf(stderr, "cannot open file %s\n", pfname);
		exit(EXIT_FAILURE);
	}
	char temp_file_name[L_tmpnam];
	tmpnam(temp_file_name);

	FILE *fdest = fopen(temp_file_name, "wb");
	if (!fdest) {
		fprintf(stderr, "cannot create temporary file\n");
		exit(EXIT_FAILURE);
	}

	Student s;
	
	int read_count = 0;
	int write_count = 0;

	while (fread(&s, sizeof(s), 1, fsource)) {
		++read_count;
		if (strcmp(s.town_, ptown)) {
			fwrite(&s, sizeof(s), 1, fdest);
			++write_count;
		}
	}

	fclose(fsource);
	fclose(fdest);
	if (remove(pfname)) {
		fprintf(stderr, "dosya silinemedi");
		exit(EXIT_FAILURE);
	}

	if (rename(temp_file_name, pfname)) {
		fprintf(stderr, "dosya ismi degistirilemedi");
		exit(EXIT_FAILURE);
	}
	printf("%s sehrinde dogan %d kisinin kaydi silindi\n", ptown, read_count- write_count);
	_getch();
}


void display_recs_by_name(const char *pfname, const char *psname)
{
	FILE *f = fopen(pfname, "rb");
	if (!f) {
		fprintf(stderr, "cannot open file %s\n", pfname);
		exit(EXIT_FAILURE);
	}
	Student s;
	int rec_cnt = 0;

	while (fread(&s, sizeof(s), 1, f)) {
		if (!strcmp(s.name_, psname)) {
			print_student(&s);
			++rec_cnt;
		}
	}
	printf("toplam %d kayit listelendi\n", rec_cnt);
	fclose(f);
}

void display_recs(const char *pfname)
{
	FILE *f = fopen(pfname, "rb");
	if (!f) {
		fprintf(stderr, "cannot open file %s\n", pfname);
		exit(EXIT_FAILURE);
	}
	Student s;
	int rec_cnt = 0;

	while (fread(&s, sizeof(s), 1, f)) {
		print_student(&s);
		++rec_cnt;
	}
	printf("toplam %d kayit listelendi\n", rec_cnt);
	fclose(f);
}

void replace_recs(const char *pfname, const char *poldname, const char *pnewname)
{
	FILE *f = fopen(pfname, "rb+");
	Student s;

	if (!f) {
		fprintf(stderr, "cannot open file %s\n", pfname);
		exit(EXIT_FAILURE);
	}

	int replaced_rec_cnt = 0;
	while (fread(&s, sizeof(s), 1, f)) {
		if (!strcmp(poldname, s.name_)) {
			strcpy(s.name_, pnewname);
			fseek(f, -(long)sizeof(s), SEEK_CUR);
			fwrite(&s, sizeof(s), 1, f);
			fseek(f, 0L, SEEK_CUR);
			++replaced_rec_cnt;
		}		
	}
	fclose(f);
	printf("%d kayit degistirildi\n", replaced_rec_cnt);
}

void sort_file(const char *pfname, int(*fp)(const Student *, const Student *))
{
	FILE *f = fopen(pfname, "rb+");
	if (!f) {
		fprintf(stderr, "cannot open file %s\n", pfname);
		exit(EXIT_FAILURE);
	}
	fseek(f, 0L, SEEK_END);
	long file_size = ftell(f);
	rewind(f);
	Student *pd = (Student*)malloc((size_t)file_size);
	if (!pd) {
		printf("bellek yetersiz\n");
		exit(EXIT_FAILURE);
	}

	fread(pd, 1, file_size, f);
	rewind(f);
	qsort(pd, (size_t)file_size / sizeof(Student), sizeof(Student), (Fcmp)fp);
	fwrite(pd, 1, file_size, f);
	free(pd);
	fclose(f);
}


int main()
{
	printf("siralama basladi\n");
	clock_t start = clock();
	sort_file("students.dat", &cmpStudentbyName);
	clock_t end = clock();
	printf("siralama bitti %f saniye\n", (double)(end - start) / CLOCKS_PER_SEC);
	_getch();
	display_recs("students.dat");

}
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "student.h"
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include "nutility.h"
#include <time.h>




static const char* const ptowns[] = {
"izmir", "afyonkarahisar", "kilis", "bolu", "yalova", "giresun", "tunceli", "manisa", "cankiri", "canakkale",
"mugla", "isparta", "ankara", "kahramanmaras", "nigde", "kirklareli", "artvin", "kirikkale", "bursa", "bingol",
"sirnak", "erzincan", "gaziantep", "bayburt", "tekirdag", "trabzon", "ardahan", "elazig", "karabuk",
"samsun", "malatya", "aksaray", "van", "kars", "amasya", "kirsehir", "balikesir", "sanliurfa",
"adiyaman", "mardin", "bilecik", "hakkari", "mus", "kayseri", "agri", "sinop", "istanbul", "mersin",
"aydin", "sivas", "yozgat", "igdir", "sakarya", "osmaniye", "konya", "tokat",
"zonguldak", "corum", "batman", "adana", "usak", "denizli", "karaman", "ordu", "diyarbakir",
"siirt", "kutahya", "bitlis", "bartin", "nevsehir", "rize", "kastamonu", "duzce", "erzurum", "gumushane",
"hatay", };


typedef int(*Fcmp)(const void *, const void *);

void del_recs(const char *pfname, const char *ptown)
{
	FILE *fsource = fopen(pfname, "rb");
	if (!fsource) {
		fprintf(stderr, "cannot open file %s\n", pfname);
		exit(EXIT_FAILURE);
	}
	char temp_file_name[L_tmpnam];
	tmpnam(temp_file_name);

	FILE *fdest = fopen(temp_file_name, "wb");
	if (!fdest) {
		fprintf(stderr, "cannot create temporary file\n");
		exit(EXIT_FAILURE);
	}

	Student s;
	
	int read_count = 0;
	int write_count = 0;

	while (fread(&s, sizeof(s), 1, fsource)) {
		++read_count;
		if (strcmp(s.town_, ptown)) {
			fwrite(&s, sizeof(s), 1, fdest);
			++write_count;
		}
	}

	fclose(fsource);
	fclose(fdest);
	if (remove(pfname)) {
		fprintf(stderr, "dosya silinemedi");
		exit(EXIT_FAILURE);
	}

	if (rename(temp_file_name, pfname)) {
		fprintf(stderr, "dosya ismi degistirilemedi");
		exit(EXIT_FAILURE);
	}
	printf("%s sehrinde dogan %d kisinin kaydi silindi\n", ptown, read_count- write_count);
	_getch();
}


void display_recs_by_name(const char *pfname, const char *psname)
{
	FILE *f = fopen(pfname, "rb");
	if (!f) {
		fprintf(stderr, "cannot open file %s\n", pfname);
		exit(EXIT_FAILURE);
	}
	Student s;
	int rec_cnt = 0;

	while (fread(&s, sizeof(s), 1, f)) {
		if (!strcmp(s.name_, psname)) {
			print_student(&s);
			++rec_cnt;
		}
	}
	printf("toplam %d kayit listelendi\n", rec_cnt);
	fclose(f);
}

void display_recs(const char *pfname)
{
	FILE *f = fopen(pfname, "rb");
	if (!f) {
		fprintf(stderr, "cannot open file %s\n", pfname);
		exit(EXIT_FAILURE);
	}
	Student s;
	int rec_cnt = 0;

	while (fread(&s, sizeof(s), 1, f)) {
		print_student(&s);
		++rec_cnt;
	}
	printf("toplam %d kayit listelendi\n", rec_cnt);
	fclose(f);
}

void replace_recs(const char *pfname, const char *poldname, const char *pnewname)
{
	FILE *f = fopen(pfname, "rb+");
	Student s;

	if (!f) {
		fprintf(stderr, "cannot open file %s\n", pfname);
		exit(EXIT_FAILURE);
	}

	int replaced_rec_cnt = 0;
	while (fread(&s, sizeof(s), 1, f)) {
		if (!strcmp(poldname, s.name_)) {
			strcpy(s.name_, pnewname);
			fseek(f, -(long)sizeof(s), SEEK_CUR);
			fwrite(&s, sizeof(s), 1, f);
			fseek(f, 0L, SEEK_CUR);
			++replaced_rec_cnt;
		}		
	}
	fclose(f);
	printf("%d kayit degistirildi\n", replaced_rec_cnt);
}

void sort_file(const char *pfname, int(*fp)(const Student *, const Student *))
{
	FILE *f = fopen(pfname, "rb+");
	if (!f) {
		fprintf(stderr, "cannot open file %s\n", pfname);
		exit(EXIT_FAILURE);
	}
	fseek(f, 0L, SEEK_END);
	long file_size = ftell(f);
	rewind(f);
	Student *pd = (Student*)malloc((size_t)file_size);
	if (!pd) {
		printf("bellek yetersiz\n");
		exit(EXIT_FAILURE);
	}

	fread(pd, 1, file_size, f);
	rewind(f);
	qsort(pd, (size_t)file_size / sizeof(Student), sizeof(Student), (Fcmp)fp);
	fwrite(pd, 1, file_size, f);
	free(pd);
	fclose(f);
}


int main()
{
	printf("siralama basladi\n");
	clock_t start = clock();
	sort_file("students.dat", &cmpStudentbyName);
	clock_t end = clock();
	printf("siralama bitti %f saniye\n", (double)(end - start) / CLOCKS_PER_SEC);
	_getch();
	display_recs("students.dat");

}
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "student.h"
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include "nutility.h"
#include <time.h>

int main()
{
	FILE *f = fopen("students.dat", "rb");
	if (!f) {
		printf("dosya acilamadi\n");;
		return 1;
	}

	randomize();
	int n = rand() % 5000;
	fseek(f, n * (long)sizeof(Student), SEEK_SET);
	fpos_t mypos;
	fgetpos(f, &mypos);
	Student s;
	fread(&s, sizeof(s), 1, f);
	print_student(&s);
	////
	fseek(f, 0L, SEEK_SET);
	///code
	fsetpos(f, &mypos);
	fread(&s, sizeof(s), 1, f);
	print_student(&s);

	fclose(f);
}
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "student.h"
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include "nutility.h"
#include <time.h>

int main()
{
	FILE *f = fopen("students.dat", "rb");
	if (!f) {
		printf("dosya acilamadi\n");;
		return 1;
	}

	printf("eof   flag = %s\n", feof(f) ? "set" : "not set");
	printf("error flag = %s\n", ferror(f) ? "set" : "not set");
	printf("\n\n");
	fseek(f, 0L, SEEK_END);

	printf("eof   flag = %s\n", feof(f) ? "set" : "not set");
	printf("error flag = %s\n", ferror(f) ? "set" : "not set");
	printf("\n\n");

	int c = fgetc(f);
	printf("c = %d\n", c);
	printf("eof   flag = %s\n", feof(f) ? "set" : "not set");
	printf("error flag = %s\n", ferror(f) ? "set" : "not set");
	printf("\n\n");

	fclose(f);
}
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------


20:13

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "student.h"
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include "nutility.h"
#include <time.h>

int main()
{
	FILE *f = fopen("isim.txt", "r");
	if (!f) {
		printf("dosya acilamadi\n");
		return 1;
	}
	char str[100];

	while (!feof(f)) {
		fgets(str, 100, f);
		printf("%s", str);
	}

	fclose(f);

}
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------


//hangi durumlarda dosya'nin buffer'i flush edilir (bosaltilir?)

1) buffer doldugunda
2) program normal olarak sonlandığında (exit)
3) dosya kapatıldığında (fclose)
4) flush fonksiyonu çağırıldığında
5) 


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "student.h"
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include "nutility.h"
#include <time.h>

int main()
{
	FILE *f = tmpfile();  //wb+ 
	//check

	fclose(f); //dosya silinecek

}
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "student.h"
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include "nutility.h"
#include <time.h>

int main()
{
	FILE *f = fopen("students.dat", "rb");
	if (!f) {
		printf("dosya acilamadi\n");
		return 1;
	}
	char buffer[1024];

	setvbuf(f, buffer, _IOFBF, 1024);



}
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------





dosya işlemleri bitecek
errno başlık dosyası ve global hata değişkeni
	perror
	strerr
önişlemci komutları
assert.h başlık dosyası ve assert makrosu

C99 ile gelen önemi araçlar
recursive işlevler....

