CXX				= clang++
#CXX	 	 	 = g++
CXXFLAGS 	= -std=c++14 -O2 -Wall -Wextra
TARGET		= Program
SRCS			= main.cpp ModelData.cpp ROCCurve.cpp SG.cpp Statistics.cpp ST.cpp SP1to2.cpp SP2to1.cpp SS.cpp
OBJS		 := $(SRCS:.cpp=.o)

all: $(TARGET)

run: all
	./$(TARGET)

$(TARGET):	$(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)
	rm -f $(OBJS)

clean:
	rm -vf $(TARGET) $(OBJS)
