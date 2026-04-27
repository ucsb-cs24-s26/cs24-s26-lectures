// queue.cpp
// queue from the C++ Standard Library
// FIFO: First In, First Out
//
// Operations:
//   push(x)   insert at back          O(1)
//   front()   peek at front           O(1)
//   back()    peek at back            O(1)
//   pop()     remove from front       O(1)
//   empty()   check if empty          O(1)
//   size()    number of elements      O(1)

#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    cout << "Front: " << q.front() << endl;  // 1 -- first in
    cout << "Back:  " << q.back()  << endl;  // 5 -- last in

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;  // 1 2 3 4 5 -- same order they were inserted

    return 0;
}
