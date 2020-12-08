#pragma once
using namespace std;

template <class T>
class Node {
private:
	Node* pNext = nullptr;

public:
	Node* getNext() const {
		return this->pNext;
	}

	Node* setNext(Node* pNext) {
		this->pNext = pNext;
		return pNext;
	}

	virtual void process(T& data) = 0;
};
