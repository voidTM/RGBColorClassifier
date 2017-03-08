# $Id: Makefile,v 1.13 2016-08-18 13:01:32-07 - - $
# Sam Song

GCC        = g++-5 -g -O0 -Wall -Wextra -std=gnu++14
MKDEP      = g++-5 -MM -std=gnu++14
VALGRIND   = valgrind --leak-check=full --show-reachable=yes
FLEX       = flex --outfile=${LEXCPP}
BISON      = bison --defines=${PARSEHDR} --output=${PARSECPP} --xml
XML2HTML   = xsltproc /usr/share/bison/xslt/xml2xhtml.xsl

LDFLAGS	   = `pkg-config opencv --cflags --libs`

MKFILE     = Makefile
DEPFILE    = Makefile.dep
SOURCES    = main.cpp  colormap.cpp
ALLCSRC    = ${SOURCES} ${CGENS}
OBJECTS    = ${ALLCSRC:.cpp=.o}
HEADERS    = colormap.h
CGENS      = ${LEXCPP} ${PARSECPP}
ALLGENS    = ${PARSEHDR} ${CGENS}
EXECBIN    = ColorMap
SRCFILES   = ${SOURCES} ${MKFILE} ${HEADERS}
SMALLFILES = ${DEPFILE} foo.oc foo1.oh foo2.oh
CHECKINS   = ${SRCFILES} ${SMALLFILES}
LISTING    = Listing.ps
LEXOUT     = yylex.output
PARSEOUT   = yyparse.output
REPORTS    = ${LEXOUT} ${PARSEOUT}
MODSRC     = ${foreach MOD, ${MODULES}, ${MOD}.h ${MOD}.cpp}
MISCSRC    = ${filter-out ${MODSRC}, ${HDRSRC} ${CPPSRC}}

all : ${EXECBIN} clean

${EXECBIN} : ${OBJECTS}
	${GCC} -o ${EXECBIN} ${OBJECTS} ${LDFLAGS}


%.o : %.cpp
	${GCC} -c $<

ci :
	cid + ${CHECKINS}
	checksource ${CHECKINS}

clean :
	- rm ${OBJECTS}

spotless : clean
	- rm ${EXECBIN} ${LISTING} ${LISTING:.ps=.pdf} ${DEPFILE} \
	     test.out misc.lis

${DEPFILE} :
	${MKDEP} ${SOURCES} >${DEPFILE}

dep :
	- rm ${DEPFILE}
	${MAKE} --no-print-directory ${DEPFILE}

include Makefile.dep

test : ${EXECBIN}
	${VALGRIND} ${EXECBIN} foo.oc 1>test.out 2>&1

misc.lis : ${DEPFILE} foo.oc foo1.oh foo2.oh
	catnv ${DEPFILE} foo.oc foo1.oh foo2.oh >misc.lis

lis : misc.lis test
	mkpspdf ${LISTING} ${SRCFILES} misc.lis test.out

again :
	${MAKE} spotless dep all test lis
