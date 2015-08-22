TARGET		= ./bin
OBJPATH 	= .
SOURCES		= $(wildcard *.cpp)
OBJS    	= $(patsubst %.cpp,%.o,$(SOURCES))
FULLOBJS 	= $(patsubst %.cpp,$(OBJPATH)/%.o,$(SOURCES))
INCPATH		=-I. -I/usr/include/python2.7 -I../header
LIBPATH		=  -lpthread 
LFLAGS      = -w 
CFLAGS      = -w -c 
CXX     	= g++

all:$(TARGET)

$(TARGET):$(OBJS)
	$(CXX) $(LFLAGS) $(FULLOBJS) -o $(TARGET) $(LIBPATH)

$(OBJS):$(SOURCES)
	$(CXX) $(CFLAGS) $*.cpp -o $(OBJPATH)/$@ $(INCPATH)

clean:
	rm -f $(OBJPATH)/*.o
	rm -f $(TARGET)
