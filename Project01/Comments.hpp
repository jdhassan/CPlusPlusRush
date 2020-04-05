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

using namespace std;

class Comments {
public:
    void makeComment();
    string getComment();
    bool isMember(string s);
    bool isApplicant(string s);
    bool validName(string s);
    string getNumberTypes();
    void tokenize(string const &str, const char delim, vector<string> &out);
};

#endif /* Comments_hpp */
