#
# Makefile template for CSE 30 -- PA4
#

HEADERS		= myls.h

C_SRCS		= myls.c buildFileInfoTable.c displayFileInfo.c \
		  displayPermissions.c displayOwnerName.c nameSortDescending.c \
		  mtimeSortAscending.c

ASM_SRCS	= displayGroupName.s mtimeSortDescending.s nameSortAscending.s

C_OBJS		= myls.o buildFileInfoTable.o displayFileInfo.o \
		  displayPermissions.o displayOwnerName.o nameSortDescending.o \
		  mtimeSortAscending.o

ASM_OBJS	= displayGroupName.o mtimeSortDescending.o nameSortAscending.o \

OBJS		= ${C_OBJS} ${ASM_OBJS}

EXE		= myls

#
# Relevant man pages:
#
# man -M /software/common/gnu/man gcc
# man -M /software/common/gnu/man as
# man -M /opt/SUNWspro/man lint
#

GCC		= /software/common/gnu/bin/gcc
ASM		= ${GCC}
LINT		= /opt/SUNWspro/bin/lint

GCC_FLAGS	= -c -g -ansi -W -Wall -D__EXTENSIONS__
LINT_FLAGS1	= -c -err=warn
LINT_FLAGS2	= -u -err=warn
ASM_FLAGS	= -c -g
LD_FLAGS	= -g -ansi -W -Wall

#
# Standard rules
#

.s.o:
	@echo "Assembling each assembly source file separately ..."
	${ASM} ${ASM_FLAGS} $<
	@echo ""

.c.o:
	@echo "Linting each C source file separately ..."
	${LINT} ${LINT_FLAGS1} $<
	@echo ""
	@echo "Compiling each C source file separately ..."
	${GCC} ${GCC_FLAGS} $<
	@echo ""

#
# Simply have our project target be a single default ${EXE} executable.
#

${EXE}:	${OBJS}
	@echo "2nd phase lint on all C source files ..."
	${LINT} ${LINT_FLAGS2} *.ln
	@echo ""
	@echo "Linking all object modules ..."
	${GCC} -o ${EXE} ${LD_FLAGS} ${OBJS}
	@echo ""
	@echo "Done."

${C_OBJS}:      ${HEADERS}

testnameSortAscending: test.h myls.h nameSortAscending.s testnameSortAscending.c
	@echo "Compiling testnameSortAscending.c"
	gcc -g -o testnameSortAscending testnameSortAscending.c nameSortAscending.s
	@echo "Done."

runtestnameSortAscending: testnameSortAscending
	@echo "Running testnameSortAscending"
	@./testnameSortAscending

testnameSortDescending: test.h myls.h nameSortDescending.c testnameSortDescending.c
	@echo "Compiling testnameSortDescending.c"
	gcc -g -o testnameSortDescending testnameSortDescending.c nameSortDescending.c
	@echo "Done."

runtestnameSortDescending: testnameSortDescending
	@echo "Running testnameSortDescending"
	@./testnameSortDescending

testmtimeSortDescending: test.h myls.h mtimeSortDescending.s testmtimeSortDescending.c
	@echo "Compiling testmtimeSortDescending.c"
	gcc -g -o testmtimeSortDescending myls.h testmtimeSortDescending.c mtimeSortDescending.s
	@echo "Done."

runtestmtimeSortDescending: testmtimeSortDescending
	@echo "Running testmtimeSortDescending"
	@./testmtimeSortDescending

testmtimeSortAscending: test.h myls.h mtimeSortAscending.c testmtimeSortAscending.c
	@echo "Compiling testmtimeSortAscending.c"
	gcc -g -o testmtimeSortAscending myls.h testmtimeSortAscending.c mtimeSortAscending.c
	@echo "Done."

runtestmtimeSortAscending: testmtimeSortAscending
	@echo "Running testmtimeSortAscending"
	@./testmtimeSortAscending

clean:
	@echo "Cleaning up project directory ..."
	/usr/bin/rm -f *.o ${EXE} *.ln core a.out
	@echo ""
	@echo "Clean."

new:
	make clean
	make

