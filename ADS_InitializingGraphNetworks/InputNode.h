#pragma once

#include "StringUtility.h"
#include "Node.h"

template <class T>
class InputNode : public Node<T> {
private:
	T output;

public:
	InputNode(T& data) {
	}

	void process(T& data) override {
		this->output = data;
	}

	T& getOutput() {
		return this->output;
	}
};