#include <iostream>
#include <stack>
#include <string>

using namespace std;

//MIS IMPLEMENTACIONES:
void rewind(int n, stack<string>& realizadas, stack<string>& deshechas) {
    //RECURSION
    //CASO BASE SI N=0 RETURN
    if(n<=0||realizadas.empty()) return;
    //CASO RECURSIVO, SACO UN ELEMENTO DE REALIZADAS Y LO MANDO A DESECHAS
    //LLAMO A REWIND CON N-1 Y LAS MISMAS DOS STACK
    deshechas.push(realizadas.top());
    realizadas.pop();
    rewind (n-1, realizadas, deshechas);
}

void redo(stack<string>& realizadas, stack<string>& deshechas){
    if(deshechas.empty()) return;
    realizadas.push(deshechas.top());
    deshechas.pop();
}


