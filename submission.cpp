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


void sortRatio(vector<Item>* v){
	cout << "sorting" << endl;
	/**
	sort(v.begin(), v.end(), [](const v& lhs, const v& rhs){
			return lhs.value < rhs.value;
	});**/
}

int main(int argc, char* argv[]){
	if(argc != 4){
		cout << "insufficient args" << endl;
	}
	fstream input(argv[1]);
	ofstream output;
	output.open(argv[2]);
	int big_index = -1;
	vector<Item> library;
	string text;
	//int num_items = 0;
	//int capacity = 0;
	clock_t time_req;
	while(!input.eof()){
		int num_items = 0;
		int capacity = 0;
		if(big_index == -1){
			if(getline(input, text, ' ')){
				num_items = stoi(text);
				cout << "Number of items: " << num_items << endl;
				getline(input, text);
				capacity = stoi(text);
				cout << "Knapsack capacity: " << capacity << endl;
				big_index++;
			}
			/**
			//getline(input, text, ' ');
			**/
			for(int i=0; i<num_items; i++){
				int weight =0;
				int profit =0;
				getline(input, text, ' ');
				weight = stoi(text);
				getline(input, text);
				profit = stoi(text);
				Item item = Item(weight, profit, i+1);
				library.push_back(item);
			}
			//getline(input, text);
			

			big_index++;
		}
		//cout << "Before: " << text << endl;
		//cout << "After: " << text << endl;
		//cout << text << endl;
		//getline(input, text, ' ');
		/**
		for(int i=0; i<num_items; i++){
			int weight =0;
			int profit =0;
			getline(input, text, ' ');
			weight = stoi(text);
			getline(input, text);
			profit = stoi(text);
			Item item = Item(weight, profit, i+1);
			library.push_back(item);
		}
	//	getline(input, text);
		**/
				
		string algorithm_type = argv[3];
		if(algorithm_type == "0"){
			time_req = clock();
			cout << "using greedy algorithm 1" << endl;
			//sortRatio(&library);
			//sorting ratio in vector
			sort(library.begin(), library.end(), [](Item& lhs, Item& rhs){
				return lhs.getRatio() > rhs.getRatio();
			});
			for(int k=0; k<num_items; k++){
				library[k].print();
			}
			int max = capacity;
			int total_weight =0;
			int total_profit =0;
			vector<Item> result;
			for(int j = 0; j < num_items; j++){
				if(total_weight < max && (total_weight+library[j].getWeight()) < max){
					total_weight += library[j].getWeight();
					total_profit += library[j].getProfit();
					result.push_back(library[j]);
				}
			}
			cout << total_weight << endl;
			cout << total_profit << endl;
			/**
			for(vector<Item>::size_type n =0; n < result.size(); n++){
				cout << result[n].getId() << " ";
			}
			cout << endl;
			**/
			float time;
			cout << "hi" << endl;
			
			time = (float)time_req;
			output << num_items << " " << total_profit << " " << time << " ";
			for(vector<Item>::size_type n=0; n <result.size(); n++){
				output << result[n].getId() << " ";
			}
			output << endl;
			library.clear();
	
		}
		else if(algorithm_type == "1"){
			cout << "using greedy algorithm 2" << endl;
		}
		else if(algorithm_type == "2"){
			cout << "using backtracking algorithm" << endl;
		}
		else{
			cout << "third value has incorrect values" << endl;
		}
		big_index = -1;
		//getline(input, text);
	}
}
