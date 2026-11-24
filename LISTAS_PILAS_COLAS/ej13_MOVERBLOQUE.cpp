
#include <iostream>
#include <stdexcept>

// ---------------------------------------------------------------
// DLL<TData>— lista doblemente enlazada
// ---------------------------------------------------------------
template <typename TData>
class DLL {
private:
    struct Node {
        TData  data;
        Node*  next;
        Node*  prev;
        explicit Node(const TData& d) : data(d), next(nullptr), prev(nullptr) {}
    };
    Node*       m_head;
    Node*       m_tail;
    std::size_t m_size;
    
    //MI IMPLEMENTACION
    void moverBloqueInicialAlFinalAux(int n) {
    if (n < 2) return;

    Node* actual = m_head;
    TData valor1 = actual->data;
    TData valor2 = actual->next->data;

    Node* viejoTail = m_tail;   // lo guardo antes de reasignar

    m_head = actual->next;
    m_head->prev = nullptr;     // <-- el nuevo head no tiene anterior

    viejoTail->next = actual;
    actual->prev = viejoTail;   // <-- actual ahora va después del viejo tail
    m_tail = actual;
    actual->next = nullptr;

    n--;
    if (valor1 == valor2) moverBloqueInicialAlFinalAux(n);
}

public:
    DLL() : m_head(nullptr), m_tail(nullptr), m_size(0) {}

    ~DLL() {
        while (m_head) {
            Node* tmp = m_head;
            m_head    = m_head->next;
            delete tmp;
        }
    }

    void pushBack(const TData& value) {
        Node* n = new Node(value);
        if (!m_tail) { m_head = m_tail = n; }
        else { n->prev = m_tail; m_tail->next = n; m_tail = n; }
        ++m_size;
    }

    void print() const {
        Node* cur = m_head;
        while (cur) {
            std::cout << cur->data;
            if (cur->next) std::cout << " ";
            cur = cur->next;
        }
        std::cout << "\n";
    }

    void printReverse() const {
        Node* cur = m_tail;
        while (cur) {
            std::cout << cur->data;
            if (cur->prev) std::cout << " ";
            cur = cur->prev;
        }
        std::cout << "\n";
    }

    std::size_t size() const { return m_size; }

    // IMPLEMENTACION MIA
    void moverBloqueInicialAlFinal() {
        if(size()>1) moverBloqueInicialAlFinalAux(size());
        return;
    }
};