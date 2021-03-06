#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Stack.h"

stack_t *createStack(uint8_t capacity){
    stack_t *stack = (stack_t *)malloc(sizeof(stack_t));
    if(stack == NULL)
        return NULL;
    
    size_t data_size = capacity * sizeof(stack_value_type_t);
    stack_value_type_t *data = (stack_value_type_t *)malloc(data_size);

    if(data == NULL){
        free(stack);
        return NULL;
    }

    stack->size = 0u;
    stack->capacity = capacity;
    stack->data = data;

    return stack;
}

stack_t *reStack(stack_t *stack, uint8_t capacity){
    if(stack->data == NULL){
        return NULL;
    }
	
	stack->capacity = capacity;
    size_t data_size = capacity * sizeof(stack_value_type_t);
    stack->data = (stack_value_type_t *)realloc(stack->data, data_size);

    return stack;
}

stack_t *deleteStack(stack_t *stack){
    if(stack){
        if(stack->data)
            free(stack->data);
        free(stack);
    }
    return NULL;
}

bool stackIsFull(stack_t *stack){
    return (stack->size == stack->capacity);
}

bool stackIsEmpty(stack_t *stack){
    return (!stack->size);
}

void stackPush(stack_t *stack, stack_value_type_t value){
    if(stackIsFull(stack))
        return;
    stack->data[stack->size] = value;
    stack->size++;
}

stack_value_type_t stackPop(stack_t *stack){
    if(stackIsEmpty(stack))
        return STACK_NO_VALUE;

    stack->size--;
    stack_value_type_t temp = stack->data[stack->size];
    stack->data[stack->size] = STACK_NO_VALUE;

    return temp;
}

stack_value_type_t stackTop(stack_t *stack){
    if(stackIsEmpty(stack))
        return STACK_NO_VALUE;
    return stack->data[stack->size-1];
}