#pragma once
#include <list>
#include <functional>
#include "Node.h"
#include "Bike.h"

using namespace std;

class BikeRemoveIfNode : public Node<list<Bike>> {
private:
	std::function<bool(Bike&)> filter;

public:

	BikeRemoveIfNode(std::function<bool(Bike&)> filter) {
		this->filter = filter;
	}

	void process(list<Bike>& list) {
		list.erase(std::remove_if(list.begin(), list.end(), filter), list.end());
		this->getNext()->process(list);
	}
};