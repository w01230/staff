#
#Makefile for static library
#
# 2016.07.29 W.J@Shanghai
#
#.SUFFIXES:.a
LIB_NAME = libhello.a

-include ../makedefs.mk

SUBDIR = lib

LIBDEPEND_FILES = $(patsubst $(SUBDIR)/%.c, $(SUBDIR)/%.o, $(wildcard $(SUBDIR)/*.c))

.SECONDEXPANSION:
.SECONDARY:
%.a:$(LIBDEPEND_FILES)
	@echo "	create $(LIB_NAME)"
	@$(AR) $(ARFLAGS) $(SUBDIR)/$(LIB_NAME) $^

%.o:%.c
#	@echo "	compile $^"
	@$(CC) $(CFLAGS) -c $^ -o $@
