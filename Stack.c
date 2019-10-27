/**
 * @file Stack.c
 * @author Hasenfresser
 * @date 2019-10-27
 *
 * @brief Source file of all Stack functions.
 */

#include "Stack.h"

Stack *stackNew(const size_t p_tSize) {
    Stack *pStack = calloc(1, sizeof(Stack));

    if(!pStack) return 0;

    pStack->m_pFirst = 0;
    pStack->m_tSize = p_tSize;

    return pStack;
}

int stackIsEmpty(Stack *const p_pStack) {
    if(!p_pStack)   return -1;

    return (!p_pStack->m_pFirst);
}

void *stackTop(Stack *const p_pStack) {
    if(!p_pStack || !p_pStack->m_pFirst)    return 0;

    return p_pStack->m_pFirst->m_pData;
}

void stackPush(Stack *const p_pStack, void *const p_pData) {
    if(!p_pStack || !p_pData)   return;

    Node *pNode = malloc(sizeof(Node));

    if(!pNode)  return;

    pNode->m_pData = malloc(p_pStack->m_tSize);

    if(!pNode->m_pData) return;

    memcpy(pNode->m_pData, p_pData, p_pStack->m_tSize);

    if(!p_pStack->m_pFirst) {
        pNode->m_pNext = 0;
        p_pStack->m_pFirst = pNode;
    }
    else {
        pNode->m_pNext = p_pStack->m_pFirst;
        p_pStack->m_pFirst = pNode;
    }
}

void stackPop(Stack *const p_pStack) {
    if(!p_pStack || !p_pStack->m_pFirst) return;

    Node *pNode = p_pStack->m_pFirst;

    p_pStack->m_pFirst = pNode->m_pNext;

    free(pNode->m_pData);
    free(pNode);
}

void stackClear(Stack *const p_pStack) {
    if(!p_pStack)   return;

    while(!stackIsEmpty(p_pStack)) stackPop(p_pStack);
}

size_t stackSize(Stack *const p_pStack) {
    if(!p_pStack)   return 0;

    Node *pTmp = p_pStack->m_pFirst;

    size_t tSize = 0;

    while(pTmp) {
        pTmp = pTmp->m_pNext;
        ++tSize;
    }

    return tSize;
}
