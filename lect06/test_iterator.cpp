// Lecture 6: std::set and iterators
// Iterators: Elegant way of going through the elements of a data structure (ADT)-> containers

#include <set>
#include <vector>
#include <list>
#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{   
    std::set<int> s {200, 50, 100, 500, 150, 10}; // BST (balanced)--> Height = O(log n )
    std::vector<int> v {200, 50, 100, 500, 150, 10}; 
    std::list<int> m {200, 50, 100, 500, 150, 10}; 
    std::set<int> s2(v.begin(), v.end());
    cout << "Iterating through std::set (always in order)" << endl;
    for(auto e : s2){
        cout << e << " ";
    }
    cout << endl;
    cout << "Iterating through std::vector" << endl;
    for(auto e : v){
        cout << e << " ";
    }
    cout << endl;

    cout << "Iterating through std::list" << endl;
    for(auto e : m){
        cout << e << " ";
    }
    cout << endl;

    // it is an iterator: Is an object that behaves like a pointer. So you can derefernce, advance, compare

    cout << "Iterating through std::set (always in order)" << endl;
    for(std::set<int>::iterator it = s.begin(); it!= s.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;
    cout << "Iterating through std::vector" << endl;
    for(std::vector<int>::iterator it = v.begin(); it!= v.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;

    cout << "Iterating through std::list" << endl;
    for(std::list<int>::iterator it = m.begin(); it!= m.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;


    return 0;
}
