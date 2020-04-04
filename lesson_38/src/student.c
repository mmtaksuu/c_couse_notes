#define _CRT_SECURE_NO_WARNINGS

#include "student.h"
#include "nutility.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define     PRIVATE     static
#define     PUBLIC


PRIVATE const char *rname(void)
{
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
		"enes", "cahide", "tayyar", "cansu", "burak", "ediz", "sefa", "anil", "alev", "atil", "muruvvet",
		"nefes", "cetin", "tansu", "bora", "sevim", "sarp", "fuat", "kaya", "zarife", "tanju", "sadettin",
		"su", "kerem", "handesu", "jade", "halime", "gurbuz", "okan", "azmi", "sevda", "leyla", "hilal",
		"galip", "alican", "atakan", "feramuz", "efecan", "osman", "nihat", "sefer", "zerrin", "binnur",
		"taner", "kayahan", "nalan", "tonguc", "kezban", "kaan", "abdulmuttalip", "dost", "deniz", "refika",
		"tijen", "umit", "yunus", "zahit", "melisa", "hulki", "hilmi", "edip", "muslum", "canan",
		"dogan", "berivan", "adnan", "helin", "fikret", "derya", "sidre", "abdullah", "billur", "nurdan",
		"agah", "engin", "burhan", "suheyla", "esra", "sadri", "sezai", "esen", "askin", "rupen", "pinat",
		"ercument", "birhan", "ahmet", "polathan", "tayfun", "mustafa", "zubeyde", "pakize", "nevsin", "naciye",
		"erdem", "asim", "orkun", "sami", "sade", "demet", "keriman", "yavuz", "mehmet", "muhsin",
		"saniye", "cesim", "aydan", "eda",
		};

	return pnames[rand() % asize(pnames)];
}


PRIVATE const char *rsurname(void)
{
	static const char* const psnames[] = {
        "uyar", "poturgeli", "fincan", "tercan", "pakdamar", "onaran", "avci", "lokmaci", "yanardoner", "portakal",
        "fitrat", "kalemsiz", "etci", "degirmenci", "renacan", "yavas", "ortaca", "beyaz", "oztoklu", "aylak",
        "sucu", "kapici", "yelden", "serinsun", "kotek", "nurtopu", "dingin", "uraz", "koylu", "safkan",
        "bahceli", "zengin", "yeldirmen", "soylu", "hurmaci", "alemdar", "karaorman", "fakir", "candamar", "celik",
        "gumus", "agaoglu", "komurcu", "kalpsiz", "kara", "dokuzcan", "comakci", "adiguzel", "kilicdar", "ecevit",
        "karaduman", "yaradan", "tekinalp", "erim", "yildirim", "temizkalp", "yasmak", "akkay", "bilgic", "zaimoglu",
        "emirkulu", "cuhadar", "kayabasi", "tertemiz", "merdane", "gurkas", "topkapi", "altinorak", "unalmis", "karakis",
        "demirdogen", "sonuzun", "uluocak", "yeldirme", "sonmez", "bakirci", "ovacik", "yasli", "damar", "bayraktar",
        "yurtsuz", "saricakir", "koralp", "edepsiz", "kelepce", "mazgirt", "muglali", "geldik", "simsek", "supuren",
        "karayel", "maganda", "tufancan", "yosun", "bekar", "ademoglu", "pirlanta", "konca", "oltu", "kirci",
        "kosnuk", "ersoy", "kulaksiz", "kalinkas", "tamirci", "altinisik", "sarikafa", "ozvezneci", "gilgamis", "yurdakul",
        "efelik", "osmaneli", "boztas", "yilmaz", "yorganci", "reis", "resimci", "engerek", "derin", "acar",
        "yilgin", "telek", "tilki", "temizel", "dokmeci", "orhancan", "azmak", "aslan", "uzunadam", "komcu",
        "ordulu", "gedik", "tokatci", "kolcak", "esbereli", "kazanci", "samanci", "konak", "takes", "karakoyun",
        "kalpten", "tuztas", "baturalp", "harmanci", "tuzcu", "akarsu", "cankoc", "yasayavas", "yersiz", "yangin",
        "semiz", "altindag", "hepguler", "terlemez", "celiker", "karaelmas", "girit", "cangoz", "zalim", "yanardag",
        "korukcu", "erdogan", "baklavaci", "kirboga", "silifkeli", "cevikkol", "engereke", "firatonu", "uslu", "cilingir",
        "kusmen", "kahraman", "elebasi", "daglarca", "ormanci", "umutsuz", "arcan", "keskin", "tekkilic", "otaci",
        "tepsici", "karabatur", "edepli", "bozkaya", "soysalan", "aklikit", "tamgun", "akkuyu", "unkapani", "canbay",
        "kucukkaya", "serce", "tepecik", "dumbuk", "akyoldas", "merzifon", "cengaver", "kilinc", "yolyapan", "nazik",
        "mirza", "salca", "gultekin", "yaygara", "acuka", "kapan", "kesman", "demirel", "tozkoporan", "olmez",
        "tantana", "akyildiz", "karamuk", "eloglu", "yagizeli", "tunali", "kocyigit", "yorgun", "cansever", "sarpdemir",
        "yikilmaz", "karakuzu", "Iliksiz", "unalan", "sofuoglu", "girik", "ulakci", "temiz", "akgunes", "yavasakan",
        "kaplan", "ergin", "elitemiz", "selercan", "elkizi", "polatkan", "sener", "uzay", "yurekli", "dosteli",
        "akcalar", "gamsiz", "ongun", "kurban", "lalezar", "jilet", "sulugoz", "tarumar", "miskin", "sefiloglu",
        "savaskan", "sivri", "topatan", "karasaban", "kurtulus", "mertek", "acgoze", "ertakan", "miskinoglu",
        "fedai", "yurekyakan", "karataban", "saferikli", "malazgirt", "esteberli", "kilimci", "soyubozuk"
	    };

	return psnames[rand() % asize(psnames)];

}


