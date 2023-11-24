#include "s21_calc.h"

// From str notation to polish notation

void initialize(Stack *stack) { stack->top = -1; }

int isEmpty(Stack *stack) { return stack->top == -1; }

int isFull(Stack *stack) { return stack->top == STACK_SIZE - 1; }

void push(Stack *stack, char item) {
  if (isFull(stack)) {
    printf("Error: Stack is full\n");
    return;
  }
  stack->data[++stack->top] = item;
}

char pop(Stack *stack) {
  if (isEmpty(stack)) {
    printf("Error: Stack is empty\n");
    return '\0';
  }
  return stack->data[stack->top--];
}

int precedence(char ch) {
  int res = 0;
  switch (ch) {
    case '+':
    case '-':
      res = 1;
      break;
    case '*':
    case '/':
    case 'm':
      res = 2;
      break;
    case '^':
      res = 3;
      break;
      // default:
      //   res = 0;
  }
  return res;
}

int isTrigonometric(char ch) { return ch == 's' || ch == 'c' || ch == 't'; }

int isMatFunctions(char str1, char str2) {
  int res = 0;
  if (str1 == 'a' && str2 == 's') {
    res = 1;
  } else if (str1 == 'a' && str2 == 'c') {
    res = 1;
  } else if (str1 == 'a' && str2 == 't') {
    res = 1;
  } else if (str1 == 's' && str2 == 'q') {
    res = 1;
  } else if (str1 == 'l' && str2 == 'n') {
    res = 1;
  } else if (str1 == 'l' && str2 == 'o') {
    res = 1;
  }
  return res;
}

void infixToPostfix(char *expression, char *result) {
  Stack stack;
  initialize(&stack);
  int check = 0;

  int i, j;
  for (i = 0, j = 0; expression[i] != '\0'; i++) {
    char ch = expression[i];
    if (isdigit(ch) || ch == '.' || ch == 'x') {
      if (check == 1) {  // float numbers
        result[j++] = ' ';
      }
      result[j++] = ch;
      check = 0;
    } else if (isOperator(ch)) {
      while (!isEmpty(&stack) && isOperator(stack.data[stack.top]) &&
             precedence(ch) <= precedence(stack.data[stack.top])) {
        if (ch == 'm') {
          result[j++] = ' ';
          result[j++] = pop(&stack);
          i += 2;
        } else {
          result[j++] = ' ';
          result[j++] = pop(&stack);
        }
      }
      push(&stack, ch);
      check = 1;
    } else if (ch == '(') {
      push(&stack, ch);
    } else if (isTrigonometric(ch)) {  // Mat functions with one word check
      while (ch != ')') {
        if (ch != '(') {
          result[j++] = ch;
        } else {
          result[j++] = ' ';
        }
        ch = expression[++i];
      }
    } else if (i != (int)(strlen(expression) - 1) &&
               isMatFunctions(
                   expression[i],
                   expression[i + 1])) {  // Mat functions with two word check
      while (ch != ')') {
        if (ch != '(') {
          result[j++] = ch;
        } else {
          result[j++] = ' ';
        }
        ch = expression[++i];
      }
    } else if (ch == ')') {
      while (!isEmpty(&stack) && stack.data[stack.top] != '(') {
        result[j++] = ' ';
        result[j++] = pop(&stack);
      }
      // if (isEmpty(&stack) || stack.data[stack.top] != '(') {
      //   printf("Error: Mismatched parentheses\n");
      //   return;
      // }
      pop(&stack);
    }
  }

  while (!isEmpty(&stack)) {
    // if (stack.data[stack.top] == '(') {
    //   printf("Error: Mismatched parentheses\n");
    //   break;
    // }
    result[j++] = ' ';
    result[j++] = pop(&stack);
  }

  result[j] = '\0';
}