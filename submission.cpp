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
#include "Item.h"
using namespace std;

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
	while(!input.eof()){
		int num_items = 0;
		int capacity = 0;
		if(big_index == -1){
			if(getline(input, text, ' ')){
				num_items = stoi(text);
				cout << "Number of items: " << num_items << endl;
				getline(input, text, ' ');
				capacity = stoi(text);
				cout << "Knapsack capacity: " << capacity << endl;
			}
			big_index++;
		}
		getline(input, text, ' ');
		cout << text << endl;
	}

				
	string algorithm_type = argv[3];
	if(algorithm_type == "0"){
		cout << "using greedy algorithm 1" << endl;
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



}
