//base case: condition used to terminate recusion

#include <iostream>
#include <filesystem>
namespace fs = std::filesystem; 
using namespace std;

int factorial(int);

int main() {
	int number;
	cout << "Enter int value and " << " I will display its factorial: ";
	cin >> number;

	cout << "The factorial of " << number << "is";
	cout << factorial(number) << endl;

	return 0;
}

//probably be asked to switch between recursive and recursion
int factorial(int n) {
	//recursive
	int x = 1;
	for (int i = 1; i <= n; i++) {
		x = x * i;
	}
	return x;  
}

long multiply(int, int);

int main() {

}

long multiply(int x, int y) {
	if (x == 1) {
		return y;
	}
	else {
		return y + multiply(x - 1, y); 
	}
}

//chance of fibonacci numbers 
//counting nodes in ll
//