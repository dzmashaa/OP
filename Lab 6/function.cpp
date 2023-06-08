#include "function.h"

template <typename T>
int Tree<T> :: k = 0;

void start_menu()
{
    string line = "Select a data type:\n Enter 1 for int, 2 for float or 3 - for char\n";
    int choice_type = correctInputNumber<int>(line);
    while(choice_type > 3 || choice_type < 1)
    {
        cout << "Please, try again\n";
        choice_type = correctInputNumber<int>(line);
    }
    if(choice_type == 1) {
        Tree<int> tree;
        program(tree);
    }
    else if(choice_type == 2){
        Tree<float> tree;
        program(tree);
    }
    else{
        Tree<char> tree;
        program(tree);
    }
}
template <typename T>
void program(Tree<T>& tree)
{
    int choice = menu();
    while(choice != 0)
    {
        switch (choice) {
            case 1:
                empty_tree(tree);
                break;
            case 2:
                built_tree(tree);
                break;
            case 3:
                tree.show();
                break;
            case 4:
                cout << "Size: " << tree.getSize(tree.begin().getNode()) << endl;
                break;
            case 5:
                find_node(tree);
                break;
            case 6:
                find_next_element(tree);
                break;
            default:
                break;
        }
        choice = menu();
    }
}
int menu()
{
    cout << "MENU\n1-> Is tree empty?\n" << "2-> Create tree\n" << "3-> Show a tree\n" <<
         "4-> Get size a tree\n" << "5-> Find node\n" << "6-> Get next element\n" <<
         "0-> Exit\n";
    int choice = correctInputNumber<int>("Select option:");
    while(choice > 9 || choice < 0)
    {
        cout << "Please, try again\n";
        choice = correctInputNumber<int>("Select option");
    }
    return choice;
}

template <typename T>
void empty_tree(Tree<T>& tree)
{
    if (tree.isEmpty())
        cout << "Yes, this tree is empty\n";
    else
        cout << "No, this tree has nodes\n";
}
template <typename T>
void built_tree(Tree<T>& tree)
{
    int size = enterSizeArray();
    T* arr  = new T[size];
    create_array(arr, size);
    tree.makeTree(arr, 0, size);
    cout << "Tree created successfully!\n" << endl;
}
template <typename T>
void find_next_element(Tree<T>& tree)
{
    T ch = correctInputNumber<T>("Enter node:");
    typename Tree<T>::Iterator iterator = tree.nextElement(ch);
    if (iterator.getNode() != nullptr) {
        cout << "Next node is " << ch << ": " << iterator.getData() << endl;
    } else {
        cout << "Node " << ch << " not found or next node not exist." << endl;
    }
}

template <typename T>
void find_node(Tree<T> &tree) {
    T ch = correctInputNumber<T>("Enter node:");
    Node<T>* result = tree.search(tree.begin().getNode(), ch);
    if (result != nullptr)
        tree.print_node(result);
    else
        cout << "This node does not exist in the tree" << endl;
}
void create_array(int arr[], int size)
{
    for(int i = 0; i < size; i++)
        arr[i] = rand()%51;
}
void create_array(float arr[], int size)
{
    for(int i = 0; i < size; i++)
        arr[i] = (rand()/(float)RAND_MAX)*50;
}
void create_array(char arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        char ch = rand()%26 + 'a';
        arr[i] = ch;
    }

}
int enterSizeArray() {
    int size;
    bool error;
    do {
        error = false;
        size = correctInputNumber<int>("Enter size of tree:");
        if (size <= 0) {
            error = true;
            cout << "Size can`t be less than 1" << endl;
        }
    } while (error);
    return size;
}
template <typename T>
T correctInputNumber(string line) {
    T n;
    char ch;
    bool check;
    do {
        check = true;
        cout << line;
        cin >> n;
        cin.get(ch);
        if (cin.fail() || (ch != '\n')) {
            check = false;
            cout << "Error: incorrect input\n";
            cin.clear();
            cin.ignore(100, '\n');
        }
    } while (!check);
    return n;
}