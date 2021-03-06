DEBUG=-g
CXXFLAG=$(DEBUG) -std=c++11
LDFLAG=
ROOT_DIR=$(dir $(lastword $(MAKEFILE_LIST)))
LIB_DIR=$(ROOT_DIR)lib
BIN_DIR=$(ROOT_DIR)bin
GTEST_DIR=$(ROOT_DIR)gtest/googletest
GMOCK_DIR=$(ROOT_DIR)gtest/googlemock
EXECUTABLE=$(BIN_DIR)/$(PROBLEM)
OBJS=$(CPPS:.cc=.o)

.PHONY: clean

$(EXECUTABLE): test.cc $(OBJS)
	mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAG) $(LDFLAG) -isystem ${GTEST_DIR}/include -isystem ${GMOCK_DIR}/include -pthread $^ $(LIB_DIR)/libgmock.a -o $@

%.o: %.cc
	$(CXX) $(CXXFLAG) -c $< -o $@

test: $(EXECUTABLE)
	$(EXECUTABLE)

clean:
	rm -f $(OBJS) $(EXECUTABLE)
