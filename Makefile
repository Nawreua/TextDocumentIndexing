CXX=g++
CXXFLAGS=-std=c++20 -pedantic -Wall -Wextra -Werror -I${UTIDIR}

SRCDIR=src
UTIDIR=${SRCDIR}/utilities
ALGODIR=${SRCDIR}/algorithm

OBJ=${SRCDIR}/indexer.o ${UTIDIR}/list.o ${UTIDIR}/map.o ${UTIDIR}/hash.o \
		${ALGODIR}/core.o
BIN=src/indexer

all: ${BIN}

${BIN}: ${OBJ}

.PHONY:clean

clean:
	${RM} ${OBJ} ${BIN}
