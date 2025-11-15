CC=gcc
CPP=g++
CFLAGS=-Wall -g -Werror -o0

INCLUDE_DIR=include
SRC_DIR=src
OBJ_DIR=obj
LIB_DIR=lib
DIST_DIR=dist
SPIKE_DIR=spike

SPIKE_SRC_DIR=spike
RUN_DIR=run

TEST_DIR=tests
TEST_BIN_DIR=$(TEST_DIR)/bin

SRCS=$(wildcard $(SRC_DIR)/*.c)
OBJS=$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

SPIKES=$(wildcard $(SPIKE_DIR)/*.c)
SPIKE_OBJS=$(patsubst $(SPIKE_DIR)/%.c, $(RUN_DIR)/%, $(SPIKES))
RUNS=$(wildcard $(RUN_DIR)/*)
DIST=$(DIST_DIR)/librnd.a

GTEST_LIB_DIR=$(LIB_DIR)/googletest/build/lib
GTEST_INCLUDE_DIR=$(LIB_DIR)/googletest/googletest/include

TESTS=$(wildcard $(TEST_DIR)/*.cpp)
TESTBINS=$(patsubst $(TEST_DIR)/%.cpp, $(TEST_BIN_DIR)/%, $(TESTS))

all: build

# spike: build

build: init $(OBJS)
	ar rcs $(DIST) $(OBJS)
	
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -o $@ -c $< -I $(INCLUDE_DIR)

$(RUN_DIR)/%: $(SPIKE_SRC_DIR)/%.c
	$(CC) $(CFLAGS) -o $@ $< -I $(INCLUDE_DIR)

init: clean
	@mkdir $(OBJ_DIR) $(DIST_DIR) $(RUN_DIR) $(TEST_BIN_DIR)

clean:
	@rm -rf $(OBJ_DIR) $(DIST_DIR) $(RUN_DIR) $(TEST_BIN_DIR)

$(TEST_BIN_DIR)/%: $(TEST_DIR)/%.cpp
	$(CPP) $(CFLAGS) -o $@ $< -I $(INCLUDE_DIR) -I $(GTEST_INCLUDE_DIR) -L $(DIST_DIR) -L $(GTEST_LIB_DIR) -lgtest -lgtest_main -l rnd

test: build $(TESTBINS)
	for t in $(TESTBINS) ; do ./$$t ; done

