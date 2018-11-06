#Variables
CXX = g++
CXFLAGS = -std=c++0x

OBJS = Lab7.o dynamicQueue.o palindrome.o 
SCRS = Lab7.cpp dynamicQueue.cpp palindrome.cpp 

HEADERS = dynamicQueue.hpp FunctionDecs.hpp 


#Compile the executiable from the object and header files
matrixCalc: ${OBJS} ${HEADERS}
	${CXX} ${CXFLAGS} ${OBJS} -o Queue

#Create object files
${OBJS}:
	${CXX} ${CXFLAGS} ${SCRS} -c $(@:.o=.cpp)

#Remove all files created during the make process
clean:
	rm *.o Queue
