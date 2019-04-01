#include "heads.h"

Punkt::Punkt(double xx, double yy, double zz)
    :x(xx), y(yy), z(zz), next(NULL)
{
}

Punkt Punkt::operator+(const Punkt& a)
{
    return Punkt(this->x + a.x, this->y + a.y, this->z + a.z);
}
Punkt Punkt::operator+=(const Punkt& a)
{
    this->x = (this->x + a.x);
    this->y = (this->y + a.y);
    this->z = (this->z + a.z);
    return *this;
}
Punkt Punkt::operator-(const Punkt& a)
{
    return Punkt(this->x - a.x,this->y - a.y,this->z - a.z);
}
Punkt Punkt::operator-=(const Punkt& a)
{
    this->x = (this->x - a.x);
    this->y = (this->y - a.y);
    this->z = (this->z - a.z);
    return *this;
}
bool Punkt::operator==(const Punkt& a)
{
    if(this->x!=a.x) return false;
    else if(this->y!=a.y) return false;
    else if(this->z!=a.z) return false;
    else return true;
}
bool Punkt::operator!=(const Punkt& a)
{
    if(this->x!=a.x) return true;
    else if(this->y!=a.y) return true;
    else if(this->z!=a.z) return true;
    else return false;
}
/*
bool operator==(const Punkt& a, const Punkt& b)
{
    if(a.x!=b.x) return false;
    else if(a.y!=b.y) return false;
    else if(a.z!=b.z) return false;
    else return true;
}
bool operator!=(const Punkt& a, const Punkt& b)
{
    if(a.x!=b.x) return true;
    else if(a.y!=b.y) return true;
    else if(a.z!=b.z) return true;
    else return false;
}
*/
std::ostream& operator<<(std::ostream& s, const Punkt& a)
{
   s << "(" << a.x << "," << a.y << "," << a.z << ")";
   return s;
}
