#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
}*start=NULL;
void insertEnd(int val)
{
    struct node *curr,*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=val;
    temp->next=NULL;
    if(start==NULL)
    {
        temp->prev=NULL;
        start=temp;
        printf("Value inserted successfully!!");
        return;
    }
    else
    {
        curr=start;
        while(curr->next!=NULL)
        {
            curr=curr->next;
        }
        temp->prev=curr;
        curr->next=temp;
    }
    printf("\nValue inserted successfully!!\n");

}
void insertBeg(int val)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=val;
    temp->prev=NULL;
    if(start==NULL)
    {
        temp->next=NULL;
    }
    else
    {
        temp->next=start;
        start->prev=temp;
    }
    start=temp;
    printf("\nValue inserted successfully!!\n");

}
void display()
{
  struct node *curr=start;
  if(start==NULL)
  {
      printf("\nList is Empty!!\n");
      return;
  }
  printf("\nThe linked list is :-\n");
  while(curr!=NULL)
  {
      printf("%d\t",curr->data);
      curr=curr->next;
  }
  printf("\n\n");
}
void insertPosition(int val,int pos)
{
    struct node *temp,*curr=start;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=val;
    if(pos!=1&&curr==NULL)
    {
        printf("\nList is empty\n");
        return;
    }
    if(pos==1)
    {
        temp->next=start;
        temp->prev=NULL;
        start=temp;
    }
    else if(pos==length()+1)
    {
        while(curr->next!=NULL)
            curr=curr->next;

        temp->next=NULL;
        temp->prev=curr;
        curr->next=temp;
        printf("\nValue Inserted Successfully!!\n");
        return;
    }
    else
    {
        while(pos-1>1&&curr!=NULL)
        {
            curr=curr->next;
            pos--;
        }
        if(curr==NULL)
        {
            printf("\nPosition is outside the list\n");
            return;
        }
        temp->next=curr->next;
        temp->prev=curr;
        curr->next->prev=temp;
        curr->next=temp;
    }
    printf("\nValue inserted successfully!!\n");

}
void delBeg()
{
    struct node *curr=start;
    if(curr==NULL)
    {
        printf("\nList is empty\n");
        return;
    }
    if(curr->next==NULL)
    {
        start=NULL;
        free(curr);
        printf("\nValue Deleted Successfully!!\n");
        return;
    }
    start=start->next;
    start->prev=NULL;
    free(curr);
    printf("\nValue Deleted Successfully!!\n");
}
void delEnd()
{
    struct node *curr=start;
    if(curr==NULL)
    {
        printf("\nList is empty\n");
        return;
    }
    if(curr->next==NULL)
    {
        start=NULL;
        free(curr);
        printf("\nValue Deleted Successfully!!\n");
        return;
    }
    while(curr->next!=NULL)
        curr=curr->next;

        curr->prev->next=NULL;
        free(curr);
        printf("\nValue Deleted Successfully!!\n");
}
void delPosition(int pos)
{
    struct node *curr=start;
    if(curr==NULL)
    {
        printf("\nList is empty\n");
        return;
    }
    if(curr==NULL&&pos!=-1)
    {
        printf("\nList is empty\n");
        return;
    }
    if(pos==1&&curr->next!=NULL)
    {
        start=start->next;
        start->prev=NULL;
        free(curr);
        printf("\nValue deleted successfully\n");
        return;
    }
    if(pos==1&&curr->next==NULL)
    {
        start=NULL;
        free(curr);
        printf("\nValue deleted successfully\n");
        return;
    }
    if(pos==length()+1)
    {
        printf("\nPosition is outside the list\n");
        return;
    }
    while(pos-1>1&&curr!=NULL)
    {
        curr=curr->next;
        pos--;
    }
    if(curr==NULL)
    {
        printf("\nPosition is outside the list\n");
        return;
    }
    struct node *temp;
    temp=curr->next;
    curr->next=temp->next;
    if(temp->next!=NULL)
    temp->next->prev=curr;

    free(temp);
    printf("\nValue deleted successfully\n");
}
int length()
{
    struct node *curr=start;
    int cnt=0;
    while(curr!=NULL)
        {
            cnt++;
            curr=curr->next;
        }

    return cnt;
}

int main()
{
    int val, ch, pos;
    while(1)
    {
        printf("\n****Double Linked List******\n");
        printf("\n1.Insert at the end");
        printf("\n2.Display");
        printf("\n3.Insert at the beginning");
        printf("\n4.Insert at particular position:- ");
        printf("\n5.Delete Beginning");
        printf("\n6.Delete End");
        printf("\n7.Delete Position");
        printf("\n8.Reverse List");
        printf("\n9.Reverse Fake");
        printf("\n10.Exit");
        printf("\nEnter your choice:- ");
        scanf("%d",&ch);

           switch(ch)
           {
           case 1:
            printf("\nEnter the value to enter at the end:- ");
            scanf("%d",&val);
            insertEnd(val);
            break;
           case 2:
             display();
             break;
             case 3:
            printf("\nEnter the value to enter at the beginning:- ");
            scanf("%d",&val);
            insertBeg(val);
            break;
            case 4:
            printf("\nEnter the value:- ");
            scanf("%d",&val);
            printf("\nEnter the position:- ");
            scanf("%d",&pos);
            insertPosition(val,pos);
            break;
            case 5:
            delBeg();
            break;
             case 6:
            delEnd();
            break;
            case 7:
                printf("Enter the position to delete:- ");
                scanf("%d",&pos);
                delPosition(pos);
                break;
            case 8:

           case 10:
            exit(0);
           }
    }
    return 0;
}
