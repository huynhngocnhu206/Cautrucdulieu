#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
int Info; 
Node* Next; 
}Node;

typedef struct List
{
Node* pHead;
Node* pTail;
}List;

Node *new_ele;

void AddFirst(List &l, Node * new_ele)
{
if (l.pHead==NULL) 
{
l.pHead = new_ele;
l.pTail = l.pHead;
}
else
{
new_ele->Next = l.pHead;
l.pHead = new_ele;
}
}


void AddTail(List &l, Node *new_ele)
{
if (l.pHead==NULL)
{
l.pHead = new_ele;
l.pTail = l.pHead;
}
else
{
l.pTail->Next = new_ele;
l.pTail = new_ele;
}
}


void AddAfter(List &l, Node *q, Node * new_ele)
{
if ( q!=NULL)
{
new_ele->Next = q->Next;
q->Next = new_ele;
if(q == l.pTail)
l.pTail = new_ele;
}
else 
AddFirst(l, new_ele);
}

Node *Search(List l, int k)
{
Node *p;
p = l.pHead;
while((p!= NULL)&&(p->Info != k))
p = p->Next;
return p;
}

void RemoveAfter (List &l, Node *q)
{
Node *p;
if ( q != NULL)
{
p = q ->Next ;
if ( p != NULL)
{
if(p == l.pTail)
l.pTail = q;
q->Next = p->Next;
delete p;
}
}
}
void ReamoveList(List &l)
{
Node *p;
while (l.pHead!= NULL)
{
p = l.pHead;
l.pHead = p->Next;
delete p;
}
l.pTail = NULL;
}

int main()
{
    List l;
    l.pHead = l.pTail = NULL;

    
    Node* node1 = (Node*)malloc(sizeof(Node));
    node1->Info = 5;
    node1->Next = NULL;
    AddTail(l, node1);  

    
    Node* node2 = (Node*)malloc(sizeof(Node));
    node2->Info = 6;
    node2->Next = NULL;
    AddTail(l, node2);  

    
    Node* node3 = (Node*)malloc(sizeof(Node));
    node3->Info = 9;
    node3->Next = NULL;
    AddTail(l, node3);  

    Node* node4 = (Node*)malloc(sizeof(Node));
    node4->Info = 1;
    node4->Next = NULL;
    AddFirst(l, node4);  
    
    Node* temp = l.pHead;
    
    while (temp != NULL)
    {
        printf("%d -> ", temp->Info);
        temp = temp->Next;
    }
    
        Node* searchResult = Search(l, 5);
    if (searchResult != NULL)
    {
        printf("\nTim thay node co gia tri %d.\n", searchResult->Info);
    }
    else
    {
        printf("\nKhong tim thay node co gia tri yeu cau.\n");
    }
    
  
    printf("NULL\n");

    return 0;
}
