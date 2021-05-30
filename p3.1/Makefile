# List all the drivers
all: mstprimdriver

# list the test program all classes (cpp files)
#  cpp files must use #include , to include *.h or *.hpp files

mstprimdriver: mstprimtest.cpp graph.cpp heap.cpp heapNode.cpp adList.cpp adNode.cpp
	g++ -std=c++11 -o mstprimdriver mstprimtest.cpp graph.cpp heap.cpp heapNode.cpp adList.cpp adNode.cpp

# List all the executables under 'all:'
clean:
	rm *.o mstprimdriver