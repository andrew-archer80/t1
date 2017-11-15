CXX = g++
LD = g++

CXXFLAGS = -Wall -std=c++14

CXXFLAGS_DEBUG = $(CXXFLAGS) -g
OBJDIR_DEBUG = ./Debug/x64
OUT_DEBUG = ./x64/t1_d

CXXFLAGS_RELEASE = $(CXXFLAGS) -O2
OBJDIR_RELEASE = ./Release/x64
OUT_RELEASE = ./x64/t1

OBJ_DEBUG = $(OBJDIR_DEBUG)/main.o
OBJ_RELEASE = $(OBJDIR_RELEASE)/main.o

LIBS = -lgtest -lgmock -lpthread

all: debug release

clean: clean_debug clean_release

before_debug: 
	test -d ./x64 || mkdir -p ./x64
	test -d $(OBJDIR_DEBUG) || mkdir -p $(OBJDIR_DEBUG)

after_debug: 

debug: before_debug out_debug after_debug

out_debug: before_debug $(OBJ_DEBUG)
	$(LD) -o $(OUT_DEBUG) $(OBJ_DEBUG) $(LIBS)

$(OBJDIR_DEBUG)/main.o: main.cpp
	$(CXX) $(CXXFLAGS_DEBUG) -c main.cpp -o $(OBJDIR_DEBUG)/main.o

clean_debug: 
	rm -f $(OBJ_DEBUG) $(OUT_DEBUG)
	rm -rf ./x64
	rm -rf $(OBJDIR_DEBUG)

before_release: 
	test -d ./x64 || mkdir -p ./x64
	test -d $(OBJDIR_RELEASE) || mkdir -p $(OBJDIR_RELEASE)

after_release: 

release: before_release out_release after_release

out_release: before_release $(OBJ_RELEASE)
	$(LD) -o $(OUT_RELEASE) $(OBJ_RELEASE) $(LIBS)

$(OBJDIR_RELEASE)/main.o: main.cpp
	$(CXX) $(CXXFLAGS_RELEASE) -c main.cpp -o $(OBJDIR_RELEASE)/main.o

clean_release: 
	rm -f $(OBJ_RELEASE) $(OUT_RELEASE)
	rm -rf ../x64
	rm -rf $(OBJDIR_RELEASE)

.PHONY: before_debug after_debug clean_debug before_release after_release clean_release

