//
// Created by Zhongkai Xu on 2020/3/15.
//

#include <iostream>
#include <vector>

#include "Find.cpp"

using namespace std;

int temp()
{
    // constructors used in the same order as described above:
    std::vector<int> first;                                // empty vector of ints
    std::vector<int> second (4,100);                       // four ints with value 100
    std::vector<int> third (second.begin(),second.end());  // iterating through second
    cout << second.size() << endl;
    int a;
    cout << sizeof(a) << a << endl;
    for (int & it : second)
        cout << it;
    // the iterator constructor can also be used to construct from arrays:
    int myints[] = {16,2,77,29};
    std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

    std::cout << "The contents of fifth are:";
    for (int & it : fifth)
        cout << ' ' << it;
    cout << '\n';

    return 0;
    return 0;
}
