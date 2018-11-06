#Variables
CXX = g++
CXFLAGS = -std=c++0x

OBJS = Lab6_Main.o Queue.o 
SCRS = Lab6_Main.cpp Queue.cpp 

HEADERS = Queue.hpp 


#Compile the executiable from the object and header files
matrixCalc: ${OBJS} ${HEADERS}
	${CXX} ${CXFLAGS} ${OBJS} -o Queue

#Create object files
${OBJS}:
	${CXX} ${CXFLAGS} ${SCRS} -c $(@:.o=.cpp)

#Remove all files created during the make process
clean:
	rm *.o Queue
