#include <iostream>
#include <string>
#include <queue>   // Para std::queue
#include <stack>   // Para std::stack
#include <cctype>  // Para std::tolower

/**
 * Verifica si una cadena de texto es un palíndromo utilizando una cola y una pila de caracteres.
 * Ignora espacios y diferencias entre mayúsculas y minúsculas.
 * El parametro texto La cadena de texto a verificar.
 * Retorna true si la cadena es un palíndromo, false en caso contrario.
 */
bool esPalindromo(const std::string& texto) {
    std::queue<char> cola;
    std::stack<char> pila;

    for (char c : texto){
        if (isalpha(c)){
            char clow = tolower(c);
            cola.push(clow);
            pila.push(clow);
        }
    }
    while(!cola.empty()||!cola.empty()){
        if (cola.front() != pila.top()) return false;
        cola.pop();
        pila.pop();
    }
    return true;
}