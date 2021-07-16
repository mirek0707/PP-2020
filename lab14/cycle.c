#include "cycle.h"
void print_list (tnode * list)
{
	if (list==NULL)
	{
		printf("LISTA JEST PUSTA\n");
		return;
	}
	tnode *wsk=list;
	do
	{
		printf("%d ",list->value);
		list=list->next;
	}
	while (list!=wsk);
	return;
}
tnode * add_el(tnode * head, tnode * el)
{
  tnode * p = head;
  if (head==NULL) 
  {
		head = el;
		el->next = head;
  }
  else
  {
        while(1)
        {
            if(p->next == head||p->next==NULL)
                break;
            p = p->next;
        }
        p->next = el;
        el->next = head;
  }

  return head;

} 
tnode * add_list (tnode *head1, tnode *head2)
{
	tnode *p=head1;
	while ((head1)->next!=p)
		(head1)=(head1)->next;
	(head1)->next=head2;
	(head1)=(head1)->next;
	while ((head1)->next!=head2)
		(head1)=(head1)->next;
	(head1)->next=p;
	head2=NULL;
	head1=(head1)->next;
	return p;
}
void free_list(tnode** head)
{
    tnode *p= *head;
    tnode *nextp= NULL;
    while (*head != NULL && (*head)->next != p)
    {
      nextp=(*head)->next;

      free(*head);
      *head=nextp;
    }

    free(*head);
}
void rev_list (tnode **head)
{
  tnode *rev = NULL;
  while (*head!=NULL) 
  {
    tnode *n=(*head)->next;
    (*head)->next = rev;
    rev = *head;
    *head = n;
  }
  rev = rev->next;
  *head = rev;
}
void del_el(struct tnode** head, int var)
{
  if (*head == NULL)
  {
    printf("LISTA JEST PUSTA\n");
    return;
  }
  tnode *akt = *head;
  tnode *pop = akt;
  int dl=0, i=0;
  while (pop->next != *head) 
  {
    pop = pop->next;
    dl++;
  }

  while (i <= dl)
  {
    if (akt->value==var)
    {
      if (akt->next != akt)
      {
        pop->next = akt->next;
      }
      else
      {
        pop->next = NULL;
      }

      if (akt == *head)
      {
        *head = pop->next;
      }
      free(akt);
      if (pop != NULL && pop->next != NULL)
      {
        akt = pop->next;
      }
      else
      {
        akt = NULL;
      }
    }
    else 
    {
      pop= akt;
      akt=akt->next;
    }
    i++;
  }
}
tnode* div_list(struct tnode** head)
{
  int i = 0;
  int ilosc = 0;

  tnode *head2 = NULL;
  tnode *pop, *akt;

  if (*head == NULL)
  {
    printf("LISTA JEST PUSTA\n");
    return NULL;
  }

  akt= *head;
  pop=akt;

  while(pop->next != *head)
  {
    pop = pop->next;
    ilosc++;
  }

  while (i <= ilosc)
  {
    if (akt->value % 2 == 1)
    {
      if (akt->next != akt)
      {
        pop->next = akt->next;
      } 
      else 
      {
        pop->next = NULL;
      }
      if (akt == *head) 
      {
        *head = pop->next;
      }
      head2 = add_el(head2, akt);
      if (pop != NULL) 
      {
        akt = pop->next;
      } 
      else
      {
        akt = NULL;
      }
    } 
    else 
    {
      pop = akt;
      akt = akt->next;
    }
    i++;
  }
  return head2;
}