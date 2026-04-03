CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -O2 \
    -Isrc -Isrc/ui -Isrc/web \
    $(shell pkg-config --cflags gtk+-3.0 webkit2gtk-4.1)

LDFLAGS = \
    $(shell pkg-config --libs gtk+-3.0 webkit2gtk-4.1)

SRC = \
    src/main.cpp \
    src/ui/browser_window.cpp \
    src/ui/navigation_bar.cpp \
    src/web/web_view.cpp \
    src/ui/bookmark_button.cpp
OBJ = $(SRC:.cpp=.o)

EXE = racoon

all: $(EXE)

$(EXE): $(OBJ)
	$(CXX) $(OBJ) -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXE)