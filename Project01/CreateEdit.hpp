//
//  CreateEdit.hpp
//  Project01
//
//  Created by Isaac Freedman Reed on 4/1/20.
//  Copyright © 2020 Isaac Freedman Reed. All rights reserved.
//

#ifndef CreateEdit_hpp
#define CreateEdit_hpp

#include "Validate.hpp"
#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <fstream>

using namespace std;

class CreateEdit {
public:
    void createNew(string fileName, string type);
    void edit(string fileName, string type);
    void deleteFile();
};

#endif /* CreateEdit_hpp */
