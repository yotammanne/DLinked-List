

#ifndef Stack_h
#define Stack_h

#include <stdio.h>
#include <stdlib.h>
#include "DLinked_List.h"

typedef struct stack{
    ll* list;
    int max_size;
    int size;
} stack;

#endif /* Stack_h */
