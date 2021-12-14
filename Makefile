EXENAME = project
OBJS = adjList.o Airport.o DataImport.o main.o PngMap.o HSLAPixel.o Route.o PNG.o lodepng.o #BFS.o

CXX = clang++
CXXFLAGS = $(CS225) -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi -lm

# Custom Clang version enforcement logic:
ccred=$(shell echo -e "\033[0;31m")
ccyellow=$(shell echo -e "\033[0;33m")
ccend=$(shell echo -e "\033[0m")

IS_EWS=$(shell hostname | grep "ews.illinois.edu") 
IS_CORRECT_CLANG=$(shell clang -v 2>&1 | grep "version 6")
ifneq ($(strip $(IS_EWS)),)
ifeq ($(strip $(IS_CORRECT_CLANG)),)
CLANG_VERSION_MSG = $(error $(ccred) On EWS, please run 'module load llvm/6.0.1' first when running CS225 assignments. $(ccend))
endif
else
ifneq ($(strip $(SKIP_EWS_CHECK)),True)
CLANG_VERSION_MSG = $(warning $(ccyellow) Looks like you are not on EWS. Be sure to test on EWS before the deadline. $(ccend))
endif
endif

.PHONY: all test clean output_msg

all : $(EXENAME)

output_msg: ; $(CLANG_VERSION_MSG)

$(EXENAME): output_msg $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

# BFS.o: BFS.cpp BFS.h
# 	$(CXX) $(CXXFLAGS) BFS.cpp

adjList.o: adjList.cpp adjList.h
	$(CXX) $(CXXFLAGS) adjList.cpp

Airport.o: Airport.cpp Airport.h
	$(CXX) $(CXXFLAGS) Airport.cpp

DataImport.o: DataImport.cpp DataImport.h
	$(CXX) $(CXXFLAGS) DataImport.cpp

main.o: main.cpp TestSuite.h
	$(CXX) $(CXXFLAGS) main.cpp

Map.o: PngMap.cpp PngMap.h
	$(CXX) $(CXXFLAGS) PngMap PngMap.cpp

Route.o: Route.cpp Route.h
	$(CXX) $(CXXFLAGS) Route.cpp

PNG.o: cs225/PNG.cpp cs225/PNG.h cs225/HSLAPixel.h cs225/lodepng/lodepng.h
	$(CXX) $(CXXFLAGS) cs225/PNG.cpp

HSLAPixel.o: cs225/HSLAPixel.cpp cs225/HSLAPixel.h
	$(CXX) $(CXXFLAGS) cs225/HSLAPixel.cpp

lodepng.o: cs225/lodepng/lodepng.cpp cs225/lodepng/lodepng.h
	$(CXX) $(CXXFLAGS) cs225/lodepng/lodepng.cpp

clean:
	-rm -f *.o $(EXENAME) test