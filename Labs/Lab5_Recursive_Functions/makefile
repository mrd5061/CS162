#Variables
CXX = g++
CXFLAGS = -std=c++0x

OBJS = Lab5Main.o functions.o 
SCRS = Lab5Main.cpp functions.cpp 

HEADERS = functions.hpp 


#Compile the executiable from the object and header files
matrixCalc: ${OBJS} ${HEADERS}
	${CXX} ${CXFLAGS} ${OBJS} -o recursive

#Create object files
${OBJS}:
	${CXX} ${CXFLAGS} ${SCRS} -c $(@:.o=.cpp)

#Remove all files created during the make process
clean:
	rm *.o recursive
