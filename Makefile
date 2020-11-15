CXX=g++
CXXFLAGS=-std=c++17 -pedantic -Wall -Wextra -Werror -I${UTIDIR} -I${ALGODIR}

STATICFLAGS=-static-libgcc -static-libstdc++ -static

SRCDIR=src
UTIDIR=${SRCDIR}/utilities
ALGODIR=${SRCDIR}/algorithm

STRING_OBJ=${UTIDIR}/string.o

OBJ=${UTIDIR}/hash.o ${ALGODIR}/core.o
BIN=${SRCDIR}/indexer

TESTDIR=tests

TESTS_TEMPLATE=${TESTDIR}/tests_list
TESTS=${TESTS_TEMPLATE} ${TESTDIR}/tests_hash ${TESTDIR}/tests_map \
			${TESTDIR}/tests_string

all: ${BIN}

static: ${OBJ}
	${CXX} ${CXXFLAGS} ${STATICFLAGS} ${SRCDIR}/indexer.cc -o indexer ${OBJ}

${BIN}: ${OBJ}

tests: ${TESTS}

${TESTDIR}/tests_hash: ${UTIDIR}/hash.o
${TESTDIR}/tests_map: ${UTIDIR}/hash.o
${TESTDIR}/tests_string: ${STRING_OBJ}

.PHONY:clean tests static

clean:
	${RM} ${OBJ} ${BIN} ${TESTS} ${STRING_OBJ} indexer
