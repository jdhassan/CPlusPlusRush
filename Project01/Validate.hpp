#ifndef Validate_hpp
#define Validate_hpp

#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <fstream>
#include <regex>


using namespace std;

class Search {
private:
    const int yearBound = 5;
    const int statusBound = 3;
    const int clearanceBound = 4;
public:
    virtual bool validClearance(int c) {
        return (c >= 0 && c <= clearanceBound);
    }
    virtual bool validName(string s) {
        return (regex_match(s, regex("^[A-Za-z.]+$")) && (s != ""));
    }

    virtual bool validYear(int y) {
        return (y >= 0 && y <= yearBound);
    }

    virtual bool validStatus(int s) {
        return (s >= 0 && s <= statusBound);
    }

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
