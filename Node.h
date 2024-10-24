#include <ostream>

template <typename T>
class Node {
public:
    T data;            // El elemento almacenado, de tipo genérico T
    Node<T>* next;     // Puntero al siguiente nodo de la secuencia (o nullptr si es el último nodo de la secuencia)

    // Constructor
    Node(T data, Node<T>* next = nullptr) : data(data), next(next) {}

    // Sobrecarga del operador << para imprimir una instancia de Node<T>
    friend std::ostream& operator<<(std::ostream &out, const Node<T> &node) {
        out << node.data;
        return out;
    }
};
