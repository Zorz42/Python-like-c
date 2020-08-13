//
//  Python.hpp
//  python-like-C
//
//  Created by Jakob Zorz on 12/08/2020.
//

#ifndef Python_hpp
#define Python_hpp

#include <iostream>

#define main __py_private::main_

#define True true
#define False false
#define is ==

enum Type {none, PY_int, str, PY_bool};

namespace __py_private {
void main_();

class PY_Object {
public:
    inline Type __returnType() const { return __type; }
    inline void* __returnData() const { return __data; }
    
    PY_Object();
    PY_Object(const PY_Object& obj);
    PY_Object(const char* input);
    PY_Object(const int input);
    PY_Object(const bool input);
    ~PY_Object();
    
    void operator=(const PY_Object obj);
    
private:
    Type __type;
    void* __data;
    void __set(const PY_Object& obj);
    void __set(const int input);
    void __set(const char* input);
    void __set(const bool input);
};
};

typedef __py_private::PY_Object var;
typedef __py_private::PY_Object def;

inline const var None;

Type type(var x);
def print(const var x, const var end="\n");

def to_int(const var x=0);
def to_str(const var x="");
def to_bool(const var x=False);

#define int PY_int
#define bool PY_bool

#endif /* Python_hpp */
