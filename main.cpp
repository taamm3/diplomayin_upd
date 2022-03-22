#include "vertex.hpp"
#include "trio.hpp"

void print(trio t)
{
    cout<<t;
}

ostream& operator<<(ostream& os, const trio& t)
{
	os << t.v[0]<<t.v[1]<<t.v[2] << endl;
	return os;
}

int intersect(trio t1, trio t2)
{
    int count = 0;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
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
            if(intersect(temp1, temp2) >= 2 && it != it1)
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
    
    vertex zero(n);
    zero.fillZero(k);
    vertex end(n);
    end.fillEnd(k);
    vertex alpha = zero;
    vertex betta, gamma;
    list<trio> l;
    int count = 0;
    trio t;
    bool flag = true;

    if (n < k)
    {
        cout<<"n must be greater than k"<<endl;
        return 0;
    }
    if(k % 2 != 1)
    {
        while(1)
        {
            betta = zero;
            while(1)
            {
                gamma = zero;
                while(1)
                {
                    if(alpha + betta + gamma == zero && 
                        alpha != betta && gamma != betta && alpha != gamma)
                    {

                        flag = true;
                        t.v[0] = alpha;
                        t.v[1] = betta;
                        t.v[2] = gamma;
                        l.push_back(t);
                        cout<<t.v[0]<<t.v[1]<<t.v[2]<<endl;
                        l = doubles(l, &flag);
                        if(flag)
                            count++;
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
    }
    cout<<endl;
    for_each(l.begin(), l.end(), print);
    cout<<count<<endl;
    return 0;
}