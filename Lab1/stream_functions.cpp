#include "functions.h"

void inputText(ofstream& file){
    string line;
    cout << "Enter text (send '***' to finish):\n";
    getline(cin, line);
    while (line != "***") {
        file << line << endl;
        getline(cin, line);
    }
}
void createInputFile(){
    string first_file_name = "First file.txt";
    ofstream input_file(first_file_name);
    if(!input_file.is_open()){
        cout << "Error: file cannot be opened "<<endl;
        return;
    }
    inputText(input_file);
    input_file.close();
}
void addTextStreamMethod(string name){
    ofstream input_file(name, ios::app);
    if(!input_file){
        cout << "Error: file cannot be opened "<< endl;
    }
    else
        inputText(input_file);
}
void createNewFileWithPairLines(string input_name, string output_name)
{
    fstream input_file(input_name);
    ofstream output_file(output_name);
    string line;
    bool point = false;
    int num_line = 1;
    while (!input_file.eof()){
        getline(input_file, line);
        if (num_line % 2 == 1 && line.back() == '.')
            point = true;
        num_line +=1;
        getline(input_file, line);

        if(!(line.back() == '.' && point) && num_line%2 == 0)
            output_file << line << "\n";

        point = false;
        num_line +=1;
    }
    input_file.close();
    output_file.close();
}
int fileSize(string name)
{
    fstream f;
    f.open(name);
    int num = 0;
    while(!f.eof()){
        string  line;
        getline(f, line);
        if (!line.empty())
            num++;
    }
    f.seekg(0, ios::beg);
    return num;
}
void createArrayLine(int size, string* arr, fstream& f){
    for (int i = 0; i < size; ++i){
        string temp;
        getline(f, temp);
        if(!temp.empty())
            arr[i] = temp;
    }
    f.close();
}
void lexicograficalSort(string *arr, int size){
    for(int i = 0; i < size - 1; ++i){
        for (int j = 0; j < size - 1 -i; ++j){
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
void createSortedNewFile(string name){
    fstream file(name);
    int size = fileSize(name);
    string text[size];
    createArrayLine(size, text, file);
    file.close();
    file.open(name, ofstream::out | ofstream::trunc);
    lexicograficalSort(text, size);
    for(int i = 0; i < size; ++i){
        file << text[i] << endl;
    }

    file.close();
}
void printFile(string name)
{
    fstream file;
    file.open(name);
    string line;
    while(!file.eof())
    {
        getline(file, line);
        cout << line << endl;
    }
    file.close();
}

int mainSteam(){
    const string first_file_name = "First file.txt";
    const string second_file_name = "Second file.txt";
    createInputFile();
    cout << "Input file:"<< endl;
    printFile(first_file_name);
    createNewFileWithPairLines(first_file_name, second_file_name );
    cout << "Pair lines:"<< endl;
    printFile(second_file_name);
    createSortedNewFile( second_file_name);
    cout << "Sorted output file:" << endl;
    printFile(second_file_name);
    return 0;
}