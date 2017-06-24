#
#Makefile for test
#
# 2014.04.25 W.J@Shanghai
#

MODULE_NAME = test

-include makedefs.mk
-include lib/subdir.mk

CFLAGS += -Ilib
CLFLAGS = -Llib
LIBS = -lpthread -lm -lhello

DEPEND_FILES = $(patsubst %.c, %.o, $(wildcard *.c))

.PHONY:all clean

all:$(MODULE_NAME)
$(MODULE_NAME): $(DEPEND_FILES) $(LIB_NAME)
	@echo "	compile $(MODULE_NAME)"
	@$(LD) $(CLFLAGS) -o $@ $< $(LIBS)
clean:
	@echo "	clean $(MODULE_NAME)"
	@rm -f $(MODULE_NAME) *.o lib/*.a lib/*.o
