#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct tnode
{
	char value[20];
    int ilosc;
	struct tnode *next;
}tnode;
void dodaj_na_poczatek(tnode **head, char val[20])
{
    tnode * new_node;
    new_node =  malloc(sizeof(tnode));
    if (new_node == NULL ) 
    {
        puts("blad"); 
        exit(1);
    }
    strcpy(new_node->value,val);
    new_node->ilosc = 1;
    new_node->next = *head;
    *head = new_node;
}
void dodaj_na_koniec(tnode** head, char val[20]) 
{
    if (*head==NULL)
    {
        *head=malloc(sizeof(tnode));
        if (head == NULL ) 
        {
            puts("blad"); 
            exit(1);
        }
        strcpy((*head)->value,val);
        (*head)->ilosc=1;
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
        strcpy(current->next->value,val);
        current->next->ilosc=1;
        current->next->next=NULL;
    }
}
void dodaj_rosnaco(tnode** head,char val[20])
{
    tnode* a= *head;
    if(a==NULL)
    {
        dodaj_na_poczatek(head,val);
    }
    else
    {
        while(a)
        {
            if (strcmp(val,a->value)==0)
            {
                a->ilosc=a->ilosc+1;
                return;
            }
            a=a->next;

        }
        a= *head;
        tnode* pop=*head;
        while(a!=NULL)
        {
            if(strcmp(val,a->value)<=0)
            {
                if (a==*head)
                {
                    tnode* n=malloc(sizeof(tnode));
                    strcpy(n->value,val);
                    n->ilosc=1;
                    n->next=a;
                    *head=n;
                }
                else
                {
                    tnode* n=malloc(sizeof(tnode));
                    strcpy(n->value,val);
                    n->ilosc=1;
                    pop->next=n;
                    n->next=a;
                }
                return;
            }
            else
            {
                pop=a;
                a=a->next;
            }
        }
        dodaj_na_koniec(head,val);
    }

}

void wyswietl(tnode* head)
{
	tnode* a=head;

    while (a != NULL) 
    {
        printf("%s: %d\n", a->value, a->ilosc);
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
int main(int argc, char const *argv[])
{
    
    tnode* head=NULL;
    FILE *p= fopen("example.txt", "r");
    if (p==NULL)
    {
        puts("ERR1");
        exit(EXIT_FAILURE);
    }
    char slowo[20];
    while ( fscanf(p,"%s", slowo)==1)
    {
        dodaj_rosnaco(&head, slowo);
    }
    wyswietl(head);
    printf("\n");

    zwolnij(head);
    fclose(p);
    return 0;
}