#include <iostream>
#include "List.h"
#include <stdexcept>

using namespace std;

template <typename T> 
class ListArray : public List<T> {

    private:
        // miembros privados
	T* array;
	int max;
	int n;
	static const int MINSIZE = 2;
	
	void resize(int new_size) {
		int capacity;
        if (new_size < 1) {
            throw std::invalid_argument("El nuevo tamaño debe ser mayor que 0");
        }
        T* new_array = new T[new_size];
        int elements_to_copy = (new_size < n) ? new_size : n;

        for (int i = 0; i < elements_to_copy; ++i) {
            new_array[i] = array[i];
        }

        delete[] array;
        array = new_array;
        capacity = new_size;

        if (n > new_size) {
            n = new_size;
        }
    }
    
    public:
        // miembros públicos, incluidos los heredados de List<T>
	ListArray(){
		array = new T[MINSIZE];
		n = MINSIZE;
	}
	~ListArray(){
		delete[] array;
	}
	
	T operator[](int pos) {
        if (pos < 0 || pos >= n-1) {
            throw std::out_of_range("Posición fuera del rango válido");
        }
        return array[pos];
    }

friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list) {
    out << "[";
    for (int i = 0; i < list.n; ++i) {
        out << list.array[i];
        if (i < list.n - 1) {
            out << ", ";
        }
    }
    out << "]";
    return out;
}

void insert(int pos, T e){
	if(pos < 0 || pos > n){
		throw std::out_of_range("Posicion fuera del rango valido")
	}

	n++;
}

void append(T e){
	array[n] = e;
}

void preppend(T e){
	array[0] = e;
}
};
