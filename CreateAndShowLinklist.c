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
    p->m_Value = (rand()+2)%10;
    p->p_Next  = pHead->p_Next;
    pHead->p_Next = p;
  }
  return pHead;
}

void PrintLinkList(LinkNode *pHead)
{
  LinkNode * pTemp = pHead;
  while(NULL!=pTemp)
  {
    printf("%d ",pTemp->m_Value);
    pTemp = pTemp->p_Next;
  }
  printf("\n");
}

void Destroy(LinkNode ** pHead)
{
  if(NULL == pHead || NULL == *pHead)
  {
    return;
  }
  LinkNode *pNext = NULL;;
  while(NULL!=*pHead)
  {
    pNext = (*pHead)->p_Next;
    free(*pHead);
    *pHead = pNext;
  }
  return;
}

LinkNode * AddSumLinkList(LinkNode *pHead1,LinkNode *pHead2)
{
  LinkNode *p1        = pHead1;
  LinkNode *p2        = pHead2;
  LinkNode *pSumHead  = (LinkNode*)malloc(sizeof(LinkNode));
  pSumHead->m_Value   = -1;
  LinkNode *pFind     = pSumHead;
  int flag            = 0;
  for(p1=pHead1,p2=pHead2;p1!=NULL||p2!=NULL;p1=(p1==NULL?NULL:p1->p_Next),p2=(p2==NULL?NULL:p2->p_Next),pFind=pFind->p_Next)
  {
    LinkNode *pTemp   = (LinkNode *)malloc(sizeof(LinkNode));
    const int value1  = (p1==NULL?0:p1->m_Value);
    const int value2  = (p2==NULL?0:p2->m_Value);
    printf("value1 = %d , value2 = %d\n",value1,value2);
    pTemp->m_Value    = (value1 + value2 + flag)%10;
    flag              = (value1 + value2 + flag)/10;
    pFind->p_Next     = pTemp;
  }
  if(flag>0)
  {
    LinkNode *p   = (LinkNode *)malloc(sizeof(LinkNode));
    p->m_Value    = flag;
    pFind->p_Next = p;
  } 
  return pSumHead->p_Next;
}

LinkNode * MergeLinkList(LinkNode *pHead1,LinkNode * pHead2)
{
  if(NULL==pHead1)  return pHead2;
  if(NULL==pHead2)  return pHead1;
  LinkNode * pMergeHead = NULL;
  if(pHead1->m_Value < pHead2->m_Value)
  {
    pMergeHead = pHead1;
    pMergeHead->p_Next = MergeLinkList(pHead1->p_Next,pHead2);
  }
  else
  {
    pMergeHead = pHead2;
    pMergeHead->p_Next = MergeLinkList(pHead1,pHead2->p_Next);
  }
  return pMergeHead;
}

void LinkListBubbleSort(LinkNode *pHead,int len)
{
   if(NULL == pHead)
   {
     return;
   }
   int i,j=0;
   for(i=0;i<len-1;i++)
   {
      LinkNode *pTemp = pHead;
      for(j=0;j<len-i-1;j++)
      {
        if(pTemp->m_Value > pTemp->p_Next->m_Value)
        {
          int temp = pTemp->m_Value;
          pTemp->m_Value = pTemp->p_Next->m_Value;
          pTemp->p_Next->m_Value = temp;
        }
        pTemp = pTemp->p_Next;
      }
   }
}

int main()
{
  LinkNode *pHead1 =  (LinkNode*)malloc(sizeof(LinkNode));
  if(pHead1==NULL)
    return -1;
  else
    pHead1->m_Value = (rand()+2)%10;
    pHead1->p_Next  = NULL;
  pHead1 = CreateLinkList(pHead1,LINKNODEFIRST-1);
  PrintLinkList(pHead1);

  LinkNode *pHead2 = (LinkNode*)malloc(sizeof(LinkNode));
  if(pHead2==NULL)
    return -1;
  else
    pHead2->m_Value = (rand()+2)%10;
    pHead2->p_Next  = NULL;
  pHead2 = CreateLinkList(pHead2,LINKNODESECOND-1);
  PrintLinkList(pHead2);
  
  LinkNode * pSumHead   = AddSumLinkList(pHead1,pHead2);
  PrintLinkList(pSumHead);

  LinkListBubbleSort(pHead1,LINKNODEFIRST);
  LinkListBubbleSort(pHead2,LINKNODESECOND);
  PrintLinkList(pHead1);
  PrintLinkList(pHead2);

  LinkNode * pMergeHead = MergeLinkList(pHead1,pHead2);
  PrintLinkList(pMergeHead);

  Destroy(&pHead1);
  Destroy(&pHead2);
 // Destroy(&pSumHead);
}

