CXX = g++

CXXFLAGS = -Wall -Wextra -std=c++17 -O2 \
    -I. \
    -Iui \
    -Icore \
    -Iplatform \
    -Istorage \
    $(shell pkg-config --cflags gtk+-3.0 webkit2gtk-4.1)

LDFLAGS = \
    $(shell pkg-config --libs gtk+-3.0 webkit2gtk-4.1)

SRC = \
    main.cpp \
    ui/browser_window.cpp \
    ui/navigation_bar.cpp \
    ui/web_view.cpp \
    ui/bookmark_button.cpp \
    core/BrowserController.cpp \
    core/HistoryManager.cpp \
    platform/WebKitWrapper.cpp \
    storage/FileStorage.cpp

OBJ = $(SRC:.cpp=.o)

EXE = racoon

all: $(EXE)

$(EXE): $(OBJ)
	$(CXX) $(OBJ) -o $(EXE) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXE)