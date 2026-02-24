// Question1/Student.c
// ------------------------------------------------------------
// CS Lab - Valid Parentheses (STACK PRACTICE)
//
// Task:
// Implement `isValid(const char *s)`.
// Given a string s containing only: () {} []
// return true if it is a valid parentheses string, else false.
//
// Valid rules:
// 1) Open brackets must be closed by the same type of brackets.
// 2) Open brackets must be closed in the correct order.
// 3) Every close bracket has a corresponding open bracket.
//
// Examples:
//   s = "()"        -> true
//   s = "()[]{}"    -> true
//   s = "(]"        -> false
//   s = "([)]"      -> false
//   s = "{[]}"      -> true
//   s = ""          -> true   (empty string is valid)
//
// How to run tests (from the folder containing the Makefile):
//   make run1
// ------------------------------------------------------------

#include "Student.h"
#include <stdbool.h>
#include <stddef.h>  // size_t
#include <string.h>  // strlen
#include <stdlib.h>

bool isValid(const char *s) {
    // TODO: Implement using a stack.
    //
    // Recommended approach:
    // - Use a char array as a stack to store opening brackets.
    // - Scan the string from left to right:
    //   - If you see an opening bracket, push it.
    //   - If you see a closing bracket:
    //       * stack must not be empty
    //       * top of stack must match the closing bracket type
    //       * then pop
    // - At the end, stack must be empty.
    //
    // Helpful matching pairs:
    //   ')' matches '('
    //   ']' matches '['
    //   '}' matches '{'
    //
    // Corner cases:
    // - s == NULL -> return false
    // - odd length strings can’t be valid 
    //
    // Note:
    // - Input contains only bracket characters, per the prompt.

    // Implement stack using linked list
    struct Node
    {
        char data;
        struct Node* next;
    };

    struct Node* top = NULL;

    // Handle edge cases
    if(s == NULL)
    {
        return false;
    }
    
    if(strlen(s) % 2 != 0)
    {
        return false;
    }

    // Iterate through the string
    for(size_t i = 0; i < strlen(s); i++)
    {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        // When an open bracket is encountered, push it to the stack
        if(s[i] == '(')
        {
            newNode->data = '(';
            // If stack is empty, newNode is new top
            if(top == NULL)
            {
                newNode->next = NULL;
                top = newNode;
            }
            // If stack is not empty, add newNode to the top of the stack
            else
            {
                newNode->next = top;
                top = newNode;
            }
        }
        else if(s[i] == '{')
        {
            newNode->data = '{';
            // If stack is empty, newNode is new top
            if(top == NULL)
            {
                newNode->next = NULL;
                top = newNode;
            }
            // If stack is not empty, add newNode to the top of the stack
            else
            {
                newNode->next = top;
                top = newNode;
            }
        }
        else if(s[i] == '[')
        {
            newNode->data = '[';
            // If stack is empty, newNode is new top
            if(top == NULL)
            {
                newNode->next = NULL;
                top = newNode;
            }
            // If stack is not empty, add newNode to the top of the stack
            else
            {
                newNode->next = top;
                top = newNode;
            }
        }
        // If a closed bracket is encountered, pop and check to see if top of stack is the matching bracket
        else if(top != NULL)
        {
            char top_char = top->data;
            if(s[i] == ')' && top_char == '(')
            {
                struct Node* ptr = top;
                top = top->next;
                free(ptr);
            }
            if(s[i] == '}' && top_char == '{')
            {
                struct Node* ptr = top;
                top = top->next;
                free(ptr);
            }
            if(s[i] == ']' && top_char == '[')
            {
                struct Node* ptr = top;
                top = top->next;
                free(ptr);
            }
        }
    }
    // If stack is empty, return true
    if(top == NULL)
    {
        return true;
    }

    (void)s; // remove after implementing
    return false; // placeholder
}
