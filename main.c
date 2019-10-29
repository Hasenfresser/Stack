/**
 * @file main.c
 * @author Hasenfresser
 * @date 2019-10-29
 * @version 1.0.3 (Rookie)
 *
 * @brief Main file for testing purposes
 *
 * This file can be used to include and test the Stack implementation.
 * A small example is already written.
 *
 * The example reverses every parameter using the Stack.
 * When enabling Stack maximum (MAX), every input parameter will be trimmed.
 */

#include <stdio.h>

#include "Stack.h"

#define MAX 8 /**< Maximum elements in Stack */

/**
 * @brief Main function
 * @param p_iArgC: number of arguments
 * @param *p_apcArgV[] argument list
 * @return Success or failure
 */
int main(const int p_iArgC, char *p_apcArgV[]) {
    // creating new Stack
    Stack *pStack = stackNew(sizeof(char));
    pStack->m_tMax = MAX;

    int iC = 1;

    // iterating through all input parameters
    while(iC < p_iArgC) {
        char *pcInput = p_apcArgV[iC];

        // iterate through all characters of input parameter
        while(*pcInput != '\0') {
            printf("%c", *pcInput);
            // Pushing each character onto Stack
            stackPush(pStack, pcInput);

            ++pcInput;
        }

        printf(" <-> ");

        // Printing top Element of Stack followed by popping until it's empty
        while(!stackIsEmpty(pStack)) {
            printf("%c", *(char *)stackTop(pStack));
            stackPop(pStack);
        }

        printf("\n");

        ++iC;
    }

    exit(EXIT_SUCCESS);
}
