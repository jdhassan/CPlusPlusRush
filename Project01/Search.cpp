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
 This Function takes in a file name (hard coded as "members.txt" or "applicants.txt" and a type (either Member or Applicant). It will then open up the correct fstream file, promtp the user for the name they are looking for, check the validity of the name (can be set in the Validate.hpp), and if it is a member/applicant, the function will iterate through the member/applicant file and will append all of the members/applicants with that name into a return-string.
 */
string Search::searchByName(string fileName, string type) {
    ifstream file(fileName, ios::in);
    string name, fname, sc, returnString;
    int year, statClear;
    bool found = false;
    bool validN = true;
    
    //sets type based strings, and checks validity of the name in the proper database, if it invalid will continue to prompt until a valid name is given, and will return empty string if break command given.
    if (type == "Member") {
        sc = ", Clearance: ";
        while (validN) {
          cout << "Input search name(break: \"break\"):" << endl;
          cin >> fname;
            if (fname == "break") {
                return "Broke search\n\n";
            }
            else {
                validN = !isMember(fname);
              if (validN) {
                  cout << "Invalid name, try again" << endl;
              }
          }
        }
    }
    else {
        sc = ", Status: ";
        while (validN) {
          cout << "Input search name(break: \"break\"):" << endl;
          cin >> fname;
            if (fname == "break") {
                return "Broke search\n\n";
            }
              validN = !isApplicant(fname);
              if (validN) {
                  cout << "Invalid name, try again" << endl;
              }
          }
    }
    
    //cycles through the .txt fstream doc
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
    //the string with all of the matching people
    return returnString;
}

/*
This Function takes in a file name (hard coded as "members.txt" or "applicants.txt" and a type (either Member or Applicant). It will then open up the correct fstream file, promtp the user for the year of the applicant/member they are looking for, with make sure the year is within the proper bounds (can be set in the Validate.hpp), and if it is, will then iterate through the fstream doc and return all of the found people on a string.
*/
string Search::searchByYear(string fileName, string type) {
    string name, returnString, sc;
    int year, fyear, statClear;
    bool found = false;
    bool isYValid = true;
    ifstream file(fileName);
    
    if (type == "Member") {
        sc = ", Clearance: ";
    }
    else {
        sc = ", Status: ";
    }
    
    //Takes in the year, check if the year is a valid int, if it is not valid, it will continuously prompt the user for a new, valid int, or the user can use the break command to break out of the search.
    while(isYValid) {
    cout << "Enter search year(break: -1):" << endl;;
    cin >> fyear;
        if (fyear == -1) {
            return "Broke search";
        }
        isYValid = !validYear(fyear);
        if (isYValid) {
            cout << "Invalid year, try again" << endl;
        }
    }
    
    //cycles through fstream doc
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
    //string to return with people found by search
    return returnString;
}

/*
This Function takes in a file name (hard coded as "members.txt" or "applicants.txt" and a type (either Member or Applicant). It will then open up the correct fstream file, promtp the user for the status or clearance level, based on the string "type" given, and once inputed, will check the validity of these (can be set in the Validate.hpp), and if they are not valid will prompt the user again for input. The user can use the break command to exit the loop.
*/
string Search::seachBystatClear(string fileName, string type) {
    string name, returnString, sc;
    int year, fstatClear, statClear;
    bool found = false;
    bool validType = true;
    ifstream file(fileName);
    
    //sets type based string along with checking the validity of the input
    if (type == "Member") {
        sc = "Clearance";
        while (validType) {
        cout << "Enter " << sc << "(break: -1):" << endl;;
           cin >> fstatClear;
            if (fstatClear == -1) {
                return "Broke search";
            }
            validType = !validClearance(fstatClear);
            if(validType) {
                cout << "Invalid Clearance level, try again" << endl;
            }
        }
    }
    else {
        sc = "Status";
        while (validType) {
        cout << "Enter " << sc << "(break: -1):" << endl;;
           cin >> fstatClear;
            if (fstatClear == -1) {
                return "Broke search";
            }
            validType = !validStatus(fstatClear);
            if(validType) {
                cout << "Invalid Status, try again" << endl;
            }
        }
    }
    
   
    
    sc = ", " + sc + ": "; //changes for athsetitic reasons
    
    //cycles though the fstream doc
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

/*
This Function takes in a file name (hard coded as "members.txt" or "applicants.txt" and a type (either Member or Applicant). It will then open up the correct fstream file, and will return a string containing all names, years, and status/clearance (based on "type").
*/
string Search::displayAll(string fileName, string type) {
    int year, statClear;
    string name, sc, returnString;
    ifstream file(fileName, ios::in);
    bool empty = true;
    //sets type based strings
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
