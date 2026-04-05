CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -O2 \
    $(shell pkg-config --cflags gtk+-3.0 webkit2gtk-4.1)

LDFLAGS = \
    $(shell pkg-config --libs gtk+-3.0 webkit2gtk-4.1)

SRC = \
    main.cpp \
    browser_window.cpp \
    navigation_bar.cpp \
    web_view.cpp
OBJ = $(SRC:.cpp=.o)

EXE = racoon

all: $(EXE)

$(EXE): $(OBJ)
	$(CXX) $(OBJ) -o $@ $(LDFLAGS)

$(OBJ): %.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXE)