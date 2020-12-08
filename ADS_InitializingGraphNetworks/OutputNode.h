#pragma once

#include "StringUtility.h"
#include "Node.h"

template <class T>
class OutputNode : public Node<T> {
private:
	T output;

public:

	void process(T& data) override {
		this->output = data;
	}

	T& getOutput() {
		return this->output;
	}
};