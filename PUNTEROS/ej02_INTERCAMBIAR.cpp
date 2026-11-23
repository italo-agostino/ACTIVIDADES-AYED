#include <iostream>
using namespace std;

void intercambiar(int* p_uno, int* p_dos){
    int aux= *p_dos;
    *p_dos = *p_uno;
    *p_uno = aux;
}

int main()
{
    int* p_algo=nullptr;
    int* p_alguito=nullptr;
    cout << "Ingrese el primer numero:" << endl << "Ingrese el segundo numero:"<< endl;
    int algo, alguito;
    cin >> algo >> alguito;
    p_algo = &algo;
    p_alguito = &alguito;
    intercambiar (p_algo, p_alguito);
    cout <<"Valores intercambiados: " <<*p_algo << " " << *p_alguito;
    return 0;
}
