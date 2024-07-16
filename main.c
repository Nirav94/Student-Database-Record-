#include"header.h"

int main()
{
	SLL *head=0;
	u8 op;
	stud_read(&head);
	while(1)
	{
		printf("\n\n\033[4m*****STUDENT RECORD MENU*****\033[0m\n");
		printf("\na/A   : add new record\n");
		printf("d/D   : delete a record\n");
		printf("s/S   : show the list\n");
		printf("m/M   : modify a record\n");
		printf("v/V   : save\n");
		printf("e/E   : exit\n");
		printf("t/T   : sort the list\n");
		printf("l/L   : delete all the records\n");
		printf("r/R   : reverse the list\n");
		printf("c/C   : clear screen\n");
		printf("\nEnter your choice: ");
		scanf(" %c",&op);
		switch(op)
		{
			case 'A'^32:stud_add(&head);break;
			case 'D'^32:stud_del(&head);break;
			case 'S'^32:stud_show(head);break;
			case 'M'^32:stud_mod(head);break;
			case 'V'^32:save(head);break;
			case 'E'^32:stud_save(head);break;
			case 'T'^32:stud_sort(head);break;
			case 'L'^32:stud_delete_all(&head);break;
			case 'R'^32:stud_reverse(&head);break;
			case 'C'^32:clr();break;
			default: printf("Wrong choice\n");
		}
	}
}
