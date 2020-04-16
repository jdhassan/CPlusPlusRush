//
//  Comments.hpp
//  Project01
//
//  Created by Isaac Freedman Reed on 4/1/20.
//  Copyright © 2020 Isaac Freedman Reed. All rights reserved.
//

#ifndef Comments_hpp
#define Comments_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include "Validate.hpp"

using namespace std;

class Comments : public Validate {
public:
    bool isMember(string s)  {
        return Validate::isMember(s);
    }
    bool isApplicant(string s)  {
        return Validate::isApplicant(s);
    }
    bool validName(string s) const {
        return Validate::validName(s);
    }
    void makeComment();
    string getComment() const;
    string getNumberTypes() const;
    void tokenize(string const &str, const char delim, vector<string> &out);
};

#endif /* Comments_hpp */
