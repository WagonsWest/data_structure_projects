# List all the drivers
all: dequeaslistdriver

# list the test program all classes (cpp files)
#  cpp files must use #include , to include *.h or *.hpp files

dequeaslistdriver: dequeaslisttest.cpp deque.cpp node.cpp
	g++ -std=c++11 -o  dequeaslistdriver dequeaslisttest.cpp deque.cpp node.cpp

# List all the executables under 'all:'
clean:
	rm *.o dequeaslistdriver