#pragma once

#include "StringUtility.h"
#include "Node.h"

class StringOutputNode : public Node<string> {
public:

	void handle(string data) override {
		//convert to lowercase
		data = StringUtility::to_lower(data);

		//if next node exists then pass forward, else return processed string
		if (this->getNext() != nullptr)
			this->getNext()->handle(data);
	}
};