CXXFLAGS = -std=c++11
CXXFLAGS += -lpthread
CXXFLAGS += -I /home/pi/Wifi+Alive\ info
CXXFLAGS += -Wall -Wextra -pedantic

prog = reach
objets = src/getData.o src/main.o src/MPU9250.o src/searchFilePath.o src/compression.o

$(prog): $(objets)
	$(LINK.cpp) $^  -o $@

# ménage
clean:
	$(RM) *~  $(objets)
 
mrproper: clean
	$(RM) $(prog)

# dépendances
src/getData.o: includes/getData.h
src/getData.o: includes/MPU9250.h
src/main.o: includes/getData.h
src/main.o: includes/MPU9250.h
src/main.o: includes/searchFilePath.h
Src/main.o: includes/compression.h
src/MPU9250.o: includes/MPU9250.h
src/searchFilePath.o: includes/searchFilePath.h
Src/compression.o: includes/compression.h
