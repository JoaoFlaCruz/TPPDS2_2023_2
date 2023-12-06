CC := g++
SRCDIR := code/src
TSTDIR := tests
OBJDIR := build
HDRDIR := code/headers
BINDIR := bin

TARGET := main
MAIN := code/main.cpp
TESTER := code/tester.cpp

SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
TSTSOURCES := $(shell find $(TSTDIR) -type f -name *.$(SRCEXT))
TESTOBJECTS := $(patsubst $(TSTDIR)/%,$(OBJDIR)/%,$(TSTSOURCES:.$(SRCEXT)=.o))

CFLAGS := -g --coverage -w -O3 -std=c++11
INC := -I third_party/ -I $(HDRDIR)/ 

# Add the include directory for tests
INC_TESTS := -I $(TSTDIR)/

$(OBJDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

$(OBJDIR)/%.o: $(TSTDIR)/%.$(SRCEXT)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INC) $(INC_TESTS) -c -o $@ $<

main: $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $(INC) $(MAIN) $^ -o $(BINDIR)/main

tests: $(TESTOBJECTS) $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $(INC) $(INC_TESTS) $(TESTER) $^ -o $(BINDIR)/tester
	$(BINDIR)/tester

all: main tests

run: main
	$(BINDIR)/main

clean:
	$(RM) -r $(OBJDIR)/* $(BINDIR)/* coverage/* *.gcda *.gcno

distcheck:
	$(RM) -r $(OBJDIR)/*
	$(RM) -r $(BINDIR)/*

coverage: tests
	gcovr -r . --exclude="third_party/doctest.h"

.PHONY: clean run
