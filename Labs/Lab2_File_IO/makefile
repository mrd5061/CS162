#a simple makefile that compiles all the needed files for the lab 1 matrix calculator

#Variables
CXX = g++
CXFLAGS = -std=c++0x

OBJS = lab2Main.o countLetters.o 
SCRS = lab2Main.cpp countLetters.cpp

HEADERS = countLetters.hpp

#Compile the executiable from the object and header files
matrixCalc: ${OBJS} ${HEADERS}
	${CXX} ${CXFLAGS} ${OBJS} -o letterCount

#Create object files
${OBJS}:
	${CXX} ${CXFLAGS} ${SCRS} -c $(@:.o=.cpp)

#Remove all files created during the make process
clean:
	rm *.o letterCount
