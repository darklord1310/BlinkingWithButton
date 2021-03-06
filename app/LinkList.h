#ifndef LinkList_H
#define LinkList_H

typedef struct ListNode ListNode;
typedef struct LinkList LinkList;

struct ListNode
{
    void *data;
    ListNode *next;
};

struct LinkList
{
  ListNode *head, *tail;
  int ListSize;
};


void initLinkList(LinkList *newlist);
void initListNode(ListNode *newNode, void *dataToAdd);
void addToTail(LinkList *list, ListNode *newNode);
void *removeTail(LinkList *list);
void addToHead(LinkList *list, ListNode *newNode);
void *removeHead(LinkList *list);
void displayList(LinkList *list);

#endif // LinkList_H
