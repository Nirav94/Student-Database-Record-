#include"header.h"

void stud_reverse(SLL **p)
{
	system("clear");
	if(*p==0)
	{
		printf("\n\033[1;31mNo records in the database\033[0m\n");
		return;
	}
	int c=count(*p);
	if(c>1)
	{
		SLL **ptr,*t=*p;
		ptr=malloc(sizeof(SLL *)*c);
		int i=0;
		while(t)
		{
			ptr[i++]=t;
			t=t->next;
		}
		for(i=1;i<c;i++)
			ptr[i]->next=ptr[i-1];
		ptr[0]->next=0;
		*p=ptr[c-1];
	}
}
