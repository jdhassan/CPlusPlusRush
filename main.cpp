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

using namespace std;

void creatNewApplicant();
void searchByName();
void searchByStatus();
void searchByYear();
void quit();
void displayall();
void search();
void deleteFile();

int main()
{
    
    int choice;
    cout << "1.Input a new applicant" << endl;
    cout << "2.Search database for applicant" << endl;
    cout << "3.Clear Log" << endl;
    cout << "4.Exit Program" << endl;
    cin >> choice;
    
    switch (choice){
        case 1:
            creatNewApplicant();
            break;
        case 2:
            search();
            break;
        case 3:
            deleteFile();
            break;
        case 4:
            quit();
            break;
            
            cin.get();
            
            
    }
}

void creatNewApplicant()
{
    string name;
    int year;
    int status;
    ofstream newapplicant("applicants.txt", ios::app);
    
    cout << "Enter the new applicant's name" << endl;
    cin >> name;
    
    cout << "Enter the applicant's year." << endl;
    cin >> year;
    
    cout << "Enter the applicant's status." << endl;
    cin >> status;
    
    
    newapplicant << name << ' ' << year << ' ' << status << endl;
    newapplicant.close();
    main();
}

void searchByName()
{
    ifstream applicant("applicants.txt");
    string name;
    string str, line;
    int year, offset;
    int status;
    bool found = false;
    cout << "Enter the applicants's name:";
    cin >> str;
    
    while (applicant >> name >> year >> status){
        if (str == name){
            found = true;
            cout << "Applicant found" << endl;
            cout << "Name" << ' ' << "Year" << ' ' << "Status" << endl;
            cout << "---------------" << endl;
            cout << name << ' ' << year <<  ' ' <<  status << endl;
        }
    }
    
    if (!found){
            cout << "Nobody under that name exists" << endl;
            
        }
    main();
}


void searchByYear()
{
    ifstream applicant("applicants.txt");
    string name;
    int year ;
    int fyear;
    int status;
    bool found = false;
    cout << "Enter the year of an applicant:";
    cin >> fyear;
    while (applicant >> name >> year >> status){
        if (fyear == year){
            found = true;
            cout << "Applicant(s) found" << endl;
            cout << "Name" << ' ' << "Year" << ' ' << "Status" << endl;
            cout << "---------------" << endl;
            cout << name << ' ' << year << ' ' << status << endl;
        }
    }
    if (!found){
            cout << "No applicant(s) found"<< endl;
    }
    cin.get();
    main();
}


void searchByStatus()
{
    ifstream applicant("applicants.txt");
    string name;
    int year ;
    int status;
    int fstatus;
    bool found = false;
    cout << "Enter an applicant's status: ";
    cin >> fstatus;
    while (applicant >> name >> year >> status){
        if (fstatus == status){
            found = true;
            cout << "Applicant found"<< endl;
            cout << "Name" << ' ' << "Year" << ' ' << "Status" << endl;
            cout << "---------------" << endl;
            cout << name << ' ' << year << ' '  << status << endl;;
            
        }
    }
    if (!found){
            cout << "No applicants(s) found" << endl;
    }
    cin.get();
    main();
}


void quit()
{
    
    cout << "Thank you for using rush application database" << endl;
    cin.get();
    exit(1);
}
void displayall()
{
    ifstream applicant("applicants.txt");
    int year;
    int status;
    string name;
    
    cout << "Entire employee database"<< endl;
    cout << "Name" << ' ' << "Year" << ' ' << "Status" << endl;
    cout << "---------------" << endl;
    while (applicant >> name >> year >> status){
        cout << name << ' ' << year << ' ' << status << endl ;
    }
    
    cin.get();
    main();
    
}
void search()
{
    int year;
    string name;
    int status;
    int choice2;
    
    
    cout << "1.Search by name" << endl;
    cout << "2.Search by year" << endl;
    cout << "3.Search by status" << endl;
    cout << "4.Display all applicants" << endl;
    cout << "5.Back" << endl;
    cout << "6.Exit program" << endl;
    cin >> choice2;
    
    switch (choice2){
        case 1:
            searchByName();
            break;
        case 2:
            searchByYear();
            break;
        case 3:
            searchByStatus();
            break;
        case 4:
            displayall();
            break;
        case 5:
            main();
            break;
        case 6:
            quit();
            break;
        case 7:
            deleteFile();
            break;
    }
    
    
    
    
}
void deleteFile()
{
    
    string decision;
    cout << "Are you sure?[Y]es[N]o" << endl;
    cin >> decision;
    if (decision == "y" || decision == "Y"){
        ofstream applicant("applicants.txt");
        std::remove("applicants.txt");
        cout << "Successfully Completed!" << endl;
        applicant.close();
        main();
    }
    else{
        main();
    }
}









