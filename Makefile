#OBJS specifies which files to compile as part of the project
OBJS = src/*.c

#CC specifies which compiler we're using
CC = gcc

#INCLUDE_PATHS specifies the additional include paths we'll need

#LIBRARY_PATHS specifies the additional library paths we'll need

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresszzes all warnings
# -Wl,-subsystem,windows gets rid of the console window
COMPILER_FLAGS = -Wall -Wfloat-conversion -ggdb -g 

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = 0

ifeq ($(OS), Windows_NT)
	LINKER_FLAGS = -lmingw32
else
	LINKER_FLAGS = -lm
endif

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = Network

#This is the target that compiles our executable
#
# -g -O -c generates .o files.
# -shared -o
all : $(OBJS)
	$(CC) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
