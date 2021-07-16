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
void dodaj_rosnaco(tnode** head,char val)
{
    tnode* a=* head;
    if(a==NULL)
    {
        dodaj_na_poczatek(head,val);
    }
    else if (val<a->value)
    {
        dodaj_na_poczatek(head,val);
    }
    else
    {
        tnode* w;
        tnode* n=malloc(sizeof(tnode));
        while(a->next!=NULL)
        {
            if(val<a->next->value)
            {
                w=a->next;
                n->value=val;
                a->next=n;
                n->next=w;
                break;
            }
            else 
            {
                a=a->next;
            }
        }
        if(a->next==NULL)
        {
            dodaj_na_koniec(head,val);
        }
    }

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


int main ()
{
    tnode* head=NULL;
    dodaj_rosnaco(&head,'a');
    dodaj_rosnaco(&head,'j');
    dodaj_rosnaco(&head,'k');
    dodaj_rosnaco(&head,'z');
    dodaj_rosnaco(&head,'w');
    wyswietl(head);
    printf("\n");

    zwolnij(head);
    return 0;
}