CXXFLAGS = -std=c++11 -Iinclude -Wall

.PHONY: all
all: bin/example1_1 bin/example1_2 bin/example2

obj/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c src/$*.cpp -o $@

bin/example1_1: obj/screen.o obj/example1_1.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) obj/screen.o obj/example1_1.o -o $@

bin/example1_2: obj/example1_2.o obj/screen.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) obj/example1_2.o obj/screen.o -o $@

bin/example2: obj/screen.o obj/cscreen.o obj/example2.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) obj/screen.o obj/cscreen.o obj/example2.o -o $@

## Dependencies from source and header files
##
obj/screen.o: src/screen.cpp include/screen.h
obj/cscreen.o: src/cscreen.cpp include/cscreen.h

SUBMISSION_FILES = \
	include/cscreen.h \
	include/screen.h \
	Makefile \
	README \
	src/cscreen.cpp \
	src/example1_1.cpp \
	src/example1_2.cpp \
	src/example2.cpp \
	src/screen.cpp \
	tests/out1_1.txt \
	tests/out1_2.txt \
	tests/out_2.txt \
	tests/test.sh

.PHONY: submission
submission: submission.tar.gz

submission.tar.gz: $(SUBMISSION_FILES)
	tar cf - $(SUBMISSION_FILES) | gzip > $@

.PHONY: clean
clean:
	rm -f obj/*.o ./bin/* submission.tar.gz
