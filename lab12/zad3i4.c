#include<stdio.h>
#include<stdlib.h>

typedef struct tnode
{
	char value;
	struct tnode *next;
}tnode;

tnode * dodaj_na_poczatek(tnode **head, char val)
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
    return *head;
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
void dodaj_na_koniec(tnode** head, char val) 
{
    if (*head==NULL)
    {
        *head=malloc(sizeof(tnode));
        if (head == NULL ) 
        {
            puts("blad"); 
            exit(1);
        }
        (*head)->value=val;
        (*head)->next=NULL;

    }
    else
    {
        tnode *current=*head;
        while(current->next!=NULL)
        {
            current=current->next;
        }
        current->next=malloc(sizeof(tnode));
        if (current->next == NULL ) 
        {
            puts("blad"); 
            exit(1);
        }
        current->next->value=val;
        current->next->next=NULL;
    }
}

int main ()
{
	tnode* head=NULL;
	head=dodaj_na_poczatek(&head,'c');
	head=dodaj_na_poczatek(&head,'a');
	head=dodaj_na_poczatek(&head,'v');
	head=dodaj_na_poczatek(&head,'f');
	head=dodaj_na_poczatek(&head,'t');
	wyswietl(head);
	zwolnij(head);
    printf("\n");
	head=NULL;
	dodaj_na_koniec(&head,'c');
	dodaj_na_koniec(&head,'a');
	dodaj_na_koniec(&head,'v');
	dodaj_na_koniec(&head,'f');
	dodaj_na_koniec(&head,'t');
	wyswietl(head);
	zwolnij(head);

}