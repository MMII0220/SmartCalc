#include "test.h"

// s21_calc s21_polish_notation

START_TEST(math_test1) {
  char *test1 = "1+2";
  char res[256] = "\0";
  char *x = "\0";
  infixToPostfix(test1, res);
  double t1 = 0.0;
  double ch1 = 1 + 2;
  evaluatePostfix(res, &t1, x);
  ck_assert_double_eq(t1, ch1);
}
END_TEST

START_TEST(math_test2) {
  char *test1 = "(1+(3+(4+5)))";
  char res[256] = "\0";
  char *x = "\0";
  infixToPostfix(test1, res);
  double t1 = 0.0;
  double ch1 = 13;
  evaluatePostfix(res, &t1, x);
  ck_assert_double_eq(t1, ch1);
}
END_TEST

START_TEST(math_test3) {
  char *test1 = "sin(1)";
  char res[256] = "\0";
  char *x = "\0";
  infixToPostfix(test1, res);
  double t1 = 0.0;
  double ch1 = 0.841471;
  evaluatePostfix(res, &t1, x);
  ck_assert_double_eq(t1, ch1);
}
END_TEST

START_TEST(math_test4) {
  char *test1 = "sqrt(4)";
  char res[256] = "\0";
  char *x = "\0";
  infixToPostfix(test1, res);
  double t1 = 0.0;
  double ch1 = 2;
  evaluatePostfix(res, &t1, x);
  ck_assert_double_eq(t1, ch1);
}
END_TEST

START_TEST(math_test5) {
  char *test1 = "cos(1)";
  char res[256] = "\0";
  char *x = "\0";
  infixToPostfix(test1, res);
  double t1 = 0.0;
  double ch1 = 0.540302;
  evaluatePostfix(res, &t1, x);
  ck_assert_double_eq(t1, ch1);
}
END_TEST

START_TEST(math_test6) {
  char *test1 = "tan(1)";
  char res[256] = "\0";
  char *x = "\0";
  infixToPostfix(test1, res);
  double t1 = 0.0;
  double ch1 = 1.55741;
  evaluatePostfix(res, &t1, x);
  ck_assert_double_eq(t1, ch1);
}
END_TEST

START_TEST(math_test7) {
  char *test1 = "log(100)";
  char res[256] = "\0";
  char *x = "\0";
  infixToPostfix(test1, res);
  double t1 = 0.0;
  double ch1 = 2;
  evaluatePostfix(res, &t1, x);
  ck_assert_double_eq(t1, ch1);
}
END_TEST

START_TEST(math_test8) {
  char *test1 = "ln(5)";
  char res[256] = "\0";
  char *x = "\0";
  infixToPostfix(test1, res);
  double t1 = 0.0;
  double ch1 = 2.3219;
  evaluatePostfix(res, &t1, x);
  ck_assert_double_eq(t1, ch1);
}
END_TEST

START_TEST(math_test9) {
  char *test1 = "asin(1)";
  char res[256] = "\0";
  char *x = "\0";
  infixToPostfix(test1, res);
  double t1 = 0.0;
  double ch1 = 1.5708;
  evaluatePostfix(res, &t1, x);
  ck_assert_double_eq(t1, ch1);
}
END_TEST

START_TEST(math_test10) {
  char *test1 = "acos(1)";
  char res[256] = "\0";
  char *x = "\0";
  infixToPostfix(test1, res);
  double t1 = 0.0;
  double ch1 = 0.0;
  evaluatePostfix(res, &t1, x);
  ck_assert_double_eq(t1, ch1);
}
END_TEST

START_TEST(math_test11) {
  char *test1 = "atan(1)";
  char res[256] = "\0";
  char *x = "\0";
  infixToPostfix(test1, res);
  double t1 = 0.0;
  double ch1 = 0.785398;
  evaluatePostfix(res, &t1, x);
  ck_assert_double_eq(t1, ch1);
}
END_TEST

START_TEST(math_test12) {
  char *test1 = "23-20";
  char res[256] = "\0";
  char *x = "\0";
  infixToPostfix(test1, res);
  double t1 = 0.0;
  double ch1 = 3.0;
  evaluatePostfix(res, &t1, x);
  ck_assert_double_eq(t1, ch1);
}
END_TEST

