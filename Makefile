
# source files
source=ppos-core-aux.c 
# libraries to link with
libs=libs/libppos_static.a
# output dir for binary files
bindir=bin
# c compiler
cc=gcc
# flags passed to the compiler
flags=-Wall -lrt #-DDEBUG

all:
	@echo "usage: make <test> run"
	@echo "list of tests: "
	@echo "               preempcao"
	@echo "               contab-prio"
	@echo "               preempcao-stress"

# build the test source file
%.o: %.c $(bindir)
	$(cc) $(source) $(libs) $(flags) $< -o $(bindir)/a.out

# run the binary file
run: $(bindir)/a.out
	cd $(bindir) && ./a.out && cd ..

# create a directory for the binary files
$(bindir):
	mkdir $(bindir)

# targets for each test file
preempcao: pingpong-preempcao.o 
contab-prio: pingpong-contab-prio.o
contab: pingpong-contab.o
preempcao-stress: pingpong-preempcao-stress.o

# just clean the binary dir
clean:
	rm -rf $(bindir)
