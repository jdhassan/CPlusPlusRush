//
//  Search.hpp
//  Project01
//
//  Created by Isaac Freedman Reed on 4/1/20.
//  Copyright © 2020 Isaac Freedman Reed. All rights reserved.
//

#ifndef Search_hpp
#define Search_hpp

#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <fstream>
#include "Validate.hpp"

using namespace std;

class Search : public Validate {
public:
    string searchByName(string fileName, string type);
    string searchByYear(string fileName, string type);
    string seachBystatClear(string fileName, string type);
    string displayAll(string fileName, string type);
    bool isMember(string s) const {
        return Validate::isMember(s);
    }
    bool isApplicant(string s) const {
        return Validate::isApplicant(s);
    }
    bool validYear(int y) const {
        return Validate::validYear(y);
    }
    bool validStatus(int y) const {
        return Validate::validStatus(y);
    }
    bool validClearance(int y) const {
        return Validate::validClearance(y);
    }
};

#endif /* Search_hpp */
