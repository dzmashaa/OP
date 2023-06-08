#include "Tree.h"

template <typename T>
Node<T>* Tree<T> ::makeTree(T *m, int from, int n ) {
    if (n == 0)
        return nullptr;
    auto *p = new Node<T>(m[from]);
    if(k == 0)
    {
        root = p;
        k++;
    }
    int nleft = n / 2;
    int nright = n - nleft - 1;
    p->left = makeTree(m, from + 1, nleft);
    p->right = makeTree(m, from + 1 + nleft, nright);
    return p;
}

template <typename T>
void Tree<T> :: show_rec(Node<T>* node, int space) const
{
    if (node == nullptr)
        return;
    space += 5;
    show_rec(node->right, space);
    cout << endl;
    for (int i = 5; i < space; i++)
        cout << " ";
    cout << node->data << "\n";
    show_rec(node->left, space);
}

template <typename T>
void Tree<T> :: show() const
{
    show_rec(root, 0);
}

template <typename T>
Node<T>* Tree<T> :: search(Node<T>* r, const T& key) const {
    if (r == nullptr || isEqual(r->data, key))
        return r;
    Node<T>* leftResult = search(r->left, key);
    if (leftResult != nullptr)
        return leftResult;
    Node<T>* rightResult = search(r->right, key);
    if (rightResult != nullptr)
        return rightResult;
    return nullptr;
}


template <typename T>
int Tree<T> :: getSize(Node<T>* n) const {
    if (n == nullptr)
        return 0;
    int leftSize = getSize(n->left);
    int rightSize = getSize(n->right);
    return leftSize + rightSize + 1;
}

template <typename T>
void Tree<T> ::print_node(Node<T>* n)
{
    Iterator it(n);
    cout << "Thіs is node with value: " << it.getData() << endl;
    if (n->left == nullptr)
        cout << " without left descendant" << endl;
    else
        cout << " with left descendant: " << it.getNode()->left->data << endl;
    if (n->right == nullptr)
        cout << " without right descendant" << endl;
    else
        cout << " with right descendant: " << it.getNode()->right->data << endl;
}

template <typename T>
T Tree<T> :: Iterator :: getData() const
{
    if(node != nullptr)
        return node->data;
}

template <typename T>
typename Tree<T>::Iterator Tree<T>::begin() {
    return Iterator(root);
}
template<typename T>
typename Tree<T>::Iterator Tree<T>::end()
{
    return Iterator(nullptr);
}


template <typename T>
typename Tree<T>::Iterator Tree<T>::nextElement(const T& key) {
    Node<T>* nextNode = nullptr;
    preorderTraversal(root, key, nextNode);
    return Iterator(nextNode);
}

template <typename T>
void Tree<T>::preorderTraversal(Node<T>* node, const T& key, Node<T>*& nextNode) {
    if (node == nullptr) {
        return;
    }

    if (node->data > key && (nextNode == nullptr || node->data < nextNode->data)) {
        nextNode = node;
    }

    if (node->data == key) {
        preorderTraversal(node->left, key, nextNode);
    }

    preorderTraversal(node->left, key, nextNode);
    preorderTraversal(node->right, key, nextNode);
}


template <>
inline bool isEqual<float>(const float & a, const float & b) {
    const double epsilon = 1e-2;
    return fabs(a - b) <= epsilon;
}

template <typename T>
inline bool isEqual(const T& a, const T& b) {
    return a == b;
}