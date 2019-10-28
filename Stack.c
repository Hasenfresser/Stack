/**
 * @file Stack.c
 * @author Hasenfresser
 * @date 2019-10-28
 * @version 1.0.1
 *
 * @brief Source file of all Stack functions.
 */

#include "Stack.h"
#include <stdio.h>

Stack *stackNew(const size_t p_tSize) {
    // allocating memory for new Stack
    Stack *pStack = malloc(sizeof(Stack));

    // check allocation, return empty pointer if failed
    if(!pStack) return 0;

    // set initial values of new Stack
    pStack->m_pFirst = 0;
    pStack->m_tElems = 0;
    pStack->m_tMax = 0;
    pStack->m_tSize = p_tSize;

    // returning pointer of new Stack
    return pStack;
}

int stackIsEmpty(Stack *const p_pStack) {
    // if Stack pointer is empty, return -1
    if(!p_pStack)   return -1;

    // return 1 if first element of Stack is empty, otherwise 0
    return (!p_pStack->m_pFirst);
}

int stackIsFull(Stack *const p_pStack) {
    // if Stack pointer is empty, return -1
    if(!p_pStack)   return -1;

    // return 1 if maximum is set and number of elements is equal or bigger than maximum, otherwise 0
    return (p_pStack->m_tMax && p_pStack->m_tElems >= p_pStack->m_tMax);
}

void *stackTop(Stack *const p_pStack) {
     // if Stack pointer is empty or Stack is empty, return empty pointer
    if(!p_pStack || !p_pStack->m_pFirst)    return 0;

    // return pointer of first element in stack
    return p_pStack->m_pFirst->m_pData;
}

void stackPush(Stack *const p_pStack, void *const p_pData) {
    // if Stack or data pointer is empty or Stack is full, return
    if(!p_pStack || !p_pData || stackIsFull(p_pStack))   return;

    // allocating memory for new Node
    Node *pNode = malloc(sizeof(Node));

    // check allocation, return if failed
    if(!pNode)  return;

    // allocating memory for data in new Node
    pNode->m_pData = malloc(p_pStack->m_tSize);

    // check allocation, return if failed
    if(!pNode->m_pData) return;

    // copying data from data pointer parameter into node data pointer using byte size of one element
    memcpy(pNode->m_pData, p_pData, p_pStack->m_tSize);

    // if stack is empty, new element has no successor
    if(!p_pStack->m_pFirst) pNode->m_pNext = 0;
    // otherwise set "old" first element as successor of new element
    else                    pNode->m_pNext = p_pStack->m_pFirst;

    // set new element as "new" first element of Stack
    p_pStack->m_pFirst = pNode;

    // increment number of Stack elements
    ++p_pStack->m_tElems;
}

void stackPop(Stack *const p_pStack) {
    // if Stack pointer or Stack is empty, return
    if(!p_pStack || stackIsEmpty(p_pStack)) return;

    // creating temporary pointer with "old" first element
    Node *pNode = p_pStack->m_pFirst;

    // Make second element the "new" first element
    p_pStack->m_pFirst = pNode->m_pNext;

    // freeing space of "old" first element (next pointer and data)
    free(pNode->m_pData);
    free(pNode);

    // decrementing number of Stack elements
    --p_pStack->m_tElems;
}

void stackClear(Stack *const p_pStack) {
    // if Stack pointer or Stack is empty, return
    if(!p_pStack)   return;

    // popping Stack until it is empty
    while(!stackIsEmpty(p_pStack))  stackPop(p_pStack);
}
