#include "LinkList.h"
#include <stdio.h>

void initLinkList(LinkList *newlist)
{
  newlist->head = NULL;
  newlist->tail = NULL;
  newlist->ListSize = 0;
}


void initListNode(void *data)
{
  
  
}


/*
  Return: 1 if empty
          0 if not
*/
int isListEmpty(LinkList *list)
{
  if(list->head == NULL)
    return 1;
  else 
    return 0;
}


void addToTail(LinkList *list, void *dataToAdd)
{
  ListNode *newNode;
  newNode = malloc(sizeof(ListNode)); 
  
  if(newNode != NULL)
  {
    newNode->data = dataToAdd;
    newNode->next = NULL;

    if( isListEmpty(list) )
      list->head = newNode;
    else
      list->tail->next = newNode;
  
    list->tail = newNode;
    list->ListSize++;
  }
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
    previousDel = NULL;
    
    while(del->next != NULL)                  //if there is the next node for the del(head), then travel until the last node
    {
      previousDel = del;
      del = del->next;
    }
    
    if(previousDel == NULL)
    {
      removeValue = del->data;
      list->head = NULL;
      list->tail = NULL;
      //free(list->head);
    }
    else
    {
      removeValue = del->data;
      previousDel->next = NULL;
      list->tail = previousDel;
      //free(del);
    }
    list->ListSize--;
  }
  
  return removeValue;
}


void addToHead(LinkList *list, void *valueToAdd)
{
  ListNode *newNode;
  newNode = malloc(sizeof(ListNode)); 
  newNode->data = valueToAdd;
  newNode->next = NULL;
  
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
    if(list->head == NULL)
      list->tail = NULL;
    list->ListSize--;
  }
  
  return removeValue;
}



