#pragma once
#include "StringUtility.h"
#include "Node.h"
using namespace std;

class StringTrimNode : public Node<string> {
public:

	void process(string& data) override {
		//convert to lowercase
		data = StringUtility::trim(data);

		//if next node exists then pass forward, else return processed string
		if (this->getNext() != nullptr)
			this->getNext()->process(data);
	}
};