"w+b"   "wb+"
"r+b"    "rb+"  
"a+b"   "ab+"



dosya text modunda açılırsa

dosyaya newline karakteri yazıldığında 2 byte yazılıyor
	  13 10
           

		#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main()
{
	FILE *f = fopen("aaaaaaa", "w"); //text modunda
	if (f == NULL) {
		printf("dosya olusturulamadi\n ");
		return 1;
	}

	for (int i = 0; i < 100; ++i) {
		fputc('\n', f);
	}

	fclose(f);

}
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main()
{
	FILE *f = fopen("aaaaaaa", "r"); //text modunda
	if (f == NULL) {
		printf("dosya acilamadi\n ");
		return 1;
	}

	int c;

	while ((c = fgetc(f)) != EOF) {
		printf("%d ", c);
	}

	fclose(f);

}
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main()
{
	FILE *f = fopen("aaaaaaa", "rb"); //text modunda
	if (f == NULL) {
		printf("dosya acilamadi\n ");
		return 1;
	}

	int c;

	while ((c = fgetc(f)) != EOF) {
		printf("%d ", c);
	}

	fclose(f);

}
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

26   ctrl-z


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main()
{
	FILE *f = fopen("aaaaaaa", "wb"); //text modunda
	if (f == NULL) {
		printf("dosya olusturulamadi\n ");
		return 1;
	}

	for (int i = 0; i < 100; ++i) {
		fputc(65, f);
	}
	fputc(26, f);
	for (int i = 0; i < 100; ++i) {
		fputc(90, f);
	}

	fclose(f);

}
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main()
{
	FILE *f = fopen("aaaaaaa", "rb"); //binary modda
	if (f == NULL) {
		printf("dosya olusturulamadi\n ");
		return 1;
	}

	int c;

	while ((c = fgetc(f)) != EOF)
		printf("%d ", c);

	fclose(f);

}
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main()
{
	FILE *f = fopen("aaaaaaa", "r"); //binary modda
	if (f == NULL) {
		printf("dosya olusturulamadi\n ");
		return 1;
	}

	int c;

	while ((c = fgetc(f)) != EOF)
		printf("%d ", c);

	fclose(f);

}
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS

//filecopy   ahmet.exe   mehmet.exe

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if (argc != 3) {
		fprintf(stderr, "usage: <filecopy> <source file name> <dest file name>\n");
		return 1;
	}
	FILE *fs = fopen(argv[1], "rb");
	if (!fs) {
		fprintf(stderr, "cannot open file %s to read\n", argv[1]);
		return 2;
	}

	FILE *fd = fopen(argv[2], "wb");
	if (!fd) {
		fprintf(stderr, "cannot create file %s to write\n", argv[2]);
		return 3;
	}

	int byte_count = 0;
	int c;

	while ((c = fgetc(fs)) != EOF) {
		fputc(c, fd);
		++byte_count;
	}

	fclose(fs);
	fclose(fd);

	printf("%d byte'lik %s dosyasinin %s isimli kopyasi cikartildi\n", byte_count, argv[1],
	argv[2]);
}
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

// bir dosyayi parcalara bolen program
// parcaladan dosyayi olusturan program

//ahmet.exe   15.720 byte

//dbol  ahmet.exe  1000
//fparca001.par    1000
//fparca002.par    1000
//fparca015.par    1000
//fparca016.par    720

//dbir mehmet.exe

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define   MAX_FILE_NAME_LEN     80
// dbol ahmet.exe  1000
//dparca001.par

int main(int argc, char **argv)
{
	char source_file_name[MAX_FILE_NAME_LEN + 1];
	char dest_file_name[MAX_FILE_NAME_LEN + 1];
	int chunk;
	FILE *fs, *fd;
	int byte_count = 0;
	int file_count = 0;
	int c;

	if (argc != 3) {
		printf("kaynak dosya ismi:  ");
		scanf("%s", source_file_name);
		printf("kac byte'lik parcalara bolunsun: ");
		scanf("%d", &chunk);
	}
	else {
		strcpy(source_file_name, argv[1]);
		chunk = atoi(argv[2]);
	}

	if ((fs = fopen(source_file_name, "rb")) == NULL) {
		fprintf(stderr, "%s dosyasi acilamadi\n", source_file_name);
		return 1;
	}

	fd = NULL;

	while ((c = fgetc(fs)) != EOF) {
		if (fd == NULL) { //uzantisi par olan yeni dosyayi olustur
			sprintf(dest_file_name, "dparca%03d.par", file_count + 1);
			if ((fd = fopen(dest_file_name, "wb")) == NULL) {
				fprintf(stderr, "dosya olusturulamadi\n");
				fclose(fs);
				return 2;
			}
			++file_count;
		}
		fputc(c, fd);

		++byte_count;
		if (byte_count % chunk == 0) { //dosyaya chunk adet byte yazildi dosya kapatilacak
			fclose(fd);
			fd = NULL;
		}
	}

	fclose(fs);
	if (fd)
		fclose(fd);
	
	printf("%d byte'lik %s isimli dosya %d byte'lik %d adet dosyaya bolundu\n",
		    byte_count, source_file_name, chunk, file_count);
}

