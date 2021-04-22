/* submission.cpp */

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>

using namespace std;

int main(int argc, char* argv[]){
	if(argc != 4){
		cout << "insufficient args" << endl;
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
