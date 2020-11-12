CXX=g++
CXXFLAGS=-std=c++20 -pedantic -Wall -Wextra -Werror -I${UTIDIR} -I${ALGODIR} -g

SRCDIR=src
UTIDIR=${SRCDIR}/utilities
ALGODIR=${SRCDIR}/algorithm

OBJ=${UTIDIR}/hash.o ${ALGODIR}/core.o ${UTIDIR}/string.o
BIN=${SRCDIR}/indexer

TESTDIR=tests

TESTS_TEMPLATE=${TESTDIR}/tests_list
TESTS=${TESTS_TEMPLATE} ${TESTDIR}/tests_hash ${TESTDIR}/tests_map \
			${TESTDIR}/tests_string

all: ${BIN}

${BIN}: ${OBJ}

tests: ${TESTS}

${TESTDIR}/tests_hash: ${UTIDIR}/hash.o
${TESTDIR}/tests_map: ${UTIDIR}/hash.o
${TESTDIR}/tests_string: ${UTIDIR}/string.o

.PHONY:clean tests

clean:
	${RM} ${OBJ} ${BIN} ${TESTS}