//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
	if (remove("aaaaaaa")) {
		printf("silme islemi basarisiz\n");
	}
	else {
		printf("dosya silindi\n");
	}
}


//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define   MAX_FILE_NAME_LEN     80

// dbir mehmet.exe 


int main(int argc, char **argv)
{
	char source_file_name[MAX_FILE_NAME_LEN + 1];
	char dest_file_name[MAX_FILE_NAME_LEN + 1];
	FILE *fs, *fd;
	int byte_count = 0;
	int file_count = 0;
	int c;

	if (argc != 2) {
		printf("hedef dosya ismi:  ");
		scanf("%s", dest_file_name);
	}
	else {
		strcpy(dest_file_name, argv[1]);
	}


	if ((fd = fopen(dest_file_name, "wb")) == NULL) {
		fprintf(stderr, "%s dosyasi olusturulamadi\n", dest_file_name);
		return 1;
	}

	while (1) {
		sprintf(source_file_name, "dparca%03d.par", file_count + 1);
		if ((fs = fopen(source_file_name, "rb")) == NULL)
			break;
		while ((c = fgetc(fs)) != EOF) {
			fputc(c, fd);
			++byte_count;
		}
		
		fclose(fs);
		if (remove(source_file_name)) {
			printf("%s dosyasi silinemedi\n", source_file_name);
			return 2;
		}
		++file_count;
	}

	fclose(fd);

	printf("%d adet dosya %d byte'lik %s dosyasi olarak birlestirildi\n",
	file_count, byte_count, dest_file_name);

}
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------


18:50'de devam

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define   MAX_FILE_NAME_LEN     80

// dbir mehmet.exe 


int main(int argc, char **argv)
{
	char source_file_name[MAX_FILE_NAME_LEN + 1];
	char dest_file_name[MAX_FILE_NAME_LEN + 1];
	FILE *fs, *fd;
	int byte_count = 0;
	int file_count = 0;
	int c;

	if (argc != 2) {
		printf("hedef dosya ismi:  ");
		scanf("%s", dest_file_name);
	}
	else {
		strcpy(dest_file_name, argv[1]);
	}


	if ((fd = fopen(dest_file_name, "wb")) == NULL) {
		fprintf(stderr, "%s dosyasi olusturulamadi\n", dest_file_name);
		return 1;
	}

	while (1) {
		sprintf(source_file_name, "dparca%03d.par", file_count + 1);
		if ((fs = fopen(source_file_name, "rb")) == NULL)
			break;
		while ((c = fgetc(fs)) != EOF) {
			fputc(c, fd);
			++byte_count;
		}
		
		fclose(fs);
		if (remove(source_file_name)) {
			printf("%s dosyasi silinemedi\n", source_file_name);
			return 2;
		}
		++file_count;
	}

	fclose(fd);

	printf("%d adet dosya %d byte'lik %s dosyasi olarak birlestirildi\n",
	file_count, byte_count, dest_file_name);

}
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

unique file name generator

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	char fname[L_tmpnam];

	for (int i = 0; i < 100; ++i) {
		tmpnam(fname);
		printf("%s\n", fname);
	}



}
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	for (int i = 0; i < 100; ++i) {
		printf("%s\n", tmpnam(NULL));
	}

}
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

rename("ali.txt", "veli.txt")


//enc ahmet.exe 76347214
// 

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	if (rename("cenk.txt", "charset.txt")) {
		printf("basarisiz\n");
	}
	else {
		printf("basarili\n");
	}
}
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

