#Please refer to the readme.md file 

# source codes
SRC1 = Sxp9653_main.cpp
SRC2 = Sxp9653_Course.cpp
SRC3 = Sxp9653_Catalog.cpp
SRC4 = Sxp9653_Main_Window.cpp
SRC5 = Sxp9653_view.cpp
SRC6 = Sxp9653_dialog.cpp

# object file names
OBJ1 = $(SRC1:.cpp=.o)
OBJ2 = $(SRC2:.cpp=.o)
OBJ3 = $(SRC3:.cpp=.o)
OBJ4 = $(SRC4:.cpp=.o)
OBJ5 = $(SRC5:.cpp=.o)
OBJ6 = $(SRC6:.cpp=.o)

# executable file name
EXE = $(SRC1:.cpp=.e)

# .h files
HFILES = Sxp9653_Course.h Sxp9653_Catalog.h Sxp9653_Main_Window.cpp Sxp9653_view.cpp  Sxp9653_dialog.h

# flags for using c++17, debugger and GUI
CFLAGS = -std=c++17 -g
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all : $(EXE)
	 ./$(EXE)

$(EXE): $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4) $(OBJ5) $(OBJ6)
	g++ $(CFLAGS) $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4) $(OBJ5)  $(OBJ6) -o $(EXE) $(GTKFLAGS)

$(OBJ1) : $(SRC1) $(HFILES)
	g++ -c $(CFLAGS) $(SRC1) -o $(OBJ1) $(GTKFLAGS)

$(OBJ2) : $(SRC2) $(HFILES)
	g++ -c $(CFLAGS) $(SRC2) -o $(OBJ2) $(GTKFLAGS)

$(OBJ3) : $(SRC3) $(HFILES)
	g++ -c $(CFLAGS) $(SRC3) -o $(OBJ3) $(GTKFLAGS)

$(OBJ4) : $(SRC4) $(HFILES)
	g++ -c $(CFLAGS) $(SRC4) -o $(OBJ4) $(GTKFLAGS)

$(OBJ5) : $(SRC5) $(HFILES)
	g++ -c $(CFLAGS) $(SRC5) -o $(OBJ5) $(GTKFLAGS)

$(OBJ6) : $(SRC6) $(HFILES)
	g++ -c $(CFLAGS) $(SRC6) -o $(OBJ6) $(GTKFLAGS)

# removees .0 files
clean :
	rm -f *.o 
