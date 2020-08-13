//
//  Python.cpp
//  python-like-C
//
//  Created by Jakob Zorz on 12/08/2020.
//

#include "Python.hpp"

#undef int
#undef bool

#undef main

int main(int argc, const char * argv[]) {
    __py_private::main_();
    return 0;
}

def print(const var x, const var end) {
    /*switch(type(x)) {
        case none:
            std::cout << "None";
            break;
        case PY_int:
            std::cout << *(int *)x.__returnData();
            break;
        case str:
            std::cout << (char*)x.__returnData();
            break;
        default:
            std::cout << "Cannot print this type." << std::endl;
            exit(1);
    }*/
    
    std::cout << (char*)to_str(x).__returnData();
    
    if(type(end) != none)
        print(end, None);
    
    return None;
}

Type type(var x) {
    return x.__returnType();
}

def to_int(const var x) {
    switch (type(x)) {
        case PY_int:
            return x;
            
        case str:
            return std::stoi((const char*)x.__returnData());
        
        case PY_bool:
            return *(bool*)x.__returnData();
            
        default:
            std::cout << "Cannot convert to type int" << std::endl;
            exit(1);
    }
}

def to_str(const var x) {
    switch (type(x)) {
        case PY_int:
            return std::to_string(*(int*)x.__returnData()).c_str();
            
        case str:
            return x;
            
        case PY_bool:
            return *(bool*)x.__returnData() ? "True" : "False";
        
        case none:
            return "None";
            
        default:
            std::cout << "Cannot convert to type str" << std::endl;
            exit(1);
    }
}

def to_bool(const var x) {
    switch (type(x)) {
        case PY_int:
            return *(int*)x.__returnData() != 0;
            
        case str:
            return ((const char*)x.__returnData())[0] != 0;
            
        default:
            std::cout << "Cannot convert to type bool" << std::endl;
            exit(1);
    }
}
