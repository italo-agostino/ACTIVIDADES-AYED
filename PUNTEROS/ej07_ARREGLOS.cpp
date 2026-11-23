#include <iostream>
using namespace std;
const int NUM=5;
int main()
{
    int val[NUM];
    int* p_val = val;
    for (int i=0; i<NUM; i++){
        cout << "Ingrese el elemento " << i << ":" << endl;
        cin >> *p_val;
        p_val++;
    }
    p_val= val;
    cout << "Arreglo:";
    for (int i=0; i<NUM; i++){
        cout << " " << *p_val;
        p_val++;
    }
    return 0;
}
