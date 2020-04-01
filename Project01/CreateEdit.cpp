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

void CreateEdit::createNew(string fileName, string type) {
    string name, sc;
    int year, statClear;
    if (type == "Member") {
        sc = "Clearance";
    }
    else {
        sc = "Status";
    }
    
    ofstream file(fileName, ios::app);
    
    cout << "Enter the new " << type << "'s Name" << endl;
    cin >> name;
    
    cout << "Enter the " << type << "'s Year." << endl;
    cin >> year;
    
    cout << "Enter the " << type << "'s "<< sc <<"." << endl;
    cin >> statClear;
    sc = ", " + sc + ": ";
    
    file << name << ' ' << year << ' ' << statClear << endl;
    file.close();
}

void CreateEdit::edit(string fileName, string type) {
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
            cout << "Enter " << type << "'s new name (type \".\" to keep old)" << endl;
            cin >> fname;
            if (fname != ".") {
                name = fname;
            }
            cout << "Enter " << type << "'s new year (type 0 to keep last)" << endl;
            cin >> fyear;
            if (fyear != 0) {
                year = fyear;
            }
            cout << "Enter " << type << "'s new" << sc << "(type 0 to keep last)" << endl;
            cin >> fStatClear;
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
