/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *link;
};
struct node *root= NULL;
int len;
void append(void);
void display(void);
int length(void);
void atbrgin(void);
void atafter(void);
void atanywhere(void);
void delete(void);
void append()
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("enter the data");
    scanf("%d",&temp->data);
    temp->link=NULL;
    if(root == NULL)
    {
        root=temp;
    }
    else
    {
        struct node *p;
        p=root;
        while(p->link!=NULL)
        {
            p=p->link;
            
        }
        p->link=temp;
    }
}
int length()
{
    struct node *temp;
    temp=root;
    int count = 0;
    while(temp!=NULL)
    {
        count+=1;
        temp=temp->link;
    }
    return count;
}
void atbegin()
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data");
    scanf("%d",&temp->data);
    temp->link=NULL;
    if (root==NULL)
    {
        root=temp;
    }
    else
    {
        temp->link=root;
        root=temp;
    }
}
void display()
{
    struct node *temp;
    temp=root;
    if(temp==NULL)
    {
        printf("List is empty ");
    }
    else
    {
        while(temp!=NULL)
        {
        printf("%d-->",temp->data);
        temp=temp->link;
        }
        printf("\n\n");
    }
    
}
void delete()
{
    struct node *temp;
    int loc;
    printf("Enter location ");
    scanf("%d",&loc);
    if(loc>length())
    {
        printf("error ");
    }
    else if (loc==1)
    {
        temp = root;
        root=temp->link;
        temp->link = NULL;
        free(temp);
    }
    else
    {
        struct node *p=root,*q;
        int i=1;
        while(i<length()-1)
        {
            p=p->link;
            
        }
        q=p->link;
        p->link=q->link;
        q->link=NULL;
        free(q);
    }
}
void atanywhere()
{
    struct node* temp,*p;
    int loc,len ,i=1;
    printf("Enter the location ");
    scanf("%d",&loc);
    if (loc>length())
    {
        printf("invalid");
        
    }
    else
    {
     p=root;
     while(i<length())
     {
        p=p->link;
        p++;
        
     }
     temp=(struct node*)malloc(sizeof(struct node));
     temp->link=p->link;
     p->link=temp;
    }
}
int main()
{
int choice;
while(1)
{
                printf("\nChoose the option:");
                printf("\n\n1.Insert data\n");
                printf("2.Add at begning\n");
                printf("3.Add after specific\n");
                printf("4.Length\n");
                printf("5.Display all elements\n");
                printf("6.Delete Element\n");
                printf("7.Quit\n");
                scanf("%d",&choice);
                switch (choice)
                {
                case 1:
                    append();
                    break;
                case 2:
                    atbegin();
                    break;
                case 3:
                    atanywhere();
                    break;
                case 4:
                    if(length()==0)
                    {
                    printf("List have no element");
                    break;
                    }
                    printf("The Length of current list is %d",length());
                    break;
                case 5:
                    display();
                    break;
                case 6:
                    delete();
                    break;        
                case 7:
                    exit(0);
                    break;        
                default:
                    printf("wrong choice entered");
                    break;
                }
        
}
return 0;
}

