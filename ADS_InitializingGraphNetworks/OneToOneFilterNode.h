#pragma once
#include <list>
#include <functional>
#include "OneToOneNode.h"
#include "Bike.h"

using namespace std;

class OneToOneFilterNode : public OneToOneNode<list<T>&> {
private:
	std::function<bool(T)> filter;

public:

	OneToOneFilterNode(std::function<bool(T)> filter) {
		this->filter = filter;
	}

	void process(list<T>& list) {
		std::remove_if(list.begin(), list.end(), filter);
		this->getNext()->process(list);
	}
};