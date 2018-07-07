#include"Sequence.h"
char str[1200000];
char* substr[1200000];

Sequence::Sequence()
{
	value = " "; 
	numberA = numberC = numberG = numberT;
}

Sequence::~Sequence()
{}

int cmple(const void* p, const void* q)
{
	return strcmp(*(char **)p, *(char **)q);
}

Sequence::Sequence(const string& filename)
{
	char ch;
	value = " ";
	numberA = numberC = numberG = numberT;
	freopen(filename.c_str(), "r", stdin);
	while (cin >> ch)
	{
		if (ch == 'A' | ch == 'C' | ch == 'G' | ch == 'T')
		{
			value += ch;
			if (ch =='A') { numberA++;continue; }
			if (ch == 'C') { numberC++;continue; }
			if (ch == 'G') { numberG++;continue; }
			if (ch =='T') { numberT++;continue; }
		}
		freopen("CON", "r", stdin);
	}
}



int Sequence::length()
{
	return value.length();
}

int Sequence::numberOf(char base)
{
	if (base == 'A')
		return numberA;
	if (base == 'C')
		return numberC;
	if (base == 'G')
		return numberG;
	if (base == 'T')
		return numberT;
}


string Sequence::longestConsecutive()
{
	int a = 0,b = 0,c = 0;
    int d = 1, e = 0;
	while (a<int(value.length()))
	{
		if (a > 0)
		{
			if (value[a] == value[a - 1])
			{
				d++;
				if (d > b)
				{
					c = e;
					b = d;
				}
			}
			else { d = 1; e = a; }
		}
		a++;
	}
	return value.substr(c, b);
}


string Sequence::longestRepeated()
{
	memcpy(str, value.c_str(), value.size());
	for (int i = 0; i<int(value.size()); i++)
	{
		substr[i] = &str[i];
	}
	qsort(substr, value.size(), sizeof(char*), cmple);
	int b_l = 0;
	int index = 0;
	for (int j = 0; j<int(value.size()) - 1; j++)
	{
		int tmp = count(substr[j], substr[j++]);
		if (tmp > b_l)
		{
			b_l = tmp;
			index = j;
		}
	}
	char tmp[400000];
	strncpy(tmp, substr[index], b_l);

	tmp[b_l + 1] = '\0';
	string ans = tmp;
	return ans;
}



int Sequence::count(const char* c1, const char* c2)
{
	int length = 0;
	while ((*c1) == (*c2) && *c1&&*c2) 
	{
		length++;
		c1++;
		c2++;
	}
	return length;
}





