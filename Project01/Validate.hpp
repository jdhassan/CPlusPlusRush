#ifndef Validate_hpp
#define Validate_hpp

#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <fstream>
#include <regex>


using namespace std;

//This class is used for inhereitance purposes in order to remove duplicate code from every .cpp/.hpp given that these checks are needed in almost every class
class Validate {
private:
    const int yearBound = 5;
    const int statusBound = 3;
    const int clearanceBound = 4;
public:
    //checks if the given int is a valid clearnace number
    virtual bool validClearance(int c) const {
        return ((c > 0 && c <= clearanceBound) || c == -1);
    }
    //checks if the string given follows the name parameters
    virtual bool validName(string s) const {
        return (regex_match(s, regex("^[A-Za-z.]+$")) && (s != ""));
    }
    //checks if the year is in the valid range
    virtual bool validYear(int y) const {
        return ((y > 0 && y <= yearBound) || y == -1);
    }
    //checks if the status s in the valid range
    virtual bool validStatus(int s) const {
        return ((s > 0 && s <= statusBound) || s == -1);
    }
    
    //checks if the name given as a string is in the members.txt
    virtual bool isMember(string s) {
        ifstream file("members.txt");
        int year, clearance;
        string name;
        while(file >> name >> year >> clearance) {
            if (name == s) {
                return true;
            }
        }
        return false;
    }
    //checks if the name given as a string is in the applicants.txt
    virtual bool isApplicant(string s) {
        ifstream file("applicants.txt");
        int year, status;
        string name;
        while(file >> name >> year >> status) {
            if (name == s) {
                return true;
            }
        }
        return false;
    }
};

#endif /* Validate_hpp */
