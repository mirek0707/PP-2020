#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

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
tnode* usun(tnode ** head, char z)
{
    tnode* left=NULL;
    if (*head)
    {
        if (z>='A' && z<='Z')
        {
            z = z + 32;
        }
        tnode* temp=NULL;
        while (*head && ((*head)->value==z || (*head)->value==(z-32)))
        {
            dodaj_na_koniec(&left, (*head)->value);
            temp=*head;
            *head=(*head)->next;
            free(temp);
        }

        tnode * node=*head;
        while(node->next)
        {
            if((node->next->value==z)||(node->next->value==(z-32)))
            {
                dodaj_na_koniec(&left, node->next->value);
                temp=node->next;
                node->next=node->next->next;
                free(temp);
            }
            else
                node=node->next;
        }
    }
    return left;
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
    tnode* l=NULL;
    while (head!=NULL)
    {
        l=head->next;
        free(head);
        head=l;
    }
}

int main ()
{
    tnode* head=NULL;
    dodaj_na_poczatek(&head,'A');
    dodaj_na_poczatek(&head,'l');
    dodaj_na_poczatek(&head,'a');
    dodaj_na_poczatek(&head,' ');
    dodaj_na_poczatek(&head,'m');
    dodaj_na_poczatek(&head,'a');
    dodaj_na_poczatek(&head,' ');
    dodaj_na_poczatek(&head,'k');
    dodaj_na_poczatek(&head,'o');
    dodaj_na_poczatek(&head,'t');
    dodaj_na_poczatek(&head,'a');
    wyswietl(head);

    printf("\n");
    tnode* left=NULL;
    left=usun(&head,'a');

    wyswietl(head);
    printf("\n");

    wyswietl(left);

    zwolnij(head);
    zwolnij(left);
    return 0;
}