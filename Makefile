CXX=g++
CXXFLAGS=-std=c++20 -pedantic -Wall -Wextra -Werror -I${UTIDIR} -I${ALGODIR}

SRCDIR=src
UTIDIR=${SRCDIR}/utilities
ALGODIR=${SRCDIR}/algorithm

OBJ=${SRCDIR}/indexer.o ${UTIDIR}/hash.o ${ALGODIR}/core.o
BIN=src/indexer

TESTDIR=tests
OBJTESTS=${TESTDIR}/tests_list.o
TESTS=${TESTDIR}/tests_list

all: ${BIN}

${BIN}: ${OBJ}

tests: ${TESTS}

${TESTS}: ${OBJTESTS}

${OBJTESTS}: ${OBJ}

.PHONY:clean tests

clean:
	${RM} ${OBJ} ${BIN} ${TESTS} ${OBJTESTS}
