TARGET = a.out
HDRS = include

SRC = src/main.cpp \
	  src/data_base.cpp \
	  src/utils.cpp

.PHONY: all clean

all: $(SRCS)
	g++ -std=c++17 -Wall -Wextra -Werror $(addprefix -I,$(HDRS)) -o $(TARGET) $(SRC)

clean: rm -rf a.out