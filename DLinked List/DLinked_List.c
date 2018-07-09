
#include <stdio.h>
#include <stdlib.h>
#include "DLinked_List.h"


node* create_node(DATA d){
    node* node = (struct node*)calloc(1,sizeof(struct node));
    node->data=d;
    node->next=NULL;
    node->prev=NULL;
    return node;
}

int create_list(ll* list){
    list->head=NULL;
    list->end=NULL;
    list->size=0;
    return 1;
}

int add_node(node* n, ll* list, int position){
    node* temp;
    int count=0;
    if(position>list->size) return 0;
    if(position==0){
        add_head(n, list);
        return 1;
    }
    if(position==list->size){
        add_end(n, list);
        return 1;
    }
    temp=list->head;
    while(count<position){
        temp=temp->next;
        count++;
    }
    add_middle(list, n, temp);
    return 1;
}

int add_middle(ll* list, node* in, node* curr){
    curr->next->prev=in;
    in->next=curr->next;
    curr->next=in;
    in->prev=curr;
    list->size++;
    return 1;
}


int add_end(node* n, ll* list){
    n->prev=list->end;
    list->end->next=n;
    list->end=n;
    n->next=NULL;
    list->size++;
    return 1;
}

int add_head(node* n, ll* list){
    list->head->prev=n;
    n->next=list->head;
    n->prev=NULL;
    list->head=n;
    list->size++;
    return 1;
}

int delete_head(ll* list){
    list->head=list->head->next;
    free(list->head->prev);
    list->head->prev=NULL;
    list->size--;
    return 1;
}

int delete_end(ll* list){
    list->end=list->end->prev;
    free(list->end->next);
    list->end->next=NULL;
    list->size--;
    return 1;
}

int delete_mid(ll* list, node* n){
    n->prev->next=n->next;
    n->next->prev=n->prev;
    free(n);
    list->size--;
    return 1;
}

int delete_node(ll* list, int pos){
    int count=0;
    node*temp=list->head;
    if(pos>=list->size) return 0;
    if(pos==0){
        delete_head(list);
        return 1;
    }
    if(pos==list->size-1){
        delete_end(list);
        return 1;
    }
    while(count<pos){
        count++;
        temp=temp->next;
    }
    delete_mid(list, temp);
    return 1;
}

int main(int argc, const char * argv[]) {
    printf("Hello, World!\n");
    return 0;
}