START_TEST(math_test13) {
  char *test1 = "3*2";
  char res[256] = "\0";
  char *x = "\0";
  infixToPostfix(test1, res);
  double t1 = 0.0;
  double ch1 = 6.0;
  evaluatePostfix(res, &t1, x);
  ck_assert_double_eq(t1, ch1);
}
END_TEST

START_TEST(math_test14) {
  char *test1 = "100/10";
  char res[256] = "\0";
  char *x = "\0";
  infixToPostfix(test1, res);
  double t1 = 0.0;
  double ch1 = 10.0;
  evaluatePostfix(res, &t1, x);
  ck_assert_double_eq(t1, ch1);
}
END_TEST

START_TEST(math_test15) {
  char *test1 = "4^2";
  char res[256] = "\0";
  char *x = "\0";
  infixToPostfix(test1, res);
  double t1 = 0.0;
  double ch1 = 16;
  evaluatePostfix(res, &t1, x);
  ck_assert_double_eq(t1, ch1);
}
END_TEST

START_TEST(math_test16) {
  char *test1 = "2.2+3";
  char res[256] = "\0";
  char *x = "\0";
  infixToPostfix(test1, res);
  double t1 = 0.0;
  double ch1 = 5.2;
  evaluatePostfix(res, &t1, x);
  ck_assert_double_eq(t1, ch1);
}
END_TEST

START_TEST(math_test17) {
  char *test1 = "3+x";
  char res[256] = "\0";
  char *x = "2.1";
  infixToPostfix(test1, res);
  double t1 = 0.0;
  double ch1 = 5.1;
  evaluatePostfix(res, &t1, x);
  ck_assert_double_eq(t1, ch1);
}
END_TEST

START_TEST(math_test18) {
  char *test1 = "3+x";
  char res[256] = "\0";
  char *x = "2";
  infixToPostfix(test1, res);
  double t1 = 0.0;
  double ch1 = 5.0;
  evaluatePostfix(res, &t1, x);
  ck_assert_double_eq(t1, ch1);
}
END_TEST

START_TEST(math_test19) {
  char *test1 = "3+x";
  char res[256] = "\0";
  char *x = "sin(1)";
  infixToPostfix(test1, res);
  double t1 = 0.0;
  double ch1 = 3.841471;
  evaluatePostfix(res, &t1, x);
  ck_assert_double_eq(t1, ch1);
}
END_TEST

START_TEST(math_test20) {
  char *test1 = "2+3+4-4-3";
  char res[256] = "\0";
  char *x = "\0";
  infixToPostfix(test1, res);
  double t1 = 0.0;
  double ch1 = 2.0;
  evaluatePostfix(res, &t1, x);
  ck_assert_double_eq(t1, ch1);
}
END_TEST

START_TEST(math_test21) {
  char *test1 = "2*2/2*2";
  char res[256] = "\0";
  char *x = "\0";
  infixToPostfix(test1, res);
  double t1 = 0.0;
  double ch1 = 4.0;
  evaluatePostfix(res, &t1, x);
  ck_assert_double_eq(t1, ch1);
}
END_TEST

START_TEST(math_test22) {
  char *test1 = "2+3*4-sqrt(25)";
  char res[256] = "\0";
  char *x = "\0";
  infixToPostfix(test1, res);
  double t1 = 0.0;
  double ch1 = 9.0;
  evaluatePostfix(res, &t1, x);
  ck_assert_double_eq(t1, ch1);
}
END_TEST

START_TEST(math_test23) {
  char *test1 = "2+3-4^2";
  char res[256] = "\0";
  char *x = "\0";
  infixToPostfix(test1, res);
  double t1 = 0.0;
  double ch1 = -11.0;
  evaluatePostfix(res, &t1, x);
  ck_assert_double_eq(t1, ch1);
}
END_TEST

START_TEST(math_test24) {
  char *test1 = "5mod2";
  char res[256] = "\0";
  char *x = "\0";
  infixToPostfix(test1, res);
  double t1 = 0.0;
  double ch1 = 1.0;
  evaluatePostfix(res, &t1, x);
  ck_assert_double_eq(t1, ch1);
}
END_TEST

START_TEST(math_test25) {
  char *test1 = "5 mod 2 + 4";
  char res[256] = "\0";
  char *x = "\0";
  infixToPostfix(test1, res);
  double t1 = 0.0;
  double ch1 = 5.0;
  evaluatePostfix(res, &t1, x);
  ck_assert_double_eq(t1, ch1);
}
END_TEST

