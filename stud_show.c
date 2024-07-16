#include"header.h"

void stud_show(SLL *ptr)
{
	system("clear");
	if(ptr==0)
	{
		printf("\033[31m========================\n");
		printf("List is empty\n");
		printf("========================\033[0m\n");
		return;
	}
	printf("\033[32m========================\n");
	printf("R.no\tName\tMarks\n\n");
	while(ptr)
	{
		printf("%3d\t%.20s\t%5.2f\n",ptr->rn,ptr->name,ptr->marks);
		ptr=ptr->next;
	}
	printf("========================\033[0m\n");	
}
