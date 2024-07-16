#include"header.h"
void stud_del(SLL **p)
{
	system("clear");
	if(*p==0)
	{
		printf("\n\033[1;31mNo records in the database\033[0m\n");
		return;
	}
	while(1)
	{
		printf("\033[4m========DELETE A RECORD=========\033[0m\n\n");
		char op;
		printf("r/R : Enter roll to delete\n");
		printf("n/N : Enter name to delete\n");
		printf("\nEnter your choice: ");
		scanf(" %c",&op);
		switch(op)
		{
			case 'r':
			case 'R': del_roll(p);return;
			case 'n':
			case 'N': del_name(p);return;
			default: printf("Wrong choice\n");
		}
	}
}

void del_roll(SLL **p)
{
	int roll;
	printf("\nEnter the roll number you want to delete: ");
	scanf("%d",&roll);
	SLL *del=*p,*prev;
	while(del)
	{
		if(del->rn==roll)
		{
			printf("\n%3d\t%.20s\t%5.2f",del->rn,del->name,del->marks);
		    	printf("\n\nDeleted the record succesfully\n");
			if(*p==del)
				*p=del->next;
			else
				prev->next=del->next;
		free(del);
		return;
		}
		prev=del;
		del=del->next;
	}
	printf("\n\nNo record with %d roll number\n",roll);
}

void del_name(SLL **p)
{
	int c=0;
	char name[20];
	printf("\nEnter the name you want to delete: ");
	scanf(" %[^\n]",name);
	SLL *del=*p,*prev;
	while(del)
	{
		if(strcmp(del->name,name)==0)
		{
			c++;
			printf("\n%3d\t%.20s\t%5.2f",del->rn,del->name,del->marks);
		}
		del=del->next;
	}
	del=*p;
	if(c==1)
	{
		while(del)
		{
			if(strcmp(del->name,name)==0)
			{
		    		printf("\n\nDeleted the record succesfully\n");
				if(*p==del)
					*p=del->next;
				else
					prev->next=del->next;
				free(del);
				return;
			}
			prev=del;
			del=del->next;
		}	
	}
	else if(c>1)
	{
		printf("\n\nIdentical names found\n");
		del_roll(p);
	}
	else
		printf("\n\nNo records with the name \"%s\" found\n",name);
}
