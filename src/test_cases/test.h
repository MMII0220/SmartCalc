#ifndef TEST_H_
#define TEST_H_

#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "../s21_calc.h"

#define RESET "\033[0m"
#define RED "\e[0;91m"
#define GREEN "\033[32m"
#define BLUE "\e[0;94m"

Suite *calc_math();
Suite *validation_math();

#endif  // TEST_H_