// priorityqueue.cpp
// priority_queue from the C++ Standard Library
//
// Operations:
//   push(x)   insert element          O(log n)
//   top()     peek at highest pri     O(1)
//   pop()     remove highest pri      O(log n)
//   empty()   check if empty          O(1)
//   size()    number of elements      O(1)

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    // Default: max-heap on int
    // priority_queue<int> is shorthand for:
    // priority_queue<int, vector<int>, less<int>>
    priority_queue<int> pq;

    pq.push(5);
    pq.push(1);
    pq.push(8);
    pq.push(3);

    cout << "Top: " << pq.top() << endl;  

    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;  

    // Min-heap: smallest element on top
    priority_queue<int, vector<int>, greater<int>> minpq;

    minpq.push(5);
    minpq.push(1);
    minpq.push(8);
    minpq.push(3);

    while (!minpq.empty()) {
        cout << minpq.top() << " ";
        minpq.pop();
    }
    cout << endl;  

    return 0;
}
