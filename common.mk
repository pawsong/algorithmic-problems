CC=g++
DEBUG=-g
CFLAG=$(DEBUG)
LDFLAG=$(DEBUG)
OBJS=$(addprefix $(LIB_DIR)/, $(CPPS:.cc=.o))

.PHONY: clean

$(EXECUTABLE): $(OBJS)
	mkdir -p $(BIN_DIR)
	$(CC) $(LDFLAG) $^ -o $(BIN_DIR)/$@

$(LIB_DIR)/%.o: %.cc
	mkdir -p $(LIB_DIR)
	$(CC) $(CFLAG) -c $< -o $@

run: $(BIN_DIR)/$(EXECUTABLE)
	$(BIN_DIR)/$(EXECUTABLE)

clean:
	rm -rf $(LIB_DIR)/*.o $(BIN_DIR)/$(EXECUTABLE)
