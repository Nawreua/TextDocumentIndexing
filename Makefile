CXX=g++
CXXFLAGS=-std=c++20 -pedantic -Wall -Wextra -Werror -I${UTIDIR} -I${ALGODIR} -g

SRCDIR=src
UTIDIR=${SRCDIR}/utilities
ALGODIR=${SRCDIR}/algorithm

OBJ=${SRCDIR}/indexer.o ${UTIDIR}/hash.o ${ALGODIR}/core.o
BIN=src/indexer

TESTDIR=tests

TESTS_TEMPLATE=${TESTDIR}/tests_list
TESTS=${TESTS_TEMPLATE} ${TESTDIR}/tests_hash ${TESTDIR}/tests_map

all: ${BIN}

${BIN}: ${OBJ}

tests: ${TESTS}

${TESTDIR}/tests_hash: ${UTIDIR}/hash.o
${TESTDIR}/tests_map: ${UTIDIR}/hash.o

.PHONY:clean tests

clean:
	${RM} ${OBJ} ${BIN} ${TESTS}
