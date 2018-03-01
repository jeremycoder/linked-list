#include "bag.h"
#include <stdio.h>
#include <tchar.h>
#include <iostream>
using namespace std;


bag::bag() {
	head = NULL;
	current = NULL;
	temp = NULL;
	length = 0;
}
void bag::insert(const int num) {
	Node* newNode = new Node;
	newNode->next = NULL;
	newNode->data = num;

	if (head != NULL) {
		if (length == 0) current = head;
		current->next = newNode;
		current = current->next;
	}
	else {
		head = newNode;
		current = head;
	}
	length++;
}
int bag::removeRandom(const int num) {
	Node* removePtr = NULL;
	int random, returnValue;
	temp = head;
	current = head;
	if(length != 0) random = rand() % length;
	else return -1;
	cout << "random value: " << random << endl;

	for (int i = 0; i < random; i++) {
		temp = current;
		current = current->next;
	}
	removePtr = current;
	current = current->next;
	temp->next = current;
	if (removePtr == head) {
		head = head->next;
		temp = NULL;
	}
	returnValue = removePtr->data;
	delete removePtr;
	length--;
	return returnValue;
}
void bag::displayBag() {
	temp = head;
	cout << "Bag length: " << length << endl;
	while (temp != NULL) {
		cout << temp->data << endl;
		temp = temp->next;

	}
}

/*ostream & operator<<(ostream & output, const bag & b)
{
	output << "aye: " << b.length;
	return output;
}/*/
