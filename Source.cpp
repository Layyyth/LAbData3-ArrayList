#include<iostream>
using namespace std;
class StackType {
	int MaxStackSize;
	int StackTop;
	int* list;
public:
	StackType(int stacksize = 100);
	void initializestack();
	bool isEmptyStack();
	bool isFullStack();
	int top();
	void push(const int& newItem);
	void pop();
	void CopyStack(StackType& otherstack);
	StackType& operator=(StackType& otherstack);
	StackType(StackType& otherstack);
	~StackType();
};

StackType::StackType(int stacksize) {
	if (stacksize <= 0) {
		cout << "error" << endl;
		MaxStackSize = 100;
	}
	else MaxStackSize = stacksize;
	StackTop = 0;
	list = new int[MaxStackSize];
}

void StackType::initializestack() {
	StackTop = 0;
}

bool StackType::isEmptyStack() {
	return (StackTop == 0);
}

bool StackType::isFullStack() {
	return (StackTop == MaxStackSize);
}

int StackType::top() {
	return list[StackTop - 1];
}

void StackType::push(const int& newItem) {
	if (!isFullStack()) {
		list[StackTop] = newItem;
		StackTop++;
	}
	else cout << "error" << endl;
}

void StackType::pop() {
	if (!isEmptyStack()) {
		StackTop--;
	}
	else cout << "error" << endl;
}

void StackType::CopyStack(StackType& otherstack) {
	delete[]list;
	MaxStackSize = otherstack.MaxStackSize;
	StackTop = otherstack.StackTop;
	list = new int[MaxStackSize];
	for (int i = 0; i < StackTop; i++)
		list[i] = otherstack.list[i];
}

StackType& StackType::operator=(StackType& otherstack) {
	if (this != &otherstack) {
		CopyStack(otherstack);
	}
	return *this;
}

StackType::StackType(StackType& otherstack) {
	list = NULL;
	CopyStack(otherstack);
}

StackType::~StackType() {
	delete[]list;
}

int main() {
	
	StackType obj;
	obj.push(9);
	obj.push(10);
	obj.push(4);
	obj.push(8);
	obj.pop();
	obj.push(obj.top() + 2);
	obj.push(3);
	StackType tempobj;
	while (!obj.isEmptyStack()) {
		tempobj.push(obj.top());
		obj.pop();
	}
	while (!tempobj.isEmptyStack()) {
		cout << tempobj.top() << " ";
		tempobj.pop();
	}



	return 0;
}