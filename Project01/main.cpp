//
//  main.cpp
//  Project01
//
//  Created by Isaac Freedman Reed on 3/20/20.
//  Copyright © 2020 Isaac Freedman Reed. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstdio>
#include "Search.hpp"
#include "CreateEdit.hpp"
#include "Comments.hpp"

static int CLEARANCE_LEVEL_NEEDED_TO_GET_COMMENTS = 2;
using namespace std;

void addSpace() {
    cout << "" << endl;
}

bool highEnoughClearance();

void commentDirectory();


void applicantOptionDirectory();
void memberOptionDirectory();
void quit();
void searchDirectory(int option);

bool firstMessageShown = false;
int main()
{
    if (!firstMessageShown) {
        cout << "Welcome to rush database" << endl;
        cout << "Press enter to continue" << endl;
        cin.get();
        firstMessageShown = true;
    }
    
    addSpace();
    CreateEdit * ce = new CreateEdit();
    int choice;
    cout << "1.Applicant Options" << endl;
    cout << "2.Member Options" << endl;
    cout << "3.Delete File(s)" << endl;
    cout << "4.Comment Options" << endl;
    cout << "5.Exit Program" << endl;
    cin >> choice;
    
    addSpace();
    switch (choice){
        case 1:
            applicantOptionDirectory();
            break;
        case 2:
            memberOptionDirectory();
            break;
        case 3:
            ce->deleteFile();
            main();
            break;
        case 4:
            commentDirectory();
        case 5:
            quit();
            break;
        default:
            cout << "Invalid Choice" << endl;
            addSpace();
            main();
            break;
            
            
    }
}

void applicantOptionDirectory () {
    addSpace();
    CreateEdit * ce = new CreateEdit();
    int choice;
    cout << "1.Add a new Applicant" << endl;
    cout << "2.Applicant Search Directory" << endl;
    cout << "3.Edit Applicant" << endl;
    cout << "4.Back" << endl;
    cin >> choice;
    
    addSpace();
    switch (choice) {
        case 1:
            ce->createNew("applicants.txt", "Applicant");
            break;
        case 2:
            searchDirectory(1);
            break;
        case 3:
            ce->edit("applicants.txt", "Applicant");
            break;
        case 4:
            break;
        default:
            cout << "Invalid choice" << endl;
            applicantOptionDirectory();
            break;
    }
    main();
}

void memberOptionDirectory() {
    addSpace();
    CreateEdit * ce = new CreateEdit();
    int choice;
    cout << "1.Add new Member" << endl;
    cout << "2.Member Search Directory " << endl;
    cout << "3.Edit Member" << endl;
    cout << "4.Back" << endl;
    cin >> choice;
    
    addSpace();
    switch (choice) {
        case 1:
            ce->createNew("members.txt", "Member");
            break;
        case 2:
            searchDirectory(2);
            break;
        case 3:
            ce->edit("members.txt", "Member");
            break;
        case 4:
            break;
        default:
            cout << "Invalid choice" << endl;
            memberOptionDirectory();
            break;
    }
    main();
}

void searchDirectory(int option)
{
    Search * s = new Search();
    string fileName, type;
    int choice;
    addSpace();
    if (option == 1) {
        fileName = "applicants.txt";
        type = "Applicants";
    }
    else {
        fileName = "members.txt";
        type = "Members";
    }
        cout << "1.Search by name" << endl;
        cout << "2.Search by year" << endl;
        cout << "3.Search by status" << endl;
        cout << "4.Display all applicants" << endl;
        cout << "5.Back" << endl;
        cout << "6.Exit program" << endl;
        cin >> choice;
        
        addSpace();
        switch (choice){
            case 1:
                cout << s->searchByName(fileName, type);
                break;
            case 2:
                cout <<
                s->searchByYear(fileName, type);
                break;
            case 3:
                cout << s->seachBystatClear(fileName, type);
                break;
            case 4:
                cout << s->displayAll(fileName, type);
                break;
            case 5:
                break;
            case 6:
                quit();
                break;
            default:
                cout << "Invalid option" << endl;
                searchDirectory(1);
                break;
        }
        main();
}

void commentDirectory() {
    int choice;
    Comments * c = new Comments();
    cout << "1.Add New Comment" << endl;
    cout << "2.Search Comments" << endl;
    cout << "3.How many positve and negative comments" << endl;
    cout << "4.Back" << endl;
    cin >> choice;
    
    switch (choice) {
        case 1:
            c->makeComment();
            break;
        case 2:
            if(highEnoughClearance()) {
            cout << c->getComment() << endl;
            }
            else {
                cout << "Not high enough clearance, or invalid name" << endl;
            }
            break;
        case 3:
            if (highEnoughClearance()) {
                cout << c->getNumberTypes() << endl;
            }
            else {
                cout << "Not high enough clearance, or invalid name" << endl;
            }
            break;
        case 4:
            break;
        default:
            cout << "Invalid input" << endl;
            commentDirectory();
            break;
    }
    main();
}



void quit()
{
    addSpace();
    cout << "Thank you for using rush application database" << endl;
    cin.get();
    exit(1);
}

bool highEnoughClearance() {
    int year, clearance;
    string name, fname;
    cout << "Input your name" << endl;
    cin >> fname;
    
    ifstream member("members.txt");
    
    while (member >> name >> year >> clearance) {
        if (fname == name) {
            return clearance >= CLEARANCE_LEVEL_NEEDED_TO_GET_COMMENTS;
        }
    }
    return false;
}








