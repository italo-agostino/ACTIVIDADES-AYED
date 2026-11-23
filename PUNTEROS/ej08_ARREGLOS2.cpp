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
    cout << "Inverso:";
    for (int i=0; i<NUM; i++){
        p_val--;
        cout << " " << *p_val;
    }
    return 0;
}
