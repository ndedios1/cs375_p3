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

void kwf1(vector<Item> &v, int capacity, ofstream &output){
	cout << "sorting" << endl;
	/**for(vector<Item>::size_type i=0; i < v.size(); i++){
		v[i].print();
	}**/
	//sorting ratio in vector
	sort(v.begin(), v.end(), [](Item& lhs, Item& rhs){
		return lhs.getRatio() > rhs.getRatio();
	});
	for(vector<Item>::size_type i =0; i < v.size(); i++){
		v[i].print();
	}
	int max = v.size();
	int total_weight =0;
	int total_profit =0;
	vector<Item> result;
	for(int j = 0; j < max; j++){
		if(total_weight < capacity && (total_weight+v[j].getWeight()) < capacity){
			total_weight += v[j].getWeight();
			total_profit += v[j].getProfit();
			result.push_back(v[j]);
		}
	}
	cout << total_weight << endl;
	cout << total_profit << endl;
	float time;
	time = (float)time_req;
	output << max << " " << total_profit << " " << time << " ";
	for(vector<Item>::size_type n=0; n <result.size(); n++){
		output << result[n].getId() << " ";
	}
	output << endl;

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
			cout << "using greedy algorithm 1" << endl;
			kwf1(library,capacity,output);
	
		}
		else if(algorithm_type == "1"){
			cout << "using greedy algorithm 2" << endl;
		}
		else if(algorithm_type == "2"){
			cout << "using backtracking algorithm" << endl;
		}
		library.clear();
		big_index = -1;
		
	}
	input.close();
	output.close();
	return 0;
}
