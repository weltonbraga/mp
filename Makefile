flags= -std=c++11 -Iinc
deps=Usuario.cpp
target=projeto
all: $(target)
%.o : %.cpp
	g++ -c -o $@ $^ $(flags)
$(target) : Main.o GerenteBD.o Usuario.o
	g++ -o $@ $^ $(flags)
clean:
	rm -f *.o