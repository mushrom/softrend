CFLAGS += -O3 -g -msse2 -mavx `sdl2-config --cflags --libs` -I./include
CXXFLAGS = $(CFLAGS)

OBJ = src/main.o

src/main: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

.PHONY: clean
clean:
	rm -f $(OBJ) src/main
