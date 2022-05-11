#include "vertex.hpp"
#include "trio.hpp"

void print(trio t)
{
	cout<<t;
}

ostream& operator<<(ostream& os, const trio& t)
{
	os << t.v[0]<<t.v[1]<<t.v[2] <<t.v[3]<< endl;
	return os;
}

int intersect(trio t1, trio t2)
{
	int count = 0;
	for(int i = 0; i <= 3; i++)
		for(int j = 0; j <= 3; j++)
			if(t1.v[i] == t2.v[j])
				count++;
	return count;
}

list<trio> doubles(list<trio> mylist, bool *flag)
{
	trio temp1,temp2;
	for (std::list<trio>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
		for (std::list<trio>::iterator it1=mylist.begin(); it1!=mylist.end(); ++it1)
		{
			temp1 = *it;
			temp2 = *it1;
			if(intersect(temp1, temp2) == 4 && it != it1)
			{
				mylist.pop_back();
				*flag = false;
			}
		}
	return mylist;
}

int main()
{
	int k, n;
	cin >> n >> k;
	
	vertex zero(n, k);
	zero.fillZero(k);
	vertex end(n, k);
	end.fillEnd(k);
	vertex comp(n, k);
	comp.fillComp();
	vertex alpha = zero;
	vertex betta, gamma, delta;
	list<trio> l;
	int count = 0;
	trio t;
	bool flag = true;

	if (n < k)
	{
		cout<<"n must be greater than k"<<endl;
		return 0;
	}
	while(1)
	{
		betta = zero;
		while(1)
		{
			gamma = zero;
			while(1)
			{
				delta = zero;
				while(1)
				{
					if((alpha + betta + gamma + delta) == comp && 
						alpha != betta && gamma != betta && alpha != gamma && delta != betta
							&& delta != alpha && delta != gamma)
					{
						flag = true;
						t.v[0] = alpha;
						t.v[1] = betta;
						t.v[2] = gamma;
						t.v[3] = delta;
						l.push_back(t);
						cout<<t.v[0]<<t.v[1]<<t.v[2]<<t.v[3]<<endl;
						l = doubles(l, &flag);
						if(flag)
							count++;
					}
					cout<<zero<<endl;
					if (delta == end)
						break ;
					++delta;
				}
				if (gamma == end)
					break ;
				++gamma;
			}
			if (betta == end)
				break ;
			++betta;
		}
		if (alpha == end)
			break ;
		++alpha;
	}
	cout<<endl;
	for_each(l.begin(), l.end(), print);
	cout<<count<<endl;
	return 0;
}