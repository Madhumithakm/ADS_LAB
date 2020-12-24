#include <stdlib.h>
#include <assert.h>
#include "test.h"


Slist       slist_new() {
    Slist s1 = {NULL, NULL, 0};
    return s1;
}

static Node* _get_new_node_(Slist *list,int  account_type,int account_num,
                     char* name,
                     int balance, int transaction_left, int due, int phone_no){
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->account_type = account_type;
    newnode->account_number = 111;
    newnode->name = name;
    newnode->balance = balance;
    if( account_type == 01){
    newnode->transaction_left = 15;
    }
    else{
    newnode->transaction_left = 10;
    }
    newnode->due = 0;
    newnode->phone_no = phone_no;
    newnode->next = NULL;
    return newnode;
}

Slist*  new_customer(Slist *list,int  account_type,int account_num,
                     char* name,
                     int balance, int transaction_left, int due, int phone_no){
    assert(list!= NULL);
    Node *new_node=_get_new_node_(list, account_type, account_num, name, balance, transaction_left, due, phone_no);
    if(list->tail!= NULL){
        list->tail-> next = new_node;
        list->tail= new_node;
    }
    else{
        list->head=list->tail=new_node;
    }
    ++list->length;
    assert((list->length == 1 && list->head==list->tail )||
        (list->length> 1 && list->head !=list->tail));

return list;
}

uint32_t    slist_length(const Slist *list){
    assert (list != NULL);
    return list->length;
}
