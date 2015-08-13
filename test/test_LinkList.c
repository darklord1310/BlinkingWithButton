#include "unity.h"
#include "LinkList.h"

void setUp(void)
{
}

void tearDown(void)
{
}


void test_initLinkList_should_return_a_list_with_head_and_tail_point_to_null_and_ListSize_0(void)
{
  LinkList list;
  initLinkList(&list);
  
  TEST_ASSERT_NULL(list.head);
  TEST_ASSERT_NULL(list.tail);
  TEST_ASSERT_EQUAL(0,list.ListSize);

}


void test_isListEmpty_given_empty_list_should_return_1()
{
  LinkList list;
  initLinkList(&list);
  
  int check = isListEmpty(&list);
  
  TEST_ASSERT_EQUAL(1, check); 
}



/* Before add 1 :  head --> NULL 
                   tail --> NULL
   
   After add 1  :  head --> 1
                   tail --> 1

*/
void test_addToTail_empty_list_and_add_1_should_get_head_is_1_tail_is_1()
{
  LinkList list;
  initLinkList(&list);
  ListNode node1;
  initListNode(&node1, (void*)1);
  
  addToTail(&list, &node1);

  TEST_ASSERT_NOT_NULL(list.head);
  TEST_ASSERT_NOT_NULL(list.tail);
  TEST_ASSERT_EQUAL( list.head->data , (void *)1);
  TEST_ASSERT_EQUAL( list.tail->data , (void *)1);
  TEST_ASSERT_EQUAL(1,list.ListSize);
}


/* Before add 2 :  head --> 1 
                   tail --> 1
   
   After add 2  :  head --> 1
                   tail --> 2

*/
void test_addToTail_given_head_is_1_and_add_2_should_get_head_is_1_tail_is_2()
{
  LinkList list;
  initLinkList(&list);
  ListNode node1;
  initListNode(&node1, (void*)1);
  ListNode node2;
  initListNode(&node2, (void*)2);

  
  addToTail(&list,&node1);
  addToTail(&list,&node2);
  
  TEST_ASSERT_EQUAL( (void *)1, list.head->data);
  TEST_ASSERT_EQUAL( (void *)2, list.tail->data);
  TEST_ASSERT_EQUAL(2,list.ListSize);
}



/* Before add c :  head --> a
                   tail --> b
   
   After add c  :  head --> a
                   tail --> c

*/
void test_addToTail_given_tail_is_b_and_add_c_should_get_head_is_a_tail_is_c()
{
  LinkList list;
  initLinkList(&list);
  ListNode nodeA;
  initListNode(&nodeA, (void*)'a');
  ListNode nodeB;
  initListNode(&nodeB, (void*)'b');
  ListNode nodeC;
  initListNode(&nodeC, (void*)'c');
  
  addToTail(&list,&nodeA);
  addToTail(&list,&nodeB);
  addToTail(&list,&nodeC);
  
  TEST_ASSERT_EQUAL(list.head->data, (void *)'a');
  TEST_ASSERT_EQUAL(list.head->next->data,(void *) 'b');
  TEST_ASSERT_EQUAL(list.tail->data, (void *)'c');
  TEST_ASSERT_EQUAL(3,list.ListSize);
}

/* List : 1 2 3 4 <-- tail
          ^
          |
        head
*/
void test_removeTail_given_sample_list_above_should_get_head_is_1_tail_is_3()
{
  LinkList list;
  initLinkList(&list);
  
  //add
  ListNode node1;
  initListNode(&node1, (void*)1);
  ListNode node2;
  initListNode(&node2, (void*)2);
  ListNode node3;
  initListNode(&node3, (void*)3);
  ListNode node4;
  initListNode(&node4, (void*)4);
  
  
  addToTail(&list,&node1);
  addToTail(&list,&node2);
  addToTail(&list,&node3);
  addToTail(&list,&node4);
  TEST_ASSERT_EQUAL(4,list.ListSize);
  
  //remove
  void *data = removeTail(&list);
  TEST_ASSERT_EQUAL(4, (int)data);
  TEST_ASSERT_EQUAL(3,list.ListSize);
  TEST_ASSERT_EQUAL(list.head->data, (void *)1);
  TEST_ASSERT_EQUAL(list.tail->data, (void *)3);
  
}


/* List : 1 2 3 4 <-- tail
          ^
          |
        head
*/
void test_removeTail_given_sample_list_above_remove_2_times_should_get_head_is_1_tail_is_2()
{
  LinkList list;
  initLinkList(&list);
  
  //add
  ListNode node1;
  initListNode(&node1, (void*)1);
  ListNode node2;
  initListNode(&node2, (void*)2);
  ListNode node3;
  initListNode(&node3, (void*)3);
  ListNode node4;
  initListNode(&node4, (void*)4);
  
  
  addToTail(&list,&node1);
  addToTail(&list,&node2);
  addToTail(&list,&node3);
  addToTail(&list,&node4);
  TEST_ASSERT_EQUAL(4,list.ListSize);
  
  //remove
  void *data = removeTail(&list);
  TEST_ASSERT_EQUAL(4, (int)data);
  TEST_ASSERT_EQUAL(3,list.ListSize);
  TEST_ASSERT_EQUAL(list.head->data, (void *)1);
  TEST_ASSERT_EQUAL(list.tail->data, (void *)3);
  
  data = removeTail(&list);
  TEST_ASSERT_EQUAL(3, (int)data);
  TEST_ASSERT_EQUAL(2,list.ListSize);
  TEST_ASSERT_EQUAL(list.head->data, (void *)1);
  TEST_ASSERT_EQUAL(list.tail->data, (void *)2);
  
}


