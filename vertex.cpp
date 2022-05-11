#include "vertex.hpp"

vertex::vertex(int n, string str)
{
	this->n = n;
	this->collection = str;
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
		n = v1.n;
		collection = v1.collection;
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

void vertex::operator++()
{
	int k = getK();

	do
	{
		int i = n - 1;
		if(collection[i] == '0')
			collection[i] = '1';
		else
		{
			while(i != -1 && collection[i] != '0')
			{
				collection[i] = '0';
				i--;
			}
			if(1 != -1)
				collection[i] = '1';
		}
	}
	while(getK() != k);
}

void vertex::fillComp()
{
	string str = "";
    for (int i = 0; i < n; i++)
        str += '0';
	collection = str;
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

ostream& operator<<(ostream& os, const vertex& v)
{
	os << '(' << v.getCollection() << ')';
	return os;
}