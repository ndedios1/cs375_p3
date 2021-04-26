/*Item.cpp*/

#include <sstream>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "Item.h"

using namespace std;

Item::Item(){
	weight=0;
	profit=0;
	ratio = 0;
}

Item::Item(int w, int p){
	weight = w;
	profit = p;
	ratio = p/w;
}

int Item::getWeight(){
	return weight;
}

int Item::getProfit(){
	return profit;
}

int Item::getRatio(){
	return ratio;
}

void Item::print(){
	cout << "Item has weight of: " << weight << " , profit of: " << profit << " and ratio of: " << ratio <<  endl;
}

