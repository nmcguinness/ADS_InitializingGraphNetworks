// ADS_InitializingGraphNetworks.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>
#include <list>
//used by demoStringProcessing
#include "StringTrimNode.h"
#include "StringToLowerNode.h"
//used by demoStructProcessing
#include "Bike.h"
#include "BikeTransformByNode.h"
#include "BikeRemoveIfNode.h"
//used by all demos
#include "OutputNode.h"

using namespace std;
void demoStringProcessing();
void demoStructProcessing();

int main()
{
	cout << endl << "************ demoProcessingString() ************" << endl;
	demoStringProcessing();

	cout << endl << "************ demoStructProcessing() ************" << endl;
	demoStructProcessing();
}

/// @brief Demonstrates how we can construct a graph to filter strings
void demoStringProcessing() {
	//construct nodes
	StringTrimNode* pTrimNode = new StringTrimNode();
	StringToLowerNode* pToLowerNode = new StringToLowerNode();
	OutputNode<string>* pOutputNode = new OutputNode<string>();

	//connect nodes
	pTrimNode->setNext(pToLowerNode)->setNext(pOutputNode);

	string data = "    This IS a tESt of transFORMing a STRinG			";
	cout << "Input:" << data << endl;

	//handle the data by passing to the first node and get result.
	//note that the Node::process() method takes a REFERENCE to the data so it will MODIFY the original.
	pTrimNode->process(data);
	cout << "Output:" << pOutputNode->getOutput() << endl;
}

/// @brief Demonstrates how we can construct a graph to remove_if (price threshold) and transform (price reduction) a list of Bike structs
void demoStructProcessing() {
	//instanciate the data to be passed through the graph (we could do this from file also)
	list<Bike> bikeList;
	bikeList.push_back(Bike("Carrera Vengeance", 16, false, true, 380));
	bikeList.push_back(Bike("Carrera Crosscity Folding Electric", 8, true, false, 1195));
	bikeList.push_back(Bike("Apollo Spiral", 18, true, false, 216));
	bikeList.push_back(Bike("Voodoo Bizango-E Shimano Electric", 10, false, false, 2879));
	bikeList.push_back(Bike("Carrera Zelos Womens Road Bike 2020", 18, true, false, 390));
	bikeList.push_back(Bike("Voodoo Nakisi Mens Adventure Bike", 21, false, true, 660));

	//construct the network nodes
	//filter
	double upperPriceLimit = 500;
	auto removeIfPriceFilter = [upperPriceLimit](Bike bike) { return bike.price < upperPriceLimit; };
	BikeRemoveIfNode* pFilterPriceNode = new BikeRemoveIfNode(removeIfPriceFilter);

	//transform
	double percentageReduction = 0.95;
	auto setPriceTransform = [percentageReduction](Bike& bike) {bike.price = bike.price * percentageReduction; };
	BikeTransformByNode* pTransformPriceNode = new BikeTransformByNode(setPriceTransform);

	//output
	OutputNode<list<Bike>>* pOutputNode = new OutputNode<list<Bike>>();

	//connect nodes
	pFilterPriceNode->setNext(pTransformPriceNode)->setNext(pOutputNode);

	//pass the data through the graph
	pFilterPriceNode->process(bikeList);

	//print the results
	for (Bike bike : pOutputNode->getOutput()) {
		cout << bike << endl;
	}
}