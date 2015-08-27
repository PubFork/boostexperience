TARGET		= ../x64/Debug/libalqaz.so
OBJPATH 	= .
SOURCES		= $(wildcard *.cpp)
OBJS    	= $(patsubst %.cpp,%.o,$(SOURCES))
FULLOBJS 	= $(patsubst %.cpp,$(OBJPATH)/%.o,$(SOURCES))
INCPATH		=-I. -I/usr/include/python2.7 -I../header -I/usr/local/include
LIBPATH		=  -lpthread  -L/usr/local/lib -lboost_python -L/usr/lib64 -lpython2.7
LFLAGS      = -w -shared 
CFLAGS      = -w -c -std=c++11 -fPIC
CXX     	= g++

all:$(TARGET)

$(TARGET):$(OBJS)
	$(CXX) $(LFLAGS) $(FULLOBJS) -o $(TARGET) $(LIBPATH)

$(OBJS):$(SOURCES)
	$(CXX) $(CFLAGS) $*.cpp -o $(OBJPATH)/$@ $(INCPATH)

clean:
	rm -f $(OBJPATH)/*.o
	rm -f $(TARGET)
