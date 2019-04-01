#ifndef HEADS_H_INCLUDED
#define HEADS_H_INCLUDED

#include<iostream>
#include<math.h>

class Punkt {
public:
    double x, y, z;
    Punkt(double xx, double yy, double zz);
    Punkt *next;

    Punkt operator+(const Punkt& a);
    Punkt operator+=(const Punkt& a);
    Punkt operator-(const Punkt& a);
    Punkt operator-=(const Punkt& a);
    bool operator==(const Punkt& a);
    bool operator!=(const Punkt& a);
    friend std::ostream& operator<<(std::ostream&, const Punkt& a);
};


class List {
public:
    List();
    Punkt *beg_, *end_;
    int len;

    List operator+(const List& l);
    void operator+=(const List& l);
    Punkt* operator[](int n);
    friend std::ostream& operator<<(std::ostream&, List& l);

    void addEl(Punkt a);
    void delEl(int n);
    void changePos(int init, int term);
    void sortList();
    void delList();
};


#endif // HEADS_H_INCLUDED
