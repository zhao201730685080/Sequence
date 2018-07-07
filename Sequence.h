#ifndef SEQUENCE_H
#define SEQUENCE_H

#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

class Sequence
{
public:
	Sequence();
		~Sequence();
	Sequence(const string& filename);
	int length();
	int numberOf(char base);
	string longestConsecutive();
	string longestRepeated();

private:
	int count(const char*c1, const char*c2);
	string value;
	int numberA, numberC, numberG, numberT;
};
#endif 




