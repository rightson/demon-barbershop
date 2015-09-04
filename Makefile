CC = g++
OPTS = -c -Wall
HEADERS = $(wildcard *.hpp)
SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
LIBS =
EXECUTABLE = barbershop
DOCS = docs
DOXYGEN_CONF = $(DOCS).doxygen

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(LINK.o) $^ -o $@ $(LIBS)

$(OBJECTS): $(HEADERS)

docs:
	doxygen $(DOXYGEN_CONF)

clean:
	$(RM) -rf $(EXECUTABLE) $(OBJECTS) $(DOCS) tags cscope.*

