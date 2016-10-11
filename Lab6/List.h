//Paul Badalian

#ifndef LIST_H
#define LIST_H

#include "Skater.h"
#include <iostream>

class List {

private:
	struct Node {
		Skater skater;
		Node* next;
	};

	Node* head;
public:
	List();
	~List();
	void insertNode(Skater);
	void displayList() const;
	bool deleteNode(string);

};




#endif