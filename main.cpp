#include <iostream>
#include <iomanip>
#include <iterator>
#include <algorithm>    // sort
#include <set>
#include <vector>
 
using namespace std;

template <typename Container>
void print(Container &container)
{
    auto itr = container.begin();
    for (; itr != container.end(); itr++)
    {
        cout << *itr<<" ";
    }
    cout << endl;
}

bool myfunction (int i,int j)
{ return (i<j); }

class myclass
{public:
  bool operator() (int i,int j) { return (i<j);}
};

void demoSort1()
{
    vector<int> v1 {70, 50,    80, 90, 60, 30, 10,    40, 50, 40, 60, 70, 20, 50};
    print(v1);
    vector<int> v2(v1), v3(v1), v4(v1), v5(v1), v6(v1), v7(v1);
    sort(v2.begin()+2, v2.begin()+7);
    print(v2);

    sort(v3.begin(), v3.end());
    print(v3);

    sort(v4.begin(), v4.end(), less<int>()); // less<int> by default
    print(v4);

    sort(v5.begin(), v5.end(), greater<int>());
    print(v5);

    sort(v6.begin(), v6.end(), [](int a, int b){return a<b;} );
    print(v6);

    sort(v7.begin(), v7.end(), myclass());
    print(v7);
}

bool compare(pair<int, int> a, pair<int, int> b)
{
    if( a.second != b.second )
      return a.second < b.second; // de menor a mayor por el segundo
    return a.first  > b.first;    // luego de > a < por el 1ro
}

void demoSort2()
{
    pair<int, int> pairs[] = {{1, 2}, {2, 1}, {7, 1}, {5, 3}, {4,1}, {3, 1}};
    sort(pairs, pairs+6, compare);
    for(auto p:pairs)
        cout << p.first << ", " << p.second << endl;
    // print(pair)
}

void demoPermutation()
{
    vector<int> v1 {70, 50, 80, 90, 60};
    // sort(v1.begin(), v1.end());
    print(v1);
    int x = 1;
    do
    {
        cout << setw(3) << left << x << ": "; 
        print(v1);
        x++;
    }//while(next_permutation(v1.begin(), v1.end()));
    while(prev_permutation(v1.begin(), v1.end()));
}

int main()
{ 
    demoSort1();
    demoSort2();
    demoPermutation();
    return 0;
}