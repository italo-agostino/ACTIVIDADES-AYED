#include <iostream>
using namespace std;

int main()
{
    int num;//declaro una variable de tipo entero
    cout << "Ingrese un numero entero:" << endl; //solicito por la consola que se ingrese un valor
    cin >> num;//permito ingresar un valor a la variable num
    int* p_num = &num;//declaro un punteero a int y le asigno como valor la direccion de la variable num
    cout << "Resultado: " << 2**p_num;//imprimo el doble del valor de la direccion guardada en el puntero
    return 0;
}