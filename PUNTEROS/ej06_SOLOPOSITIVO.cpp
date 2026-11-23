#include <iostream>
using namespace std;

int main()
{
    cout << "Ingrese un numero entero:" << endl;
    int num;
    cin >> num;
    int* p_num=nullptr;
    if(num>0){
        p_num = &num;
    }
    if (p_num) cout << "Valor: " << *p_num;
    else cout << "Puntero nulo";
    return 0;
}
