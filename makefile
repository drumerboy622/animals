CXX = g++ 
CXXFLAGS = -std=c++0x 
LDFLAGS = -lboost_data_time

SRCS = zoo.cpp animal.cpp menu.cpp checkInput.cpp penguin.cpp tiger.cpp turtle.cpp 

HEADERS = zoo.hpp animal.hpp menu.hpp checkInput.hpp penguin.hpp tiger.hpp turtle.hpp 

PDFS = Project2Report.pdf 

make = makefile 

default: ${SRCS}${HEADERS}
	${CXX}${CXXFLAGS}${SRCS}-o project2

clean: 
	rm *project2

zip: 
	 zip -D Project2_Solbrack_Matthew.zip ${SRCS}${HEADERS}${PDFS}${make}
