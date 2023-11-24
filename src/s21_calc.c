#include "s21_calc.h"

// From polish notation to number

void initialize_stack(Stack_real *stack) { stack->top = NULL; }

int isEmpty_stack(Stack_real *stack) { return stack->top == NULL; }

void push_stack(Stack_real *stack, double value) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode != NULL) {
    newNode->value = value;
    newNode->next = stack->top;
    stack->top = newNode;
  }
}

double pop_stack(Stack_real *stack) {
  if (isEmpty_stack(stack)) {
    printf("Error: Stack is empty\n");
    exit(0);
  }
  Node *temp = stack->top;
  double value = temp->value;
  stack->top = temp->next;
  free(temp);
  return value;
}

double multipleTimesTen(int num) {
  double res = 1.0;
  for (int i = 1; i <= num; ++i) {
    res *= 10.0;
  }
  return res;
}

double find_Math_Operation(char str1, char str2, char *expression, int *i) {
  double res = 0.0, operand = 0.0;
  while (!isdigit(expression[*i])) {  // skip all no numbers
    *i += 1;
  }

  int check = 0;
  while (isdigit(expression[*i]) ||
         expression[*i] == '.') {               // skil all number and add them
    if (expression[*i] == '.' || check != 0) {  // for float numbers
      if (check == 0) *i += 1;                  // skip dot
      ++check;
      operand = operand + ((expression[*i] - '0') / (multipleTimesTen(check)));
    } else {
      operand = operand * 10 + (expression[*i] - '0');
    }
    *i += 1;
  }
  if (str1 == 'a' && str2 == 'c') {
    res = acos(operand);
  } else if (str1 == 'a' && str2 == 't') {
    res = atan(operand);
  } else if (str1 == 'a' && str2 == 's') {
    res = asin(operand);
  } else if (str1 == 's' && str2 == 'q') {
    res = sqrt(operand);
  } else if (str1 == 'l' && str2 == 'n') {
    res = log(operand);
  } else if (str1 == 'l' && str2 == 'o') {
    res = log10(operand);
  } else if (str1 == 't') {
    res = tan(operand);
  } else if (str1 == 'c') {
    res = cos(operand);
  } else if (str1 == 's') {
    res = sin(operand);
  }
  return res;
}

double evaluatePostfix(char *expression, double *result, char *x) {
  Stack_real stack;
  initialize_stack(&stack);

  int i, flag = 0;  // if expression is without operator
  for (i = 0; expression[i] != '\0'; ++i) {
    char ch = expression[i];
    if (isdigit(ch) || ch == '.' || ch == 'x') {
      double operand = 0.0;
      int check = 0, j = 0;  // 3.422 for floating part of number
      while (isdigit(ch) || ch == '.') {
        if (ch == '.' || check != 0) {
          if (check == 0) ch = expression[++i];  // skip dot
          ++check;
          operand = operand + ((ch - '0') / (multipleTimesTen(check)));
        } else {
          operand = operand * 10 + (ch - '0');
        }
        ch = expression[++i];
      }
      if (ch == 'x' &&
          (isTrigonometric(x[j]) ||
           (j < ((int)strlen(x) - 1) && isMatFunctions(x[j], x[j + 1])))) {
        operand = find_Math_Operation(x[j], x[j + 1], x, &j);
        ch = expression[++i];
      } else if (ch == 'x') {
        operand = atof(x);
        ch = expression[++i];
      }
      --i;
      push_stack(&stack, operand);
    } else if (isTrigonometric(ch) ||
               (i != (int)(strlen(expression) - 1) &&
                isMatFunctions(expression[i], expression[i + 1]))) {
      char str1 = expression[i];
      char str2 = expression[i + 1];
      push_stack(&stack, find_Math_Operation(str1, str2, expression, &i));
    } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' ||
               ch == 'm') {
      double operand2 = pop_stack(&stack);
      double operand1 = pop_stack(&stack);
      switch (ch) {
        case '+':
          *result = operand1 + operand2;
          break;
        case '-':
          *result = operand1 - operand2;
          break;
        case '*':
          *result = operand1 * operand2;
          break;
        case '/':
          *result = operand1 / operand2;
          break;
        case '^':
          *result = pow(operand1, operand2);
          break;
        case 'm':
          *result = fmod(operand1, operand2);
          break;
      }
      flag = 1;
      push_stack(&stack, *result);
    }
  }
  if (flag == 0) {  // if expression is without operator
    *result = pop_stack(&stack);
  } else {
    pop_stack(&stack);
  }
  return 0;
}