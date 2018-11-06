#A simple makefile that compiles all the needed files for the lab 1 matrix calculator

#Variables
CXX = g++
CXFLAGS = -std=c++0x

OBJS = lab1Main.o readMatrix.o determinant.o

SCRS = lab1Main.cpp readMatrix.cpp determinant.cpp

HEADERS = readMatrix.hpp determinant.hpp

#Compile the executiable from the object and header files
matrixCalc: ${OBJS} ${HEADERS}
	${CXX} ${CXFLAGS} ${OBJS} -o matrixCalc

#Create object files
${OBJS}:
	${CXX} ${CXFLAGS} ${SCRS} -c $(@:.o=.cpp)

#Remove all files created during the make process
clean:
	rm *.o matrixCalc
