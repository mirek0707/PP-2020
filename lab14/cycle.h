#ifndef CYCLE_H
#define CYCLE_H
#include <stdio.h>
#include <stdlib.h>
typedef struct tnode
{
	int value;
	struct tnode *next;
} tnode;
void print_list (tnode * list);
tnode * add_el(tnode * head, tnode * el);
tnode * add_list (tnode *head1, tnode *head2);
void free_list(tnode** head);
void rev_list (tnode **head);

void del_el(struct tnode** head, int var);
tnode* div_list(struct tnode** head);
# endif