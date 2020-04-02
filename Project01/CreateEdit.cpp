//
//  CreateEdit.cpp
//  Project01
//
//  Created by Isaac Freedman Reed on 4/1/20.
//  Copyright © 2020 Isaac Freedman Reed. All rights reserved.
//

#include "CreateEdit.hpp"
#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <fstream>
#include <regex>

using namespace std;

void CreateEdit::createNew(string fileName, string type) {
    bool validNameString = true;
    bool validYearInt = true;
    bool validStatClearInt = true;
    string name, sc;
    int year, statClear;
    if (type == "Member") {
        sc = "Clearance";
    }
    else {
        sc = "Status";
    }
    
    ofstream file(fileName, ios::app);
    
    while(validNameString) {
    cout << "Enter the new " << type << "'s Name" << endl;
    cin >> name;
        validNameString = !validName(name);
        if (validNameString) {
            cout << "Invalid input, try again" << endl;
        }
    }
    
    while(validYearInt) {
    cout << "Enter the " << type << "'s Year." << endl;
    cin >> year;
        validYearInt = !validYear(year);
        if (validYearInt) {
            cout << "Invalid input, try again" << endl;
        }
    }
    
    while(validStatClearInt) {
    cout << "Enter the " << type << "'s "<< sc <<"." << endl;
    cin >> statClear;
        validStatClearInt = !validStatus(statClear);
        if (validStatClearInt) {
            cout << "Invalid input, try again" << endl;
        }
    }
    sc = ", " + sc + ": ";
    
    file << name << ' ' << year << ' ' << statClear << endl;
    file.close();
}

void CreateEdit::edit(string fileName, string type) {
    bool isNameValid = true;
    bool isyearValid = true;
    bool isStatClearValid = true;
    string name, fname, gname, newFileName, sc;
    newFileName = "new"+fileName;
    int year, fyear;
    int statClear, fStatClear;
    ifstream file(fileName, ios::in);
    ofstream newFile(newFileName, ios::out);
    bool found = false;
    cout << "Enter the name of the " << type << " you want to edit" << endl;
    cin >> gname;
    
    if (type == "Member") {
        sc = " clearnace ";
    }
    else {
        sc = " status ";
    }
    while (file >> name >> year >> statClear) {
        if (name == gname) {
            found = true;
            while(isNameValid) {
            cout << "Enter " << type << "'s new name (type \".\" to keep old)" << endl;
            cin >> fname;
                isNameValid = !validName(fname);
                if (isNameValid) {
                    cout << "Invalid input, try again" << endl;
                }
            }
            if (fname != ".") {
                name = fname;
            }
            
            while(isyearValid) {
            cout << "Enter " << type << "'s new year (type 0 to keep last)" << endl;
            cin >> fyear;
                isyearValid = !validYear(fyear);
                if (isyearValid) {
                    cout << "Invalid input, try again" << endl;
                }
            }
            if (fyear != 0) {
                year = fyear;
            }
            
            while(isStatClearValid) {
            cout << "Enter " << type << "'s new" << sc << "(type 0 to keep last)" << endl;
            cin >> fStatClear;
                isStatClearValid = !validStatus(fStatClear);
                if (isStatClearValid) {
                    cout << "Invalid input, try again" << endl;
                }
            }
            if (fStatClear != 0) {
                statClear = fStatClear;
            }
        }
        newFile << name << ' ' << year << ' ' << statClear << endl;
    }
    if (!found) {
        cout << "No applicant by that name found" << endl;
    }
    
    file.close();
    newFile.close();
    if (type == "Applicant") {
        remove("applicants.txt");
        rename("newApplicants.txt", "applicants.txt");
    }
    else {
        remove("members.txt");
        rename("newmembers.txt", "members.txt");
    }
}

void CreateEdit::deleteFile() {
    int option;
    cout << "1.Delete Members/Comments file" << endl;
    cout << "2.Delete Applicants file" << endl;
    cout << "3.Delete All files" << endl;
    cout << "4.Back" << endl;
    cin >> option;
    
    
    if (option == 1) {
        string decision;
        cout << "Are you sure?[Y]es[N]o" << endl;
        cout << "if you delete the members file you also delete the comments" << endl;
        cin >> decision;
        if (decision == "y" || decision == "Y"){
            ofstream member("members.txt");
            std::remove("members.txt");
            cout << "Successfully Completed!" << endl;
            member.close();
        }
    }
    if (option == 2) {
        string decision;
        cout << "Are you sure?[Y]es[N]o" << endl;
        cin >> decision;
        if (decision == "y" || decision == "Y"){
            ofstream applicant("applicants.txt");
            std::remove("applicants.txt");
            cout << "Successfully Completed!" << endl;
            applicant.close();
        }
    }
    if (option == 3) {
        string decision;
        cout << "Are you sure?[Y]es[N]o" << endl;
        cin >> decision;
        if (decision == "y" || decision == "Y"){
            ofstream applicant("applicants.txt");
            std::remove("applicants.txt");
            ofstream member("members.txt");
            std::remove("members.txt");
            cout << "Successfully Completed!" << endl;
            applicant.close();
            member.close();
        }
        
    }
}


bool CreateEdit::validName(string s) {
    return (regex_match(s, regex("^[A-Za-z.]+$")) && (s != ""));
}

bool CreateEdit::validYear(int y) {
    return (y >= 0 && y <= 5);
}

bool CreateEdit::validStatus(int s) {
    return (s >= 0 && s <= 4);
}
