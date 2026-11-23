#include <iostream>
using namespace std;
int NUM=6;
int main()
{
    int array[NUM], pares=0;
    int* p_array = array;
    for(int i=0; i<NUM; i++){
        cout << "Ingrese el elemento " << i << ":" << endl;
        cin >> *p_array;
        if(*p_array%2==0) pares++;
        p_array++;
    }
    cout << "Cantidad de pares: " << pares;
    return 0;
}
