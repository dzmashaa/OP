#include "functions.h"

int main() {
    srand(time(nullptr));
    int m = enterSizeArray();
    auto *iarr = new IntArray[m];
    auto *darr = new DoubleArray[m];
    fill_arrays(iarr, darr, m);
    print_arrays(iarr, darr, m);
    change_arrays(iarr, darr, m);
    cout << "\nAFTER CHANGE" << endl;
    print_arrays(iarr, darr, m);
    find_max_arithmetic_mean(iarr, darr, m);
    return 0;
}
