#pragma once

enum class NodeType {
	Input,
	Filter,
	Sort,
	Transform,
	Copy,
	Output
};

/// @brief Abstract parent class for a 1-to-1 and 1-to-Many node
/// @tparam T C++ or User-defined type (e.g. int, string, vector<float>, list<Student*>)
template <class T>
class Node {
private:
	Node<T>* pNext = nullptr;

public:

	Node() {};
	~Node() {};

	Node<T>* setNext(Node<T>* pNext) {
		this->pNext = pNext;
		return this->pNext;
	}

	Node<T>* getNext() {
		return this->pNext;
	}

	virtual void process(T& data) = 0;
};
