CC = gcc 
FLAGS = -Wall -Werror -Wextra --std=c11 
UNIT_TESTS_FLAGS = -lcheck -pthread -lrt -lpthread -lsubunit -lm
all: matrix.a test gcov_report

matrix.a:
	$(CC)  $(FLAGS) -c s21_eq_matrix.c s21_create_matrix.c s21_remove_matrix.c s21_arithmetic_matrix.c s21_is_valid_matrix.c s21_inverse.c
	ar rcs matrix.a *.o
	rm *.o
tests.a:
	$(CC) $(FLAGS) -c ./unit_tests/*.c
	mv s21_*_test.o ./unit_tests/
	ar rcs s21_tests.a ./unit_tests/*.o
	rm ./unit_tests/*.o
test: tests.a
	@gcc unit_tests/main.c -L. tests.a matrix.a $(UNIT_TESTS_FLAGS) -o unit_tests/main
	@unit_tests/main

gcov_report: 
	mkdir -p gcov_files
	gcc --coverage *.c unit_tests/*.c -L. matrix.a -o ./gcov_files/test.out $(UNIT_TESTS_FLAGS)
	./gcov_files/test.out
	lcov -t "Report" -c -d ./gcov_files -o ./gcov_files/coverage.info
	genhtml ./gcov_files/coverage.info -o ./gcov_files/report
	open ./gcov_files/report/index.html
rebuild: clean matrix.a
clean:
	rm -f *.o
	rm -f ./unit_tests/s21_*_test
	rm -f *.a
	rm -fr ./gcov_files/*
n:
	clang-format -n *.c *.h ./unit_tests/*.c *.h
i:
	clang-format -i *.c *.h ./unit_tests/*.c *.h

valgrind: test
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes 2>&1 ./unit_tests/main | grep -E "ERROR|LEAK"

