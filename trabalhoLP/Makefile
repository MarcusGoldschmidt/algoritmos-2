all: build

build: index.o tela.o venda.o relatorios.o
	#Build
	gcc -o Main index.o venda.o relatorios.o tela.o

index.o: index.c tela.h venda.h relatorios.h
	gcc -o index.o -c index.c -W -Wall
	
tela.o: tela.c venda.h relatorios.h tela.h
	gcc -o tela.o -c tela.c -W -Wall
	
venda.o: venda.c venda.h
	gcc -o venda.o -c venda.c -W -Wall
	
relatorios.o: relatorios.c venda.h
	gcc -o relatorios.o -c relatorios.c -W -Wall

clean:
	rm -rf *-o
