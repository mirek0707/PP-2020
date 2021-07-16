#include<stdio.h>
#include<stdlib.h>

typedef struct tnode
{
	char value;
	struct tnode *next;
}tnode;

void dodaj_na_poczatek(tnode **head, char val)
{
    tnode * new_node;
    new_node =  malloc(sizeof(tnode));
    if (new_node == NULL ) 
    {
    	puts("blad"); 
    	exit(1);
    }
    new_node->value = val;
    new_node->next = *head;
    *head = new_node;
}

void wyswietl(tnode* head)
{
	tnode* a=head;

    while (a != NULL) 
    {
        printf("%c\n", a->value);
        a = a->next;
    }
}
void zwolnij(tnode* head)
{
    tnode* a=head;
    tnode* n=head;

    while (a!=NULL) 
    {
        n = a->next;
        free(a);
        a = n;
    }
}

tnode *odwroc (tnode *head)
{
  tnode *w1, *w2;
  if(head)
  {
    w2=head;
    while(w2->next)
    {
      w1=w2->next;
      w2->next=w1->next;
      w1->next=head;
      head=w1;
    }
  }
  return head;
}

int main ()
{
    tnode* head=NULL;
    dodaj_na_poczatek(&head,'i');
    dodaj_na_poczatek(&head,'u');
    dodaj_na_poczatek(&head,'d');
    dodaj_na_poczatek(&head,'f');
    wyswietl(head);
    printf("\n");
    head = odwroc(head);
    wyswietl(head);
    zwolnij(head);
    return 0;
}