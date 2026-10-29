/*
 * Name       : Ayesha Qaisar
 * Reg No     : L1S26BSCS0110
 * Assignment : 02 - File Handling
 * Question   : Q2 - Parking Report
 */

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

 int main(){
    ifstream infile("parking.txt");
    if(!infile){
        cout<<"parking.txt not found!"<<endl;
        return 1;
    }
    int d,m,y;
    char slash;
    
    infile>>d>>slash>>m>>slash>>y;
    infile.ignore(100,'\n');
    infile.ignore(100,'\n');
    cout<<"Parking Report for "<<d<<"/"<<m<<"/"<<y<<endl;

 ofstream outfile("receipts.txt");
 outfile <<"Receipts for "<<d<<"/"<<m<<'/'<<y<<endl;

 char plate[15];
 char type,colon;
 int inH,inM,outM,outH;
 int cars=0;
 int bikes=0;
 int vehicles=0;
 int total=0;
 int longest=-1;
 char longestPlate[15];

 while (infile>>plate>>type>>inH>>colon>>inM>>outH>>colon>>outM) {
 int start=inH*60+inM;
 int end=outH*60+outM;
 int minutes=end-start;

 int hours=(minutes + 59)/60;
 if(hours == 0)
 hours = 1;
 int fee;
 if(type == 'C') {
  fee=hours*100;
   cars++;  }
 else{
   fee=hours*40;
   bikes++; }

 int actualHours=minutes/60;
 int actualMinutes=minutes%60;
 if(type == 'C')
  cout<<plate<<" Car ";
 else{
  cout<<plate<<" Bike ";
  }

 cout<<actualHours<<" h "<<actualMinutes<<" min Fee: "<<fee<<endl;
 total=total+fee;
  vehicles++;

  if(minutes>longest) {
  longest=minutes;
  strcpy(longestPlate,plate);
  }

 outfile<<plate<< " " <<fee<<endl;
    
 }

  if(vehicles == 0) {
  cout << "No vehicles found!" << endl;
   }
  else {
        cout<<"Vehicles: "<<vehicles<<endl;
        cout<<"Cars: "<<cars<<" Bikes: "<<bikes<<endl;
        cout<<"Total collected: "<<total<<endl;

        cout<<"Longest stay: "<<longestPlate<< " ("<<longest/60<< " h "<<longest%60<<" min)"<<endl;
    }

    infile.close();
    outfile.close();

    return 0;
}








 