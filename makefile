#Directories
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build

#Libraries
LIBS = -lncurses

#compiler and flags
CC = g++
CFLAGS = -Wall -g -MMD -I${INC_DIR}

#build objects
OBJS = main.o screen.o coord.o
BUILD_OBJS =  ${addprefix ${BUILD_DIR}/, ${OBJS}}

main: ${BUILD_OBJS}
	${CC} ${CFLAGS} ${BUILD_OBJS} ${LIBS} -o $@

${BUILD_DIR}:
	mkdir -p ${BUILD_DIR}

${BUILD_DIR}/main.o: main.cpp | ${BUILD_DIR}
	${CC} ${CFLAGS} -c main.cpp -o $@

${BUILD_DIR}/screen.o: ${SRC_DIR}/screen.cpp | ${BUILD_DIR}
	${CC} ${CFLAGS} -c ${SRC_DIR}/screen.cpp -o $@

${BUILD_DIR}/coord.o: ${SRC_DIR}/coord.cpp | ${BUILD_DIR}
	${CC} ${CFLAGS} -c ${SRC_DIR}/coord.cpp -o $@

clean:
	rm -rf ${BUILD_DIR} main

-include $(wildcard ${BUILD_DIR}/*.d)
