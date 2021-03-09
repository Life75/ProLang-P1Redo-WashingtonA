CXX = g++
CXXFLAGS = -g -std=c++11 -Wall -ftest-coverage -fprofile-arcs

SRCS = $(wildcard *.hpp)
OBJECTS = lexicon.o parser.o symbolTable.o register.o$(SRCS:%.hpp=%.o) 

main: $(OBJECTS) main.o
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -rf main.dSYM
	$(RM) *.o *.gc* test/*.o test/*.gc* *.dSYM test/test core main

testBuild: $(OBJECTS) test/test.o
	$(CXX) $(CXXFLAGS) -o test/test $^

test: testBuild
	$(RM) *.gcda *.gcov test/*.gcda test/*.gcov
	test/test
valgrind:
		valgrind --leak-check=yes --track-origins=yes test/test

coverage: SHELL:=/bin/bash
coverage: test
	total_score=0; \
	total_lines=0; \
	cpp_files=`ls *.cpp | grep -v main.cpp`; \
	echo "$${cpp_files}"; \
	gcov $${cpp_files}; \
	for file in `gcov $${cpp_files} | sed  -n -e "/File '[A-Za-z.]/{N;N;p;}" | grep -v "File" | grep -v "creating" | sed 's/[^0-9]*//' | sed 's/\.[0-9]*% of /,/'`; \
	do \
		IFS=', ' read -r -a array <<< "$${file}"; \
		total_lines=$$((total_lines+$${array[1]})); \
		total_score=$$((total_score+($${array[0]}*$${array[1]}))); \
		echo "$${array[0]}% of $${array[1]} lines"; \
	done; \
	echo "$${total_lines} total lines"; \
	echo "Overall coverage: $$((total_score/total_lines))%"
