#include "heads.h"
#include <iostream>

int main()
{
    Punkt a(1.0,2.0,3.0);
    Punkt b(0.0,5.0,0.0);
    Punkt c(-1.0,-2.0,-3.0);
    Punkt d(0.0,9.0,0.0);
    Punkt e(6.7,6.7,6.7);

    b+=d;
    b-=d;

    List lista;
    lista.addEl(a);
    lista.addEl(b);
    lista.addEl(c);
    lista.addEl(d);
    lista.addEl(e);

    std::cout << d << std::endl;
    if(b==d) std::cout << "rowne" << std::endl;
    else if(b!=d) std::cout << "nierowne" << std::endl;



    std::cout << *lista[1] << std::endl;
    std::cout << *lista[2] << std::endl;
    std::cout << *lista[3] << std::endl;
    std::cout << *lista[4] << std::endl;
    std::cout << *lista[5] << std::endl;
    lista.delEl(1);
    std::cout << lista << std::endl;



    return 0;
}
