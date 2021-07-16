#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include"cycle.h"
int rand_int(int a, int b)
{
    return rand() % (b-a+1) + a;
}
int main()
{
	int i;
	tnode *list1=NULL;
	tnode *list2=NULL;
	for (i=0;i<5;i++)
	{
		tnode *elem=malloc(sizeof(tnode));
		elem->value=rand_int(0,20);
		list1=add_el(list1, elem);
	}
	for (i=0;i<4;i++)
	{
		tnode *elem=malloc(sizeof(tnode));
		elem->value=rand_int(0,20);
		list2=add_el(list2, elem);
	}
	print_list(list1);
	printf("\n");
	print_list(list2);
	printf("\n\n");

	printf("po usunieciu 9:\n");
	del_el(&list1, 9);
	print_list(list1);
	printf("\n");
	del_el(&list2, 9);
	print_list(list2);
	printf("\n\n");

	tnode *list;
	list=add_list(list1, list2);
	printf("po polaczeniu:\n");
	print_list (list);
	printf("\n\n");

	rev_list (&list);
	printf("po odwroceniu:\n");
	print_list (list);
	printf("\n\n");
	
	tnode *nieparzyste=NULL;
	nieparzyste=div_list(&list);
	printf("nieparzyste: \n");
	print_list(nieparzyste);
	printf("\nparzyste:\n");
	print_list(list);
	printf("\n\n");
	
	free_list(&list);
	free_list(&nieparzyste);

	return 0;
}
