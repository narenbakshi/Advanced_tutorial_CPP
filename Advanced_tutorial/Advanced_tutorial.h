// Advanced_tutorial.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <iostream>


using namespace std;

template<class T, class K>
class TestTemp {
private:
	T obj;
	K obj2;
public:
	TestTemp(T obj,K obj2) {
		this->obj = obj;
		this->obj2 = obj2;
	}

	void print() {
		cout << obj << ":" << obj2 << endl;
	}
};

template<class M, class S>
void printany(M n,S s) {
	cout << n << s<< endl;
}

//mandatory brackets required
template<class T>
void show() {
	cout << T() << endl;
}




// TODO: Reference additional headers your program requires here.