//enc ahmet.exe 76347214
// 

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
	FILE *fsource, *fdest;
	char temp_file_name[L_tmpnam];
	int c;

	if (argc != 3) {
		fprintf(stderr, "usage: <enc> <filename> <key>\n");
		return 1;
	}
	
	unsigned long seed = strtoul(argv[2], NULL, 10);
	srand((unsigned int)seed);

	if ((fsource = fopen(argv[1], "rb")) == NULL) {
		fprintf(stderr, "File %s cannot opened\n", argv[1]);
		return 2;
	}

	tmpnam(temp_file_name);

	if ((fdest = fopen(temp_file_name, "wb")) == NULL) {
		fprintf(stderr, "cannot created temporary file\n");
		return 3;
	}

	while ((c = fgetc(fsource)) != EOF) {
		fputc(c ^ rand(), fdest);
	}

	fclose(fsource);
	fclose(fdest);

	if (remove(argv[1])) {
		fprintf(stderr, "cannot delete file\n");
		return 4;
	}

	if (rename(temp_file_name, argv[1])) {
		fprintf(stderr, "cannot rename file\n");
		return 5;
	}

}
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

formatlı okuma yazma işlemleri
==============================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "nutility.h"

#define   N					10'000'000
#define   PRIME_PER_LINE	10

int main()
{
	FILE *f = fopen("prime.txt", "w");
	if (!f) {
		fprintf(stderr, "cannot create file\n");
		return 1;
	}

	randomize();
	int prime_cnt = 0;
	int x = 2;

	while (prime_cnt < N) {
		if (isprime(x)) {
			if (prime_cnt && prime_cnt % PRIME_PER_LINE == 0)
				fprintf(f, "\n");
			fprintf(f, "%-18d", x);
			++prime_cnt;
		}
		++x;
	}

	fclose(f);


}

//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "nutility.h"
#include <conio.h>


int main()
{
	FILE *f = fopen("prime.txt", "r");
	if (!f) {
		fprintf(stderr, "dosya acilamadi\n");
		return 1;
	}
	int x;

	while (fscanf(f, "%d", &x)) {
		printf("%d ", x);
		_getch();
	}

	fclose(f);
}

//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "nutility.h"
#include <conio.h>


int main()
{
	FILE *fsource = fopen("prime.txt", "r");
	if (!fsource) {
		fprintf(stderr, "dosya acilamadi\n");
		return 1;
	}

	FILE *fdest= fopen("twinprime.txt", "w");
	if (!fdest) {
		fprintf(stderr, "dosya acilamadi\n");
		return 1;
	}
	int x, y;

	while (fscanf(fsource, "%d%d", &x, &y) != EOF) {
		if (y - x == 2) {
			fprintf(fdest, "%-16d %-16d\n", x, y);
		}
	}

	fclose(fsource);
	fclose(fdest);
}

//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "nutility.h"
#include <conio.h>
#include <string.h>

static const char *const pnames[] = {
		"kamil", "korhan", "beril", "turhan", "ufuk", "murathan", "figen", "malik", "bulent", "cengiz",
		"baran", "nurullah", "dilber", "tuncer", "recep", "pelinsu", "cihan", "yesim", "aziz", "kazim",
		"afacan", "tevfik", "sumeyye", "hande", "aslihan", "emine", "temel", "gulsah", "hasan", "gul",
		"soner", "ayla", "cuneyt", "tekin", "binnaz", "emrecan", "yasar", "yilmaz", "feraye", "tugra",
		"melek", "garo", "yurdagul", "tarik", "derin", "handan", "aytac", "petek", "cem", "aylin",
		"gursel", "haldun", "nazife", "hulusi", "sevilay", "sabriye", "gulden", "tansel", "ege", "turgut",
		"cahit", "berk", "nazli", "aykut", "kayhan", "cemre", "murat", "kunter", "gunay", "cahide",
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
		"su", "kerem", "handesu", "Jade", "halime", "gurbuz", "okan", "azmi", "sevda", "leyla",
		"galip", "alican", "atakan", "feramuz", "efecan", "osman", "nihat", "sefer", "zerrin", "binnur",
		"taner", "kayahan", "nalan", "tonguc", "kezban", "kaan", "abdulmuttalip", "dost", "deniz", "refika",
		"tijen", "umit", "yunus", "zahit", "melisa", "hulki", "hilmi", "edip", "muslum", "canan",
		"dogan", "berivan", "adnan", "helin", "fikret", "derya", "sidre", "abdullah", "billur", "nurdan",
		"agah", "engin", "burhan", "suheyla", "esra", "sadri", "sezai", "esen", "askin", "rupen",
		"ercument", "birhan", "ahmet", "polathan", "tayfun", "mustafa", "zubeyde", "pakize", "nevsin", "naciye",
		"erdem", "asim", "orkun", "sami", "sade", "demet", "keriman", "yavuz", "mehmet", "muhsin",
		"saniye", "cesim", "aydan", "eda", };




