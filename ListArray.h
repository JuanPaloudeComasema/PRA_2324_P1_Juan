#include <iostream>
#include "List.h"
#include <stdexcept>

using namespace std;

template <typename T> 
class ListArray : public List<T> {

    private:
        // miembros privados
	T* arr;
	int max;
	int n;
	static const int MINSIZE = 2;
	
	void resize(int new_size) {
		T *new_arr = new T [new_size];
        int elements_to_copy = (new_size < n) ? new_size : n;

        for (int i = 0; i < max; ++i) {
            new_arr[i] = arr[i];
        }
        delete[] arr;
        arr = new_arr;
        max = new_size;
	}
    
    public:
        // miembros públicos, incluidos los heredados de List<T>
	ListArray() : n(0), max(MINSIZE){
		arr = new T[MINSIZE];
	}
	~ListArray(){
		delete[] arr;
	}
	
	T operator[](int pos) {
        if (pos < 0 || pos >= n-1) {
            throw std::out_of_range("Posición fuera del rango válido");
        }
        return arr[pos];
    }

friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list) {
    out << "[";
    for (int i = 0; i < list.n; ++i) {
        out << list.arr[i] << ", ";
    }
    out << "]";
    return out;
}

void insert(int pos, T e){
	if(pos < 0 || pos > n){
		throw std::out_of_range("Posicion fuera del rango valido");
	}
	arr[pos] = e;
	n++;
	if(n > max){
		resize(max+1);
	}
}

void append(T e){
	n++;
	if(n < max){
		resize(max+1);
	}
	arr[n] = e;
}

void preppend(T e){
	n++;
	if(n < max){
                resize(max+1);
        }
	for(int i = n; i >= 0; i--){
		arr[i] = arr [i-1];
	arr[0] = e;
	}
}


T remove(int pos){
	for(int i = pos; i < n; i){
		arr[i] = arr[i+1];
	}
	n--;
}

T get(int pos){
	if(pos < 0 || pos > n){
                throw std::out_of_range("Posicion fuera del rango valido");
        }
	T index =  arr[pos];

	return index;
}

int search(T e){
	for(int i = 0; i <= n;i++){
	       if(arr[i] == e){

		return i;
	       }
	}
	return -1;
}

bool empty() const{
	n == 0;
}

int size(){
	return n;
}
