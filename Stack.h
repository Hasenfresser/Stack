/**
 * @file Stack.h
 * @author Hasenfresser
 * @date 2019-11-25
 * @version 1.0.4 (Amateur)
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
 * @brief Enumeration with all error and init values.
 */
enum {
    STACK_EMPTY = 0, /**< Initial value for Stack members */
    STACK_ZP = -1, /**< error value if parameter is zero pointer */
    STACK_BADMAL = -2, /**< error value if memory allocation failed */
    STACK_FULL = -3 /**< error value if Stack is full (no push) */
};

/**
 * @brief Struct for single element (Node) in Stack.
 */
typedef struct StackElem {
    void *m_pData; /**< void pointer to element data */
    struct StackElem *m_pNext; /**< pointer to next element (Node) */
} StackElem;

/**
 * @brief Struct for Stack. Pointer to this is used as the actual stack in the program.
 */
typedef struct Stack {
    size_t m_tSize; /**< Byte size of each element in Stack */
    size_t m_tMax; /**< Maximum number of elements (Nodes) in Stack */
    size_t m_tElems; /**< Number of elements (Nodes) in Stack */
    StackElem *m_pFirst; /**< Pointer to first element (Node) in Stack */
} Stack;

/**
 * @brief Creates a new Stack with a specific element size
 * @param p_tSize: size_t with element size in stack
 * @return Pointer to new Stack; when creation failed, pointer is zero
 */
extern Stack *stackNew(const size_t p_tSize);

/**
 * @brief Checks if Stack is empty
 * @param p_pStack: Pointer to actual Stack
 * @return 1 when Stack is empty, otherwise 0 or error value
 *
 * If Stack pointer is zero, the function returns STACK_ZP.
 */
extern int stackIsEmpty(Stack *const p_pStack);

/**
 * @brief Checks if Stack is full
 * @param p_pStack: Pointer to actual Stack
 * @return 1 when Stack is full otherwise 0 or error value
 *
 * If Stack pointer is zero, the function returns STACK_ZP.
 */
extern int stackIsFull(Stack *const p_pStack);

/**
 * @brief Returns top element of the Stack
 * @param p_pStack: Pointer to actual Stack
 * @return Pointer to top element of Stack or error value
 *
 * If Stack pointer is zero, the function returns STACK_ZP.
 */
extern void *stackTop(Stack *const p_pStack);

/**
 * @brief Pushes element onto Stack.
 * @param p_pStack: pointer to actual Stack
 * @param p_pData: pointer to new element (Node) data
 * @return Number of bytes pushed or error value
 *
 * If any parameter pointer is zero, the function returns STACK_ZP.
 * If something with memory allocation went wrong, the functions returns STACK_BADMAL.
 * If Stack reached its maximum number of elements, the function returns 0.
 */
extern int stackPush(Stack *const p_pStack, void *const p_pData);

/**
 * @brief Pops (deletes) top element of Stack.
 * @param p_pStack: pointer to actual Stack
 * @return Number of bytes popped or error value
 *
 * If Stack pointer is zero, the function returns STACK_ZP.
 */
extern int stackPop(Stack *const p_pStack);

/**
 * @brief Pops (deletes) all element of Stack.
 * @param p_pStack: pointer to actual Stack
 * @return Number of elements deleted or error value

 * If Stack pointer is zero, the function returns STACK_ZP.
 */
extern int stackClear(Stack *const p_pStack);

#endif // STACK_H
