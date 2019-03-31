#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

bool knownN = false;
bool median = false;
vector<int> vectorius;
string answer = "";

struct studentas{
    string name;
    string surname;
    int h1;
    int h2;
    int h3;
    int h4;
    int h5;
    float exam;
} student;

void skaitau() {
    ifstream inFile;
    inFile.open("Students.txt");
    string line;
    inFile>>line;

    if (inFile.is_open()){
        getline(inFile,line);
    }

    while ( getline (inFile,line) ){
     inFile>>student.name>>student.surname>>student.h1>>student.h2>>student.h3>>student.h4>>student.h5>>student.exam;
    }
    inFile.close();
}

void credentials(){
    cout<<"Enter your name and surname"<<endl;
    cin>>student.name>>student.surname;
}

void useMedian() {
    cout<<"Wanna use median?  (yes or no)"<<endl;
    cin>>answer;
    if(answer == "yes" || answer == "Yes" || answer == "YES"){
        median = true;
    }
}

void score(){
    cout<<"Enter exam score"<<endl;
    cin>>student.exam;
}

void fillHomeworkVector(){
    int tempo;
    bool enter = false;
    cout<<"Enter homework grade"<<endl;
    cin>>tempo;
    vectorius.push_back(tempo);
    while(enter == false){
        cout<<"Do you want to enter another grade? (yes or no)?"<<endl;
        cin>>answer;
        if(answer == "yes" || answer == "Yes" || answer == "YES"){
            cin>>tempo;
            vectorius.push_back(tempo);
        }
        else {
            enter = true;
        }
    }
}

float medianSum(){
    float medianSum = 0;

    if(vectorius.size() % 2 == 0){
        sort(vectorius.begin(), vectorius.end());
        int indicator = vectorius.size() / 2;
        medianSum = (vectorius[indicator] + vectorius[indicator-1]) / 2;
    } else{
        sort(vectorius.begin(), vectorius.end());
        int indicator = vectorius.size() / 2;
        medianSum = vectorius[indicator];
    }

    return medianSum;
  }

float finalPoints() {
     int homeworkSum = 0;
     float averageOfHomework = 0;
     for(int i = 0; i < vectorius.size() ; i++){
            homeworkSum += vectorius[i];
        }
        averageOfHomework = homeworkSum / vectorius.size();

       return 0.4 * averageOfHomework + 0.6 * student.exam;
}

void printTable(){
    useMedian();
    float sum = medianSum();
    float finals = finalPoints();

  if(median){

    cout<<left<<setw(30)<<"Surname";
    cout<<left<<setw(30)<<"Name";
    cout<<left<<setw(30)<<"Final points (Avg.)";
    cout<<left<<setw(30)<<"Final points (Med.)"<<endl;

    cout<<left<<setw(30)<<student.surname;
    cout<<left<<setw(30)<<student.name;
    cout<<left<<setw(30)<<setprecision(2)<<finals;
    cout<<left<<setw(30)<<setprecision(2)<<sum<<endl;

    }
    else{

    cout<<left<<setw(30)<<"Surname";
    cout<<left<<setw(30)<<"Name";
    cout<<left<<setw(30)<<"Final points (Avg.)"<<endl;

    cout<<left<<setw(30)<<student.surname;
    cout<<left<<setw(30)<<student.name;
    cout<<left<<setw(30)<<setprecision(2)<<finals;

    }
  }


int main()
{
    credentials();
    score();
    fillHomeworkVector();
    printTable();
 }
