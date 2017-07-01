#include <stdio.h>
#include <malloc.h>

#define LINKNODEFIRST  6
#define LINKNODESECOND 9

typedef struct linknode{
  int m_Value;
  struct linknode *p_Next;
}LinkNode;

LinkNode * CreateLinkList(LinkNode *pHead , int LinkLength)
{
  int index = 0;
  for(index=0;index<LinkLength;index++)
  { 
    LinkNode *p = (LinkNode *)malloc(sizeof(LinkNode));
    p->m_Value = rand()%10;
    p->p_Next  = pHead->p_Next;
    pHead->p_Next = p;
  }
  return pHead;
}

void PrintLinkList(LinkNode *pHead)
{
  while(NULL!=pHead)
  {
    printf("%d ",pHead->m_Value);
    pHead = pHead->p_Next;
  }
  printf("\n");
}

int main()
{
  LinkNode *pHead1 =  (LinkNode*)malloc(sizeof(LinkNode));
  if(pHead1==NULL)
    return -1;
  else
    pHead1->m_Value = rand()%10;
  pHead1 = CreateLinkList(pHead1,LINKNODEFIRST);
  PrintLinkList(pHead1);

  LinkNode *pHead2 = (LinkNode*)malloc(sizeof(LinkNode));
  if(pHead2==NULL)
    return -1;
  else
    pHead2->m_Value = rand()%10;
  pHead2 = CreateLinkList(pHead2,LINKNODESECOND);
  PrintLinkList(pHead2);
}
