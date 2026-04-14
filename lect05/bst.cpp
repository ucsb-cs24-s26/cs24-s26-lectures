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
    void insert(Node* r, int key); // assumption that inserting into a non-empty tree;
};


void bst::insert(int key){
    if(!root){
        root = new Node(key);
        return;
    }
    insert(root, key);

}

void bst::insert(Node* r, int key){
    if(key == r->data){
        return;
    }
    if(key < r->data){
        //insert into the left subtree
        if(!r->left){
            // insert this key as the left child
            r->left = new Node(key, r);
        }else{
            insert(r->left, key);
        }
    }else{
        //insert into the right subtree
        if(!r->right){
            r->right = new Node(key, r);
        }else{
            insert(r->right, key);
        }
    }
}

// Helper recursive function
void bst::printInorder(Node *r) const{
    if(!r) return;
    printInorder(r->left);
    cout << r->data << " ";
     printInorder(r->right);
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
    cout << "Print Inorder"<< endl;
    b.printInorder();
    cout << endl;
    return 0;
}