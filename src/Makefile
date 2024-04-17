LIBS_ADDITIONAL = 
CMD_OPEN = open


LIBS_ADDITIONAL = -lm -pthread -lsubunit -lrt
CMD_OPEN = xdg-open

CC=gcc


OBJ_DIR = obj
GCOV_OBJ_DIR = obj/gcov
TESTS_OBJ_DIR = obj/tests
TEST_DIR = tests
MODULES_DIR = ./
REPORT_DIR = report

TEST_EXE = test
GCOV_EXE = gcov_report

MODULES_STATIC_LIBRARY_TEST = my_decimal_test.a
MODULES_STATIC_LIBRARY_GCOV = my_decimal_gcov.a

LFLAGS= 
CFLAGS=-Wall -Werror -Wextra -c -std=c11 -pedantic
CFLAGS_TESTS = $(CFLAGS)


GCOV_FLAGS =-fprofile-arcs -ftest-coverage

LIBS = -lcheck $(LIBS_ADDITIONAL)

LIBS_GCOV = $(LIBS) -lgcov

# Заполняем переменные со списком директорий, исходных и исполняемых файлов
ALL_MODULES_DIRS = $(shell find $(MODULES_DIR) -type d)
ALL_MODULES_C = $(notdir $(shell find $(ALL_MODULES_DIRS) -maxdepth 1 -name "*.c"))
ALL_MODULES_H = $(shell find $(ALL_MODULES_DIRS) -maxdepth 1 -name "*.h")
MAIN_H = $(shell find . -maxdepth 1 -name "*.h")
ALL_H = $(ALL_MODULES_H) $(MAIN_H)
ALL_MODULES_O = $(ALL_MODULES_C:%.c=%.o)

ALL_TESTS_DIRS = $(shell find $(TEST_DIR) -type d)
ALL_TESTS_C = $(notdir $(shell find $(ALL_TESTS_DIRS) -maxdepth 1 -name "*.c"))
ALL_TESTS_H = $(shell find $(ALL_TESTS_DIRS) -maxdepth 1 -name "*.h")
ALL_TESTS_O = $(addprefix $(TESTS_OBJ_DIR)/, $(notdir $(ALL_TESTS_C:%.c=%.o)))

ALL_MODULES_GCOV_O = $(addprefix $(GCOV_OBJ_DIR)/, $(notdir $(ALL_MODULES_C:.c=.o)))

ALL_C_H_FILES = $(shell find . -type f | grep "\.(c|h)$$" -E)

vpath %.c $(ALL_MODULES_DIRS) : $(ALL_TESTS_DIRS)
vpath %.o $(OBJ_DIR)

all: my_decimal.a

my_decimal.a: clean
	$(CC)	$(CFLAGS)	-c	*.c
	ar	rcs	my_decimal.a	*.o
	ranlib	my_decimal.a
	rm	*.o

$(TEST_EXE): clean $(OBJ_DIR) $(TESTS_OBJ_DIR) $(MODULES_STATIC_LIBRARY_TEST) $(ALL_TESTS_O)
	@$(CC) $(LFLAGS) $(ALL_TESTS_O) $(MODULES_STATIC_LIBRARY_TEST) $(LIBS) -o $(TEST_EXE)
	@echo "\n-------------------------------------------------------------------------------------------------\n"
	@./$(TEST_EXE)

$(GCOV_EXE): clean $(GCOV_OBJ_DIR) $(TESTS_OBJ_DIR) $(REPORT_DIR) $(MODULES_STATIC_LIBRARY_GCOV) $(ALL_TESTS_O) $(ALL_H) $(ALL_TESTS_H)
	@$(CC) $(LFLAGS) $(ALL_TESTS_O) $(MODULES_STATIC_LIBRARY_GCOV) $(LIBS_GCOV) -o ./$(GCOV_EXE)
	@echo "\n-------------------------------------------------------------------------------------------------\n"
	@./$(GCOV_EXE)
	@lcov -t "test" -o test_report.info -c -d .
	@genhtml -o report test_report.info
	@rm -rf *.o *.a  *.gch *.gcno test
	@open ./report/index.html

$(MODULES_STATIC_LIBRARY_TEST): $(OBJ_DIR) $(TESTS_OBJ_DIR) $(ALL_MODULES_O) $(ALL_H)
	@echo "*\c"
	@ar rc $(MODULES_STATIC_LIBRARY_TEST) $(addprefix $(OBJ_DIR)/, $(ALL_MODULES_O))
	@ranlib $(MODULES_STATIC_LIBRARY_TEST)

$(MODULES_STATIC_LIBRARY_GCOV): $(GCOV_OBJ_DIR) $(TESTS_OBJ_DIR) $(ALL_MODULES_GCOV_O) $(ALL_H)
	@echo "*\c"
	@ar rc $(MODULES_STATIC_LIBRARY_GCOV) $(ALL_MODULES_GCOV_O)
	@ranlib $(MODULES_STATIC_LIBRARY_GCOV)

%.o: %.c $(ALL_H) $(ALL_TESTS_H)
	@echo "*\c"
	@$(CC) $(CFLAGS) -o $(addprefix $(OBJ_DIR)/, $@) $<

$(GCOV_OBJ_DIR)/%.o : %.c $(ALL_H) $(ALL_TESTS_H)
	@echo "*\c"
	@$(CC) $(CFLAGS) $(GCOV_FLAGS) -o $@ $<

$(TESTS_OBJ_DIR)/%.o : %.c $(ALL_H) $(ALL_TESTS_H)
	@echo "*\c"
	@$(CC) $(CFLAGS_TESTS) -o $@ $<

$(REPORT_DIR):
	@mkdir -p $(REPORT_DIR)
	@echo "folder: $(REPORT_DIR) was created"
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "folder: $(OBJ_DIR) was created"
$(GCOV_OBJ_DIR):
	@mkdir -p $(GCOV_OBJ_DIR)
	@echo "folder: $(GCOV_OBJ_DIR) was created"
$(TESTS_OBJ_DIR):
	@mkdir -p $(TESTS_OBJ_DIR)
	@echo "folder: $(TESTS_OBJ_DIR) was created"

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(REPORT_DIR)
	rm -f *.a *.o
	rm -f *.c.gcov *.gcno *.gcov *.gcda output.info
	rm -f ./$(GCOV_EXE) ./$(TEST_EXE)

rebuild: clean all

leaks:
	leaks --atExit -- ./$(TEST_EXE)
valgrind:
	valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all -s ./$(TEST_EXE)
style:
	cp ../materials/linters/.clang-format ./
	clang-format -style=google -i *.c *.h
	clang-format -style=google -i tests/*.*
	rm -f ./.clang-format


.PHONY: all clean rebuild cpplint cppcheck leaks valgrind
