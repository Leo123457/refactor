CXX = g++
CXXFLAGS = -g -std=c++11 -O2 -Wall -Wextra -fsanitize=address

SRCS = 65.cc Statements.cc VariableSet.cc Item.cc
OBJS = $(SRCS:.cc=.o)
OUT = 65

all: $(OUT)

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OUT): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f $(OBJS) $(OUT)

