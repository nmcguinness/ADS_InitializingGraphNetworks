// ADS_InitializingGraphNetworks.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>
#include "StringTrimNode.h"
#include "StringToLowerNode.h"
#include "OutputNode.h"

using namespace std;

void demoProcessingString();

int main()
{
	demoProcessingString();
}

void demoProcessingString() {
	//construct nodes
	StringTrimNode* pTrimNode = new StringTrimNode();
	StringToLowerNode* pToLowerNode = new StringToLowerNode();
	OutputNode<string>* pOutputNode = new OutputNode<string>();

	//connect nodes
	pTrimNode->setNext(pToLowerNode)->setNext(pOutputNode);

	////handle the data by passing to the first node and get result
	string data = "    This IS a tESt			";
	pTrimNode->process(data);

	cout << pOutputNode->getOutput() << endl;
}