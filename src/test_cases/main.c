#include "test.h"

void tests_fucn_s21(Suite *s) {
  SRunner *runner = srunner_create(s);
  srunner_set_fork_status(runner, CK_NOFORK);
  srunner_run_all(runner, CK_NORMAL);
  srunner_free(runner);
}

int main() {
  tests_fucn_s21(calc_math());
  tests_fucn_s21(validation_math());
  return 0;
}