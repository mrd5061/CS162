 

#Variables
CXX = g++
CXFLAGS = -std=c++0x

OBJS = Barbarian.o BlueMen.o Character.o HarryPotter.o Medusa.o Menu.o Project_Main.o Vampire.o 

SCRS =  Barbarian.cpp BlueMen.cpp Character.cpp HarryPotter.cpp Medusa.cpp Menu.cpp Project_Main.cpp Vampire.cpp 



HEADERS = Barbarinan.hpp BlueMen.hpp Character.hpp HarryPotter.hpp Medusa.hpp Menu.hpp Vampire.hpp 

#Compile the executiable from the object and header files
matrixCalc: ${OBJS} ${HEADERS}
	${CXX} ${CXFLAGS} ${OBJS} -o battle

#Create object files
${OBJS}:
	${CXX} ${CXFLAGS} ${SCRS} -c $(@:.o=.cpp)

#Remove all files created during the make process
clean:
	rm *.o battle
