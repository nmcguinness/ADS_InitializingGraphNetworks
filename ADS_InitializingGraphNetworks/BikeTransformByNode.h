#pragma once
#include <list>
#include <functional>
#include <algorithm>
#include "Node.h"
#include "Bike.h"

using namespace std;

class BikeTransformByNode : public Node<list<Bike>> {
private:
	std::function<void(Bike&)> transform;

public:

	BikeTransformByNode(std::function<void(Bike&)> transform) {
		this->transform = transform;
	}

	void process(list<Bike>& list) {
		//notice that we use Bike& in the for loop, otherwise we would just transform the copy and not
		for (Bike& bike : list)
			transform(bike);

		this->getNext()->process(list);
	}
};