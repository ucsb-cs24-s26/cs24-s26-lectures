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
    int getHeight() const; // returns the height of the tree
    // mutators or setter
    void insert(int key);
    void clear();
    void erase(int key);
    class iterator;
    iterator begin();
    iterator end();

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
    int getHeight(Node* r) const;
    void printInorder(Node* r) const;
    void insert(int value, Node *r);
    void linearize(Node* r, vector<int>& result) const;
    static Node* successor(Node* r);
    static Node* getmin(Node* r);
};

class bst::iterator{
    public:
    iterator(Node* p = nullptr): curr(p){}
    // Kinds of operations on an iterator , == , !=, *, ++(pre and post)
    bool operator==(const iterator& rhs){
        return curr == rhs.curr;
    }

    bool operator!=(const iterator& rhs){
        return curr != rhs.curr;
    }

    int operator*(){
        return curr->data;
    }

    // Options: A. *this  B. curr.data  C. curr->data D. All of the above
    //preincrement
    iterator& operator++(){
        curr = bst::successor(curr);
        return *this;
    }

    // //postincrement
    // iterator operator++(){
    //     return iterator();
    // }
    

    private:
        Node* curr;
};

bst::iterator bst::begin(){
    return iterator(getmin(root));
}
bst::iterator bst::end(){
    return iterator(nullptr);
}



bst::Node* bst::getmin(Node* r){
    if(!r) return nullptr;
    while(r->left) r = r->left;
    return r;
}



void bst::insert(int key){
    if(!root){
        root = new Node(key, nullptr);
        return;
    }
    insert(key, root);
}

void bst::insert(int key, Node *r) {
    if(key == r->data) return;
    if(key < r->data){
        if(!r->left) r->left = new Node(key, r);
        else         insert(key, r->left);
    }else{
        if(!r->right) r->right = new Node(key, r);
        else          insert(key, r->right);
    }
}

bst::Node* bst::successor(Node* r){
    if(r->right){
        return getmin(r->right);
    }else{
        Node* p = r->parent;
        while(p && r == p->right){
            r = p;
            p = p->parent;
        }
        return p;  // nullptr when r was the max node → matches end()
    }
}

// Helper recursive function
void bst::printInorder(Node *r) const{
    if(!r) return;
    printInorder(r->left);
    cout << r->data << " ";
    printInorder(r->right);
}

// Helper getHeight recursive
int bst::getHeight(Node *r) const{
    if (!r){
        return -1;
    }
    int hleft = getHeight(r->left);
    int hright = getHeight(r->right);
    return max(hleft, hright) + 1;
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

int bst::getHeight() const{
    return getHeight(root); // call helper
}

int main(){
    bst b;
    b.insert(41);
    b.insert(45);
    b.insert(32);
    b.insert(42);
    b.insert(12);
    cout << "print the tree in order: ";
    b.printInorder();
    cout << endl;
    cout << "Iterating through my custom bst" << endl;
    for(auto e : b){
        cout << e << " ";
    }
    cout << endl;
    // Code below doesn't work because Node is private and the rest are private helper functons.
    // Node* p = b.getmin();
    // while(p){
    //     cout << p->data << " ";
    //     p = b.successor(p);
    // }


    return 0;
}