#CXX = clang++
CXX=g++                                                                                          
CXXFLAGS = -std=c++11 -Wall -Wextra 

main: Source1.o List.o UserNetwork.o Wall.o User.o WallPost.o
	${CXX} $^ -o $@


clean:
	/bin/rm -f ${BINARIES} *.o
