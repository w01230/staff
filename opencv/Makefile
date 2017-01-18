#
# This is test make file for opencv
#
# John Wang@2017/01/16
# 
MODULE = test

CFLAGS = -g -O2 -Wall
CLFLAGS = -O2 -Wall
OPENCV = `pkg-config --cflags --libs opencv`

CC = g++
LD = $(CC)

DEPEND_FILES = $(patsubst %.cpp, %.o, $(wildcard *.cpp))

.PHONY: all clean

all:$(MODULE)
$(MODULE):$(DEPEND_FILES)
	@echo "compile $(MODULE)"
	@$(LD) $(CLFLAGS) $(OPENCV) -o $@ $<

%.o:%.cpp
#	@echo "compile $?"
	@$(CC) $(CFLAGS) -c $^ -o $@

clean:
	@rm -f *.o $(MODULE)
