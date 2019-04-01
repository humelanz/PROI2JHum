#include "heads.h"

List::List()
    :beg_(NULL), end_(NULL), len(0)
{
}

List List::operator+(const List& l)
{
    List lis;
    Punkt *tmp=this->beg_;
    while (tmp){
    lis.addEl(*tmp);
    tmp=tmp->next;
    }
    tmp=l.beg_;
    while (tmp){
    lis.addEl(*tmp);
    tmp=tmp->next;
    }
    return lis;
}
void List::operator+=(const List& l)
{
    this->end_->next=l.beg_;
    this->end_=l.end_;
    this->len+=l.len;
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

void List::addEl(Punkt a)
{
    Punkt *el = new Punkt(a.x,a.y,a.z);
    if(this->len==0) this->beg_=el;
    else this->end_->next=el;
    this->end_=el;
    (this->len)++;
}
void List::delEl(int n)
{
    if(this->len==0||n>this->len||n==0) return;

    Punkt *el=this->beg_;
    for(int i=1;i<n;i++)
        el=el->next;

    Punkt *tmp;
    if(el == this->beg_) {
        tmp = this->beg_;
        this->beg_ = this->beg_->next;
        delete(tmp);
        this->len--;
        return;
    }
    tmp = this->beg_;
    while(tmp->next != el && tmp->next != NULL) tmp = tmp->next;

    if(tmp->next != NULL) {
        tmp->next = tmp->next->next;
        delete(el);
    }
    this->len--;
}
void List::changePos(int init, int term)
{
    if (init>this->len||term>this->len||init==term) return;

    Punkt *a=this->beg_;
    for(int i=1;i<init;i++) a=a->next;
    Punkt *b=this->beg_;
    for(int i=1;i<term;i++) b=b->next;

    if(init==1){
        this->beg_=this->beg_->next;
        a->next=b->next;
        b->next=a;
        return;}

    Punkt *tmp;
    if(term==1){
        tmp=this->beg_;
        while(tmp->next!=a&&tmp)tmp=tmp->next;
        tmp->next=tmp->next->next;
        a->next=b;
        this->beg_=a;
        return;}

    tmp=this->beg_;
    while(tmp->next!=a&&tmp)tmp=tmp->next;
    tmp->next=tmp->next->next;

    tmp=this->beg_;
    while(tmp->next!=b&&tmp!=NULL)tmp=tmp->next;

    if(init>term){
        tmp->next=a;
        a->next=b;}
    if(init<term){
        tmp->next=b;
        a->next=b->next;
        b->next=a;}
}
void List::sortList()
{
    if (this->len==0) return;

    int t=0;
    Punkt *head=(this->beg_);
    while(head!=NULL){
        Punkt *tmp=head;
        Punkt *min_=head;
        while(tmp!=NULL){
            if((sqrt((tmp->x*tmp->x)+(tmp->y*tmp->y)+(tmp->z*tmp->z)))<(sqrt((min_->x*min_->x)+(min_->y*min_->y)+(min_->z*min_->z))))
                min_=tmp;
            tmp=tmp->next;
        }
        if(t!=0){
            tmp=(this->beg_);
            while(tmp->next!=head){
                tmp=tmp->next;
            }
            tmp->next=min_;
        }
        else{
            (this->beg_)=min_;
            t++;
        }
        if(min_!=head){
            tmp=head;
            while(tmp->next!=min_)
                tmp=tmp->next;
            tmp->next=min_->next;
            min_->next=head;
        }
        else
            head=head->next;
}
}
void List::delList()
{
    if(this->len==0) return;
    int n=this->len;
    for(int i=0;i<n;i++)this->delEl(1);
}
