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
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void Comments::makeComment() {
    string Cname, name, comment, isPositive, output;
    output = "";
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
    
    cout << "Enter your comment: ";
    cin.ignore();
    getline(cin, comment);
    replace(comment.begin(), comment.end(), ' ', '*');
    cout << endl;
    output = Cname + "|" + name + "|" + to_string(isPos) + "|" + comment;
    comments << output << endl;
    comments.close();
}

string Comments::getComment() {
    string fname, name, cname, o, c, token, output, posi;
    size_t pos = 0;
    string outputs[4];
    bool byApp = true;
    bool sort = false;
    bool byPos = false;
    int choice;
    string delim = "|";
    cout << "Would you like to use parameter?" << endl;
    cout << "1.By Applicant name" << endl;
    cout << "2.By Applicant name and positive only" << endl;
    cout << "3.By Applicant name and negative only" << endl;
    cout << "4.By Commentor name" << endl;
    cout << "5.By Commentor name and positive only" << endl;
    cout << "6.By Commentor name and negative only" << endl;
    cout << "7.All comments" << endl;
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
            break;
        default:
            cout << "Invalid choice" << endl;
            getComment();
            break;
    }
    ifstream comments("comments.txt");
    
    if (name == "empty") {
     while(comments >> o) {
         int i = 0;
         while ((pos = o.find(delim)) != string::npos) {
             token = o.substr(0, pos);
             outputs[i] = token;
             i++;
             o.erase(0, pos + delim.length());
         }
         replace(o.begin(), o.end(), '*', ' ');
         if (outputs[2] == "1") { posi = "true"; } else {posi = "false";}
         output.append("Commentor: " + outputs[0] + ", Applicant: " + outputs[1] + ", Is Comment Positive: " + posi + ",\nComment: " + o + "\n");
     }
    }
    else {
    while(comments >> o) {
          int i = 0;
                while ((pos = o.find(delim)) != string::npos) {
                    token = o.substr(0, pos);
                    outputs[i] = token;
                    i++;
                    o.erase(0, pos + delim.length());
                }
                replace(o.begin(), o.end(), '*', ' ');
                if (outputs[2] == "1") { posi = "true"; } else {posi = "false";}
        if (byApp && !sort) {
            if (outputs[1] == fname) {
               output.append("Commentor: " + outputs[0] + ", Applicant: " + outputs[1] + ", Is Comment Positive: " + posi + ",\nComment: " + o + "\n");
            }
        }
        if (byApp && sort && byPos) {
            if (outputs[1] == fname && posi == "true") {
                    output.append("Commentor: " + outputs[0] + ", Applicant: " + outputs[1] + ", Is Comment Positive: " + posi + ",\nComment: " + o + "\n");
                }
        }
        if (byApp && sort && !byPos) {
                if (outputs[1] == fname && posi == "false") {
                    output.append("Commentor: " + outputs[0] + ", Applicant: " + outputs[1] + ", Is Comment Positive: " + posi + ",\nComment: " + o + "\n");
                }
        }
        if (!byApp && !sort) {
            if (outputs[0] == fname) {
                output.append("Commentor: " + outputs[0] + ", Applicant: " + outputs[1] + ", Is Comment Positive: " + posi + ",\nComment: " + o + "\n");
            }
        }
        if (!byApp && sort && byPos) {
                if (outputs[0] == fname && posi == "true") {
                    output.append("Commentor: " + outputs[0] + ", Applicant: " + outputs[1] + ", Is Comment Positive: " + posi + ",\nComment: " + o + "\n");
                }
        }
        if (!byApp && sort && !byPos) {
                if (outputs[0] == fname && posi == "false") {
                    output.append("Commentor: " + outputs[0] + ", Applicant: " + outputs[1] + ", Is Comment Positive: " + posi + ",\nComment: " + o + "\n");
                }
        }
    }
    }
    return output;
}

string Comments::getNumberTypes() {
    string fname, token, o;
    string outputs[4];
    int posCount = 0;
    int negCount = 0;
    string delim = "|";
    cout << "Input name of applicant" << endl;
    cin >> fname;
    ifstream comment("comments.txt");
    while(comment >> o) {
        int i = 0;
        size_t pos = 0;
        while ((pos = o.find(delim)) != string::npos) {
                token = o.substr(0, pos);
                outputs[i] = token;
                i++;
                o.erase(0, pos + delim.length());
            }
        if (fname == outputs[1]) {
            if (outputs[2] == "1") {
                posCount++;
            }
            else {
                negCount++;
            }
        }
    }
    string returnString= "";
    returnString.append("Positive Comments: " + to_string(posCount) + ", Negative Comments: " + to_string(negCount));
    return returnString;
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

void Comments::tokenize(string const &str, const char delim,
            vector<string> &out)
{
    // construct a stream from the string
    stringstream ss(str);

    string s;
    while (getline(ss, s, delim)) {
        out.push_back(s);
    }
}
