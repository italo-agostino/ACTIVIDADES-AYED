#include <iostream>
using namespace std;
int NUM=5;
int main()
{
    int array[NUM];
    int* p_array = array;
    int suma=0;
    for (int i=0; i<NUM; i++){
        cout << "Ingrese el elemento " << i << ":" << endl;
        cin >> *p_array;
        p_array++;
    }
    p_array = array;
    for (int i=0;i<NUM;i++){
        suma += *p_array;
        p_array++;
    }
    cout << "Suma: " << suma;
    return 0;
}
