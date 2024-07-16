#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

typedef struct student
{
	int rn;
	char name[20];
	float marks;
	struct student *next;
}SLL;

typedef char u8;

void stud_add(SLL **);
void stud_read(SLL **);
void sort_rn(SLL *);

void stud_del(SLL **);
void del_roll(SLL **);
void del_name(SLL **);

void stud_show(SLL *);

void stud_mod(SLL *);
void search_rn(SLL *);
void search_name(SLL *);
void search_perc(SLL *);
void choice(SLL *);
void change_name(SLL *);
void change_perc(SLL *);
void change_both(SLL *);

void stud_save(SLL *);
void save(SLL *);
void stud_sort(SLL *);
int count(SLL *);
void sort_name(SLL *);
void sort_perc(SLL *);
void stud_delete_all(SLL **);
void stud_reverse(SLL **);
void clr(void);
