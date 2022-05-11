#include "vertex.hpp"

vertex::vertex(int n, string str)
{
	this->n = n;
	this->collection = str;
}

vertex::vertex(int n, int k)
{
	this->n = n;
	this->k = k;
}

vertex::~vertex() {}

vertex::vertex() {}

vertex::vertex(int num)
{
    string str;

    this->n = num;
    for (int i = 0; i < num; i++)
        this->collection[i] = '0';
}

vertex vertex::operator+(const vertex& v1)
{
	vertex v;
	v = v1;
	v+=*this;
	return v;
}

bool vertex::operator==(const vertex& v1)
{
	int i = 0;
	while(this->collection[i] != '\0')
	{
		if(this->collection[i] != v1.collection[i])
			return 0;
		i++;
	}
	return 1;
}

bool vertex::operator!=(const vertex& v1)
{
	int i = 0;
	while(this->collection[i] != '\0')
	{
		if(this->collection[i] != v1.collection[i])
			return 1;
		i++;
	}
	return 0;
}

int vertex::getK()
{
	int i = 0;
	int count = 0;
	while(this->collection[i] != '\0')
	{
		if(this->collection[i] == '1')
			count++;
		i++;
	}
	return count;
}

string vertex::getCollection() const
{
	return collection;
}

void vertex::setCollection(string s)
{
	for (int i = 0; i < n; i++)
		collection[i] = s[i];
}


vertex& vertex::operator=(const vertex& v1)
{
	if (this != &v1)
	{
		int i = 0;
		n = v1.n;
		k = v1.k;
		collection = "";
		while(i < n)
		{
			collection += v1.collection[i];
			i++;
		}
	}
	return *this;
}

vertex vertex::operator+=(const vertex& v1)
{
	int i = n - 1;
	n = v1.n;
	while(i != -1)
	{
		if (this->collection[i] == '0' && v1.collection[i] == '0')
			this->collection[i] = '0';
		else if (this->collection[i] == '1' && v1.collection[i] == '1')
			this->collection[i] = '0';
		else
			this->collection[i] = '1';
		i--;
	}
	return *this;
}

void vertex::operator++()  // 0011 0101 1001 0110 1010 1100 \0011
{
	static int index1 = n - 1;
	static int index2 = n - k;
	int i;
	vertex v1(n, k);
	v1.fillZero(k);
	if(v1 == *this)
	{
		index1 = n - 1;
		index2 = n - k;
	}
	// for(i = 0; collection[i] == '1'; i++) ;
	// for(; collection[i] == '0'; i++) ;
	if(index2 == 0)
	{
		collection[index1] = '0';
		index1--;
		if(index1 > 0)
		{
			collection[index1] = '1';
			collection[index2] = '0';
			index2 = index1 - k + 1;
			collection[index2] = '1';
		}
	}
	else if(index2 > 0)
	{
		collection[index2 - 1] = '1';
		collection[index2] = '0';
		index2--;
	}
}

void vertex::fillZero(int k)
{
	string str = "";
    for (int i = 0; i < n - k; i++)
        str += '0';
    for (int i = 0; i < k; i++)
        str += '1';
	collection = str;
}

void vertex::fillEnd(int k)
{
	string str("");
    for (int i = 0; i < k; i++)
        str += '1';
    for (int i = 0; i < n - k; i++)
        str += '0';
	collection = str;
}

void vertex::fillComp()
{
	string str = "";
    for (int i = 0; i < n; i++)
        str += '0';
	collection = str;
}

ostream& operator<<(ostream& os, const vertex& v)
{
	os << '(' << v.getCollection() << ')';
	return os;
}