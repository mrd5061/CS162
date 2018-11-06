

#Variables
CXX = g++
CXFLAGS = -std=c++0x

OBJS = Dice.o LoadedDice.o Game.o RollDice.o 
SCRS = Dice.cpp LoadedDice.cpp Game.cpp RollDice.cpp

HEADERS = Dice.hpp LoadedDice.hpp Game.hpp

#Compile the executiable from the object and header files
matrixCalc: ${OBJS} ${HEADERS}
	${CXX} ${CXFLAGS} ${OBJS} -o DiceWar

#Create object files
${OBJS}:
	${CXX} ${CXFLAGS} ${SCRS} -c $(@:.o=.cpp)

#Remove all files created during the make process
clean:
	rm *.o DiceWar
