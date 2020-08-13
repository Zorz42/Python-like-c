//
//  PY_object.cpp
//  python-like-C
//
//  Created by Jakob Zorz on 12/08/2020.
//

#include "Python.hpp"

#undef int
#undef bool

var::PY_Object() {
    __type = none;
    __data = nullptr;
}

var::PY_Object(const PY_Object& obj) {
    __set(obj);
}

var::PY_Object(const char* input) {
    __set(input);
}

var::PY_Object(const int input) {
    __set(input);
}

var::PY_Object(const bool input) {
    __set(input);
}

void var::__set(const PY_Object &obj) {
    __type = obj.__returnType();
    switch(__type) {
        case none:
            __type = none;
            __data = nullptr;
            break;
        case str:
            __set((const char*)obj.__returnData());
            break;
        case PY_int:
            __set(*(const int*)obj.__returnData());
            break;
        case PY_bool:
            __set(*(const bool*)obj.__returnData());
            break;
        default:
            std::cout << "Cannot convert type" << std::endl;
            exit(1);
    }
}

void var::__set(const int input) {
    __type = PY_int;
    __data = new int(input);
}

void var::__set(const char *input) {
    __type = str;
    __data = malloc(sizeof(char) * strlen(input));
    strcpy((char *)__data, input);
}

void var::__set(const bool input) {
    std::cout << "setting" << std::endl;
    __type = PY_bool;
    __data = new bool(input);
}

var::~PY_Object() {
    if(__data)
        std::cout << "freeing" << std::endl;
    if(__data)
        switch(__type) {
            case PY_int:
                delete (int*)__data;
                __data = nullptr;
                break;
            
            case str:
                delete (const char*)__data;
                __data = nullptr;
                break;
            
            case PY_bool:
                delete (bool*)__data;
                __data = nullptr;
                break;
                
            default:
                break;
        }
}

void var::operator=(const PY_Object obj) {
    this->~PY_Object();
    __set(obj);
}
