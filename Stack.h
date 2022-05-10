#include<bits/stdc++.h>
#include <windows.h>
using namespace std;
void changeColor(int desiredColor)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), desiredColor);
}
template<class T>
class Stack
{
    struct element
    {
        T value;
        element *before;
        element *after;
    };
    element *l,*r;//leftmost element + rightmost element
public:
    unsigned int Size;
    Stack()
    {
        r=nullptr;
        l=nullptr;
        Size=0;
    };
    Stack(Stack &s)
    {
        element *p=s.l;
        r=nullptr;
        l=nullptr;
        Size=0;
        for(int i=1; i<=s.size(); i++)
        {
            push(p->value);
            p=p->after;
        }
    }
    void split(Stack &s,unsigned int k)
    {
        element *p=l;
        for(int i=1; i<=k; i++)
        {
            p=p->after;
        }
        for(int i=k+1; i<=Size; i++)
        {
            p=p->after;
            s.r=p;
        }
        s.Size=Size-k;
        Size=k;
        // s.r=r;//!!!
        r=p;
        r->after=nullptr;
        s.l=p;
        s.l->before=nullptr;
    }
    void operator+=(Stack &s)
    {
        element *p=s.l;
        for(int i=1; i<=s.size(); i++)
        {
            push(p->value);
            p=p->after;
        }
        // return s;
    }
    void push(T val)
    {
        Size++;
        element *x=new element;
        x->value=val;
        if(r)
            r->after=x;
        x->before=r;
        if(Size==1)
            l=x;
        r=x;
    };
    friend istream &operator>>(istream &in, Stack &s)
    {
        unsigned int nrElements;
        in>>nrElements;
        in.get();
        T x;
        for(int j=1; j<=nrElements; j++)
        {
            in>>x;
            s.push(x);///chemat intern
        }
        return in;
    }
    ~Stack()
    {
        element *p;
        while(r)
        {
            p=r;
            r=r->before;
            delete p;
        }
    }

    T pop()
    {
        if(r)  //isn't empty
        {
            Size--;
            element *e=r;
            T x=r->value;
            r=r->before;
            delete e;
            return x;
        }
        else
        {
            changeColor(10);
            cerr<<"ERROR. Elements can't be removed from and empty stack.";
            changeColor(7);
            exit(-69);
        }
    };
    T top()
    {
        changeColor(5);
        return r->value;
        changeColor(7);
    };

    unsigned int size()
    {
        return Size;
    }
    bool empty()
    {
        return Size==0;
    }

    friend ostream& operator<<(ostream &out,Stack &s)
    {
        /*  changeColor(4);
          element *p=s.l;
          for(int i=1; i<=s.size(); i++)
          {
              out<<p->value<<" ";
              p=p->after;
          }
          changeColor(7);
          out<<endl;
          return out;*/
        element *p=s.l;
        auto time = std::time(nullptr);
        for(int i=1; i<=s.size(); i++)
        {
            out << put_time(localtime(&time), "%c") <<"       <"<<i-1<<">       "<<p->value<<"\n";
           // cout<<"05/10/22 21:53:12    <DIR>    0 Stack(47)";
            p=p->after;
        }
        out<<endl;
        return out;

    }

};
