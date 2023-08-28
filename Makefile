# Name of the project
PROJ_NAME=ScreenArt
 
# .cpp files
CPP_SOURCE= ScreenArtMain.cpp ScreenFactory.cpp

# Object files
OBJS= $(CPP_SOURCE:.cpp=.o)
 
# Compiler and linker
CC=g++

#Remove Command
RM = -del -fR
 
# Flags for compiler
CC_FLAGS= -c -Wall -ansi -pedantic -std=c++17

#
# Compilation and linking
#
all: $(PROJ_NAME)

$(PROJ_NAME): $(OBJS)
	$(CC) -o $@ $^

%.o: %.cpp
	$(CC) $(CC_FLAGS) $<

clean:
	$(RM) $(PROJ_NAME).exe *.o