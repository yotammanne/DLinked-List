
#ifndef DLinked_List_h
#define DLinked_List_h

#define DATA int

typedef struct node{
    struct node* next;
    struct node* prev;
    DATA data;
    int position;
} node;

typedef struct linked_list{
    node* head;
    node* end;
    int size;
} ll;

node* create_node(DATA d);
int create_list(ll* list);
int add_end(node* n, ll* list);
int add_node(node* n, ll* list, int position);
int add_middle(ll* list, node* in, node* curr);
int add_head(node* n, ll* list);
int delete_head(ll* list);
int delete_end(ll* list);
int delete_mid(ll* list, node* n);

#endif /* DLinked_List_h */
