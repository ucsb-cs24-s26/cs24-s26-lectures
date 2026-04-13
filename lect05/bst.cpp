// bst.cpp
#include <iostream>
#include <random>
#include <set>
using namespace std;


// bst is an Abstract Data Type
class bst{
public:
    // initialization routine: constructor
    bst() : root(nullptr) {}
    // accessors or getter
    bool find(int key) const; // searches for a key
    void printInorder() const;

    // mutators or setter
    void insert(int key);
    void clear();
    void erase(int key);

private:
    struct Node{
        int data;
        Node* parent;
        Node* left;
        Node* right;
        Node(int d, Node* p = nullptr) : data(d), parent(p){
            left = right = nullptr;
        }
    };
    Node* root;
    void printInorder(Node* r) const;
};


void bst::insert(int key){
    //TO DO

}

// Helper recursive function
void bst::printInorder(Node *r) const{
}


bool bst::find(int value) const{
    return false;
}

void bst::printInorder() const{
    printInorder(root);
}

void bst::clear(){
    return;
}

void bst::erase(int value){
    return;
}


int main(){
    bst b;
    b.insert(41);
    b.insert(45);
    b.insert(32);
    b.insert(42);
    b.insert(12);
    cout << endl;
    return 0;
}