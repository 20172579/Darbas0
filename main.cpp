#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

void skaitau() {
    int h1,h2,h3,h4,h5,exam;
    string name,surname;
    ifstream inFile;
    inFile.open("Students.txt");
    string line;
    inFile>>line;

    if (inFile.is_open())
        getline(inFile,line);
  {
    while ( getline (inFile,line) )
    {
     inFile>>name>>surname>>h1>>h2>>h3>>h4>>h5>>exam;
    }
    inFile.close();
  }

  cout<<name<<surname<<h1<<h2<<h3<<h4<<h5<<exam<<endl;
}

int blabla(){
    int a,b;
    a = 5;
    b = 7;
    return a+b;
}

int main()
{
    string name;
    string surname;
    int n=1000;
    float exam = 0.0;
    bool median = false;
    float medianSum = 0;
    string answer;
    float homeworkSum = 0;
    bool knownN = false;
    int tempoI = 0;
    int home = 0;



    float averageOfHomework  = 0.0;
   skaitau();

   int rez;
   rez = blabla();

cout<<rez<<endl;

cout<<name<<" "<<surname<<endl;
    cout<<"Enter your name and surname"<<endl;
    cin>>name>>surname;

    cout<<"Enter exam score"<<endl;
    cin>>exam;

    cout<<"Do you know homework amount (n), (yes or no)"<<endl;
    cin>>answer;

    if(answer == "yes" || answer == "Yes" || answer == "YES"){
        knownN = true;
        cout<<"Enter n"<<endl;
        cin>>n;
        cout<<"Enter grades"<<endl;
    }
    int homework[n];

    if(knownN){
        for(int i = 0; i < n ; i++){
            cin>>homework[i];
        }
    }
    else {
        n = 0;
        while(knownN == false){
            cout<<"Do you want to enter n? (yes or no)?"<<endl;
            cin>>answer;
            if(answer == "yes" || answer == "Yes" || answer == "YES"){
            cin>>homework[tempoI];
            tempoI++;
            n++;
            }else{
                knownN = true;
            }
        }
    }

    cout<<"Use median? (yes or no)"<<endl;
    cin>>answer;

    if(answer == "yes" || answer == "Yes" || answer == "YES"){
        median = true;
    }

    if(n % 2 == 0){
        sort(homework, homework+n);
        int indicator = n / 2;
        medianSum= (homework[indicator] + homework[indicator-1])/2;
    } else{
        sort(homework, homework+n);
        int indicator = n / 2;
        medianSum = homework[indicator];

    }
        for(int i = 0; i< n ; i++){
            homeworkSum += homework[i];
        }
        averageOfHomework = homeworkSum / n;

        float final_points = 0.4 * averageOfHomework + 0.6 * exam;


    if(median){

    cout<<left<<setw(30)<<"Surname";
    cout<<left<<setw(30)<<"Name";
    cout<<left<<setw(30)<<"Final points (Avg.)";
    cout<<left<<setw(30)<<"Final points (Med.)"<<endl;

    cout<<left<<setw(30)<<surname;
    cout<<left<<setw(30)<<name;
    cout<<left<<setw(30)<<setprecision(2)<<final_points;
    cout<<left<<setw(30)<<setprecision(2)<<medianSum<<endl;

    }else{

    cout<<left<<setw(30)<<"Surname";
    cout<<left<<setw(30)<<"Name";
    cout<<left<<setw(30)<<"Final points (Avg.)"<<endl;

    cout<<left<<setw(30)<<surname;
    cout<<left<<setw(30)<<name;
    cout<<left<<setw(30)<<setprecision(2)<<final_points;

    }
}
