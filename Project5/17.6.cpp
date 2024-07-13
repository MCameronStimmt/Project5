#include <iostream>
#include <fstream> 
#include <string> 
#include <map>
using namespace std;

void addMap(map<string, int>, string);

int main() {
	//create map
	map<string, int> words; 
	//create name of text file "WordCount.txt" 
	string txtName = "WordCount.txt";        //***replace file here***

	addMap(words, txtName);


	return 0; 
}

void addMap(map<string, int> words, string txtName) {
	//open and read file
	fstream file;
	string word;
	file.open(txtName.c_str());
	//iterate through file into map
	while (file >> word) {
		words[word]++; 
	}
	//close file
	file.close(); 
	//print out map using iterator 
	for (map<string, int>::iterator it = words.begin(); it != words.end(); ++it) {
		cout << it->first << " : " << it->second << endl;
	}
}

//base case: condition used to terminate recusion

#include <iostream>
using namespace std;

int factorial(int);

int main() {
	int n, result;
	cout << "Enter non negative #: " << endl;
	cin >> n; 
	result = factorial(n);
	cout << "Factorial of" << n << "=" << result;
	return 0;
}

int factorial(int n) {
	if (n > 1) {
		return n * factorial(n - 1);
	}
	else {
		return 1; 
	}
}