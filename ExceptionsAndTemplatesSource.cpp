/*
John Lander
CIS 1202 §101
1 May 2022
*/

#include<iostream>
#include<typeinfo>
#include<math.h>
#include<stdexcept>

using namespace std;

template <class T>
T half(T in) {
	double temp;

	if (typeid(in).name() == float || typeid(in).name() == double) {
		return (in / 2);
	}
	else if (typeid(in).name() == int) {
		temp = (static_cast<double>(in) / 2);
		return nearbyint(temp);
	}
	else {cout << "shit broken";}//for debug
}


char character(char start, int offset) {
	//Honestly, I have no idea what "calculate character offset" means, so I looked it up and it seems like something dealing with sequential pointers.

	char* startPtr = &start;
	char target;

	//If the target is not a letter, throw an invalidRangeException.
	try {
		target = *(startPtr + offset);
	}
	catch (const out_of_range&) {
		return start;
	}

	return target;
};

int main() {
	int choice;
	
	cout << "templates 1, exceptions 2 >>"; cin >> choice;

	if (choice == 1) {
		
		try {
			//test data here (do with try/catch):
			character('a', 1);//should return 'b'.
			character('a', -1);//should throw an invalidRangeExpection.
			character('Z', -1);//should return 'Y'.
			character('?', 5);//should throw an invalidCharacterExcpeption.
			character('A', 32);//should throw an exception, not return 'a'.
		}
		catch (const invalid_argument&) {

		}
		catch (const /**/&) {

		}
		catch (const invalid_argument&) {

		}
	}

	if (choice == 2) {
		half<int>(3);
		half<float>(3);
		half<double>(3);
	}
};