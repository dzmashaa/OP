#include <iostream>
#include <cmath>
using namespace std;

template <typename T>
struct Node{
    T data;
    Node<T> *left, *right;
    Node(const T& val): data(val), right(nullptr), left(nullptr) {}
};


template <typename T>
class Tree{
    Node<T> *root;
public:
    static int k;
    Tree(): root(nullptr){}
    Node<T>* makeTree(T *m, int, int);
    void show_rec(Node<T>* root, int space) const;
    void show() const;
    bool isEmpty() const {return root == nullptr;}
    Node<T>* search(Node<T>* root, const T& key) const;
    int getSize(Node<T>*) const;
    void print_node(Node<T>*);
    void preorderTraversal(Node<T>* node, const T& key, Node<T>*& nextNode);
    Node<T> * getRoot(){return root;}
    class Iterator
    {
        Node<T> *node;
    public:
        Iterator(): node(nullptr){};
        Iterator(Node <T>* n): node(n) {}
        Node<T>* getNode() const {return  node;}
        T getData() const;
    };
    Iterator begin();
    Iterator end();
    Iterator nextElement(const T& key);
};

template <typename T>
inline bool isEqual(const T& a, const T& b);


template <>
inline bool isEqual<float>(const float & a, const float & b);