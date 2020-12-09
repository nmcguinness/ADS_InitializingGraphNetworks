#pragma once
#include "Node.h"

/// @brief Implements a 1-to-1 node where this node is connected to ONE downstream node only
/// @tparam T C++ or User-defined type (e.g. int, string, vector<float>, list<Student*>)
template <class T>
class OneToOneNode : public Node<T> {
private:
	Node<T>* pNext = nullptr;

public:

	void setNext(Node<T>* pNext) {
		this->pNext = pNext;
	}

	Node<T>* getNext() {
		return this->pNext;
	}
};
