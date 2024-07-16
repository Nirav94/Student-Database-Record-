#include"header.h"
void stud_mod(SLL *p)
{
	system("clear");
	if(p==0)
	{
		printf("\n\033[1;31mNo records in the database\033[0m\n");
		return;
	}
	while(1)
	{
		printf("\033[4m========MODIFY A RECORD=========\033[0m\n");
		char op;
		printf("\nEnter which record to search for modification\n");
		printf("r/R : To search a rollno\n");
		printf("n/N : To search a name\n");
		printf("p/P : To search based on percentage\n");
		printf("g/G : Go back\n");
		printf("\nEnter your choice: ");
		scanf(" %c",&op);
		switch(op)
		{
			case 'R': search_rn(p);return;
			case 'N': search_name(p);return;
			case 'P': search_perc(p);return;
			case 'G': system("clear");return;
			default : printf("Wrong choice\n");
		}
	}
}

void search_rn(SLL *p)
{
	int roll;
	char op;
	printf("\nEnter the roll number of the record you want to modify: ");
	scanf("%d",&roll);
	while(p)
	{
		if(p->rn==roll)
		{
			printf("\n%3d\t%.20s\t%5.2f\n",p->rn,p->name,p->marks);
			choice(p);
			return;	
		}
		p=p->next;
	}
	printf("\nNo record with %d roll number\n",roll);
}

void search_name(SLL *p)
{
	int roll,c=0;
	char s[20];
	SLL *temp=p;
	printf("\nEnter the name of the record you want to modify: ");
	scanf(" %[^\n]",s);
	while(temp)
	{
		if((strcmp(temp->name,s))==0)
		{
			c++;
			printf("\n%3d\t%.20s\t%5.2f",temp->rn,temp->name,temp->marks);
		}
		temp=temp->next;
	}
	temp=p;
	if(c==1)
	{
		while(temp)
		{
			if(strcmp(temp->name,s)==0)
			{
				choice(temp);
				return;
			}
			temp=temp->next;
		}	
	}
	else if(c>1)
	{
		printf("\n\nIdentical names found\n");
		search_rn(p);
	}
	else
		printf("\nNo records with the name \"%s\" found\n",s);
}

void search_perc(SLL *p)
{
	int roll,c=0;
	float mark;
	SLL *temp=p;
	printf("\nEnter the percentage of the record you want to modify: ");
	scanf("%f",&mark);
	while(temp)
	{
		if(temp->marks==mark)
		{
			c++;
			printf("\n%3d\t%.20s\t%5.2f",temp->rn,temp->name,temp->marks);
		}
		temp=temp->next;
	}
	temp=p;
	if(c==1)
	{
		while(temp)
		{
			if(temp->marks==mark)
			{
				choice(temp);
				return;
			}
			temp=temp->next;
		}	
	}
	else if(c>1)
	{
		printf("\n\nIdentical percentage found\n");
		search_rn(p);
	}
	else
		printf("\nNo stduent with the %f percentage found\n",mark);
}

void choice(SLL *p)
{
	char op;
	while(1)
	{
		printf("\n\033[35mn/N: To change name\n");
		printf("p/P: To change percentage\n");
		printf("b/B: To change name and percentage\n");
		printf("r/R: To return without changing\n");
		printf("\nEnter your choice: \033[0m");
		scanf(" %c",&op);
		op=op|32;
		switch(op)
		{
			case 'n': change_name(p);return;
			case 'p': change_perc(p);return;
			case 'b': change_both(p);return;
			case 'r': return;
			default:printf("Wrong choice\n");
		}
	}
}

void change_name(SLL *p)
{
	char name[20];
	printf("\nEnter the new name: ");
	scanf(" %[^\n]",name);
	strcpy(p->name,name);
	printf("\nThe record has modified successfully\n");
}

void change_perc(SLL *p)
{
	printf("\nEnter the new percentage: ");
	scanf("%f",&p->marks);
	printf("\nThe record has modified successfully\n");
}

void change_both(SLL *p)
{
	char name[20];
	printf("\nEnter the new name: ");
	scanf(" %[^\n]",name);
	strcpy(p->name,name);
	printf("\nEnter the new percentage: ");
	scanf("%f",&p->marks);
	printf("\nThe record has modified successfully\n");
}
