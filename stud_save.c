#include"header.h"
void stud_save(SLL *p)
{
	char op;
	while(1)
	{
		printf("\nEnter\n");
		printf("s/S : Save and exit\n");
		printf("e/E : Exit witohut saving\n");
		printf("\nEnter your choice: ");
		scanf(" %c",&op);
		switch(op)
		{
			case 's':
			case 'S': save(p);
			case 'e':
			case 'E': exit(0);break; 
			default: printf("Wrong choice please enter again\n");
		}
	}
}

void save(SLL *p)
{
//	sort_rn(p);
	FILE *fp=fopen("student.dat","w");
	while(p)
	{
		fprintf(fp,"%d %s %f\n",p->rn,p->name,p->marks);
		p=p->next;
	}
	fclose(fp);
	printf("File saved Succesfully\n");
	sleep(2);
}

