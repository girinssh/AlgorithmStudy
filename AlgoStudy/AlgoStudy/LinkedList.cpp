#include <iostream>
#include "pch.h"

template<typename T> class  List {
	T Data;
	List * next;

	List<T>() {
		Data = NULL;
		next = NULL;
	}
	List<T>(T data) {
		Data = data;
		next = NULL;
	}

};