#pragma once
#include <list>
#include <functional>
#include <algorithm>
#include "Node.h"
#include "Bike.h"

using namespace std;

/// @brief Tranforms (modifies) the Bike objects in the list
class BikeTransformByNode : public Node<list<Bike>> {
private:
	std::function<void(Bike&)> transform;

public:

	BikeTransformByNode(std::function<void(Bike&)> transform) {
		this->transform = transform;
	}

	void process(list<Bike>& list) {
		//notice that we use Bike& in the for loop below
		//otherwise we would just transform the copy and not change it INSIDE the list
		for (Bike& bike : list)
			transform(bike);

		this->getNext()->process(list);
	}
};