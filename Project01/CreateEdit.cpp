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

/*
 This function takes in a file name (hardcoded as applicants.txt or members.txt) and a type (Member/Applicant) and then opens up a file with the fileName, and takes in the inputs for a adding a new member, and also checks the validity of the inputs.
 */
void CreateEdit::createNew(string fileName, string type) {
    bool validNameString = true;
    bool validYearInt = true;
    bool validStatClearInt = true;
    string name, sc;
    int year, statClear;
    //sets type based strings
    if (type == "Member") {
        sc = "Clearance";
    }
    else {
        sc = "Status";
    }
    
    ofstream file(fileName, ios::app);
    
    //checks for valid name
    while(validNameString) {
    cout << "Enter the new " << type << "'s Name (first.last)" << endl;
    cin.ignore();
    getline(cin, name);
        validNameString = !validName(name);
        if (validNameString) {
            cout << "Invalid input, try again" << endl;
        }
    }
    
    //checks for valid year
    while(validYearInt) {
    cout << "Enter the " << type << "'s Year(integer)." << endl;
    cin >> year;
        validYearInt = !validYear(year);
        if (validYearInt) {
            cout << "Invalid input, try again" << endl;
        }
    }
    
    //checks for valid status/clearance
    while(validStatClearInt) {
    cout << "Enter the " << type << "'s "<< sc <<"(integer)." << endl;
    cin >> statClear;
        validStatClearInt = !validStatus(statClear);
        if (validStatClearInt) {
            cout << "Invalid input, try again" << endl;
        }
    }
    sc = ", " + sc + ": ";
    
    //adds the new applicant/member to the file
    file << name << ' ' << year << ' ' << statClear << endl;
    file.close();
}

/*
This function takes in a file name (hardcoded as applicants.txt or members.txt) and a type (Member/Applicant) and then opens up a file with the fileName, It then prompts the user for the name to edit, checks the validity of the name, then transfers all of the data from one document to the next while making the changes to the specified person. Finally, it renames the new document.
*/
void CreateEdit::edit(string fileName, string type) {
    bool isNameValid = true;
    bool isyearValid = true;
    bool isStatClearValid = true;
    bool isToEditValid = true;
    string name, fname, gname, newFileName, sc;
    newFileName = "new"+fileName;
    int year, fyear;
    int statClear, fStatClear;
    bool found = false;
    
    //checks the validity of the name you want to edit, along with the break option before the fstream files are opened
    while(isToEditValid) {
    cout << "Enter the name (first.last) of the " << type << " you want to edit(break: \"b\"):" << endl;
    cin.ignore();
    getline(cin, gname);
        if (gname == "b") {
            return;
        }
        if (type == "Member" ) {
            if (!isMember(gname)) {
                cout << "Invalid name, please try again" << endl;
            }
            else {
                isToEditValid = !isToEditValid;
            }
        }
        if (type == "Applicant") {
            if (!isApplicant(gname)) {
                cout << "Invalid name, please try again" << endl;
            }
            else {
                isToEditValid = !isToEditValid;
            }
        }
    }
    
    ifstream file(fileName, ios::in);
    ofstream newFile(newFileName, ios::out);
    
    
    if (type == "Member") {
        sc = " clearnace ";
    }
    else {
        sc = " status ";
    }
    //searches for the name of the person to edit
    while (file >> name >> year >> statClear) {
        if (name == gname) {
            found = true;
            //what the new name is, or to keep old
            while(isNameValid) {
            cout << "Enter " << type << "'s new name (first.last) (type \".\" to keep old)" << endl;
            cin.ignore();
            getline(cin, fname);
                isNameValid = !validName(fname);
                if (isNameValid) {
                    cout << "Invalid input, try again" << endl;
                }
            }
            //setting new name
            if (fname != ".") {
                name = fname;
            }
            //what the new year is or to keep old
            while(isyearValid) {
            cout << "Enter " << type << "'s new year (type -1 to keep last)" << endl;
            cin >> fyear;
                isyearValid = !validYear(fyear);
                if (isyearValid) {
                    cout << "Invalid input, try again" << endl;
                }
            }
            //setting new year
            if (fyear != -1) {
                year = fyear;
            }
            //what the status/clearnace is or to keep old
            while(isStatClearValid) {
            cout << "Enter " << type << "'s new" << sc << "(type 0 to keep last)" << endl;
            cin >> fStatClear;
                if (type == "Applicant") {
                    isStatClearValid = !validStatus(fStatClear);
                }
                else {
                    isStatClearValid = !validClearance(fStatClear);
                }
                
                if (isStatClearValid) {
                    cout << "Invalid input, try again" << endl;
                }
            }
            //setting new status/clearance
            if (fStatClear != -1) {
                statClear = fStatClear;
            }
        }
        //adding all info to the new doc
        newFile << name << ' ' << year << ' ' << statClear << endl;
    }
    if (!found) {
        cout << "No applicant by that name found" << endl;
    }
    
    //closes the files, removes the old file, and renames the ne file
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

/*
 This function handles the deletion of the stored information. The user is prompted to choose which, if any files to delete. After the inital choice, they will be given a final chance to stop before deleting the data, else the data will be deleted.
 */
void CreateEdit::deleteFile() {
    int option;
    //deletion options
    cout << "1.Delete Members/Comments file" << endl;
    cout << "2.Delete Applicants file" << endl;
    cout << "3.Delete Comment file" << endl;
    cout << "4.Delete All files" << endl;
    cout << "5.Back" << endl;
    cin >> option;
    
    //enactment of the deletion based of the choice
    if (option == 1) {
        string decision;
        cout << "Are you sure?[Y]es[N]o" << endl;
        cout << "if you delete the members file you also delete the comments" << endl;
        cin >> decision;
        if (decision == "y" || decision == "Y"){
            ofstream comments("comments.txt");
            ofstream member("members.txt");
            std::remove("members.txt");
            std::remove("comments.txt");
            cout << "Successfully Completed!" << endl;
            member.close();
            comments.close();
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
            ofstream comment("comments.txt");
            std::remove("comments.txt");
            cout << "Successfully Completed!" << endl;
            comment.close();
        }
    }
    if (option == 4) {
        string decision;
        cout << "Are you sure?[Y]es[N]o" << endl;
        cin >> decision;
        if (decision == "y" || decision == "Y"){
            ofstream comments("comments.txt");
            std::remove("comments.txt");
            ofstream applicant("applicants.txt");
            std::remove("applicants.txt");
            ofstream member("members.txt");
            std::remove("members.txt");
            cout << "Successfully Completed!" << endl;
            applicant.close();
            member.close();
            comments.close();
        }
        
    }
}

