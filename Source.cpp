#include<iostream>
using namespace std;
struct Node {
	int info;
	Node* link;
};
class LinkedStack {
	Node* StackTop;
public:
	LinkedStack();
	bool isEmptyStack();
	void initializeStack();
	int top();
	void push(const int& newItem);
	void pop();
	void CopyStack(const LinkedStack& otherstack)

};
LinkedStack::LinkedStack() {
	StackTop = NULL;
}

bool LinkedStack::isEmptyStack() {
	return (StackTop = NULL);
}

void LinkedStack::initializeStack() {
	Node* temp;
	while (StackTop != NULL) {
		temp = StackTop;
		StackTop = StackTop->link;
		delete temp;
	}
}

int LinkedStack::top() {
	assert(StackTop != NULL);
	return StackTop->info;
}

void LinkedStack::push(const int& newItem) {
	Node* newnode = new Node;
	newnode->info = newItem;
	if (!isEmptyStack()) {
		newnode->link = StackTop;
		StackTop = newnode;
	}
	else {
		StackTop = newnode;
		newnode->link = NULL;
	}
}

void LinkedStack::pop() {
	if (isEmptyStack()) {
		cout << "error" << endl;
	}
	else {
		Node* temp = StackTop;
		StackTop = StackTop->link;
		delete temp;
	}
}
void LinkedStack::CopyStack(const LinkedStack& otherstack) {
	Node* current, *last, *newnode;
	if (StackTop != NULL)
		initializeStack();
	if (otherstack.StackTop == NULL)
		StackTop = NULL;
	else {
		current = otherstack.StackTop;
		StackTop = new Node;
		StackTop->info = current->info;
		StackTop->link = NULL;
		last = StackTop;
		current = current->link;
		while (current != NULL) {
			newnode = new Node;
			newnode->info = current->info;
			newnode->link = NULL;
			last = newnode;
			current = current->link;
		}

	}


}
int main() {








	return 0;
}