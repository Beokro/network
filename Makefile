#CXX = clang++
CXX=g++                                                                                          


main: Source1.o DLinkList.o UserNetwork.o Wall.o User.o WallPost.o
	${CXX} $^ -o $@


clean:
	/bin/rm -f ${BINARIES} *.o
