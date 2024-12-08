CXX = gcc
CXXFLAGS = -Wall -I ./include
SRCDIR = src
SRCS = $(wildcard src/*.c) main.c
ODIR = obj
OBJS = $(addprefix $(ODIR)/, $(notdir $(SRCS:%.c=%.o))) # Add all source files into object directory
DEPENDS = $(addprefix $(ODIR)/, $(notdir $(SRCS:%.c=%.d)))

make: e-cellman

list:
	echo $(DEPENDS)

.PHONY: all clean

all: make clean

build: $(OBJS)

clean:
	rm -rf $(ODIR)

# Main program
e-cellman: $(OBJS)
	$(CXX) -o $@ $(OBJS)

# Make object directory if needed
obj:
	mkdir $(ODIR)

# Build all source files found in source directory
$(ODIR)/%.o: $(SRCDIR)/%.c | obj
	$(CXX) -c -MMD -MP $(CXXFLAGS) $(CPPFLAGS) -O $< -o $@

# Build any source files found in top directory (Such as main.c)
$(ODIR)/%.o: %.c | obj
	$(CXX) -c -MMD -MP $(CXXFLAGS) $(CPPFLAGS) -O $< -o $@

# Use any existing dependency files that exist in the obj directory
-include $(DEPENDS)