Suite *calc_math(void) {
  Suite *s;
  TCase *tc_math;
  s = suite_create("calc_math");
  tc_math = tcase_create("math");
  tcase_add_test(tc_math, math_test1);
  tcase_add_test(tc_math, math_test2);
  tcase_add_test(tc_math, math_test3);
  tcase_add_test(tc_math, math_test4);
  tcase_add_test(tc_math, math_test5);
  tcase_add_test(tc_math, math_test6);
  tcase_add_test(tc_math, math_test7);
  tcase_add_test(tc_math, math_test8);
  tcase_add_test(tc_math, math_test9);
  tcase_add_test(tc_math, math_test10);
  tcase_add_test(tc_math, math_test11);
  tcase_add_test(tc_math, math_test12);
  tcase_add_test(tc_math, math_test13);
  tcase_add_test(tc_math, math_test14);
  tcase_add_test(tc_math, math_test15);
  tcase_add_test(tc_math, math_test16);
  tcase_add_test(tc_math, math_test17);
  tcase_add_test(tc_math, math_test18);
  tcase_add_test(tc_math, math_test19);
  tcase_add_test(tc_math, math_test20);
  tcase_add_test(tc_math, math_test21);
  tcase_add_test(tc_math, math_test22);
  tcase_add_test(tc_math, math_test23);
  tcase_add_test(tc_math, math_test24);
  tcase_add_test(tc_math, math_test25);

  suite_add_tcase(s, tc_math);
  return s;
}

// s21_validation

START_TEST(validation_test1) {
  char str[256] = "2++2";
  char *res = NULL;
  check_valid_form(str, &res);
  char *outStr = "Ошибка, два оператора подряд!";
  ck_assert_str_eq(res, outStr);
}
END_TEST

START_TEST(validation_test2) {
  char str[256] = "(2+3))";
  char *res = NULL;
  check_valid_form(str, &res);
  char *outStr = "Ошибка, скобки не перекрыты!";
  ck_assert_str_eq(res, outStr);
}
END_TEST

START_TEST(validation_test3) {
  char str[256] = "2/0";
  char *res = NULL;
  check_valid_form(str, &res);
  char *outStr = "Ошибка, деление на 0 невозможно";
  ck_assert_str_eq(res, outStr);
}
END_TEST

START_TEST(validation_test4) {
  char str[256] = "2(3+5)";
  char *res = NULL;
  check_valid_form(str, &res);
  char *outStr = "Ошибка, не поставлен оператор перед скобкой!";
  ck_assert_str_eq(res, outStr);
}
END_TEST

START_TEST(validation_test5) {
  char str[256] = "sqrt(-4)";
  char *res = NULL;
  check_valid_form(str, &res);
  char *outStr = "Ошибка в математических функциях.";
  ck_assert_str_eq(res, outStr);
}
END_TEST

START_TEST(validation_test6) {
  char str[256] = "sin)";
  char *res = NULL;
  check_valid_form(str, &res);
  char *outStr = "Ошибка в математических функциях.";
  ck_assert_str_eq(res, outStr);
}
END_TEST

START_TEST(validation_test7) {
  char str[256] = "2+2-4";
  char *res = NULL;
  check_valid_form(str, &res);
  char *outStr = NULL;
  ck_assert_pstr_eq(res, outStr);
}
END_TEST

START_TEST(validation_test8) {
  char str[256] = "2+3-4*(2+sin(3))-20/2";
  char *res = NULL;
  check_valid_form(str, &res);
  char *outStr = NULL;
  ck_assert_pstr_eq(res, outStr);
}
END_TEST

Suite *validation_math(void) {
  Suite *s;
  TCase *tc_validation;
  s = suite_create("validation_math");
  tc_validation = tcase_create("validation");

  tcase_add_test(tc_validation, validation_test1);
  tcase_add_test(tc_validation, validation_test2);
  tcase_add_test(tc_validation, validation_test3);
  tcase_add_test(tc_validation, validation_test4);
  tcase_add_test(tc_validation, validation_test5);
  tcase_add_test(tc_validation, validation_test6);
  tcase_add_test(tc_validation, validation_test7);
  tcase_add_test(tc_validation, validation_test8);

  suite_add_tcase(s, tc_validation);
  return s;
}