/**
 * @file Stack.h
 * @author Hasenfresser
 * @date 2019-10-28
 * @version 1.0.1
 *
 * @brief Header file of all Stack functions and structures.
 *
 * This is a low level implementation of a Stack in C programming language.
 * Every Stack can be initialized with a specific element size, therefore any data type can be stored as a stack.
 *
 * The usage is very simple, but has also very little comfortableness for wrong usage or error handling.
 *
 * @see https://github.com/Hasenfresser/Stack
 */

#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <string.h>

/**
 * @brief Struct for single element (Node) in Stack.
 */
typedef struct Node {
    void *m_pData; /**< void pointer to element data */
    struct Node *m_pNext; /**< pointer to next Node (element) */
} Node;

/**
 * @brief Struct for Stack. Pointer to this is used as the actual stack in the program.
 */
typedef struct Stack {
    size_t m_tSize; /**< Byte size of each element in Stack */
    size_t m_tMax; /**< Maximum number of elements (Nodes) in Stack */
    size_t m_tElems; /**< Number of elements (Nodes) in Stack */
    Node *m_pFirst; /**< Pointer to first Node (element) in Stack */
} Stack;

/**
 * @brief Creates a new Stack with a specific element size
 * @param p_tSize: size_t with element size in stack
 * @return Pointer to new Stack; when creation failed, pointer is zero
 */
extern Stack *stackNew(const size_t p_tSize);

/**
 * @brief Checks if Stack is empty.
 * @param p_pStack: Pointer to actual Stack.
 * @return 1 when Stack is empty, 0 if Stack is not empty, -1 if p_pStack is zero pointer
 */
extern int stackIsEmpty(Stack *const p_pStack);

/**
 * @brief Checks if Stack is full.
 * @param p_pStack: Pointer to actual Stack.
 * @return 1 when Stack is full, 0 if Stack is not full, -1 if p_pStack is zero pointer
 */
extern int stackIsFull(Stack *const p_pStack);

/**
 * @brief Returns top element of the Stack.
 * @param p_pStack: Pointer to actual Stack
 * @return Pointer to top element in Stack, zero pointer if p_pStack is zero pointer
 */
extern void *stackTop(Stack *const p_pStack);

/**
 * @brief Pushes element onto Stack.
 * @param p_pStack: pointer to actual Stack
 * @param p_pData: pointer to new element (Node) data
 *
 * If any parameter pointer is zero, the function will do nothing.
 * If Stack reached its maximum number of elements, the function will do nothing.
 */
extern void stackPush(Stack *const p_pStack, void *const p_pData);

/**
 * @brief Pops (deletes) top element of Stack.
 * @param p_pStack: pointer to actual Stack
 *
 * If p_pStack is zero, the function will do nothing.
 */
extern void stackPop(Stack *const p_pStack);

/**
 * @brief Pops (deletes) all element of Stack.
 * @param p_pStack: pointer to actual Stack
 *
 * If p_pStack is zero, the function will do nothing.
 */
extern void stackClear(Stack *const p_pStack);

#endif // STACK_H
