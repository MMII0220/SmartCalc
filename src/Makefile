CC = gcc
DELETE = rm -rf

VALGRIND_OUTPUT = valgrind.txt

BUILD_FLAGS = -Wall -Wextra -Werror -std=c11 -pedantic -fanalyzer
VALGRIND_FLAGS = -s --log-file="$(VALGRIND_OUTPUT)" --track-origins=yes --trace-children=yes --leak-check=full --leak-resolution=med
LIBS_FLAGS = -lcheck

SRC_C_FILES = s21_calc.c s21_validation.c s21_polish_notation.c
TEST_C_FILES = test_cases/main.c test_cases/suite.c

TEST_TARGET  = s21_test

REPORT_DIR = report

INCLUDES = . 

BUILD_DIR = ../build/

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	LIBS_FLAGS += -lsubunit -lm
endif

all: clean test gcov_report

test: format $(SRC_C_FILES) calc.a
	$(CC) $(BUILD_FLAGS) $(addprefix -I , $(INCLUDES))	 $(SRC_C_FILES) $(TEST_C_FILES) -o $(TEST_TARGET) $(LIBS_FLAGS)
	./$(TEST_TARGET)

calc.a:
	$(CC) -c $(SRC_C_FILES)
	ar rcs calc.a *.o
	ranlib $@
	cp calc.a my_calc_qtcreator/calc

lib.so:
	$(CC) -fPIC -c $(SRC_C_FILES)
	$(CC) -shared -o libcalc.so *.o

gcov_report: format
	$(CC) --coverage $(BUILD_FLAGS) $(addprefix -I , $(INCLUDES)) $(SRC_C_FILES) $(TEST_C_FILES) -o $(TEST_TARGET) $(LIBS_FLAGS)
	./$(TEST_TARGET)
	lcov --no-external  -t "$(TEST_TARGET)" -o $(TEST_TARGET).info -c -d .
	genhtml -o report $(TEST_TARGET).info
	rm *.gcda *.gcno *.info
	open report/index.html

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem .

uninstall:
	$(DELETE) build

install: uninstall calc.a
	mkdir build
	cd my_calc_qtcreator/calc && qmake . && make
	cd ..

clean:
	$(DELETE) $(TEST_TARGET)
	$(DELETE) $(REPORT_DIR)
	$(DELETE) *.info
	$(DELETE) *.o
	$(DELETE) *.gc*
	$(DELETE) *.a 
	$(DELETE) calc.tar.gz
	$(DELETE) calc.app
	$(DELETE) $(VALGRIND_OUTPUT)

valgrind: format test
	valgrind $(VALGRIND_FLAGS) ./$(TEST_TARGET)
	grep --color=always -n "ERROR SUMMARY" $(VALGRIND_OUTPUT) | grep -v "0 errors from 0 contexts" || true
	grep --color=always -n "definitely lost:" $(VALGRIND_OUTPUT) | grep -v "0 bytes in 0 blocks" || true

leak:
	leaks -atExit -- ./$(TEST_TARGET)

dvi:
	open ../README.md

dist: install
	tar -czf calc.tar.gz my_calc_qtcreator/calc/calc.app
	cp calc.tar.gz build
	cp -R my_calc_qtcreator/calc/calc.app build

clang:
	cp ../materials/linters/.clang-format .
	clang-format -n *.h *.c test_cases/*.c test_cases/*.h my_calc_qtcreator/calc/*.h
	rm -f .clang-format

format:
	cp ../materials/linters/.clang-format .
	clang-format -style=Google *.c -i
	clang-format -style=Google *.h -i
	clang-format -style=Google test_cases/*.c -i
	clang-format -style=Google test_cases/*.h -i
	clang-format -style=Google my_calc_qtcreator/calc/*.h my_calc_qtcreator/calc/*.cpp -i
	rm -rf .clang-format
