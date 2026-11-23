#include <iostream>
using namespace std;

void hacerPositivo(int* n){
    if (*n<0) *n = -*n;
}

int main()
{
    int num;
    cout << "Ingrese un numero entero: " << endl << "Resultado: ";
    cin >> num;
    int* p_num = &num;
    hacerPositivo(p_num);
    cout << *p_num;
    return 0;
}
