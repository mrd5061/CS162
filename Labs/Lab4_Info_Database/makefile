

#Variables
CXX = g++
CXFLAGS = -std=c++0x

OBJS = Instructor.o Person.o Student.o Building.o University.o Lab4Main.o 
SCRS = Instructor.cpp Person.cpp Student.cpp Building.cpp University.cpp Lab4Main.cpp 


HEADERS = Instructor.hpp Person.hpp Student.hpp Building.hpp University.hpp 


#Compile the executiable from the object and header files
matrixCalc: ${OBJS} ${HEADERS}
	${CXX} ${CXFLAGS} ${OBJS} -o university

#Create object files
${OBJS}:
	${CXX} ${CXFLAGS} ${SCRS} -c $(@:.o=.cpp)

#Remove all files created during the make process
clean:
	rm *.o university
