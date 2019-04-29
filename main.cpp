#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <stdlib.h>
#include <list>
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

int randomNum(){
return  rand() % 10 + 1;
}

void generateFilesWithStudents100(){
    ofstream ofFile;
    ofFile.open("100studu.txt");
    for (int i=0; i<100; i++){
        string name = "Name";
        string surname = "Surname";
        int h1 = randomNum();
        int h2 = randomNum();
        int h3 = randomNum();
        int h4 = randomNum();
        int h5 = randomNum();
        int exam = randomNum();
        ofFile << name
               <<i
               <<" "
               << surname
               << i
               << " "
               << h1
               << " "
               << h2
               << " "
               << h3
               << " "
               << h4
               << " "
               << h5
               << " "
               << exam
               << " "
               <<endl;
    }
    ofFile.close();

}
void getinfo(){
    ifstream file("100studu.txt");
    ofstream ofFile;
    ofFile.open("100failed.txt");
std::string name;
std::string surname;
string result;
float averageOfHomework;
int h1,h2,h3,h4,h5,exam;
double finalResult;
if(file.is_open())
{
    int suma = 0;
    int examSum = 0;
    while(file >> name >> surname >> h1 >> h2 >> h3 >> h4 >> h5 >> exam){
        suma += h1 + h2 + h3 + h4 + h5;
        examSum += exam;
        averageOfHomework = suma /5;
        finalResult= 0.4 * averageOfHomework + 0.6 * examSum;
        if ( finalResult >= 5.0){
            result = "passed";
        } else {
            result = "failed";
        }
        ofFile << name << " " << surname << " " << result << endl;
        suma = 0;
        examSum = 0;
        averageOfHomework = 0;
        finalResult = 0;
        }

    }
    ofFile.close();
    file.close();
}

void generateFilesWithStudents1000(){
    ofstream ofFile;
    ofFile.open("1000studu.txt");
    for (int i=0; i<1000; i++){
        string name = "Name";
        string surname = "Surname";
        int h1 = randomNum();
        int h2 = randomNum();
        int h3 = randomNum();
        int h4 = randomNum();
        int h5 = randomNum();
        int exam = randomNum();
        ofFile << name
               <<i
               <<" "
               << surname
               << i
               << " "
               << h1
               << " "
               << h2
               << " "
               << h3
               << " "
               << h4
               << " "
               << h5
               << " "
               << exam
               << " "
               <<endl;
    }
    ofFile.close();

}
void generateFilesWithStudents10000(){
    ofstream ofFile;
    ofFile.open("10000studu.txt");
    for (int i=0; i<10000; i++){
        string name = "Name";
        string surname = "Surname";
        int h1 = randomNum();
        int h2 = randomNum();
        int h3 = randomNum();
        int h4 = randomNum();
        int h5 = randomNum();
        int exam = randomNum();
        ofFile << name
               <<i
               <<" "
               << surname
               << i
               << " "
               << h1
               << " "
               << h2
               << " "
               << h3
               << " "
               << h4
               << " "
               << h5
               << " "
               << exam
               << " "
               <<endl;
    }
    ofFile.close();

}
void generateFilesWithStudents100000(){
    ofstream ofFile;
    ofFile.open("100000studu.txt");
    for (int i=0; i<100000; i++){
        string name = "Name";
        string surname = "Surname";
        int h1 = randomNum();
        int h2 = randomNum();
        int h3 = randomNum();
        int h4 = randomNum();
        int h5 = randomNum();
        int exam = randomNum();
        ofFile << name
               <<i
               <<" "
               << surname
               << i
               << " "
               << h1
               << " "
               << h2
               << " "
               << h3
               << " "
               << h4
               << " "
               << h5
               << " "
               << exam
               << " "
               <<endl;
    }
    ofFile.close();

}

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

void choose(){
cout<<"Do you want to generate exam score or write it in(if generate write - no; if write it in write - yes)?"<<endl;
cin>>answer;
if(answer == "yes" || answer == "Yes" || answer == "YES")
    score();
else{
    cout<<"Random exam grade"<<endl;
    student.exam=randomNum();
    cout<<student.exam<<endl;
}

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

void gen(){
cout<<"Do you want to generate homework grades or write them in(if generate write - no; if write them in write - yes?"<<endl;
cin>>answer;
if(answer == "yes" || answer == "Yes" || answer == "YES")
    fillHomeworkVector();

else{
    int tempo = 0;
    bool enter = false;
    cout<<"Random grade"<<endl;
    tempo = randomNum();
    cout<<tempo<<endl;
    vectorius.push_back(tempo);
    while(enter == false){
        cout<<"Do you want to generate another grade? (yes or no)?"<<endl;
        cin>>answer;
        if(answer == "yes" || answer == "Yes" || answer == "YES"){
            tempo = randomNum();
            cout<<tempo<<endl;
            vectorius.push_back(tempo);
        }
        else {
            enter = true;
        }
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
//    randomNum();
//    credentials();
//    choose();
//    gen();
//    printTable();
    generateFilesWithStudents100();
    getinfo();
  //  generateFilesWithStudents1000();
 //   generateFilesWithStudents10000();
  //  generateFilesWithStudents100000();
 }
