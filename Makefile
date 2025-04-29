CC = g++
CFLAGS = -Iinclude -Isdl/include/SDL2
LDFLAGS = -Lsdl/lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer
SOURCES = main.cpp $(wildcard src/*.cpp)
TARGET = main.exe

all:
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET) $(LDFLAGS)
clean:
	del $(TARGET)
