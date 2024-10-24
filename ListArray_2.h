#include <iostream>
#include <stdexcept>
#include "List.h"
template <typename T>
class ListArray {
private:
    T* arr; // Puntero al inicio del array que almacenará los elementos de la lista de forma contigua
    int max; // Tamaño actual del array
    int n; // Número de elementos que contiene la lista
    static const int MINSIZE = 2; // Tamaño mínimo del array

    // Método privado para redimensionar el array
    void resize(int new_size) {
        if (new_size < MINSIZE) {
            throw std::invalid_argument("El nuevo tamaño debe ser mayor o igual a MINSIZE");
        }

        T* new_arr = new T[new_size];
        int elements_to_copy = (new_size < n) ? new_size : n;

        for (int i = 0; i < elements_to_copy; ++i) {
            new_arr[i] = arr[i];
        }

        delete[] arr;
        arr = new_arr;
        max = new_size;

        if (n > new_size) {
            n = new_size;
        }
    }

public:
    // Constructor sin argumentos
    ListArray() {
        arr = new T[MINSIZE];
        max = MINSIZE;
        n = 0;
    }

    // Destructor para liberar la memoria dinámica
    ~ListArray() {
        delete[] arr;
    }

    // Sobrecarga del operador []
    T operator const {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición fuera del rango válido");
        }
        return arr[pos];
    }

    // Sobrecarga del operador <<
    friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list) {
        out << "[";
        for (int i = 0; i < list.n; ++i) {
            out << list.arr[i];
            if (i < list.n - 1) {
                out << ", ";
            }
        }
        out << "]";
        return out;
    }

    // Método para obtener el tamaño del array
    int getSize() const {
        return n;
    }

    // Método para agregar un elemento al array
    void add(const T& element) {
        arr[n++] = element;
    }

    // Método para eliminar un elemento del array
    void remove() {
        if (n > 0) {
            --n;
        }
    }

    // Método para insertar un elemento en una posición específica
    void insert(int pos, T e) {
        if (pos < 0 || pos > n) {
            throw std::out_of_range("Posición fuera del rango válido");
        }

        for (int i = n; i > pos; --i) {
            arr[i] = arr[i - 1];
        }

        arr[pos] = e;
        ++n;
    }

    // Método para insertar un elemento al final de la lista
    void append(T e) {
        add(e);
    }

    // Método para insertar un elemento al principio de la lista
    void prepend(T e) {
        insert(0, e);
    }

    // Método para eliminar y devolver el elemento en una posición específica
    T remove(int pos) {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición fuera del rango válido");
        }
        T removed_element = arr[pos];
        for (int i = pos; i < n - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        --n;
        return removed_element;
    }

    // Método para obtener el elemento en una posición específica
    T get(int pos) const {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición fuera del rango válido");
        }
        return arr[pos];
    }

    // Método para buscar un elemento y devolver su posición
    int search(T e) const {
        for (int i = 0; i < n; ++i) {
            if (arr[i] == e) {
                return i;
            }
        }
        return -1; // No encontrado
    }

    // Método para verificar si la lista está vacía
    bool empty() const {
        return n == 0;
    }

    // Método para obtener el número de elementos de la lista
    int size() const {
        return n;
    }
};
