CC = gcc
CFLAGS = -g -Wall

SRC = src
OBJ = build

SRCS = $(wildcard $(SRC)/*.c)
OBJS = $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))
HDRS = $(wildcard $(SRC)/*.h)
BINARY = ksamp

$(BINARY): $(OBJS) $(OBJ)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJ)/%.o: $(SRC)/%.c $(OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ):
	mkdir -p $@

clean:
	rm -r $(OBJ)
	rm $(BINARY)
