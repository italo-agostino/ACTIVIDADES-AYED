#include <iostream>
using namespace std;

int mayor(int* p_X, int* p_Y){
    if(*p_X>=*p_Y) return *p_X;
    else return *p_Y;
}

int main()
{
    cout << "Ingrese el primer numero:" << endl << "Ingrese el segundo numero:"<< endl;
    int x,y;
    cin >> x >> y;
    int* p_X = &x;
    int* p_Y = &y;
    cout << "Mayor: "<< mayor (p_X,p_Y);
    return 0;
}
