# Variabile
USM = g++
HBBBUBAA = -Wall -std=c++11

# Ținta principală
all: Game.exe

# Regulă pentru a construi executabilul 'Game.exe'
Game.exe: main.o Game.o GameController.o Player.o Table.o Cell.o
	$(USM) $(HBBBUBAA) -o Game.exe main.o Game.o GameController.o Player.o Table.o Cell.o

# Regulă pentru a compila main.o din main.cpp (asigură-te că ai acest fișier)
main.o: main.cpp Game.hpp GameController.hpp Player.hpp Table.hpp Cell.hpp Mark.hpp
	$(USM) $(HBBBUBAA) -c main.cpp

# Regulă pentru a compila Game.o din Game.cpp
Game.o: Game.cpp Game.hpp Table.hpp Mark.hpp
	$(USM) $(HBBBUBAA) -c Game.cpp

# Regulă pentru a compila GameController.o din GameController.cpp
GameController.o: GameController.cpp GameController.hpp Game.hpp Player.hpp
	$(USM) $(HBBBUBAA) -c GameController.cpp

# Regulă pentru a compila Player.o din Player.cpp
Player.o: Player.cpp Player.hpp Mark.hpp
	$(USM) $(HBBBUBAA) -c Player.cpp

# Regulă pentru a compila Table.o din Table.cpp
Table.o: Table.cpp Table.hpp Cell.hpp Mark.hpp
	$(USM) $(HBBBUBAA) -c Table.cpp

# Regulă pentru a compila Cell.o din Cell.cpp
Cell.o: Cell.cpp Cell.hpp Mark.hpp
	$(USM) $(HBBBUBAA) -c Cell.cpp

# Regulă pentru a curăța fișierele obiect și executabilul
clean:
	rm -f *.o Game.exe

