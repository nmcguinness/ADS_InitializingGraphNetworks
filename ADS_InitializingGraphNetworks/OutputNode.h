#pragma once
#include "Node.h"

/// @brief Final Node used in any graph network to capture the data and make available via getOutput()
/// @tparam T C++ or User-defined type (e.g. int, string, vector<float>, list<Student*>)
template <class T>
class OutputNode : public Node<T> {
private:
	T output;

public:

	void process(T& data) override {
		this->output = data;
	}

	T getOutput() {
		return this->output;
	}
};