CC=g++
GTEST_DIR=gtest/googletest
LIB_DIR=lib
BIN_DIR=bin
PROBLEMS=$(wildcard problems/*/)

.PHONY: $(PROBLEMS) clean test

all: gtest $(PROBLEMS)

$(PROBLEMS):
	make -C $@

clean:
	rm -f $(LIB_DIR)/*
	rm -f $(BIN_DIR)/*

gtest: $(LIB_DIR)/gtest-all.o $(LIB_DIR)/libgtest.a

$(LIB_DIR)/gtest-all.o: ${GTEST_DIR}/src/gtest-all.cc
	mkdir -p $(LIB_DIR)
	$(CC) -isystem ${GTEST_DIR}/include -I${GTEST_DIR} -pthread -c ${GTEST_DIR}/src/gtest-all.cc -o $(LIB_DIR)/gtest-all.o

$(LIB_DIR)/libgtest.a: $(LIB_DIR)/gtest-all.o
	ar -rv $(LIB_DIR)/libgtest.a $(LIB_DIR)/gtest-all.o

test:
