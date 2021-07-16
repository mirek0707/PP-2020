#include <stdlib.h>
#include <stdio.h>
#include <time.h>
typedef struct tnode 
{
	int value;
	struct tnode *next;
	struct tnode *prev;
}tnode;
int rand_int(int a, int b)
{
    return rand() % (b-a+1) + a;
}
void print_list(struct tnode* head)
{

	while (head!=NULL)
	{
		printf("%d ", head->value);
		head=head->next;
	}
}
struct tnode* add_first(struct tnode* head, struct tnode* el)
{
	el->next=head;
	el->prev=NULL;
	if (head != NULL) 
	{
        head->prev = el; 
	}
	head=el;
	return head;
} 
struct tnode* add_last(struct tnode* head, struct tnode* el)
{
	tnode* l=head;
	el->next=NULL;
	if (head==NULL) 
	{ 
        el->prev=NULL; 
        head=el; 
        return head; 
    } 
    while (l->next != NULL) 
        l=l->next;
    l->next=el;
    el->prev=l; 
    return head;
}
struct tnode* del_el(struct tnode** head, int var)
{
	if (*head==NULL)
    	return NULL;

    tnode* p=*head;

    while (p!= NULL) 
    {
        if (p->value == var) 
        {
            if (*head == p)
            {
                *head = p->next;
            }
            if (p->prev != NULL) 
            {
                p->prev->next = p->next;
            }
            if (p->next != NULL) 
            {
                p->next->prev = p->prev;
            }

            p->next = NULL;
            p->prev = NULL;

            return p;
        } 
        else 
        {
            p = p->next;
        }
    }
    return NULL;
}
void add_sort(struct tnode** head1, struct tnode* el)
{
	tnode* p;
	el->next=NULL;
	if (*head1==NULL)
	{
		*head1=el;
	}
	else if ((*head1)->value>=el->value)
	{
		el->next=*head1;
		el->next->prev=el;
		*head1=el;
	}
	else
	{
		p=*head1;
		while(p->next!=NULL && p->next->value<el->value)
		{
			p=p->next;
		}
		el->next=p->next;
		if (p->next!=NULL)
			el->next->prev=el;
		p->next=el;
		el->prev=p;
	}
}
struct tnode* div_list(struct tnode** head)
{
	tnode* head1=NULL;
	tnode* n;
	tnode* p=*head;
	while (p!=NULL)
	{
		if (p->value%2==0)
		{
			n=p->next;
			
			head1=add_last(head1, del_el(head, p->value));
			p=n;
		}
		else
			p=p->next;
	}
	return head1;	
	
}
void free_list(struct tnode** head)
{
    tnode* l=NULL;
    while (*head!=NULL)
    {
        l=(*head)->next;
        free(*head);
        *head=l;
    }
}

void swap (int* a, int* b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
tnode* partition(struct tnode *pierwszy, struct tnode *ostatni)
{
    int x=ostatni->value;
    tnode *temp=pierwszy->prev;

    for (tnode *i=pierwszy; i!=ostatni; i=i->next)
    {
        if (i->value<=x)
        {
            if(temp==NULL)
            	temp=pierwszy;
            else
            	temp=temp->next;
            swap(&(temp->value), &(i->value));
        }
    }
    if(temp==NULL)
        temp=pierwszy;
    else
        temp=temp->next;
    swap(&(temp->value), &(ostatni->value));

    return temp;
}
void quickSort(tnode* head, tnode *ostatni)
{
    if (ostatni!=NULL && head!=ostatni && head!=ostatni->next)
    {
        tnode *p=partition(head, ostatni);
        quickSort(head, p->prev);
        quickSort(p->next, ostatni);
    }
}
void sort(struct tnode** head) {
    tnode *ostatni=*head;
    while (ostatni && ostatni->next)
    {
        ostatni=ostatni->next;
    }
    quickSort(*head, ostatni);
}

int main ()
{
	tnode * head=NULL;
	//srand(time(NULL)); 
	int i;
	printf("wylosowane elementy:\n");
	for (i=0;i<5;i++)
	{
		tnode *elem=malloc(sizeof(tnode));
		elem->value=rand_int(0,20);
		printf("%d\n", elem->value);
		head=add_first(head, elem);
	}
	printf("lista:\n");
	print_list(head);
	printf("\n\n");

	printf("dodawanie na koniec:\n");
	tnode *elem=malloc(sizeof(tnode));
	elem->value=rand_int(0,20);
	printf("%d\n", elem->value);
	head=add_last(head, elem);
	print_list(head);
	printf("\n\n");

	printf("usuwanie elementu 9:\n");
	int var = 9;
	tnode* d=del_el(&head, var);
	free(d);
	print_list(head);
	printf("\n\n");

	printf("sortowanie:\n");
	sort(&head);
	print_list(head);
	printf("\n\n");

	printf("dodawanie rosnaco:\n");
	elem=malloc(sizeof(tnode));
	elem->value=rand_int(0,20);
	printf("%d\n", elem->value);
	add_sort(&head, elem);
	print_list(head);
	printf("\n\n");

	printf("dzielenie na dwie listy:\n");
	tnode * head1=div_list(&head);
	print_list(head1);
	printf("\n");
	print_list(head);
	printf("\n\n");

	free_list(&head);
	free_list(&head1);
	return 0;
}