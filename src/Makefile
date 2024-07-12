CXX = g++
CXXFLAGS = -std=c++1y -c -g -O0 -Wall -Wextra -pedantic
LD = g++
LDFLAGS = -std=c++1y

all : play_console
#TODO add new dependencies to each if cpp files have any new ones!
play_console : main.o character.o console_player.o crop.o environment_tile.o \
	inventory.o item.o navigator.o question.o speech.o villager.o worldobject.o
	$(LD) main.o character.o console_player.o crop.o environment_tile.o \
	inventory.o item.o navigator.o question.o speech.o villager.o worldobject.o $(LDFLAGS) -o play_console

main.o : main.cpp console_player.hpp
	$(CXX) $(CXXFLAGS) main.cpp

character.o : character.cpp character.hpp
	$(CXX) $(CXXFLAGS) character.cpp

console_player.o : console_player.cpp console_player.hpp character.hpp navigator.hpp inventory.hpp \
					crop.hpp item.hpp villager.hpp environment_tile.hpp conversation.hpp question.hpp
	$(CXX) $(CXXFLAGS) console_player.cpp

crop.o : crop.cpp crop.hpp worldobject.hpp
	$(CXX) $(CXXFLAGS) crop.cpp

environment_tile.o : environment_tile.cpp environment_tile.hpp
	$(CXX) $(CXXFLAGS) environment_tile.cpp

inventory.o : inventory.cpp inventory.hpp item.hpp
	$(CXX) $(CXXFLAGS) inventory.cpp

item.o : item.cpp item.hpp worldobject.hpp crop.hpp
	$(CXX) $(CXXFLAGS) item.cpp

navigator.o : navigator.cpp navigator.hpp item.hpp environment_tile.hpp worldobject.hpp villager.hpp
	$(CXX) $(CXXFLAGS) navigator.cpp

question.o : question.cpp question.hpp conversation.hpp
	$(CXX) $(CXXFLAGS) question.cpp

speech.o : speech.cpp speech.hpp conversation.hpp
	$(CXX) $(CXXFLAGS) speech.cpp

villager.o : villager.cpp villager.hpp worldobject.hpp item.hpp conversation.hpp
	$(CXX) $(CXXFLAGS) villager.cpp

worldobject.o : worldobject.cpp worldobject.hpp
	$(CXX) $(CXXFLAGS) worldobject.cpp

# test : test.o main.o
# 	$(LD) test.o main.o $(LDFLAGS) -o test
test : character.o console_player.o crop.o environment_tile.o \
	inventory.o item.o navigator.o question.o speech.o villager.o worldobject.o test.o catch_amalgamated.o
	$(LD) character.o console_player.o crop.o environment_tile.o \
	inventory.o item.o navigator.o question.o speech.o villager.o worldobject.o test.o catch_amalgamated.o $(LDFLAGS) -o test

test.o : ../test/test.cpp ../include/Catch2/catch_amalgamated.hpp
	$(CXX) $(CXXFLAGS) ../test/test.cpp

catch_amalgamated.o : ../include/Catch2/catch_amalgamated.cpp ../include/Catch2/catch_amalgamated.hpp
	$(CXX) $(CXXFLAGS) ../include/Catch2/catch_amalgamated.cpp

clean :
	rm play_console main.o character.o console_player.o crop.o environment_tile.o \
	inventory.o item.o navigator.o question.o speech.o villager.o worldobject.o test