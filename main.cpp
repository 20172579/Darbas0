#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    string name;
    string surname;
    int n=1000;
    float exam = 0.0;
    bool median = false;
    int medianSum = 0;
    string answer;
    int homeworkSum = 0;
    bool knownN = false;
    int tempoI = 0;
    int home = 0;
    float averageOfHomework  = 0.0;

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
        medianSum= homework[indicator] + homework[indicator-1];
    } else{
        int indicator = n / 2;
        medianSum = homework[indicator];
        cout<<medianSum<<endl;
    }
        for(int i = 0; i< n ; i++){
            homeworkSum += homework[i];
        }
        averageOfHomework = homeworkSum / n;

        float final_points = 0.4 * averageOfHomework + 0.6 * exam;

    if(median){
    cout<<"Surname     Name          Final points (Avg.) / Final points (Med.) "<<endl;
    cout<<".............................................  "<<endl;
    cout<<surname<<"        "<<name<<"          "<<medianSum<<endl;
    }else{
        cout<<"Surname     Name          Final points (Avg.)  "<<endl;
    cout<<".............................................  "<<endl;
    cout<<surname<<"   "<<name<<"        "<<final_points<<endl;
    }





}
