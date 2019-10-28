# Stack
A low level implementation in **C** of a stack container. Can be filled with nearly any data type.


## What's a Stack?
A Stack is a dynamic data container. It can store an (theoretically) infinite or a specific number elements of the same data type.
The elements are accessed with the **LIFO (last in first out)** principle.

New elements are *pushed* on top of the stack, while a *pop* deletes the top element. A Stack can access its *top* element very easily.
Most Stacks have also some functionalities like a *maximum size*, a *clear* function (deleting all elements) or a check if stack is *full* or *empty*.

![StackVisu](https://upload.wikimedia.org/wikipedia/commons/b/b4/Lifo_stack.png)

Graphical visualization of a Stack.
*Source: https://upload.wikimedia.org/wikipedia/commons/b/b4/Lifo_stack.png*


## Usage

This C implementation of a stack is **not** fixed to a specific data type which can be stored in it. You can use it for *nearly* every data type.

Just copy the *Stack.c* and *Stack.h* into your project folder and include *Stack.h* in your source code.

```
#include "<optional_path/>Stack.h"
```

### Creating new Stack

*Example 1:* Creating a Stack of `int`:
```
Stack *pdStack = newStack(sizeof(int));
```


*Example 2:* Creating a Stack of `double`:
```
Stack *piStack = newStack(sizeof(int));
```

The function `Stack *newStack(const size_t p_tSize)` gets a byte size as parameter. It is usefull to get the byte size of an element by using `sizeof`.
The function returns a pointer to the newly created Stack.

A newly created Stack can store an infinite amount of elements. You can change this later.

If anything goes wrong while creating the Stack, the returned pointer is empty (`0`).


### Stack maximum

After creating a new Stack, you can edit the maximum number of elements.

*Example 1:* Set number of `double` elements in Stack to `5`:

This sets the maximum number of elements in the Stack to `5`.
If the maximum number of elements is reached, no new elements can be *pushed*.
```
pdStack->m_tMax = 5;
```

*Example 2:* Set number of `int` elements in Stack to infinite:
```
piStack->m_tMax = 0;
```

 If set to `0`, the stack can contain an infinte number of elements (theoretically).

The other members of the Stack structure (`m_tSize`, `m_tElems`and `m_pFirst`) should **never ever** be touched! Otherwise this could cause undefined behavior.


### Pushing new element onto Stack

*Example 1:* Pushing new `double` onto Stack:

```
double d = 4.5;
stackPush(pdStack, &d);
```

*Example 2:* Pushing new `int` onto Stack:

```
int i = -4;
stackPush(piStack, &i);
```

The function `void stackPush(Stack *const p_pStack, void *const p_pData)` gets the Stack pointer as argument. 

The second argument contains a void pointer to the actual data. Therefore the data could be anything. **Make sure** that the data the pointer is referencing to has the correct data type - there is no actual check if the this is correct!
If the pushed data is bigger than the single element byte size, it will **not** be properly stored!

If any argument is an empty pointer, the function will do nothing.


### Getting top element of Stack

*Example 1:* Getting top `double` element of Stack in `double dTop`:
```
double dTop = *(double *)stackTop(pdStack);
```

*Example 2:* Saving top `int` element of Stack in `int iTop`:
```
int iTop = *(int *)stackTop(piStack);
```

*Example 3:* Saving top `int` element of Stack in `void pointer`:
```
void *p = stackTop(piStack);
```

The function `void *stackTop(Stack *const p_pStack)` gets the Stack pointer as argument.

It will return a pointer to the top element of the Stack. It can be stored in a void pointer or casted to a specific data type (which usually matches with the data type the Stack stores).

If the Stack pointer or the Stack itself is empty (contains 0 elements) the function will return an empty pointer (`0`).

### Popping top element of Stack

*Example 1:* Popping top `double` element of Stack:
```
stackTop(pdStack);
```

The function `void stackPop(Stack *const p_pStack)` gets the Stack pointer as argument.

If Stack is not empty, it will delete the top element of the Stack.

If the Stack pointer is empty, the function will do nothing.


### Clearing Stack

*Example 1:* Clearing all `double` elements in Stack:
```
stackClear(pdStack);
```

The function `void stackClear(Stack *const p_pStack)` gets the Stack pointer as argument.

It will repetitive delete the top element of the Stack until it is empty.

If the Stack pointer is empty, the function will do nothing.


### Stack flags

*Example 1:* Check if `int` Stack is empty
```
int iEmpty = stackIsEmpty(piStack);
```

The function `void stackIsEmpty(Stack *const p_pStack)` gets the Stack pointer as argument.

If the Stack stores no elements, it will return `0`, otherwise the number of stored elements.

If the Stack pointer is empty, it will return `-1`.

*Example 2:* Check if `double` Stack with a maximum of `5` elements is full
```
pdStack->m_tMax = 5;
/* (...some pushing...) */
int iEmpty = stackIsFull(pdStack);
```

The function `void stackIsFull(Stack *const p_pStack)` gets the Stack pointer as argument.

If the number of elements in the Stack equals or is bigger than the maximum, it will return `1`, otherwise `0`.
If there is no maximum set (`0`), it will always return `0`.
If the Stack pointer is empty, it will return `-1`.

## Misc
- This implementation tries to make **C** programming a little bit easier, but is also some kind of low level. So don't expect to much comfort while using it. It is recommended to check everything twice before releasing something. Empty pointers can easily become dangerous! :stuck_out_tongue_winking_eye:
- It is **not** recommended to use this implelentation in **C++**, because it has its own class for [Stacks](http://www.cplusplus.com/reference/stack/stack/). It can also be used for objects, which is a great advantage.

## ToDos

- :white_check_mark: Basic implementation of all functionalities
- :white_check_mark: Adding maximum size 
- :white_check_mark: Adding full flag
- :white_check_mark: Adding Doxygen comments and config file
- :white_check_mark: Completing ReadMe.md

- :negative_squared_cross_mark: Some more code documentation in *Stack.c* 
- :negative_squared_cross_mark: Getting some feedback 

## Bugs and Issues

...if you find some, just let me know! :wink:


Greetings,
Hasenfresser
