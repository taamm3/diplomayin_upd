#pragma once
#include <iostream>
using namespace std;
#include <string>
#include <algorithm>
#include <iterator>
#include <list>

class vertex
{
    private:
        int flag;
        string collection;
        int n;
        int k;
    public:
        vertex(int n, string str);
        vertex& operator=(const vertex& v1);
        ~vertex();
        vertex();
        vertex(int n);
        vertex(int n, int k);

        vertex operator+(const vertex& v1);
        vertex operator+=(const vertex& v1);
        void operator++();
        bool operator==(const vertex& v1);
        bool operator!=(const vertex& v1);

        void fillZero(int k);
        void fillEnd(int k);
        void fillComp();
        int getK();
        string getCollection() const;
        void setCollection(string s);

        friend ostream& operator<<(ostream& os, const vertex& v);
};
