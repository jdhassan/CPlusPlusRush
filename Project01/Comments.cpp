//
//  Comments.cpp
//  Project01
//
//  Created by Isaac Freedman Reed on 4/1/20.
//  Copyright © 2020 Isaac Freedman Reed. All rights reserved.
//

#include "Comments.hpp"

#include <cstdio>
#include <fstream>
#include <regex>

void Comments::makeComment() {
    string Cname, name, comment, isPositive, output;
    bool isPos;
    bool isNameValid = true;
    bool isAppNameValid = true;
    bool isValidBool = true;
    ofstream comments("comments.txt", ios::app);
    
    while(isNameValid) {
        cout << "Please input your name" << endl;
        cin >> Cname;
        isNameValid = !(validName(Cname) && isMember(Cname));
        if(isNameValid) {
            cout << "Name is not in the system, try again" << endl;
        }
    }
    
    while(isAppNameValid) {
        cout << "Please input applicants name" << endl;
        cin >> name;
        isAppNameValid = !(validName(name) && isApplicant(name));
        if(isAppNameValid) {
            cout << "Name is not in the system, try again" << endl;
        }
    }
    
    while (isValidBool) {
        cout << "Is this comment positive (p) or negative (n)" << endl;
        cin >> isPositive;
        if (isPositive == "p" || isPositive == "P") {
            isPos = true;
            isValidBool = false;
        }
        if (isPositive == "n" || isPositive == "N") {
            isPos = false;
            isValidBool = false;
        }
        if(isValidBool) {
            cout << "not a valid bool, try again" << endl;
        }
    }
    
    cout << "Enter your comment" << endl;
    cin >> comment;
    
   
    comments << Cname << ' ' << name << ' ' << to_string(isPos) << ' '<< comment << endl;
    comments.close();
}

string Comments::getComment() {
    string fname, name, cname, output, c;
    bool isPos;
    bool byApp = true;
    bool sort = false;
    bool byPos = false;
    int choice;
    cout << "Would you like to use parameter?" << endl;
    cout << "1.By Applicants name" << endl;
    cout << "2.By Applicant name and positive only" << endl;
    cout << "3.By Applicant name and negative only" << endl;
    cout << "4.By Commentor name" << endl;
    cout << "5.By Commentor name and positive only" << endl;
    cout << "6.By Commentor name and negative only" << endl;
    cout << "7.No Parameters" << endl;
    cin >> choice;
    
    switch (choice) {
        case 1:
            cout << "Input applicants name:" << endl;
            cin >> fname;
            sort = false;
            break;
        case 2:
            cout << "Input applicants name:" << endl;
            cin >> fname;
            sort = true;
            byPos = true;
            break;
        case 3:
            cout << "Input applicants name:" << endl;
            cin >> fname;
            sort = true;
            byPos = false;
            break;
        case 4:
            cout << "Input commentors name:" << endl;
            cin >> fname;
            byApp = false;
            sort = false;
            break;
        case 5:
            cout << "Input commentors name:" << endl;
            cin >> fname;
            sort = true;
            byPos = true;
            byApp = false;
            break;
        case 6:
            cout << "Input commentors name:" << endl;
            cin >> fname;
            sort = true;
            byPos = false;
            byApp = false;
            break;
        case 7:
            sort = false;
            name = "empty";
        default:
            cout << "Invalid choice" << endl;
            getComment();
            break;
    }
    ifstream comments("comments.txt");
    
    if (name == "empty") {
     while(comments >> cname >> name >> isPos >> c) {
         output.append("Commentor: " + cname + ", Application: " + name + ", Is Comment Positive: " + to_string(isPos) + ".\nComment: " + c);
     }
    }
    else {
    while(comments >> cname >> name >> isPos >> c) {
        if (byApp && !sort) {
            if (cname == fname) {
                output.append("Commentor: " + cname + ", Application: " + name + ", Is Comment Positive: " + to_string(isPos) + ".\nComment: " + c);
            }
        }
        if (byApp && sort && byPos) {
                if (cname == fname && isPos == true) {
                    output.append("Commentor: " + cname + ", Application: " + name + ", Is Comment Positive: " + to_string(isPos) + ".\nComment: " + c);
                }
        }
        if (byApp && sort && !byPos) {
                if (cname == fname && isPos == false) {
                    output.append("Commentor: " + cname + ", Application: " + name + ", Is Comment Positive: " + to_string(isPos) + ".\nComment: " + c);
                }
        }
        if (!byApp && !sort) {
            if (cname == fname) {
                output.append("Commentor: " + cname + ", Application: " + name + ", Is Comment Positive: " + to_string(isPos) + ".\nComment: " + c);
            }
        }
        if (!byApp && sort && byPos) {
                if (cname == fname && isPos == true) {
                    output.append("Commentor: " + cname + ", Application: " + name + ", Is Comment Positive: " + to_string(isPos) + ".\nComment: " + c);
                }
        }
        if (!byApp && sort && !byPos) {
                if (cname == fname && isPos == false) {
                    output.append("Commentor: " + cname + ", Application: " + name + ", Is Comment Positive: " + to_string(isPos) + ".\nComment: " + c);
                }
        }
    }
    }
    return output;
}


bool Comments::isMember(string s) {
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

bool Comments::isApplicant(string s) {
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

bool Comments::validName(string s) {
    return (regex_match(s, regex("^[A-Za-z.]+$")) && (s != ""));
}
