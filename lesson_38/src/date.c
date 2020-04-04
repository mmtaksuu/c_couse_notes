#define _CRT_SECURE_NO_WARNINGS

#include "date.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define  PUBLIC
#define  PRIVATE		static

#define  YEARBASE			1900
#define  ISLEAP(y)			((y) % 4 == 0 && ((y) % 100 != 0 || (y) % 400 == 0))
#define  MDAY(y, m)			(daytabs[ISLEAP(y)][m])
#define  YDAY(y)            (ISLEAP(y) ? 366 : 365)
#define  RANDOM_MIN_YEAR	1940
#define  RANDOM_MAX_YEAR	2020

PRIVATE const int daytabs[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

PRIVATE int is_valid_date(int d, int m, int y);
PRIVATE Date* set(Date *p, int d, int m, int y);
PRIVATE int totaldays(const Date *p);
PRIVATE Date* to_date(Date *p, int totaldays);


//PUBLIC FUNCTIONS

PUBLIC Date* set_date(Date *p, int d, int m, int y)
{
	return set(p, d, m, y);
}

//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

PUBLIC Date* set_date_today(Date *p)
{
	time_t timer;
	time(&timer);
	struct tm* tptr = localtime(&timer);

	int d = tptr->tm_mday;
	int m = tptr->tm_mon + 1;
	int y = tptr->tm_year + 1900;
	return set(p, d, m, y);
}
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

PUBLIC Date* set_date_str(Date *p, const char *pstr)
{
	int d = atoi(pstr);
	int m = atoi(pstr + 3);
	int y = atoi(pstr + 6);

	return set(p, d, m, y);
}
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
PUBLIC Date* set_year(Date *p, int year)
{
	return set(p, p->md, p->mm, year);
}
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
PUBLIC Date* set_month(Date *p, int month)
{
	return set(p, p->md, month, p->my);
}
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
Date* set_month_day(Date *p, int mday)
{
	return set(p, mday, p->mm, p->my);
}
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//get functions //getter //accessor  observer
PUBLIC int get_year(const Date *p)
{
	return p->my;
}
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
PUBLIC int get_month(const Date *p)
{
	return p->mm;
}
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

PUBLIC int get_month_day(const Date *p)
{
	return p->md;
}
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
int get_week_day(const Date *p)
{
	const int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
	int y = p->my;
	int m = p->mm;
	int d = p->md;

	if (m < 3)
		y -= 1;

	return ((y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7);
}
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
PUBLIC int get_year_day(const Date *p)
{
	int sum = p->md;

	for (int i = 1; i < p->mm; ++i) {
		sum += MDAY(p->my, i);
	}

	return sum;
}

//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------



PUBLIC void print_date(const Date *p)
{
	static const char *const pmons[] = {
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

	static const char *const pdays[] = {
	"Pazar",
	"Pazartesi",
	"Sali",
	"Carsamba",
	"Persembe",
	"Cuma",
	"Cumartesi",
	};
	printf("%02d %s %d %s\n", p->md, pmons[p->mm], p->my, pdays[get_week_day(p)]);
}

PUBLIC Date* scan_date(Date *p)
{
	//clear_input_buffer();
	int d, m, y;
	scanf("%d%d%d", &d, &m, &y);

	return set(p, d, m, y);
}
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

//utility functions
int get_date_diff(const Date *p1, const Date *p2)
{
	return abs(totaldays(p1) - totaldays(p2));
}
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

int cmp_date(const Date *p1, const Date *p2)
{
	if (p1->my != p2->my)
		return p1->my - p2->my;

	if (p1->mm != p2->mm)
		return p1->mm - p2->mm;

	return p1->md - p2->md;
}

//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
PUBLIC Date *random_date(Date *p)
{
	int y = rand() % (RANDOM_MAX_YEAR - RANDOM_MIN_YEAR + 1) + RANDOM_MIN_YEAR;
	int m = rand() % 12 + 1;
	int d = rand() % MDAY(y, m) + 1;

	return set(p, d, m, y);
}
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

PUBLIC Date* ndaysafter(Date *pdest, const Date *psource, int n)
{
	return to_date(pdest, totaldays(psource) + n);
}
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
















//PRIVATE FUNCTIONS

PRIVATE int is_valid_date(int d, int m, int y)
{
	return y >= YEARBASE &&
		m > 0 && m <= 12 &&
		d > 0 && d <= MDAY(y, m);
}


PRIVATE Date* set(Date *p, int d, int m, int y)
{
	if (!is_valid_date(d, m, y)) {
		fprintf(stderr, "hatali tarih olustu!\n");
		exit(EXIT_FAILURE);
	}

	p->md = d; 
	p->mm = m;
	p->my = y;

	return p;
}

//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

PRIVATE int totaldays(const Date *p)
{
	int sum = get_year_day(p);

	for (int i = YEARBASE; i < p->my; ++i) {
		sum += ISLEAP(i) ? 366 : 365;
	}

	return sum;
}



PRIVATE Date* to_date(Date *p, int totaldays)
{
	int y = YEARBASE;

	while (totaldays > YDAY(y)) {
		totaldays -= YDAY(y);
		++y;
	}
	int m = 1;

	while (totaldays > MDAY(y, m)) {
		totaldays -= MDAY(y, m);
		++m;
	}

	int d = totaldays;

	return set(p, d, m, y);
}
