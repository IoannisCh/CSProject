CXX := g++
TARGET := racoon

PKGS := gtk+-3.0 webkit2gtk-4.1

CPPFLAGS += -I. -Iui -Icore -Iplatform -Istorage
CPPFLAGS += $(shell pkg-config --cflags $(PKGS) 2>/dev/null)

CXXFLAGS += -std=c++17 -Wall -Wextra -Wpedantic -O2
CXXFLAGS += -MMD -MP

LDLIBS += $(shell pkg-config --libs $(PKGS) 2>/dev/null)

SOURCES := \
    main.cpp \
    ui/browser_window.cpp \
    ui/navigation_bar.cpp \
    ui/web_view.cpp \
    ui/bookmark_button.cpp \
    core/BrowserController.cpp \
    core/HistoryManager.cpp \
    platform/WebKitWrapper.cpp \
    storage/FileStorage.cpp

OBJECTS := $(SOURCES:.cpp=.o)
DEPS := $(OBJECTS:.o=.d)

.PHONY: all clean check-deps

all: check-deps $(TARGET)

check-deps:
	@pkg-config --exists $(PKGS) || \
	    (echo "Missing GTK/WebKitGTK development dependencies."; \
	     echo "Check: pkg-config --modversion $(PKGS)"; exit 1)

$(TARGET): $(OBJECTS)
	$(CXX) $(LDFLAGS) -o $@ $(OBJECTS) $(LDLIBS)

%.o: %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS) $(DEPS) $(TARGET)

-include $(DEPS)