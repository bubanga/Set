#include "Set.h"

Set::Set(int _n) {
    this->n = _n;
    this->elem = new int[_n];
    this->generate();
}

Set::Set(const Set &other) {
    this->n = other.n;
    this->elem = new int[this->n];
    for (int i = 0; i < this->n; ++i) {
        this->elem[i] = other.elem[i];
    }
}

Set::~Set() {
    delete[] this->elem;
}

void Set::generate() {
    for (int i = 0; i < this->n; ++i) {
        this->elem[i] = this->min + (rand() % (this->max - this->min + 1));
    }
}

void Set::print(ostream &os) {
    os << "{";
    for (int i = 0; i < this->n; ++i) {
        if (i+1 < this->n)
            os << this->elem[i] << ", ";
        else
            os << this->elem[i];
    }
    os << "}";
}

Set &Set::operator=(const Set &) {
    return *this;
}

Set &Set::operator+=(const Set &other) {
    int _n = 0;
    int _elem[this->n + other.n];

    for (int i = 0; i < this->n; ++i) {
        if (!existInTab(this->elem[i], _elem, _n))
            _elem[_n++] = this->elem[i];
    }

    for (int i = 0; i < other.n; ++i) {
        if (!existInTab(other.elem[i], _elem, _n))
            _elem[_n++] = other.elem[i];
    }

    this->elem = new int[_n];

    for (int i = 0; i < _n; ++i) {
        this->elem[i] = _elem[i];
    }

    this->n = _n;
    return *this;
}

Set &Set::operator-=(const Set &other) {
    int _n = 0;
    int _elem[this->n + other.n];

    for (int i = 0; i < this->n; ++i) {
        if (!existInTab(this->elem[i], _elem, _n) && !existInTab(this->elem[i], other.elem, other.n))
            _elem[_n++] = this->elem[i];
    }

    this->elem = new int[_n];

    for (int i = 0; i < _n; ++i) {
        this->elem[i] = _elem[i];
    }

    this->n = _n;
    return *this;
}

Set &Set::operator*=(const Set &other) {
    int _n = 0;
    int _elem[this->n + other.n];

    for (int i = 0; i < this->n; ++i) {
        if (!existInTab(this->elem[i], _elem, _n) && existInTab(this->elem[i], other.elem, other.n))
            _elem[_n++] = this->elem[i];
    }

    for (int i = 0; i < other.n; ++i) {
        if (!existInTab(other.elem[i], _elem, _n) && existInTab(other.elem[i], this->elem, this->n))
            _elem[_n++] = other.elem[i];
    }

    this->elem = new int[_n];

    for (int i = 0; i < _n; ++i) {
        this->elem[i] = _elem[i];
    }

    this->n = _n;
    return *this;
}


Set operator+(const Set& s1, const Set& s2) {
    Set s = s1;
    s += s2;
    return s;
}

Set operator-(const Set& s1, const Set& s2) {
    Set s = s1;
    s -= s2;
    return s;
}

Set operator*(const Set& s1, const Set& s2) {
    Set s = s1;
    s *= s2;
    return s;
}

ostream &operator<<(ostream &os, Set &set) {
    set.print(os);
    return os;
}

bool existInTab(int a, const int tab[], int sizeTab) {
    for (int i = 0; i < sizeTab; ++i) {
        if (a == tab[i])
            return true;
    }

    return false;
}