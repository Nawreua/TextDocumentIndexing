CXX=g++
CXXFLAGS=-std=c++20 -pedantic -Wall -Wextra -Werror -I${UTIDIR} -I${ALGODIR} -g

SRCDIR=src
UTIDIR=${SRCDIR}/utilities
ALGODIR=${SRCDIR}/algorithm

OBJ=${SRCDIR}/indexer.o ${UTIDIR}/hash.o ${ALGODIR}/core.o
BIN=src/indexer

TESTDIR=tests

OBJ_TESTS=

TESTS_TEMPLATE=${TESTDIR}/tests_list
TESTS=${TESTS_TEMPLATE}

all: ${BIN}

${BIN}: ${OBJ}

tests: ${TESTS}

${TESTS}: ${OBJ_TESTS}

${OBJ_TESTS}: ${OBJ}

.PHONY:clean tests

clean:
	${RM} ${OBJ} ${BIN} ${TESTS} ${OBJ_TESTS}
