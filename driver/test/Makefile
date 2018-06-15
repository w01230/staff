#
#Makefile for test
#
# 2014.04.25 W.J@Shanghai
#

MODULE_NAME = test

-include makedefs.mk

#CFLAGS += 
#CLFLAGS +=
LIBS = -lpthread -lm

DEPEND_FILES = $(patsubst %.c, %.o, $(wildcard *.c))

.PHONY:all clean

all:$(MODULE_NAME)
$(MODULE_NAME): $(DEPEND_FILES)
	@echo "	compile $(MODULE_NAME)"
	@$(LD) $(CLFLAGS) -o $@ $^ $(LIBS)
	
$(DEPEND_FILES):%.o:%.c
	@$(CC) $(CFLAGS) -c $^ -o $@

clean:
	@echo "	clean $(MODULE_NAME)"
	@rm -f $(MODULE_NAME) *.o lib/*.a lib/*.o
