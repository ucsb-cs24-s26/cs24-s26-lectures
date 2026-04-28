// priorityqueue.cpp
// priority_queue from the C++ Standard Library
//
// Operations: // PQ can actually store duplicates unlike std::set (bst!)
//   push(x)   insert element          O(log n)
//   top()     peek at highest priority     O(1) // magically the highest priority key is brought to the front in O(1)
//   pop()     remove highest priprity      O(log n)
//   empty()   check if empty               O(1)
//   size()    number of elements           O(1)

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    // Default: max-heap on int
    // priority_queue<int> is shorthand for:
    // priority_queue<int, vector<int>, less<int>>
    priority_queue<int> pq; // By default, higher value key has higher priority

    pq.push(5);
    pq.push(1);
    pq.push(8);
    pq.push(3);

    cout << "Top: " << pq.top() << endl;   // 8 

    while (!pq.empty()) {
        cout << pq.top() << " "; // 8, 5, 3, 1
        pq.pop(); 
    }
    cout << endl;  

    // Min-heap: smallest element on top
    priority_queue<int, vector<int>, greater<int>> minpq;
    // first template parameter is the type of key (int)
    // second template parameter (next lecture!)
    // third template parameter specifies how to compare elements 
    
    // priority_queue<int, vector<int>, customComparisonClass> mypq;
    // This is how the customComparisonClass is used by the priority queue to figure out 
    // which element among two possiblies (x, y) , who has higher priority?
    /*
    customComparisonClass cmp;
    cmp(x, y) returns True then the PQ infer that x has lower priority than y

    
    */
    greater<int> cmp;
    auto x = 5;
    auto y = 3;
    auto result = cmp(x, y); // True when x > y  means for the PQ x has lower priority than y --> 
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
