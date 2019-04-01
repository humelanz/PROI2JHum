#include "heads.h"
#include <iostream>

int main()
{

    Punkt a(1.8,1.2,-1.3);
    Punkt b(32.0,32.0,32.0);
    Punkt c(7.0,7.0,7.0);
    Punkt d(13.0,13.0,13.0);
    Punkt e(6.0,6.0,6.0);

    a=a+b-d;
    c+=e;

    if(c==d) std::cout <<"c=d"<<std::endl;
    if(c!=d) std::cout <<"c nierowne d"<<std::endl;
    if(a==d) std::cout <<"a=d"<<std::endl;
    if(a!=d) std::cout <<"a nierowne d"<<std::endl;

    std::cout <<a<<b<<c<<d<<e<<std::endl;

    List lista1, lista2, lista3;
    lista1.addEl(a);
    lista1.addEl(b);
    lista2.addEl(c);
    lista2.addEl(d);
    lista2.addEl(e);

    std::cout << lista1 << std::endl;
    std::cout << lista2 << std::endl;

    lista3=lista2+lista1;

    std::cout << lista1 << std::endl;
    std::cout << lista2 << std::endl;
    std::cout << lista3 << std::endl;

    lista1+=lista2;

    std::cout << lista1 << std::endl;

    lista1.delEl(1);

    lista1.sortList();

    std::cout << lista1 << std::endl;

    lista1.delList();
    lista2.delList();
    lista3.delList();

    std::cout << lista1 << std::endl;
    std::cout << lista2 << std::endl;
    std::cout << lista3 << std::endl;

    return 0;
}
