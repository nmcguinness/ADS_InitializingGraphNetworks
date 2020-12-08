#pragma once

#include "StringUtility.h"
#include "Node.h"

class StringToLowerNode : public Node<string> {
public:

	void process(string& data) override {
		//convert to lowercase
		data = StringUtility::to_lower(data);

		//if next node exists then pass forward, else return processed string
		if (this->getNext() != nullptr)
			this->getNext()->process(data);
	}
};