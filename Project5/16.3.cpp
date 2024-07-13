#include <iostream>
#include <string>
using namespace std;

//min template
template <typename T> 
T leMin(T value1, T value2) {
	if (value1 > value2) {
		return value2;
	}
	else {
		return value1;
	}
}

//max template
template <typename T> 
T leMax(T value1, T value2) {
	if (value1 > value2) {
		return value1;
	}
	else {
		return value2;
	}

}

int main() {
	//test int and double
	cout << "Min int: " << leMin<int>(3, 4) << endl;
	cout << "Max double: " << leMax<double>(15.6, 24.3) << endl;

	//test char and string
	cout << "Min char: " << leMin<char>('a', 'A') << endl;
	cout << "Max string: " << leMax<string>("Mmmm eggs", "do you fear god.") << endl;

	return 0;
}