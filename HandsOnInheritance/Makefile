CC=g++

Learning: Contact.o Skater.o main.o
	$(CC) -o HandsOnInheritance Contact.o Skater.o main.o

Contact.o: Contact.cpp Contact.h
	$(CC) -c Contact.cpp

Skater.o: Skater.cpp Skater.h Contact.h
	$(CC) -c Skater.cpp

main.o: main.cpp Skater.h Contact.h
	$(CC) -c main.cpp
	
clean:
	rm HandsOnInheritance main.o Skater.o Contact.o