void build_file(const char *ptr)
{
	FILE *fsource = fopen("sinav.txt", "r");
	if (!fsource) {
		fprintf(stderr, "dosya acilamadi\n");
		exit(EXIT_FAILURE);
	}

	
	char dest_file_name[80];
	sprintf(dest_file_name, "%s.txt", ptr);

	FILE *fdest = fopen(dest_file_name, "w");
	if (fdest == NULL) {
		printf("dosya olusturulamadi\n");
		exit(EXIT_FAILURE);
	}

	int no;
	char name[40];
	char fname[40];
	char town[40];
	int grade;

	while (fscanf(fsource, "%d%s%s%s%d", &no, name, fname, town, &grade) != EOF) {
		if (!strcmp(name, ptr)) {
			fprintf(fdest, "%-8d%-16s%-18s%-16s%d\n", no, name, fname, town, grade);
		}
	}

	fclose(fsource);
	fclose(fdest);

}


int main()
{
	for (size_t i = 0; i < asize(pnames); ++i) {
		build_file(pnames[i]);
	}

}

//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "nutility.h"
#include <conio.h>
#include <string.h>

static const char *const pnames[] = {
		"kamil", "korhan", "beril", "turhan", "ufuk", "murathan", "figen", "malik", "bulent", "cengiz",
		"baran", "nurullah", "dilber", "tuncer", "recep", "pelinsu", "cihan", "yesim", "aziz", "kazim",
		"afacan", "tevfik", "sumeyye", "hande", "aslihan", "emine", "temel", "gulsah", "hasan", "gul",
		"soner", "ayla", "cuneyt", "tekin", "binnaz", "emrecan", "yasar", "yilmaz", "feraye", "tugra",
		"melek", "garo", "yurdagul", "tarik", "derin", "handan", "aytac", "petek", "cem", "aylin",
		"gursel", "haldun", "nazife", "hulusi", "sevilay", "sabriye", "gulden", "tansel", "ege", "turgut",
		"cahit", "berk", "nazli", "aykut", "kayhan", "cemre", "murat", "kunter", "gunay", "cahide",
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
		"su", "kerem", "handesu", "Jade", "halime", "gurbuz", "okan", "azmi", "sevda", "leyla",
		"galip", "alican", "atakan", "feramuz", "efecan", "osman", "nihat", "sefer", "zerrin", "binnur",
		"taner", "kayahan", "nalan", "tonguc", "kezban", "kaan", "abdulmuttalip", "dost", "deniz", "refika",
		"tijen", "umit", "yunus", "zahit", "melisa", "hulki", "hilmi", "edip", "muslum", "canan",
		"dogan", "berivan", "adnan", "helin", "fikret", "derya", "sidre", "abdullah", "billur", "nurdan",
		"agah", "engin", "burhan", "suheyla", "esra", "sadri", "sezai", "esen", "askin", "rupen",
		"ercument", "birhan", "ahmet", "polathan", "tayfun", "mustafa", "zubeyde", "pakize", "nevsin", "naciye",
		"erdem", "asim", "orkun", "sami", "sade", "demet", "keriman", "yavuz", "mehmet", "muhsin",
		"saniye", "cesim", "aydan", "eda", };


int main()
{
	FILE *fp[asize(pnames)];

	for (size_t i = 0; i < asize(pnames); ++i) {
		static char fname[40];
		sprintf(fname, "%s.txt", pnames[i]);
		fp[i] = fopen(fname, "w");
		if (!fp[i]) {
			printf("%s dosyasi olusturulamadi\n", fname);
			return 1;
		}
	}

	FILE *fsource = fopen("sinav.txt", "r");
	if (!fsource) {
		fprintf(stderr, "dosya acilamadi\n");
		exit(EXIT_FAILURE);
	}

	int no;
	char name[40];
	char fname[40];
	char town[40];
	int grade;

	while (fscanf(fsource, "%d%s%s%s%d", &no, name, fname, town, &grade) != EOF) {
		size_t i;

		for (i = 0; i < asize(pnames); ++i)
			if (!strcmp(name, pnames[i]))
				break;
		if (i == asize(pnames)) {
			printf("%s ismi bulunamadi\n", name);
			return 1;
		}

		fprintf(fp[i], "%-8d%-16s%-18s%-16s%d\n", no, name, fname, town, grade);
	}

	_fcloseall();

}

