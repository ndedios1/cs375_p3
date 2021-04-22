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
	weight;
	profit;
}

Item::Item(int w, int p){
	weight = w;
	profit = p;
}

int Item::getWeight(){
	return weight;
}

int Item::getProfit(){
	return profit;
}

