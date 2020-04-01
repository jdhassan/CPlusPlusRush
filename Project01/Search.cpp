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

/*
Searches data for an applicant or member by name, taking in the fileName we are searching in and the type (applicant or member)
*/
string Search::searchByName(string fileName, string type) {
    ifstream file(fileName, ios::in);
    string name, fname, sc, returnString;
    int year, statClear;
    bool found = false;
    
    //check if searching for applicant or member
    if (type == "Member") {
        sc = ", Clearance: ";
    }
    else {
        sc = ", Status: ";
    }
    
    //takes in name desired for search
    cout << "Input search name:" << endl;
    cin >> fname;
    
    //searches the file
    while (file >> name >> year >> statClear){
        //found case
        if (fname == name){
                found = true;
                returnString.append(type + " found: \n");
                returnString.append("---------------\n");
                returnString.append("Name: " + name + ", Year: " + to_string(year) + sc +  to_string(statClear) + "\n");
                returnString.append("---------------\n");
            }
        }
    //not found case
    if (!found){
        returnString.append("Nobody found\n");
    }
    //return result (found or not)
    return returnString;
}

/*
Searches data for an applicant or member by year, taking in the fileName we are searching in and the type (applicant or member)
*/
string Search::searchByYear(string fileName, string type) {
    string name, returnString, sc;
    int year, fyear, statClear;
    bool found = false;
    ifstream file(fileName);
    
    //check if searching for applicant or member
    if (type == "Member") {
        sc = ", Clearance: ";
    }
    else {
        sc = ", Status: ";
    }
    
    cout << "Enter search year:" << endl;;
    cin >> fyear;
   
    //searches the file
    while (file >> name >> year >> statClear){
        //found case
        if (fyear == year){
            found = true;
            returnString.append(type + " found: \n");
            returnString.append("---------------\n");
            returnString.append("Name: " + name + ", Year: " + to_string(year) + sc +  to_string(statClear) + "\n");
            returnString.append("---------------\n");
            }
        }
        //not found case
        if (!found){
            returnString.append("Nobody found\n");
        }
    //return result (found or not)
    return returnString;
}

/*
Searches data for an applicant or member by status, taking in the fileName we are searching in and the type (applicant or member)
*/
string Search::seachBystatClear(string fileName, string type) {
    string name, returnString, sc;
    int year, fstatClear, statClear;
    bool found = false;
    ifstream file(fileName);
    
    //check if searching for applicant or member
    if (type == "Member") {
        sc = "Clearance";
    }
    else {
        sc = "Status";
    }
    
    cout << "Enter " << sc << ":" << endl;;
    cin >> fstatClear;
    
    sc = ", " + sc + ": ";
    
    //searches the file
    while (file >> name >> year >> statClear){
        //found case
        if (fstatClear == statClear){
            found = true;
            returnString.append(type + " found: \n");
            returnString.append("---------------\n");
            returnString.append("Name: " + name + ", Year: " + to_string(year) + sc +  to_string(statClear) + "\n");
            returnString.append("---------------\n");
            }
        }
        //not found case
        if (!found){
            returnString.append("Nobody found\n");
        }
    //return result (found or not)
    return returnString;
}

/*
Displays the entirety of members or applicants in a file, taking in filename and type (member or applicant)
*/
string Search::displayAll(string fileName, string type) {
    int year, statClear;
    string name, sc, returnString;
    ifstream file(fileName, ios::in);
    bool empty = true;
    
    //check if searching for applicant or member
    if (type == "Member") {
        sc = ", Clearance: ";
    }
    else {
        sc = ", Status: ";
    }
    returnString.append( "Entire " + type + " database:\n");
    
    //go through entire file and add each member/applicant to output string
    while (file >> name >> year >> statClear) {
        empty= false;
        returnString.append("---------------\n");
        returnString.append("Name: " + name + ", Year: " + to_string(year) + sc +  to_string(statClear) + "\n");
        returnString.append("---------------\n");
        }
    //empty file case
    if (empty) {
        returnString.append("No " + type + " found");
    }
    //return all members/applicants
    return returnString;
}
