#include <stdio.h>
#include <malloc.h>

#define LINKMAX  10
typedef struct listnode
{
  int m_Value;
  struct listnode *p_Next;
}LinkNode;

void ShowLinkList(LinkNode *pHead)
{
  LinkNode * pNode = pHead;
  while(NULL!=pNode)
  {
    printf("%d ",pNode->m_Value);
    pNode = pNode->p_Next;
  }
  printf("\n");
}

void ReverseMNLinkList(LinkNode *pHead,int from,int to)
{
  LinkNode *pStoreHead = pHead;
  LinkNode *pCurr      = pHead->p_Next;
  int      index       = 0;
  for(index=0;index<from-1;index++)
  {
    pHead = pCurr;
    pCurr = pCurr->p_Next;
  }
  LinkNode *pPrev = pCurr;
  pCurr           = pCurr->p_Next;
  LinkNode *pNext = NULL;
  for(;index<to-1;index++)
  {
    pNext = pCurr->p_Next;
    pCurr->p_Next = pHead->p_Next;
    pHead->p_Next = pCurr;
    pPrev->p_Next = pNext;
    pCurr         = pNext;
  }
  ShowLinkList(pStoreHead);
}

void deleteDuplication(LinkNode **pHead)
{
  if(NULL==pHead || NULL== *pHead)
  {
    return ;
  }
  LinkNode * pPrevNode = NULL;
  LinkNode * pNode     = *pHead;
  while(NULL!=pNode)
  {
    LinkNode *pNext = pNode->p_Next;
    int  needDelete = 0;
    if(NULL!=pNext && pNext->m_Value == pNode->m_Value)
    {
      needDelete = 1;
    }
    if(!needDelete)
    {
      pPrevNode = pNode;
      pNode     = pNode->p_Next;
    }
    else
    {
      int value = pNode->m_Value;
      LinkNode *pToBeDel = pNode;
      while(pToBeDel!=NULL && pToBeDel->m_Value == value)
      {
        pNext = pToBeDel->p_Next;
        free(pToBeDel);
        pToBeDel = NULL;
        pToBeDel = pNext;
      }
      if(NULL==pPrevNode)
      {
        *pHead = pNext;
      }
      else
      {
        pPrevNode->p_Next = pNext;
      }
      pNode = pNext;
    }
  }
}


int main()
{
  LinkNode *pHead = (LinkNode *)malloc(sizeof(LinkNode));
  pHead->m_Value  = -1;
  pHead->p_Next   = NULL;
  int       index = 0;
  int         k   = 0;
  for(index=0;index<LINKMAX;index++)
  {
    LinkNode * pNode = (LinkNode *)malloc(sizeof(LinkNode));
    /*
    if(index<3)
      { k = 5; }
    else if(k<6)
      { k = 9; }
    else
      { k  =8 ;}*/
    pNode->m_Value   = index ;
    pNode->p_Next    = pHead->p_Next;
    pHead->p_Next    = pNode;
  }
  printf("Create a Link List And Show : ");
  ShowLinkList(pHead);
  ReverseMNLinkList(pHead,3,7);
/*
  deleteDuplication(&pHead);
  ShowLinkList(pHead);
*/
}
