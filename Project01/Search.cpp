//
//  Search.cpp
//  Project01
//
//  Created by Isaac Freedman Reed on 4/1/20.
//  Copyright © 2020 Isaac Freedman Reed. All rights reserved.
//

#include "Search.hpp"
#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <fstream>

string Search::searchByName(string fileName, string type) {
    ifstream file(fileName, ios::in);
    string name, fname, sc, returnString;
    int year, statClear;
    bool found = false;
    
    if (type == "Member") {
        sc = ", Clearance: ";
    }
    else {
        sc = ", Status: ";
    }
    
    cout << "Input search name:" << endl;
    cin >> fname;
    
    while (file >> name >> year >> statClear){
        if (fname == name){
                found = true;
                returnString.append(type + " found: \n");
                returnString.append("---------------\n");
                returnString.append("Name: " + name + ", Year: " + to_string(year) + sc +  to_string(statClear) + "\n");
                returnString.append("---------------\n");
            }
        }
    if (!found){
        returnString.append("Nobody found\n");
    }
    return returnString;
}

string Search::searchByYear(string fileName, string type) {
    string name, returnString, sc;
    int year, fyear, statClear;
    bool found = false;
    ifstream file(fileName);
    
    if (type == "Member") {
        sc = ", Clearance: ";
    }
    else {
        sc = ", Status: ";
    }
    
    cout << "Enter search year:" << endl;;
    cin >> fyear;
    
    while (file >> name >> year >> statClear){
        if (fyear == year){
            found = true;
            returnString.append(type + " found: \n");
            returnString.append("---------------\n");
            returnString.append("Name: " + name + ", Year: " + to_string(year) + sc +  to_string(statClear) + "\n");
            returnString.append("---------------\n");
            }
        }
        if (!found){
            returnString.append("Nobody found\n");
        }
    return returnString;
}


string Search::seachBystatClear(string fileName, string type) {
    string name, returnString, sc;
    int year, fstatClear, statClear;
    bool found = false;
    ifstream file(fileName);
    
    if (type == "Member") {
        sc = "Clearance";
    }
    else {
        sc = "Status";
    }
    
    cout << "Enter " << sc << ":" << endl;;
    cin >> fstatClear;
    
    sc = ", " + sc + ": ";
    
    while (file >> name >> year >> statClear){
        if (fstatClear == statClear){
            found = true;
            returnString.append(type + " found: \n");
            returnString.append("---------------\n");
            returnString.append("Name: " + name + ", Year: " + to_string(year) + sc +  to_string(statClear) + "\n");
            returnString.append("---------------\n");
            }
        }
        if (!found){
            returnString.append("Nobody found\n");
        }
    return returnString;
}

string Search::displayAll(string fileName, string type) {
    int year, statClear;
    string name, sc, returnString;
    ifstream file(fileName, ios::in);
    bool empty = true;
    if (type == "Member") {
        sc = ", Clearance: ";
    }
    else {
        sc = ", Status: ";
    }
    returnString.append( "Entire " + type + " database:\n");
    
    while (file >> name >> year >> statClear) {
        empty= false;
        returnString.append("---------------\n");
        returnString.append("Name: " + name + ", Year: " + to_string(year) + sc +  to_string(statClear) + "\n");
        returnString.append("---------------\n");
        }
    
    if (empty) {
        returnString.append("No " + type + " found");
    }
    return returnString;
}
