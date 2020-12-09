#pragma once
#include <list>
#include "Node.h"

/// @brief Implements a 1-to-N node where this node is connected to MULTIPLE downstream nodes
/// @tparam T C++ or User-defined type (e.g. int, string, vector<float>, list<Student*>)
template <class T>
class OneToManyNode : public Node<T> {
private:
	list<Node<T>> listNext;

public:

	void setNext(list<Node<T>>& listNext) {
		this->pListNext = listNext;
	}

	list<Node<T>>& getNext() {
		return this->listNext;
	}
};