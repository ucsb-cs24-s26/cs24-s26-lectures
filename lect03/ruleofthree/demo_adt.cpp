#include <iostream>
#include <vector>
#include <list>
#include <forward_list>

using namespace std;

// Helper to print any sequence container
template<typename T>
void print(const string& name, const T& container) {
    cout << name << ": [ ";
    for (const auto& x : container) cout << x << " ";
    cout << "]" << endl;
}

// ============================================
// std::vector — dynamic array
// ============================================

void demo_vector() {
    cout << "========================================" << endl;
    cout << "  std::vector (dynamic array)" << endl;
    cout << "========================================" << endl;
    cout << "Internally: contiguous array on the heap" << endl;
    cout << endl;

    vector<int> v;

    v.push_back(10);   print("push_back(10)", v);
    v.push_back(20);   print("push_back(20)", v);
    v.push_back(30);   print("push_back(30)", v);
    cout << endl;

    v.pop_back();      print("pop_back()   ", v);
    cout << endl;

    // push_front not supported on vector — too slow (shifts everything)
    cout << "push_front: NOT supported on vector" << endl;
    cout << "  (would require shifting all elements — O(n))" << endl;
    cout << endl;
}

// ============================================
// std::list — doubly linked list
// ============================================

void demo_list() {
    cout << "========================================" << endl;
    cout << "  std::list (doubly linked list)" << endl;
    cout << "========================================" << endl;
    cout << "Internally: nodes on the heap, each with prev + next pointer" << endl;
    cout << endl;

    list<int> l;

    l.push_back(10);   print("push_back(10) ", l);
    l.push_back(20);   print("push_back(20) ", l);
    l.push_front(5);   print("push_front(5) ", l);
    cout << endl;

    l.pop_back();      print("pop_back()    ", l);
    l.pop_front();     print("pop_front()   ", l);
    cout << endl;
}

// ============================================
// std::forward_list — singly linked list
// ============================================

void demo_forward_list() {
    cout << "========================================" << endl;
    cout << "  std::forward_list (singly linked list)" << endl;
    cout << "========================================" << endl;
    cout << "Internally: nodes on the heap, each with next pointer only" << endl;
    cout << endl;

    forward_list<int> fl;

    fl.push_front(30);  print("push_front(30)", fl);
    fl.push_front(20);  print("push_front(20)", fl);
    fl.push_front(10);  print("push_front(10)", fl);
    cout << endl;

    fl.pop_front();     print("pop_front()   ", fl);
    cout << endl;

    // No push_back or pop_back — can't reach the tail without traversing
    cout << "push_back / pop_back: NOT supported on forward_list" << endl;
    cout << "  (no tail pointer — would require O(n) traversal)" << endl;
    cout << endl;

    // reverse is a member function — not std::reverse (needs bidirectional iterator)
    fl.reverse();       print("reverse()     ", fl);
    cout << endl;
}

// ============================================
// Side-by-side comparison
// ============================================

void demo_comparison() {
    cout << "========================================" << endl;
    cout << "  ADT Comparison" << endl;
    cout << "========================================" << endl;
    cout << endl;
    cout << "Operation       vector    list    forward_list" << endl;
    cout << "─────────────────────────────────────────────" << endl;
    cout << "push_back(x)    O(1)*     O(1)    NO" << endl;
    cout << "pop_back()      O(1)      O(1)    NO" << endl;
    cout << "push_front(x)   NO        O(1)    O(1)" << endl;
    cout << "pop_front()     NO        O(1)    O(1)" << endl;
    cout << "operator[]      O(1)      NO      NO" << endl;
    cout << "reverse()       O(n)      O(n)    O(n)" << endl;
    cout << endl;
    cout << "* push_back on vector is amortized O(1)" << endl;
    cout << endl;
    cout << "Same interface, different internals — that's the ADT idea." << endl;
    cout << "You choose the right one based on what operations you need." << endl;
    cout << endl;
}

// ============================================
// Main
// ============================================

int main() {
    cout << endl;
    cout << "=======================================" << endl;
    cout << "  CS24 Lecture 2 — ADT Demo" << endl;
    cout << "  std::vector, std::list, std::forward_list" << endl;
    cout << "=======================================" << endl;
    cout << endl;

    demo_vector();

    cout << "Press Enter to continue..."; cin.get(); cout << endl;

    demo_list();

    cout << "Press Enter to continue..."; cin.get(); cout << endl;

    demo_forward_list();

    cout << "Press Enter to continue..."; cin.get(); cout << endl;

    demo_comparison();

    return 0;
}
