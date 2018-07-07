#include"Sequence.h"
#include<iostream>
using namespace std;

int main()
{
	string al = "dna.txt";
	Sequence test(al);
	cout << test.length() << endl;
	cout << "A: " << test.numberOf('A') << endl;
	cout << "C: " << test.numberOf('C') << endl;
	cout << "G: " << test.numberOf('G') << endl;
	cout << "T: " << test.numberOf('T') << endl;
	cout << test.longestConsecutive() << endl;
	cout << test.longestRepeated() << endl;
	system("pause");
	return 0;
}




