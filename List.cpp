#include "heads.h"

List::List()
    :beg_(NULL), end_(NULL), len(0)
{
}

List List::operator+(const List& l)
{

}
List List::operator+=(const List& l)
{

}
Punkt* List::operator[](int n)
{
    if(this->len==0) return NULL;
    Punkt *tmp=this->beg_;
    for(int i=1;i<n;i++) tmp=tmp->next;
    return tmp;
}
std::ostream& operator<<(std::ostream& s, List& l)
{
    s << "List:";
    for(int i=1;i-1<l.len;i++) s <<'\n'<< i <<". "<< *l[i];
    return s;
}

void List::addEl(Punkt& a)
{
    if(this->len==0) this->beg_=&a;
    else this->end_->next=&a;
    this->end_=&a;
    (this->len)++;
}
void List::delEl(int n)
{
    if(this->len==0||n>this->len) return;

    Punkt *el=this->beg_;
    for(int i=1;i<n;i++)
        el=el->next;

    Punkt *tmp;
    if(el == this->beg_) {
        tmp = this->beg_;
        this->beg_ = this->beg_->next;
        //delete(tmp);
        this->len--;
        return;
    }
    tmp = this->beg_;
    while(tmp->next != el && tmp->next != NULL) tmp = tmp->next;

    if(tmp->next != NULL) {
        tmp->next = tmp->next->next;
        //free(el);
    }
    else {
        std::cout<<"Nie znaleziono elementu\n";
    }
    this->len--;

}
void List::sortList()
{
}
void List::switchEls(int n, int m)
{
}
