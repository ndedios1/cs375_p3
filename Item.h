/*Item.h*/

#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Item{
	public:
		Item();
		Item(int w, int p, int i);
		int getWeight();
		int getProfit();
		int getId();
		int getRatio();
		void print();
	private:
		int weight;
		int profit;
		int id;
		int ratio;
};
#endif
