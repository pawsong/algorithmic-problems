DEBUG=-g
CFLAG=$(DEBUG)
LDFLAG=$(DEBUG)
ROOT_DIR=$(dir $(lastword $(MAKEFILE_LIST)))
LIB_DIR=$(ROOT_DIR)lib
BIN_DIR=$(ROOT_DIR)bin
GTEST_DIR=$(ROOT_DIR)gtest/googletest
EXECUTABLE=$(BIN_DIR)/$(PROBLEM)
OBJS=$(CPPS:.cc=.o)

.PHONY: clean

$(EXECUTABLE): $(OBJS)
	mkdir -p $(BIN_DIR)
	$(CXX) $(LDFLAG) -isystem ${GTEST_DIR}/include -pthread test.cc $^ $(LIB_DIR)/libgtest.a -o $@

%.o: %.cc
	$(CXX) $(CFLAG) -c $< -o $@

test: $(EXECUTABLE)
	$(EXECUTABLE)

clean:
	rm -f $(OBJS) $(EXECUTABLE)
