#ifndef BAG_H
#define BAG_H

class bag {
public:
	bag(); //Constructor
	int length;
	void insert(const int);
	void removeRandom(const int);
	int removeRandom(); //Removes a random from list; returns -1 if list is empty
	void displayBag();
	friend ostream& operator<< (ostream&, const className&);
private:
	struct Node {
		int data;
		Node* next;
	};

	Node* head;
	Node* current;
	Node* temp;

};
#endif
