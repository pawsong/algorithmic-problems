GTEST_DIR=gtest/googletest
GMOCK_DIR=gtest/googlemock
LIB_DIR=lib
BIN_DIR=bin
PROBLEMS=$(wildcard problems/*/)

.PHONY: $(PROBLEMS) clean test

all: gtest $(PROBLEMS)

$(PROBLEMS):
	$(MAKE) -C $@

clean:
	rm -rf $(LIB_DIR)
	rm -rf $(BIN_DIR)
	$(foreach PROBLEM, $(PROBLEMS), $(MAKE) clean -C $(PROBLEM);)

gtest: $(LIB_DIR)/libgmock.a

$(LIB_DIR)/gtest-all.o: ${GTEST_DIR}/src/gtest-all.cc
	mkdir -p $(LIB_DIR)
	$(CXX) -isystem ${GTEST_DIR}/include -I${GTEST_DIR} -isystem ${GMOCK_DIR}/include -I${GMOCK_DIR} -pthread -c $^ -o $@

$(LIB_DIR)/gmock-all.o: ${GMOCK_DIR}/src/gmock-all.cc
	mkdir -p $(LIB_DIR)
	$(CXX) -isystem ${GTEST_DIR}/include -I${GTEST_DIR} -isystem ${GMOCK_DIR}/include -I${GMOCK_DIR} -pthread -c $^ -o $@

$(LIB_DIR)/libgmock.a: $(LIB_DIR)/gtest-all.o $(LIB_DIR)/gmock-all.o
	ar -rv $@ $^

test:
	$(foreach PROBLEM, $(PROBLEMS), $(MAKE) test -C $(PROBLEM);)
