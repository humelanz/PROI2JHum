#include "heads.h"

List::List()
    :beg_(NULL), end_(NULL), len(0)
{
}

List List::operator+(const List& l)
{
    Punkt *head1=this->beg_;
    Punkt *head2=l.beg_;
    Punkt *tmp=head1;
    while(tmp->next) tmp=tmp->next;
    tmp->next=head2;
    while(tmp->next) tmp=tmp->next;
    List lis;
    lis.beg_=head1;
    lis.end_=tmp;
    lis.len=this->len+l.len;
    return lis;

}
List List::operator+=(const List& l)
{
    this->end_->next=l.beg_;
    this->end_=l.end_;
    this->len+=l.len;
    return *this;
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
        this->beg_ = this->beg_->next;      //delete(tmp);?
        this->len--;
        return;
    }
    tmp = this->beg_;
    while(tmp->next != el && tmp->next != NULL) tmp = tmp->next;

    if(tmp->next != NULL) {
        tmp->next = tmp->next->next;        //free(el);?
    }
    this->len--;
}
void List::switchEls(int n, int m)
{
    if (n>this->len||m>this->len||n==m) return;





}
void List::sortList()
{




}
