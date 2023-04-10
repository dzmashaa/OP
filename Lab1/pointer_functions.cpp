#include "functions.h"

void inputText(char name[])
{
    FILE *fptr;
    char c = '\n';
    fptr = fopen(name,"w");
    char *input_line = new char[10000];
    printf("Enter text (send '***' to finish):\n");
    gets(input_line);
    while(strcmp(input_line, "***") != 0){
        fputs(input_line, fptr);
        fputc(c, fptr);
        gets(input_line);
    }
    delete[] input_line;
    fclose(fptr);
}
void printFile(char name[]){
    FILE *f;
    f = fopen(name,"r");
    int n =100000;
    char *line = new char[n];
    while(fgets(line, n, f) != nullptr){
        cout << line;
    }
    cout<< endl;
    delete[] line;
    fclose(f);
}
void findPairLines(char in_name[], char **matrix, int &size){
    FILE *pin;
    pin = fopen(in_name,"r");
    bool point = false;
    int num_line = 1, n =100000;
    char *input_line = new char[n];
    while(fgets(input_line, n, pin) != nullptr){
        int index_last = strlen(input_line) - 2;
        if (num_line % 2 == 1 && input_line[index_last] == '.') {
            point = true;
        }
        num_line +=1;
        if(fgets(input_line, n, pin) != nullptr) {
            index_last = strlen(input_line) - 2;
            if (!(input_line[index_last] == '.' && point) && num_line % 2 == 0) {
                strcpy(matrix[size], input_line);
                size++;
            }
        }
        point = false;
        num_line +=1;
    }
    delete[] input_line;
    fclose(pin);
}
void lexicograficalSort(char **matrix, int size){
    for(int i = 0; i < size - 1; i++){
        for(int j = i + 1; j < size; j++){
            if(strcmp(matrix[i], matrix[j]) > 0){
                char *tmp;
                tmp = matrix[i];
                matrix[i] = matrix[j];
                matrix[j] = tmp;
            }
        }
    }
}
void printMatrix(char **matrix, int size)
{
    cout<< "Pair lines:"<<endl;
    for(int i = 0; i < size; i++){
        cout << matrix[i];
    }
    cout << endl;
}
void recordInFile(char name[], char **matrix, int size ){
    FILE *f;
    f = fopen(name,"w");
    for(int i = 0; i < size; i++){
        fputs(matrix[i], f);
    }
    fclose(f);
}
void createNewFile(char input_name[], char output_name[]){
    int n = 10000, num_line = 0;
    char** lines = new char*[n];
    for (int i = 0; i < n; i++) {
        lines[i] = new char[n];
    }
    findPairLines(input_name, lines, num_line );
    printMatrix(lines, num_line);
    lexicograficalSort(lines, num_line);
    recordInFile(output_name, lines, num_line);
    //printFile(output_name);
    for(int i = 0; i < n;i++) {
        delete[] lines[i];
    }
    delete[] lines;
}
void addTextPointerMethod(char name[]){
    FILE *fptr;
    char c = '\n';
    fptr = fopen(name,"a");
    char *input_line = new char[10000];
    printf("Enter text (send empty line to finish):\n");
    gets(input_line);
    while(strlen(input_line)){
        fputs(input_line, fptr);
        fputc(c, fptr);
        gets(input_line);
    }
    delete[] input_line;
    fclose(fptr);
}
int mainPointer(){
    char input_file[] = "First file.txt";
    char output_file[] = "Second file.txt";
    inputText(input_file);
    cout << "Input file:"<< endl;
    printFile(input_file);
    createNewFile( input_file, output_file);
    cout << "Output file:"<< endl;
    printFile(output_file);
    return 0;
}