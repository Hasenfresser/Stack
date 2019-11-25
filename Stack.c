/**
 * @file Stack.c
 * @author Hasenfresser
 * @date 2019-11-25
 * @version 1.0.4 (Amateur)
 *
 * @brief Source file of all Stack functions.
 */

#include "Stack.h"

Stack *stackNew(const size_t p_tSize) {
    // allocating memory for new Stack
    Stack *pStack = malloc(sizeof(Stack));

    // check allocation, return zero pointer if failed
    if(!pStack) {
        return STACK_EMPTY;
    }

    // set initial values of new Stack
    pStack->m_pFirst = STACK_EMPTY;
    pStack->m_tElems = STACK_EMPTY;
    pStack->m_tMax = STACK_EMPTY;
    pStack->m_tSize = p_tSize;

    // returning pointer of new Stack
    return pStack;
}

int stackIsEmpty(Stack *const p_pStack) {
    // if Stack pointer is empty, return -1
    if(!p_pStack) {
        return STACK_ZP;
    }

    // return 1 if first element of Stack is empty, otherwise 0
    return (!p_pStack->m_pFirst);
}

int stackIsFull(Stack *const p_pStack) {
    // if Stack pointer is empty, return zero pointer error
    if(!p_pStack) {
        return STACK_ZP;
    }

    // return 1 if maximum is set and number of elements is equal or bigger than maximum, otherwise 0
    return (p_pStack->m_tMax && p_pStack->m_tElems >= p_pStack->m_tMax);
}

void *stackTop(Stack *const p_pStack) {
     // if Stack pointer is empty or Stack is empty, return empty pointer
    if(!p_pStack || !p_pStack->m_pFirst) {
        return STACK_EMPTY;
    }

    // return pointer of first element in stack
    return p_pStack->m_pFirst->m_pData;
}

int stackPush(Stack *const p_pStack, void *const p_pData) {
    // if Stack or data pointer is empty, return zero pointer error
    if(!p_pStack || !p_pData) {
        return STACK_ZP;
    }
    // check if Stack is full, return Stack full error
    else if(stackIsFull(p_pStack)) {
        return STACK_FULL;
    }

    // allocating memory for new Stack element (Node) and initialize with zero
    StackElem *pNode = calloc(1, sizeof(StackElem));

    // check allocation, return bad memory allocation error if failed
    if(!pNode) {
        return STACK_BADMAL;
    }

    // allocating memory for data in new Node and initialize with 0
    pNode->m_pData = calloc(1, p_pStack->m_tSize);

    // check allocation, clear allocated memory and return bad memory allocation error if failed
    if(!pNode->m_pData) {
        free(pNode);
        return STACK_BADMAL;
    }

    // copying data from data pointer parameter into node data pointer using byte size of one element
    memcpy(pNode->m_pData, p_pData, p_pStack->m_tSize);

    // if stack is empty, new element has no successor
    if(p_pStack->m_pFirst) {
        pNode->m_pNext = p_pStack->m_pFirst;
    }

    // set new element as first element of Stack
    p_pStack->m_pFirst = pNode;

    // increment number of Stack elements
    ++p_pStack->m_tElems;

    // Return number of pushed bytes
    return p_pStack->m_tSize;
}

int stackPop(Stack *const p_pStack) {
    // if Stack pointer or Stack is empty, return STACK_ZP
    if(!p_pStack || stackIsEmpty(p_pStack)) {
        return STACK_ZP;
    }

    // creating temporary pointer with "old" first element
    StackElem *pNode = p_pStack->m_pFirst;

    // Make second element the "new" first element
    p_pStack->m_pFirst = pNode->m_pNext;

    // freeing space of "old" first element (next pointer and data)
    free(pNode->m_pData);
    free(pNode);

    // decrementing number of Stack elements
    --p_pStack->m_tElems;

    // Return number of popped bytes
    return p_pStack->m_tSize;
}

int stackClear(Stack *const p_pStack) {
    // if Stack pointer or Stack is empty, return STACK_ZP
    if(!p_pStack) {
        return STACK_ZP;
    }

    // setting up counter
    int iCounter = STACK_EMPTY;

    // popping Stack until it is empty and increment counter
    while(!stackIsEmpty(p_pStack)) {
        stackPop(p_pStack);
        ++iCounter;
    }

    // returning counter (number of deleted elements)
    return iCounter;
}
