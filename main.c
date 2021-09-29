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
struct node *root=NULL;
void reverse()
{
    struct node *p,*q;
    int i=0,j= length()-1,temp;
    p,q=root;
    while(i<j)
    {
        int k =0;
        while(k<j)
        {
            q=q->link;
            k++;
        }
        temp=p->data;
        p->data=q->data;
        q->data=temp;
    }
    i++;
    j--;
    p=p->link;
    q=root;
}
