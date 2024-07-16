outfile : clear_scr.o main.o stud_add.o stud_del.o stud_delete_all.o stud_mod.o stud_reverse.o stud_save.o stud_show.o stud_sort.o
	cc clear_scr.c main.c stud_add.c stud_del.c stud_delete_all.c stud_mod.c stud_reverse.c stud_save.c stud_show.c stud_sort.c

clear_scr.o : clear_scr.c
	cc -c clear_scr.c
main.o : main.c
	cc -c main.c
stud_add.o : stud_add.c
	cc -c stud_add.c
stud_del.o : stud_del.c
	cc -c stud_del.c
stud_delete_all.o : stud_delete_all.c
	cc -c stud_delete_all.c
stud_mod.o : stud_mod.c
	cc -c stud_mod.c
stud_reverse.o : stud_reverse.c
	cc -c stud_reverse.c
stud_save.o : stud_save.c
	cc -c stud_save.c
stud_show.o : stud_show.c
	cc -c stud_show.c
stud_sort.o : stud_sort.c
	cc -c stud_sort.c

