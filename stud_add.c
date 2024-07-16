#include"header.h"
void stud_add(SLL **p)
{
	if(*p!=0)
		sort_rn(*p);
	int roll=1;
	SLL *new,*t=*p;
	new=malloc(sizeof(SLL));
	while(t)
	{
		if(roll!=t->rn)
			break;
		roll++;
		t=t->next;
	}
	new->rn=roll;
	system("clear");
	printf("Enter name of student: ");
	scanf(" %[^\n]",new->name);
	printf("Enter percentage of student: ");
	scanf("%f",&new->marks);
	new->next=0;
	if(*p==0)
		*p=new;
	else
	{
		SLL *t=*p;
		while(t->next)
			t=t->next;
		t->next=new;
	}
}

void stud_read(SLL **p)
{
	SLL *new;
	FILE *fp=fopen("student.dat","r");
	if(fp==0)
	{
		printf("\n\033[31;1mStudent database not present\033[0m\n");
		return;
	}
	while(1)
	{
		new=malloc(sizeof(SLL));
		if(fscanf(fp,"%d %s %f",&new->rn,new->name,&new->marks )==EOF)
			break;
		new->next=0;
		if(*p==0)
			*p=new;
		else
		{
			SLL *last=*p;
			while(last->next)
				last=last->next;
			last->next=new;
		}
	}
	fclose(fp);
}

void sort_rn(SLL *p)
{
		SLL *p1,*p2,t;
		p1=p;
		int i,j,c=count(p);
		for(i=0;i<c-1;i++)
		{
			p2=p1->next;
			for(j=0;j<c-i-1;j++)
			{
				if(p1->rn>p2->rn)
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

