CXX = g++
CXXFLAGS = -std=c++17 -c -g -O0 -Wall -Wextra -pedantic
LD = g++
LDFLAGS = -std=c++17
objects = character.o console_player.o crop.o environment_tile.o \
			inventory.o item.o navigator.o question.o speech.o villager.o worldobject.o

main : $(objects) main.o test
	g++ -std=c++17 -o main $(objects) main.o

main.o : main.cpp console_player.hpp
	$(CXX) $(CXXFLAGS) main.cpp -c
character.o : character.cpp character.hpp
	$(CXX) $(CXXFLAGS) character.cpp -c
console_player.o : console_player.cpp console_player.hpp character.hpp navigator.hpp inventory.hpp \
					crop.hpp item.hpp villager.hpp environment_tile.hpp conversation.hpp question.hpp
	$(CXX) $(CXXFLAGS) console_player.cpp -c
crop.o : crop.cpp crop.hpp worldobject.hpp
	$(CXX) $(CXXFLAGS) crop.cpp -c
environment_tile.o : environment_tile.cpp environment_tile.hpp
	$(CXX) $(CXXFLAGS) environment_tile.cpp -c
inventory.o : inventory.cpp inventory.hpp item.hpp
	$(CXX) $(CXXFLAGS) inventory.cpp -c
item.o : item.cpp item.hpp worldobject.hpp crop.hpp
	$(CXX) $(CXXFLAGS) item.cpp -c
navigator.o : navigator.cpp navigator.hpp item.hpp environment_tile.hpp worldobject.hpp villager.hpp
	$(CXX) $(CXXFLAGS) navigator.cpp -c
question.o : question.cpp question.hpp conversation.hpp
	$(CXX) $(CXXFLAGS) question.cpp -c
speech.o : speech.cpp speech.hpp conversation.hpp
	$(CXX) $(CXXFLAGS) speech.cpp -c
villager.o : villager.cpp villager.hpp worldobject.hpp item.hpp conversation.hpp
	$(CXX) $(CXXFLAGS) villager.cpp -c
worldobject.o : worldobject.cpp worldobject.hpp
	$(CXX) $(CXXFLAGS) worldobject.cpp -c

test : $(objects) test.o catch_amalgamated.o
	g++ -std=c++17 -o test $(objects) test.o catch_amalgamated.o

test.o : ../test/test.cpp ../include/Catch2/catch_amalgamated.hpp
	$(CXX) $(CXXFLAGS) ../test/test.cpp -c
catch_amalgamated.o : ../include/Catch2/catch_amalgamated.cpp ../include/Catch2/catch_amalgamated.hpp
	$(CXX) $(CXXFLAGS) ../include/Catch2/catch_amalgamated.cpp -c

.PHONY : clean
clean :
		rm $(objects) test.o catch_amalgamated.o test main