#include <string>
#include <iostream>

#define debug
#include "debug.h"

template <class T>
class RefPtr {
public:
    // constructor allocates a new string and a new counter, which it sets to 1
    RefPtr(const T &s) :
        ps(new T(s)), use(new size_t (1)) { _ref() }
    RefPtr(const T *s=new T) :
        ps(new T(*s)), use(new size_t (1)) { delete s; _ref() }
    // copy constructor copies all three data members and increments the counter
    RefPtr(const RefPtr &p) :
        ps(p.ps), use(p.use) {  ++ *use; _ref() }

    RefPtr& operator= (const RefPtr& rhs) {
        // increment the use count of the right-hand operand
        ++*rhs.use;
        _undef()
        if(--*use == 0) {   // then decrement this object’s counter
            _del()
            delete ps;      // if no other users
            delete use;     // free this object’s allocated members
        }
        ps = rhs.ps;        // copy data from rhs into this object
        use = rhs.use;
        _ref()
        return *this;       // return this object
    }
    ~RefPtr() {
        _undef()
        if(--*use == 0) {  // if the reference count goes to 0
            _del()
            delete ps;     // delete the string
            delete use;    // and the counter
        }
    }
    const T* operator -> () { return this->get();}
    const T* get () { return ps;}
    size_t ref () { return *use;}

private:
    const T *ps;

    // member to keep track of how many objects share *ps
    size_t *use;  // --> reference counter

};

RefPtr<std::string> test () {
    _d(RefPtr<std::string> p1(new std::string("abc"));)
    _d(auto p2(p1);)
    _d(auto p3 = p1;)
    
    _d(p1 = p3 = p2;)

    _d(return p1;)
}

int main () {
    _d(decltype(test()) p(std::string("test")));
    _d(p = test());
    _p(p.ref() << " " << p->data());
    _d(return 0);
}
