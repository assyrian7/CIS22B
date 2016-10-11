//Paul Badalian

#include "List.h"

List::List() {
	/*
	Pre: nothing
	Purpose: construct Skater instance
	Post: return nothing
	*/
	head = NULL;
}

List::~List() {
	/*
	Pre: nothing
	Purpose: destruct Skater instance
	Post: return nothing
	*/
	Node* nodeptr;
	Node* nextNode;

	nodeptr = head;
	while (nodeptr != NULL) {
		nextNode = nodeptr->next;
		delete nodeptr;
		nodeptr = nextNode;
	}

}
void List::insertNode(Skater skater) {
	/*
	Pre: skater: skater instance that will be inserted into the list
	Purpose: insert skater into the list
	Post: return nothing
	*/
	Node* previousNode;
	Node* nodeptr;
	Node* newNode;

	newNode = new Node;
	newNode->skater = skater;

	if (!head) {
		head = newNode;
		newNode->next = NULL;
	}
	else {

		nodeptr = head;
		previousNode = NULL;

		while (nodeptr != NULL && nodeptr->skater > skater) {
			previousNode = nodeptr;
			nodeptr = nodeptr->next;
		}

		if (previousNode == NULL) {
			head = newNode;
			newNode->next = nodeptr;
		}
		else {
			previousNode->next = newNode;
			newNode->next = nodeptr;
		}
	}
}
bool List::deleteNode(string name) {
	/*
	Pre: name: string to identify what node should be deleted
	Purpose: remove a skater from the list
	Post: return an indication whether a skater is deleted
	*/
	Node* previousNode;
	Node* nodeptr;
	bool found = false;

	if (!head) {
		found = false;
	}
	if (head->skater.getName().compare(name) == 0) {
		nodeptr = head->next;
		delete head;
		head = nodeptr;
		found = true;
	}
	else {

		nodeptr = head;
		previousNode = NULL;

		while (nodeptr != NULL && nodeptr->skater.getName().compare(name) != 0) {
			previousNode = nodeptr;
			nodeptr = nodeptr->next;
		}

		if (nodeptr) {
			previousNode->next = nodeptr->next;
			found = true;
		}
	}

	return found;
}
void List::displayList() const{
	/*
	Pre: nothing
	Purpose: display the entire list of skaters
	Post: return nothing
	*/
	Node* nodeptr;

	if (!head) {
		cout << "List empty, nothing to display" << endl;
	}
	else {
		nodeptr = head;

		cout << "Contestants:" << endl;

		while (nodeptr) {
			cout << nodeptr->skater.getName();
			nodeptr = nodeptr->next;
		}

		cout << endl;

		nodeptr = head;

		cout << "Results:" << endl << endl;

		while (nodeptr) {
			cout << nodeptr->skater << endl;
			nodeptr = nodeptr->next;
		}
	}

}