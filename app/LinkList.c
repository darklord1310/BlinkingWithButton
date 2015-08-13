#include "LinkList.h"

void initLinkList(LinkList *newlist)
{
  newlist->head = 0;
  newlist->tail = 0;
  newlist->ListSize = 0;
}


void initListNode(ListNode *newNode, void *dataToAdd)
{
  newNode->data = dataToAdd;
  newNode->next = 0;
}


/*
  Return: 1 if empty
          0 if not
*/
int isListEmpty(LinkList *list)
{
  if(list->ListSize == 0)
    return 1;
  else 
    return 0;
}


void addToTail(LinkList *list, ListNode *newNode)
{
  if( isListEmpty(list) )
    list->head = newNode;
  else
    list->tail->next = newNode;
  
  list->tail = newNode;
  list->ListSize++;
}


/*
  Input: firstNode    is the head of the list
*/
void *removeTail(LinkList *list)
{
  ListNode *del, *previousDel;                //previousDel will point to the node before the node being to delete
                                              //del         will point to the node that is to be delete
  void *removeValue;
  
  if(!isListEmpty(list))                      //check if list is not empty
  {
    del = list->head;                         //always assume the del to be the head
    previousDel = 0;
    
    while(del->next != 0)                  //if there is the next node for the del(head), then travel until the last node
    {
      previousDel = del;
      del = del->next;
    }
    
    if(previousDel == 0)
    {
      removeValue = del->data;
      list->head = 0;
      list->tail = 0;
    }
    else
    {
      removeValue = del->data;
      previousDel->next = 0;
      list->tail = previousDel;
    }
    list->ListSize--;
    
  }
  
  return removeValue;
}


void addToHead(LinkList *list, ListNode *newNode)
{
  if(isListEmpty(list))
  {
    list->head = newNode;
    list->tail = newNode;
  }
  else
  {
    newNode->next = list->head;
    list->head = newNode;
  }
  
  list->ListSize++;
}


void *removeHead(LinkList *list)
{
  void *removeValue;
  
  if(!isListEmpty(list))
  {
    removeValue = list->head->data;
    list->head = list->head->next;
    if(list->head == 0)
      list->tail = 0;
    list->ListSize--;
  }
  
  return removeValue;
}



