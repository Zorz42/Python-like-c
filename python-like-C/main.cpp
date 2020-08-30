//
//  main.cpp
//  python-like-C
//
//  Created by Jakob Zorz on 12/08/2020.
//

#include "Python.hpp"

def test_a(var& param) {
    return None;
}

void main() {
    print("test:");
    var test1 = True, test2 = True;
    if(test1 != test2)
        print("It's True :)");
}
