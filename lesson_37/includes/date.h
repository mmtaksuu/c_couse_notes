#ifndef DATE_H
#define DATE_H

typedef struct {
	int md, mm, my;
	//
}Date;

//set functions //mutator  //setters
Date* set_date(Date *p, int d, int m, int y);
Date* set_date_today(Date *p);
Date* set_date_str(Date *p, const char *pstr); //04-03_1987
Date* set_year(Date *p, int year);
Date* set_month(Date *p, int month);
Date* set_month_day(Date *p, int mday);


//get functions //getter //accessor  observer
int get_year(const Date *p);
int get_month(const Date *p);
int get_month_day(const Date *p);
int get_week_day(const Date *p); //0 Pazartesi 1 Sali ....
int get_year_day(const Date *p); //1 => 1 Ocak 

//input - output functions
void print_date(const Date *p);
Date* scan_date(Date *p);

//utility functions

Date *random_date(Date *p);
int cmp_date(const Date *p1, const Date *p2);
int get_date_diff(const Date *p1, const Date *p2);
Date* ndaysafter(Date *pdest, const Date *psource, int n);
Date* ndaysbefore(Date *pdest, const Date *psource, int n);
Date* increment(Date *p);
Date* decrement(Date *p);
char* to_string(const Date *p, char *pbuf);





#endif