/* List : 1 2 3 4 <-- tail
          ^
          |
        head
*/
void test_removeTail_given_sample_list_above_remove_3_times_should_get_head_is_1_tail_is_1()
{
  LinkList list;
  initLinkList(&list);
  
  //add
  ListNode node1;
  initListNode(&node1, (void*)1);
  ListNode node2;
  initListNode(&node2, (void*)2);
  ListNode node3;
  initListNode(&node3, (void*)3);
  ListNode node4;
  initListNode(&node4, (void*)4);
  
  addToTail(&list,&node1);
  addToTail(&list,&node2);
  addToTail(&list,&node3);
  addToTail(&list,&node4);
  TEST_ASSERT_EQUAL(4,list.ListSize);
  
  //remove
  void *data = removeTail(&list);
  TEST_ASSERT_EQUAL(4, (int)data);
  TEST_ASSERT_EQUAL(3,list.ListSize);
  TEST_ASSERT_EQUAL(list.head->data, (void *)1);
  TEST_ASSERT_EQUAL(list.tail->data, (void *)3);
  
  data = removeTail(&list);
  TEST_ASSERT_EQUAL(3, (int)data);
  TEST_ASSERT_EQUAL(2,list.ListSize);
  TEST_ASSERT_EQUAL(list.head->data, (void *)1);
  TEST_ASSERT_EQUAL(list.tail->data, (void *)2);
  
  data = removeTail(&list);
  TEST_ASSERT_EQUAL(2, (int)data);
  TEST_ASSERT_EQUAL(1,list.ListSize);
  TEST_ASSERT_EQUAL(list.head->data, (void *)1);
  TEST_ASSERT_EQUAL(list.tail->data, (void *)1);
  
}


/* List : 1 <-- tail
          ^
          |
        head
*/
void test_removeTail_given_sample_list_above_should_get_head_is_NULL_tail_is_NULL()
{
  LinkList list;
  initLinkList(&list);
  
  //add
  ListNode node1;
  initListNode(&node1, (void*)1);
  
  addToTail(&list,&node1);
  TEST_ASSERT_EQUAL(1,list.ListSize);
  
  //remove
  void *data = removeTail(&list);
  TEST_ASSERT_EQUAL(0,list.ListSize);
  TEST_ASSERT_NULL(list.head);
  TEST_ASSERT_NULL(list.tail);
  
}


//boundary test
void test_removeTail_given_empty_list_should_not_do_anything_or_fail()
{
  LinkList list;
  initLinkList(&list);
  removeTail(&list);
  
  TEST_ASSERT_NULL(list.head);
  TEST_ASSERT_NULL(list.tail);
  TEST_ASSERT_EQUAL(0,list.ListSize);
}


/* List : 2 3 <-- tail
          ^
          |
        head
*/
void test_addToHead_given_sample_list_above_and_add_1_should_get_head_is_1()
{
  //set up test condition
  LinkList list;
  initLinkList(&list);
  ListNode node1;
  initListNode(&node1, (void*)1);
  ListNode node2;
  initListNode(&node2, (void*)2);
  ListNode node3;
  initListNode(&node3, (void*)3);
  addToTail(&list, &node2);
  addToTail(&list, &node3);

  
  //test add to head
  addToHead(&list, &node1);
  TEST_ASSERT_EQUAL(3,list.ListSize);
  TEST_ASSERT_EQUAL(list.head->data, (void *)1);
  TEST_ASSERT_EQUAL(list.head->next->data, (void *)2);
  TEST_ASSERT_EQUAL(list.head->next->next->data, (void *)3);
  TEST_ASSERT_EQUAL(list.tail->data, (void *)3);
}


//boundary test
void test_addToHead_given_empty_list_and_add_1_should_get_head_is_1_tail_is_1()
{
  //set up test condition
  LinkList list;
  initLinkList(&list);
  ListNode node1;
  initListNode(&node1, (void*)1);
  
  //test add to tail
  addToHead(&list, &node1);
  TEST_ASSERT_EQUAL(1,list.ListSize);
  TEST_ASSERT_EQUAL(list.head->data, (void *)1);
  TEST_ASSERT_EQUAL(list.tail->data, (void *)1);
}


/* List : 0 1 2 <-- tail
          ^
          |
        head
*/
void test_removeHead_given_sample_list_above_should_get_head_is_1_tail_is_2()
{
  //set up test condition
  LinkList list;
  initLinkList(&list);
  ListNode node0;
  initListNode(&node0, (void*)0);
  ListNode node1;
  initListNode(&node1, (void*)1);
  ListNode node2;
  initListNode(&node2, (void*)2);
  addToTail(&list, &node0);
  addToTail(&list, &node1);
  addToTail(&list, &node2);
  TEST_ASSERT_EQUAL(3,list.ListSize);
  
  
  void *data = removeHead(&list);
  TEST_ASSERT_EQUAL(0, (int)data);
  TEST_ASSERT_EQUAL(2,list.ListSize);
  TEST_ASSERT_EQUAL(list.head->data, (void *)1);
  TEST_ASSERT_EQUAL(list.tail->data, (void *)2);
}


//boundary test
/* List : 0 <-- tail
          ^
          |
        head
*/
void test_removeHead_given_sample_list_above_should_get_head_is_NULL_tail_is_NULL()
{
  //set up test condition
  LinkList list;
  initLinkList(&list);
  ListNode node0;
  initListNode(&node0, (void*)0);
  addToTail(&list, &node0);
  TEST_ASSERT_EQUAL(1,list.ListSize);
  
  removeHead(&list);
  TEST_ASSERT_EQUAL(0,list.ListSize);
  TEST_ASSERT_NULL(list.head);
  TEST_ASSERT_NULL(list.tail);
}