PRIVATE const char* rtown(void)
{
	static const char* const ptowns[] = {
        "izmir", "afyonkarahisar", "kilis", "bolu", "yalova", "giresun", "tunceli", "manisa", "cankiri", "canakkale",
        "mugla", "isparta", "ankara", "kahramanmaras", "nigde", "kirklareli", "artvin", "kirikkale", "bursa", "bingol",
        "sirnak", "erzincan", "gaziantep", "bayburt", "tekirdag", "kocaeli", "trabzon", "ardahan", "elazig", "karabuk",
        "samsun", "malatya", "aksaray", "van", "kars", "amasya", "kirsehir", "balikesir", "eskisehir", "sanliurfa",
        "adiyaman", "mardin", "bilecik", "hakkari", "mus", "kayseri", "agri", "sinop", "istanbul", "mersin",
        "aydin", "sivas", "yozgat", "igdir", "sakarya", "burdur", "antalya", "osmaniye", "konya", "tokat",
        "zonguldak", "corum", "batman", "adana", "usak", "denizli", "edirne", "karaman", "ordu", "diyarbakir",
        "siirt", "kutahya", "bitlis", "bartin", "nevsehir", "rize", "kastamonu", "duzce", "erzurum", "gumushane",
        "hatay",
        };

	return ptowns[rand() % asize(ptowns)];

}


Student* random_student(Student *p)
{
	p->no_ = rand();
	strcpy(p->name_, rname());
	strcpy(p->surname_, rsurname());
	strcpy(p->town_, rtown());
	random_date(&p->bdate_);

	return p;
}


void print_student(const Student *p)
{
	printf("%-8d %-16s %-20s %-16s ", p->no_, p->name_, p->surname_, p->town_);
	print_date(&p->bdate_);
}


int cmpStudentbyName(const Student*p1, const Student *p2)
{
	return strcmp(p1->name_, p2->name_);
}

int cmpStudentbySurname(const Student* p1, const Student *p2)
{
	return strcmp(p1->surname_, p2->surname_);
}

int cmpStudentbyNo(const Student* p1, const Student *p2)
{
	return p1->no_ - p2->no_;
}

int cmpStudentbyDate(const Student* p1, const Student *p2)
{
	return cmp_date(&p1->bdate_, &p2->bdate_);
}

int cmpStudentbyTown(const Student* p1, const Student *p2)
{
	return strcmp(p1->town_, p2->town_);
}
