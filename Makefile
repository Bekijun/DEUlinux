# Makefile

CC = gcc
CFLAGS = -fPIC -Wall
LIB_DIR = lib
SRC_DIR = src

# 목적 파일
OBJ = $(SRC_DIR)/arithmetic.o

# 정적 및 공유 라이브러리
STATIC_LIB = $(LIB_DIR)/libarithmetic.a
SHARED_LIB = $(LIB_DIR)/libarithmetic.so

# 각 연산 프로그램
ADD_PROG = add_program
SUBTRACT_PROG = subtract_program
MULTIPLY_PROG = multiply_program
DIVIDE_PROG = divide_program

all: $(ADD_PROG) $(SUBTRACT_PROG) $(MULTIPLY_PROG) $(DIVIDE_PROG)

# 목적 파일 생성
$(OBJ): $(SRC_DIR)/arithmetic.c $(SRC_DIR)/arithmetic.h
	$(CC) -c $< -o $@

# 정적 라이브러리 생성
$(STATIC_LIB): $(OBJ)
	ar rcs $@ $^

# 공유 라이브러리 생성
$(SHARED_LIB): $(OBJ)
	$(CC) -shared -o $@ $^

# 덧셈 프로그램 빌드 (정적 라이브러리 사용)
$(ADD_PROG): $(SRC_DIR)/add_main.c $(STATIC_LIB)
	$(CC) $< -L$(LIB_DIR) -larithmetic -o $@

# 뺄셈 프로그램 빌드 (정적 라이브러리 사용)
$(SUBTRACT_PROG): $(SRC_DIR)/subtract_main.c $(STATIC_LIB)
	$(CC) $< -L$(LIB_DIR) -larithmetic -o $@

# 곱셈 프로그램 빌드 (공유 라이브러리 사용)
$(MULTIPLY_PROG): $(SRC_DIR)/multiply_main.c $(SHARED_LIB)
	$(CC) $< -L$(LIB_DIR) -larithmetic -o $@

# 나눗셈 프로그램 빌드 (공유 라이브러리 사용)
$(DIVIDE_PROG): $(SRC_DIR)/divide_main.c $(SHARED_LIB)
	$(CC) $< -L$(LIB_DIR) -larithmetic -o $@

clean:
	rm -f $(SRC_DIR)/*.o $(ADD_PROG) $(SUBTRACT_PROG) $(MULTIPLY_PROG) $(DIVIDE_PROG)
	rm -f $(STATIC_LIB) $(SHARED_LIB)

