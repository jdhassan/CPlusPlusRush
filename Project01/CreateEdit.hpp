//
//  CreateEdit.hpp
//  Project01
//
//  Created by Isaac Freedman Reed on 4/1/20.
//  Copyright © 2020 Isaac Freedman Reed. All rights reserved.
//

#ifndef CreateEdit_hpp
#define CreateEdit_hpp

#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <fstream>
#include "Validate.hpp"

using namespace std;

class CreateEdit : public Validate {
public:
    void createNew(string fileName, string type);
    void edit(string fileName, string type);
    void deleteFile();
    bool validYear(int y) const {
        return Validate::validYear(y);
    }
    bool validName(string s) const {
        return Validate::validName(s);
    }
    bool validStatus(int s) const {
        return Validate::validStatus(s);
    }
    bool validClearance(int s) const {
        return Validate::validClearance(s);
    }
    bool isMember(string s) const {
        return Validate::isMember(s);
    }
    bool isApplicant(string s) const  {
        return Validate::isApplicant(s);
    }
};

#endif /* CreateEdit_hpp */
