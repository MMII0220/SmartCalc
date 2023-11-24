#include "s21_calc.h"

// Validation of operation

int isOperator(char ch) {
  return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' ||
         ch == 'm';
}

int isOperatorBrackets(char ch) {
  return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(';
}

void skipMatFunctions(char *expression, int *i, int *res_num, int *check,
                      int *flag, int *finish_matFunctions, int *left_bracket) {
  int digit_check = 0;
  while (expression[*i] != ')') {
    if (expression[*i] == '(') {
      *left_bracket += 1;
    }
    if (isdigit(expression[*i])) {
      digit_check = 1;
    }
    if ((digit_check == 0 && expression[*i] == '-') ||
        (isOperator(expression[*i]) && isOperator(expression[*i + 1]))) {
      *res_num = 3;
      break;
    }
    if (expression[*i] == ')' || (int)strlen(expression) < *i) {
      *res_num = 3;
      break;
    }
    if ((*i < ((int)strlen(expression) - 1) &&
         isMatFunctions(expression[*i], expression[*i + 1])) &&
        *flag % 2 != 1) {
      *check = 1;
      break;
    }
    *i += 1;
  }
  if (expression[*i] ==
      ')') {  // if inner mat function/functions is/are finished
    *finish_matFunctions = 1;
  }
  if (*res_num != 3 && *res_num != 0 /* || *check != 0*/) {
    *i += 1;
  }
}

void check_valid_form(char *str, char **res) {
  int res_num = 0, left_bracket = 0, right_bracket = 0, len = strlen(str),
      /*pop_bracket = 0, */ flag = 0, finish_matFunctions = 0;
  for (int i = 0; i < len; ++i) {
    int flag_check = 0;
    if (isTrigonometric(str[i]) ||
        (i < (len - 1) && isMatFunctions(str[i], str[i + 1]))) {
      skipMatFunctions(str, &i, &res_num, &flag_check, &flag,
                       &finish_matFunctions, &left_bracket);
      if (flag_check == 1) {  // to not croos road for 'bus error'
        flag += 1;
      }
      i -= flag_check;
      // pop_bracket = 1;
    } else if (i != 0 && (str[i] == '(' && !isOperatorBrackets(str[i - 1]))) {
      *res = "Ошибка, не поставлен оператор перед скобкой!";
      res_num = 2;
    } /* else if (i < (len - 1) && str[i] == ')' && (!isOperator(str[i + 1]))) {
         *res = "Ошибка, не поставлен оператор после скобки!";
         res_num = 2;
     }*/
    if (i < (len - 1) && isOperator(str[i]) && isOperator(str[i + 1])) {
      *res = "Ошибка, два оператора подряд!";
      res_num = 1;
    } else if (str[i] == '(' /* && pop_bracket == 0*/) {
      ++left_bracket;
    } else if (str[i] == ')' /* && pop_bracket == 0*/) {
      ++right_bracket;
    } else if (i != (len - 1) && str[i] == '/' && str[i + 1] == '0') {
      *res = "Ошибка, деление на 0 невозможно";
      res_num = 1;
    }

    if (res_num != 0) {
      break;
    }
  }
  if (res_num == 3) {
    *res = "Ошибка в математических функциях.";
  } else if (res_num == 0 && left_bracket != right_bracket) {
    *res = "Ошибка, скобки не перекрыты!";
  }
}