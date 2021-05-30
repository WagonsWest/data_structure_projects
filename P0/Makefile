# List all the drivers
all: playlistdriver

# list the test program all classes (cpp files)
#  cpp files must use #include , to include *.h or *.hpp files

playlistdriver: playlistdriver.cpp playlist.cpp song.cpp
	g++ -std=c++11 -o  playlistdriver playlistdriver.cpp playlist.cpp song.cpp

# List all the executables under 'all:'
clean:
	rm *.o playlistdriver