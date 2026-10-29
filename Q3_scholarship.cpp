/*
 * Name       : Ayesha Qaisar
 * Reg No     : L1S26BSCS0110
 * Assignment : 02 - File Handling
 * Question   : Q3 - Scholarship Report
 */

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

int main() {
    char path[100], name[30], topName[30];
    int number;
    int count = 0;
    int eligible = 0;
    double cgpa, sum = 0, topCGPA = -1;

    cout<< "Enter the file name: ";
    cin.getline(path, 100);

    ifstream inFile(path);

    if(!inFile.is_open()){
        cout<< "Could not open "<<path<<"!";
        return 0;
    }

    inFile>>number;

    if(number>30){
        cout<<"Too many students!";
        return 0;
    }

 inFile.ignore(100, '\n');

 ofstream outFile("scholarship.txt");

 for(int i = 0;i<number;i++) {
 inFile.getline(name, 30, ',');
 if (!inFile)
 break;
 inFile>>cgpa;
 if (!inFile)
 break;
 inFile.ignore(100, '\n');

 cout<<"["<<name<<"] CGPA: "<<cgpa<<endl;
   sum=sum+cgpa;
   count++;
 if(cgpa >= 3.50){
   outFile<<name<<","<<cgpa<<endl;
   eligible++;
 }
if(cgpa>topCGPA){
    topCGPA=cgpa;
    strcpy(topName, name);
 }
 }
if(count<number){
 cout<<"Warning: only "<<count<<" of "<<number<<" records found."<<endl;
 }

inFile.close();
outFile.close();

if(count == 0){
 cout<< "No students found!";
return 0;
 }

cout<<"Students: "<<count<<endl;
cout<<"Average CGPA: "<<sum/count<<endl;
cout<<"Eligible for scholarship: "<<eligible<<endl;
cout<<"Top student: "<<topName<<" (" <<topCGPA<< ")"<<endl;

 return 0;
}
