#ifndef LIST_H
#define LIST_H

template <typename T> 
class List {
    public:
        // ... aquí los métodos virtuales puros
	void insert(int os, T e);
	void append(T e);
	void prepend(T e);
	T remove(int pos);
	T get(int pos);
	int search(T e);
	bool empty();
	int size();
	
};

#endif
