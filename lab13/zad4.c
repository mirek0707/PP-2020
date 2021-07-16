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
tnode *sklej (tnode** head1, tnode** head2)
{
    tnode *head=NULL;

    dodaj_na_poczatek(&head,'0');
    tnode *p=head;
    while ((*head1)&&(*head2))
    {
        if ((*head1)->value>(*head2)->value)
        {
            p->next=(*head2);
            (*head2)=(*head2)->next;
        }
        else
        {
            p->next=(*head1);
            (*head1)=(*head1)->next;
        }
        p=p->next;
    }
    while (*head1)
    {
        p->next=(*head1);
        (*head1)=(*head1)->next;
        p=p->next;
    }
    while (*head2)
    {
        p->next=(*head2);
        (*head2)=(*head2)->next;
        p=p->next;
    }
    p=head;
    if (p)
    {
        head=p->next;
        free(p);
    }

    return head;
}
int main ()
{
    tnode* head1=NULL;
    tnode* head2=NULL;
    dodaj_rosnaco(&head1,'a');
    dodaj_rosnaco(&head1,'z');
    dodaj_rosnaco(&head1,'l');
    dodaj_rosnaco(&head1,'k');

    dodaj_rosnaco(&head2,'a');
    dodaj_rosnaco(&head2,'b');
    dodaj_rosnaco(&head2,'n');
    dodaj_rosnaco(&head2,'l');
    dodaj_rosnaco(&head2,'w');

    tnode* head3=sklej (&head1, &head2);
    wyswietl(head3);
    zwolnij(head1);
    zwolnij(head2);
    zwolnij(head3);
}
