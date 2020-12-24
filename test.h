#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED
#include<stdint.h>
#include <stdio.h>
#define NAME_LEN   64
#define BANK_CODE       20
#define AREA_CODE       1234





typedef struct _node_ Node;
struct _node_
{
    int     account_type;
    long int     account_number;
    char*    name;
    int     balance;
    int     transaction_left;
    int     due;
    int     phone_no;
    int     PAN;
    Node    *next;
};

typedef struct _slist_ Slist;
struct _slist_
{
    Node        *head;
    Node        *tail;
    uint32_t    length;
};

int number_acc;

Slist       slist_new();
Slist*      new_customer(Slist *list,int  account_type,int account_num,
                     char name,
                     int balance, int transaction_left, int due, int phone_no);
Slist*      credit(Slist *list, int val);
Slist*      debit(Slist *list, int val);
int         balance(Slist *list);

#endif // TEST_H_INCLUDED
