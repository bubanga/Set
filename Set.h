#ifndef SET_SET_H
#define SET_SET_H

#include <cstdlib>
#include <cstdio>
#include <iostream>
using namespace std;

class Set {
private:
    const int min = 1;
    const int max = 3;
    int n;
    int* elem;

public:
    explicit Set(int _n);
    Set(const Set &other);
    ~Set();
    void print(ostream &os);
    Set& operator=(const Set&);
    Set& operator+=(const Set&);
    Set& operator-=(const Set&);
    Set& operator*=(const Set&);

private:
    void generate();
};

Set operator+(const Set& s1, const Set& s2);
Set operator-(const Set& s1, const Set& s2);
Set operator*(const Set& s1, const Set& s2);
ostream &operator<<(ostream &os, Set &set);
bool existInTab(int a, const int tab[], int sizeTab);
#endif //SET_SET_H
