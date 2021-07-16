#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct tnode
{
	int value;
	struct tnode *next;
}tnode;

void dodaj_na_poczatek(tnode **head, int val)
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
void dodaj_na_koniec(tnode** head, int val)
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
void wyswietl(tnode* head)
{
    tnode* a=head;

    while (a != NULL)
    {
        printf("%d\n", a->value);
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
int fp (tnode *h1, tnode *h2)
{
    tnode* p1=h1;
    tnode* p2=h2;
    while (p1)
    {
        p2=h2;
        while (p2)
        {
            if (p1->next==p2->next)
            {
                return 1;
            }
            p2=p2->next;
        }
        p1=p1->next;
    }
    return 0;
}
int main ()
{
    int n, i;
    tnode *head1=NULL;
    tnode *head2=NULL;
    tnode *head=NULL;
    scanf ("%d",&n);
    while (n<20)
    {
        if (n==0)
        {

            dodaj_na_koniec(&head,n);
            scanf ("%d",&n);
            while (n<20)
            {
                dodaj_na_koniec(&head,n);
                scanf ("%d",&n);
            }
            break;
        }
        else if (n%2==0)
        {
            dodaj_na_koniec(&head1,n);
        }
        else
        {
            dodaj_na_koniec(&head2,n);
        }
        scanf ("%d",&n);
    }
    tnode* p1=head1;
    tnode* p2=head2;
    while (p1->next)
    {
        p1=p1->next;
    }
    while (p2->next)
    {
        p2=p2->next;
    }
    p1->next=head;
    p2->next=head;
    printf("\n");
    wyswietl (head1);
    printf("\n");
    wyswietl (head2);
    int m=fp(head1, head2);
    printf("maja wspolne elementy (tak/nie):%d\n", m);
    
    if(head1 != NULL && head2 != NULL)
    {
        tnode *temp = head2;
        if(temp->value == 0)
            head2 = NULL;
        while(temp)
        {
            if(temp->next && temp->next->value == 0)
            {
                temp->next = NULL;
                break;
            }
            temp = temp->next;
        }
    }
    zwolnij(head1);
    zwolnij(head2);
    return 0;
}