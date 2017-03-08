# $Id: Makefile,v 1.23 2016-10-12 16:59:53-07 - - $
# by Sam Song (sasong@ucsc.edu)

DEPSFILE  = Makefile.deps
NOINCLUDE = clean spotless
NEEDINCL  = ${filter ${NOINCLUDE}, ${MAKECMDGOALS}}
CPP       = g++-5 -g -O0 -Wall -Wextra -std=gnu++14
MKDEPS    = g++-5 -MM -std=gnu++14
GRIND     = valgrind --leak-check=full --show-reachable=yes

LDFLAGS	   = `pkg-config opencv --cflags --libs`


MODULES   = colormap
HDRSRC    = ${MODULES:=.h}
CPPSRC    = ${MODULES:=.cpp} main.cpp
EXECBIN   = Classify
ALLCSRC   = ${CPPSRC} ${CGENS}
OBJECTS   = ${ALLCSRC:.cpp=.o}
MODSRC    = ${foreach MOD, ${MODULES}, ${MOD}.h ${MOD}.cpp}
MISCSRC   = ${filter-out ${MODSRC}, ${HDRSRC} ${CPPSRC}}
ALLSRC    = README ${FLEXSRC} ${BISONSRC} ${MODSRC} ${MISCSRC} Makefile
TESTINS   = ${wildcard test*.oc}
EXECTEST  = ${EXECBIN} -ly
LISTSRC   = ${ALLSRC} ${DEPSFILE} ${PARSEHDR}

all : ${EXECBIN}

${EXECBIN} : ${OBJECTS}
	${CPP} -o ${EXECBIN} ${OBJECTS} ${LDFLAGS}
	-rm ${OBJECTS}

%.o : %.cpp
	${CPP} -c $<

clean :
	- rm ${OBJECTS} ${ALLGENS} ${REPORTS} ${DEPSFILE} core
	- rm ${foreach test, ${TESTINS:.in=}, \
		${patsubst %, ${test}.%, out err log}}

spotless : clean
	- rm ${EXECBIN}

deps : ${ALLCSRC}
	@ echo "# ${DEPSFILE} created `date` by ${MAKE}" >${DEPSFILE}
	${MKDEPS} ${ALLCSRC} >>${DEPSFILE}

${DEPSFILE} :
	@ touch ${DEPSFILE}
	${MAKE} --no-print-directory deps

tests : ${EXECBIN}
	touch ${TESTINS}
	make --no-print-directory ${TESTINS:.in=.out}

%.out %.err : %.in
	${GRIND} --log-file=$*.log ${EXECTEST} $< 1>$*.out 2>$*.err; \
	echo EXIT STATUS = $$? >>$*.log

again :
	gmake --no-print-directory spotless deps ci all lis

ifeq "${NEEDINCL}" ""
include ${DEPSFILE}
endif
