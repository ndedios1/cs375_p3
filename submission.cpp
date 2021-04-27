/* submission.cpp */

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <ctime>
#include <vector>
#include <algorithm>
#include "Item.h"
using namespace std;

clock_t time_req;
vector<Item> result;
int maxB = 0;

void backtrack(vector<Item>&v, int capacity, int n, int max){
	vector<Item> temp;
	bool isSolution;
	int val = 0;
	maxB = max;
	for(vector<Item>::size_type  x = n; x < v.size(); x++){
		if(capacity > 0){
			if(v[x].getWeight() <= capacity){
				temp.push_back(v[x]);
				if(val + v[x].getProfit() >= maxB){
					maxB = val + v[x].getProfit();
					isSolution = true;
				}
			}
			if((x+1) < v.size()){
				backtrack(v, capacity - v[x].getWeight(), x+1, maxB);
			}
			else{
				if(isSolution == true){
					if(!result.empty()){
						result.clear();
						move(temp.begin(), temp.end(), back_inserter(result));
						temp.clear();
						isSolution = false;
					}
				}
				else{
					temp.clear();
				}
			return;
			}
		}
		else{
			if(isSolution == true){
				if(!result.empty()){
					result.clear();
					move(temp.begin(), temp.end(), back_inserter(result));
					temp.clear();
					isSolution = false;
				}
			}
			else{
				temp.clear();
			}
			return;
		}
	}
}

int greedy2(vector<Item> &v, int capacity, int greedy_one){
	int maxProfit= greedy_one;
	Item maxItem;
	bool found = false;
	for(vector<Item>::size_type i = 0; i < v.size(); i++){
		if(v[i].getProfit() > maxProfit && v[i].getWeight() <= capacity){
			maxProfit = v[i].getProfit();
			maxItem = v[i];
			found = true;
		}
	}
	if(found == true){
		result.clear();
		result.push_back(maxItem);
	}
	return maxProfit;

}

int greedy1(vector<Item> &v, int capacity){
	//sorting ratio in vector
	sort(v.begin(), v.end(), [](Item& lhs, Item& rhs){
		return lhs.getRatio() > rhs.getRatio();
	});
	/**
	for(vector<Item>::size_type i =0; i < v.size(); i++){
		v[i].print();
	}**/
	int max = v.size();
	int total_weight =0;
	int total_profit =0;
	for(int j = 0; j < max; j++){
		if(total_weight < capacity && (total_weight+v[j].getWeight()) <= capacity){
			total_weight += v[j].getWeight();
			total_profit += v[j].getProfit();
			result.push_back(v[j]);
		}
	}
	cout << total_weight << endl;
	cout << total_profit << endl;
	return total_profit;
	
}

int main(int argc, char* argv[]){
	if(argc != 4){
		cout << "insufficient args" << endl;
		exit(0);
	}
	fstream input(argv[1]);
	ofstream output;
	output.open(argv[2]);
	int big_index = -1;
	vector<Item> library;
	string text;
	//int num_items = 0;
	//int capacity = 0;
	while(!input.eof()){
		bool correct = false;
		int num_items = 0;
		int capacity = 0;
		if(big_index == -1){
			if(getline(input, text, ' ')){
				num_items = stoi(text);
				cout << "Number of items: " << num_items << endl;
				getline(input, text);
				capacity = stoi(text);
				cout << "Knapsack capacity: " << capacity << endl;
				cout << "here" << endl;
				correct = true;
			}
			big_index++;
			//correct = true;
		}
		int index = num_items;
		int weight = 0;
		int profit = 0;
		int id = 1;
		while(index != 0){
			getline(input, text, ' ');
			weight = stoi(text);
			getline(input, text);
			profit = stoi(text);
			Item item = Item(weight, profit, id);
			id++;
			library.push_back(item);
			index--;
		}		
		string algorithm_type = argv[3];
		if(algorithm_type == "0" && correct == true){
			time_req = clock();
			int maxProfit = greedy1(library,capacity);
			//float time;
			//time = (float)time_req;
			output << num_items << " " << maxProfit << " " << time_req << " ";
			for(vector<Item>::size_type n=0; n <result.size(); n++){
				output << result[n].getId() << " ";
			}
			output << endl;
		}
		else if(algorithm_type == "1" && correct == true){
			time_req = clock();
			int greedy = greedy1(library,capacity);
			int maxProfit2 = greedy2(library,capacity,greedy);
			//float time;
			//time = (float)time_req;
			output << num_items << " " << maxProfit2 << " " << time_req << " ";
			for(vector<Item>::size_type p=0; p<result.size(); p++){
				output << result[p].getId() << " ";
			}
			output << endl;
		}
		else if(algorithm_type == "2" && correct == true){
			time_req = clock();
			int greedy = greedy1(library, capacity);
			int prof = greedy2(library, capacity, greedy);
			backtrack(library,capacity, 0, prof);
			output << num_items << " " << maxB << " " << time_req << " ";
			for(vector<Item>::size_type r = 0; r <result.size(); r++){
				output << result[r].getId() << " ";
			}
			output << endl;
			cout << "finished" << endl;
		}
		library.clear();
		result.clear();
		big_index = -1;
		
	}
	input.close();
	output.close();
	return 0;
}
