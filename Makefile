CC=gcc
CFLAGS=-Wall -g -Werror -o0

INCLUDE_DIR=include
SRC_DIR=src
OBJ_DIR=obj
DIST_DIR=dist
SPIKE_DIR=spike

SPIKE_SRC_DIR=spike
RUN_DIR=run

SRCS=$(wildcard $(SRC_DIR)/*.c)
OBJS=$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

SPIKES=$(wildcard $(SPIKE_DIR)/*.c)
SPIKE_OBJS=$(patsubst $(SPIKE_DIR)/%.c, $(RUN_DIR)/%, $(SPIKES))
RUNS=$(wildcard $(RUN_DIR)/*)

all: spike

spike: build

build: init $(SPIKE_OBJS)
	for t in $(RUNS) ; do ./$$t ; done
	

$(RUN_DIR)/%: $(SPIKE_SRC_DIR)/%.c
	$(CC) $(CFLAGS) -o $@ $< -I $(INCLUDE_DIR)

init: clean
	@mkdir $(OBJ_DIR) $(DIST_DIR) $(RUN_DIR)

clean:
	@rm -rf $(OBJ_DIR) $(DIST_DIR) $(RUN_DIR)