//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "nutility.h"
#include <conio.h>
#include <string.h>

static const char *const pnames[] = {
		"kamil", "korhan", "beril", "turhan", "ufuk", "murathan", "figen", "malik", "bulent", "cengiz",
		"baran", "nurullah", "dilber", "tuncer", "recep", "pelinsu", "cihan", "yesim", "aziz", "kazim",
		"afacan", "tevfik", "sumeyye", "hande", "aslihan", "emine", "temel", "gulsah", "hasan", "gul",
		"soner", "ayla", "cuneyt", "tekin", "binnaz", "emrecan", "yasar", "yilmaz", "feraye", "tugra",
		"melek", "garo", "yurdagul", "tarik", "derin", "handan", "aytac", "petek", "cem", "aylin",
		"gursel", "haldun", "nazife", "hulusi", "sevilay", "sabriye", "gulden", "tansel", "ege", "turgut",
		"cahit", "berk", "nazli", "aykut", "kayhan", "cemre", "murat", "kunter", "gunay", "cahide",
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
		"su", "kerem", "handesu", "Jade", "halime", "gurbuz", "okan", "azmi", "sevda", "leyla",
		"galip", "alican", "atakan", "feramuz", "efecan", "osman", "nihat", "sefer", "zerrin", "binnur",
		"taner", "kayahan", "nalan", "tonguc", "kezban", "kaan", "abdulmuttalip", "dost", "deniz", "refika",
		"tijen", "umit", "yunus", "zahit", "melisa", "hulki", "hilmi", "edip", "muslum", "canan",
		"dogan", "berivan", "adnan", "helin", "fikret", "derya", "sidre", "abdullah", "billur", "nurdan",
		"agah", "engin", "burhan", "suheyla", "esra", "sadri", "sezai", "esen", "askin", "rupen",
		"ercument", "birhan", "ahmet", "polathan", "tayfun", "mustafa", "zubeyde", "pakize", "nevsin", "naciye",
		"erdem", "asim", "orkun", "sami", "sade", "demet", "keriman", "yavuz", "mehmet", "muhsin",
		"saniye", "cesim", "aydan", "eda", };


int main()
{
	char filename[100];

	for (size_t i = 0; i < asize(pnames); ++i) {
		sprintf(filename, "%s.txt", pnames[i]);
		if (remove(filename)) {
			printf("%s dosyasi silinemedi\n", filename);
		}
		else {
			printf("%s dosyasi silindi\n", filename);
		}
	}

}

//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

dosyanın satır satır okunması

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <string.h>



#define			BUFFER_SIZE		1000

int main()
{
	char buffer[BUFFER_SIZE];
	FILE *f = fopen("sinav.txt", "r");
	if (!f) {
		fprintf(stderr, "dosya acilamadi\n");
		return 1;
	}

	char *p;
	while (fgets(buffer, BUFFER_SIZE, f)) {
		if ((p = strchr(buffer, '\n')) != NULL)
			*p = '\0';
		_strrev(buffer);
		printf("%s\n", buffer);
		_getch();
	}
	fclose(f);
}
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------



sort  sinav.txt


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <string.h>



#define			BUFFER_SIZE		1000

int main()
{
	char buffer[BUFFER_SIZE];
	FILE *f = fopen("sinav.txt", "r");
	if (!f) {
		fprintf(stderr, "dosya acilamadi\n");
		return 1;
	}

	char *p;
	while (fgets(buffer, BUFFER_SIZE, f)) {
		if ((p = strchr(buffer, '\n')) != NULL)
			*p = '\0';
		_strrev(buffer);
		printf("%s\n", buffer);
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

#define			BUFFER_SIZE		1000

int main()
{
	char buffer[BUFFER_SIZE];
	FILE *f = fopen("nutility.h", "r");
	if (!f) {
		fprintf(stderr, "dosya acilamadi\n");
		return 1;
	}

	char *p;
	while (fgets(buffer, BUFFER_SIZE, f)) {
		printf("%s", buffer);
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

#define			BUFFER_SIZE		1000

int main()
{
	char str[100];
	FILE *f = fopen("out.txt", "w");
	if (!f) {
		fprintf(stderr, "dosya olusmadi\n");
		return 1;
	}

	for (int i = 0; i < 5; ++i) {
		printf("yaziyi girin: ");
		sgets(str);
		fputs(str, f);
	}

	fclose(f);

}
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

