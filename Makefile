CFLAGS += -O3 -mavx `sdl2-config --cflags --libs` -I./include -std=c++20
#CFLAGS += -O1 -g -mavx `sdl2-config --cflags --libs` -I./include -std=c++20
CXXFLAGS = $(CFLAGS)

OBJ = src/main.o src/jobQueue.o

src/main: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

.PHONY: clean
clean:
	rm -f $(OBJ) src/main
