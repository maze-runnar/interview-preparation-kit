#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
    int data;
    struct node *lChild;
    struct node *rChild;
};

void swap(struct node *x)
{
    if(x==NULL)
        return;
    struct node *temp;
    temp=x->rChild;
    x->rChild=x->lChild;
    x->lChild=temp;
}

void swapAtD(struct node *start,int h,int d)
{
    if(start==NULL)
        return;
    if(h%d==0)
    {
        swap(start);
    }
    swapAtD(start->lChild,h+1,d);
    swapAtD(start->rChild,h+1,d);
}


struct node* addNode(int i)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->lChild=NULL;
    temp->rChild=NULL;
    temp->data=i;
    return temp;
}

void inorder(struct node *start)
{
    if(start==NULL)
        return;
    inorder(start->lChild);
    cout<<start->data<<" ";
    inorder(start->rChild);
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,l,r;
    struct node* ptrArray[1025]={NULL};
    cin>>n;
    for(int i=1;i<=n;i++)
    {
            if(ptrArray[i]==NULL)
            ptrArray[i]=addNode(i);
            cin>>l>>r;
            if(l!=-1)
            {
                ptrArray[l]=addNode(l);
                ptrArray[i]->lChild=ptrArray[l];
            }
            if(r!=-1)
            {
                ptrArray[r]=addNode(r);
                ptrArray[i]->rChild=ptrArray[r];
            }
    }

    int T,d;
    cin>>T;
    while(T--)
    {
        cin>>d;
        swapAtD(ptrArray[1],1,d);
        inorder(ptrArray[1]);
        cout<<endl;
    }
    return 0;
}
