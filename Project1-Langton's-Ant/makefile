#A simple makefile that compiles all the needed files for the lab 1 matrix calculator

#Variables
CXX = g++
CXFLAGS = -std=c++0x

OBJS = langtonsAnt.o menu.o ant.o antBoard.o antSimulation.o

SCRS = langtonsAnt.cpp menu.cpp ant.cpp antBoard.cpp antSimulation.cpp

HEADERS = ant.hpp menu.hpp antBoard.hpp antSimulation.hpp

#Compile the executiable from the object and header files
matrixCalc: ${OBJS} ${HEADERS}
	${CXX} ${CXFLAGS} ${OBJS} -o antSim

#Create object files
${OBJS}:
	${CXX} ${CXFLAGS} ${SCRS} -c $(@:.o=.cpp)

#Remove all files created during the make process
clean:
	rm *.o antSim
