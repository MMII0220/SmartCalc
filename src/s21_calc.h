#ifndef SRC_S21_CALC_H_
#define SRC_S21_CALC_H_

#define STACK_SIZE 256

typedef struct {
  char data[STACK_SIZE];
  int top;
} Stack;

typedef struct Node {
  double value;
  struct Node *next;
} Node;

typedef struct {
  Node *top;
} Stack_real;

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isOperator(char ch);
int isOperatorBrackets(char ch);
void skipMatFunctions(char *expression, int *i, int *res_num, int *check,
                      int *flag, int *finish_matFunctions, int *left_bracket);
void check_valid_form(char *str, char **res);

int precedence(char ch);
char pop(Stack *stack);
void push(Stack *stack, char item);
int isFull(Stack *stack);
int isEmpty(Stack *stack);
void initialize(Stack *stack);
double multipleTimesTen(int num);
int isTrigonometric(char ch);
int isMatFunctions(char str1, char str2);
void infixToPostfix(char *expression, char *result);

void initialize_stack(Stack_real *stack);
int isEmpty_stack(Stack_real *stack);
void push_stack(Stack_real *stack, double value);
double pop_stack(Stack_real *stack);
double evaluatePostfix(char *expression, double *result, char *x);

#endif  // SRC_S21_CALC_H_