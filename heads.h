#ifndef HEADS_H_INCLUDED
#define HEADS_H_INCLUDED

#include<iostream>

class Punkt {
private:
    double x, y, z;
public:
    Punkt(double xx, double yy, double zz);
    Punkt *next;

    Punkt operator+(const Punkt& a);
    Punkt operator+=(const Punkt& a);
    Punkt operator-(const Punkt& a);
    Punkt operator-=(const Punkt& a);
    friend bool operator==(const Punkt& a, const Punkt& b);
    friend bool operator!=(const Punkt& a, const Punkt& b);
    friend std::ostream& operator<<(std::ostream&, const Punkt& a);
};


class List {
public:
    List();
    Punkt *beg_, *end_;
    int len;

    List operator+(const List& l);
    List operator+=(const List& l);
    Punkt* operator[](int n);
    friend std::ostream& operator<<(std::ostream&, List& l);

    void addEl(Punkt& a);
    void delEl(int n);
    void sortList();
    void switchEls(int n, int m);
};


#endif // HEADS_H_INCLUDED
