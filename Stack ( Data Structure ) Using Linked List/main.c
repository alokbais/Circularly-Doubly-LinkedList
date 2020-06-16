#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Stack
{
    struct Node *top;
};

void create(struct Stack *st)
{
    struct Node *p=NULL,*temp=NULL;
    int i,x;

    printf("Enter Size Of Stack : \n");
    scanf("%d",&x);

    st->top=(struct Node *)malloc(sizeof(struct Node));
    st->top->next=NULL;
    p=st->top;

    printf("Enter Information About Stack :\n\n");
    printf("Enter Data Of 1 Node : ");
    scanf("%d",&p->data);
    printf("\n");

    for(i=1;i<x;i++)
    {
        temp=(struct Node *)malloc(sizeof(struct Node));

        printf("Enter Data Of %d Node : ",i+1);
        scanf("%d",&temp->data);
        printf("\n");

        temp->next=p->next;
        p->next=temp;
        p=temp;
    }
}

void Display(struct Node *q)
{
    struct Node *p=q;
    static int i=0;

    if(p==NULL)
    {
        printf("\n-------------------------------------------\n\n");
        printf("Size Of The Stack Is : %d\n\n",i);
        printf("Stack Is As Follows :\n\n");
        return;
    }

    i++;

    if(p)
    {
        Display(p->next);
        printf("%d ",p->data);
        i--;
    }

    if(i==0)
        printf("\n\n-------------------------------------------\n");
}

int main()
{
    struct Stack st;

    create(&st);

    Display(st.top);
    printf("Testing Git");
}
