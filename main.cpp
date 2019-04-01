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

    List lista1,lista2;
    lista1.addEl(a);
    lista1.addEl(b);
    lista2.addEl(c);
    lista2.addEl(d);
    lista2.addEl(e);

    std::cout << lista1 << std::endl;
    std::cout << lista2 << std::endl;


    lista1+=lista2;

    //std::cout << d << std::endl;
    //if(b==d) std::cout << "rowne" << std::endl;
    //else if(b!=d) std::cout << "nierowne" << std::endl;



    std::cout << *lista1[1] << std::endl;
    std::cout << *lista1[2] << std::endl;
    std::cout << *lista1[3] << std::endl;
    std::cout << *lista1[4] << std::endl;
    std::cout << *lista1[5] << std::endl;

    std::cout << *lista2[1] << std::endl;
    std::cout << *lista2[2] << std::endl;
    std::cout << *lista2[3] << std::endl;

    //lista.delEl(1);
    std::cout << lista1 << std::endl;
    std::cout << lista2 << std::endl;
    //std::cout << lista12 << std::endl;



    return 0;
}
