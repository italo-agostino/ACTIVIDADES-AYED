#include <iostream>
using namespace std;

void calcular(int* p_X, int* p_Y){
    int suma= *p_X + *p_Y;
    int prod= *p_X * *p_Y;
    *p_X= suma;
    *p_Y= prod;
}

int main()
{
    int x,y;
    cout << "Ingrese el primer numero:" << endl;
    cin >> x;
    cout << "Ingrese el segundo numero:"<< endl;
    cin >> y;
    int* p_X = &x;
    int* p_Y = &y;
    calcular(p_X, p_Y);
    cout << "Suma: " << *p_X << endl << "Producto: " << *p_Y;
    return 0;
}
