#include"header.h"
void stud_delete_all(SLL **p)
{
	system("clear");
	int c=1;
	if(*p==0)
	{
		printf("\n\033[1;31m No records in the database\033[0m\n");
		return;
	}
	SLL *del=*p;
	while(del)
	{
		*p=del->next;
		printf("%d : Record is Deleted\n",c++);
		sleep(1);
		free(del);
		del=*p;
	}
	printf("\n\033[1;32m All the records are deleted\033[0m\n");
}

