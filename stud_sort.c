#include"header.h"
void stud_sort(SLL *p)
{
	system("clear");
	if(p==0)
	{
		printf("\033[1;31mNo records in the database\033[0m\n");
		return;
	}
	char op;
	while(1)
	{
		printf("\nEnter\n");
		printf("n/N : Sort with name\n");
		printf("p/P : Sort with percentage\n");
		printf("\nEnter your choice: ");
		scanf(" %c",&op);
		switch(op)
		{
			case 'n':
			case 'N': sort_name(p);stud_show(p);return;
			case 'p':
			case 'P': sort_perc(p);stud_show(p);return; 
			default: printf("Wrong choice please enter again\n");
		}
	}
}

int count(SLL *ptr)
{
	int c=0;
	while(ptr)
	{
		c++;
		ptr=ptr->next;
	}
	return c;
}

void sort_name(SLL *p)
{
	SLL *p1,*p2,t;
	p1=p;
	int i,j,c=count(p);
	for(i=0;i<c-1;i++)
	{
		p2=p1->next;
		for(j=0;j<c-i-1;j++)
		{
			if(strcmp(p1->name,p2->name)>0)
			{
				t.rn=p1->rn;
				strcpy(t.name,p1->name);
				t.marks=p1->marks;

				p1->rn=p2->rn;
				strcpy(p1->name,p2->name);
				p1->marks=p2->marks;

				p2->rn=t.rn;
				strcpy(p2->name,t.name);
				p2->marks=t.marks;
			}
			p2=p2->next;
		}
		p1=p1->next;
	}
}

void sort_perc(SLL *p)
{
	SLL *p1,*p2,t;
	p1=p;
	int i,j,c=count(p);
	for(i=0;i<c-1;i++)
	{
		p2=p1->next;
		for(j=0;j<c-i-1;j++)
		{
			if(p1->marks<p2->marks)
			{
				t.rn=p1->rn;
				strcpy(t.name,p1->name);
				t.marks=p1->marks;

				p1->rn=p2->rn;
				strcpy(p1->name,p2->name);
				p1->marks=p2->marks;

				p2->rn=t.rn;
				strcpy(p2->name,t.name);
				p2->marks=t.marks;
			}
			p2=p2->next;
		}
		p1=p1->next;
	}
}

