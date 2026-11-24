
#include <iostream>
#include <stdexcept>

// ---------------------------------------------------------------
// Queue<TData>
// ---------------------------------------------------------------
template <typename TData>
class Queue {
private:
    struct Node {
        TData   data;
        Node*   next;
        explicit Node(const TData& d) : data(d), next(nullptr) {}
    };
    Node*       m_front;
    Node*       m_back;
    std::size_t m_size;

public:
    Queue() : m_front(nullptr), m_back(nullptr), m_size(0) {}

    ~Queue() { while (!isEmpty()) dequeue(); }

    void enqueue(const TData& value) {
        Node* n = new Node(value);
        if (m_back) m_back->next = n;
        else        m_front      = n;
        m_back = n;
        ++m_size;
    }

    void dequeue() {
        if (isEmpty()) throw std::underflow_error("Queue::dequeue — queue vacia");
        Node* tmp = m_front;
        m_front   = m_front->next;
        if (!m_front) m_back = nullptr;
        delete tmp;
        --m_size;
    }

    const TData& front() const {
        if (isEmpty()) throw std::underflow_error("Queue::front — queue vacia");
        return m_front->data;
    }

    bool        isEmpty() const { return m_front == nullptr; }
    std::size_t size()    const { return m_size; }

    // MI IMPLEMENTACION
    void fusionarCanales() {
        Queue par, impar;
        int tamanio= size(), n=0;

        while(!isEmpty()){
            if(n<tamanio/2) par.enqueue(front());
            else impar.enqueue(front());
            n++;
            dequeue();

        }
        while(!par.isEmpty() && !impar.isEmpty()){
            enqueue(par.front());
            par.dequeue();
            enqueue(impar.front());
            impar.dequeue();
        }
    }
};

// ---------------------------------------------------------------
// Helpers de test — no modificar
// ---------------------------------------------------------------
template <typename TData>
void printQueue(Queue<TData>& q) {
    std::size_t n = q.size();
    for (std::size_t i = 0; i < n; ++i) {
        TData val = q.front();
        std::cout << val;
        if (i + 1 < n) std::cout << " ";
        q.dequeue();
        q.enqueue(val);
    }
    std::cout << "\n";
}
