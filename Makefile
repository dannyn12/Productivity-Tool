TARGET = productivity-tool
SRC_FILES = main.cpp Productivity.cpp Note.cpp Task.cpp Calendar.cpp

CXX = g++
CFLAGS = -Wall -g -std=c++11
OBJECTS = $(SRC_FILES:.cpp=.o)

ifeq ($(shell echo "Windows"), "Windows")
	TARGET := $(TARGET).exe
	DEL = del
else
	DEL = rm
endif

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^

.cpp.o:
	$(CXX) $(CFLAGS) -o $@ -c $<

clean:
	$(DEL) $(TARGET) $(OBJECTS)

# DEPENDENCIES
main.o: main.cpp Productivity.cpp Productivity.h Task.cpp Task.h Note.cpp Note.h Calendar.cpp Calendar.h  
Productivity.o: Productivity.cpp Productivity.h Task.cpp Task.h Note.cpp Note.h Calendar.cpp Calendar.h 
Task.o: Task.cpp Task.h
Note.o: Note.cpp Note.h
Calendar.o: Calendar.cpp Calendar.h
