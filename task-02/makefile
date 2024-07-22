parametrosCompilacao=-Wall -Wextra -Wshadow
nomePrograma=trab2grr20235087

all: $(nomePrograma)

$(nomePrograma): main.o ordenacao.o auxiliar.o pilha.o
	gcc -o $(nomePrograma) main.o ordenacao.o auxiliar.o pilha.o $(parametrosCompilacao)

main.o: main.c
	gcc -c main.c $(parametrosCompilacao)

ordenacao.o: ordenacao.h ordenacao.c
	gcc -c ordenacao.c $(parametrosCompilacao)

auxiliar.o: auxiliar.h auxiliar.c
	gcc -c auxiliar.c $(parametrosCompilacao)

pilha.o: pilha.h pilha.c
	gcc -c pilha.c $(parametrosCompilacao)

clean:
	rm -f *.o *.gch $(nomePrograma)                                       
