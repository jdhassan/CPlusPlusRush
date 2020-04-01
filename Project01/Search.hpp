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


using namespace std;

class Search {
public:
    string searchByName(string fileName, string type);
    string searchByYear(string fileName, string type);
    string seachBystatClear(string fileName, string type);
    string displayAll(string fileName, string type);
    
};

#endif /* Search_hpp */
