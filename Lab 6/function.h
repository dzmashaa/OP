#include <iostream>
using namespace std;
#include <ctime>
#include "Tree.cpp"

void create_array(int arr[], int size);
void create_array(float arr[], int size);
void create_array(char arr[], int size);
int enterSizeArray();

int menu();
void start_menu();

template <typename T>
void program(Tree<T>& tree );
template <typename T>
void built_tree(Tree<T>& tree);
template <typename T>
void empty_tree(Tree<T>& tree);
template <typename T>
void find_next_element(Tree<T>& tree);
template <typename T>
void find_node(Tree<T> &tree);
template <typename T>
T correctInputNumber(string line);