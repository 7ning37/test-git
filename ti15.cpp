#include <iostream>
#include<string>
using namespace std;

class student
{
private:
    int my_number;
    string my_name;
    int my_age;
    int my_score;
public:
    student():my_number(0),my_name(""),my_age(0),my_score(0){};

    void setnumber(int number){
        my_number=number;
    }

    void setname(string name){
        my_name=name;
    }

    void setage(int age){
        my_age=age;
    }
    
    void setscore(int score){
        my_score=score;
    }

    void show(){
        cout<<"number:"<<my_number<<endl;
        cout<<"name:"<<my_name<<endl;
        cout<<"age:"<<my_age<<endl;
        cout<<"score:"<<my_score<<endl;
    }
};

int main()
{
    student s1,s2;
    int number1,number2,age1,age2,score1,score2;
    string name1,name2;
    cout<<"input the information of student 1:"<<endl;
    cout<<"number:";
    cin>>number1;
    cout<<"name:";
    cin>>name1;
    cout<<"age:";
    cin>>age1;
    cout<<"score:";
    cin>>score1;
    cout<<"\n";
    cout<<"input the information of student 2:"<<endl;
    cout<<"number:";
    cin>>number2;
    cout<<"name:";
    cin>>name2;
    cout<<"age:";
    cin>>age2;
    cout<<"score:";
    cin>>score2;
    cout<<endl;
    s1.setnumber(number1);
    s1.setname(name1);
    s1.setage(age1);
    s1.setscore(score1);
    s2.setnumber(number2);
    s2.setname(name2);
    s2.setage(age2);
    s2.setscore(score2);
    cout<<"input konggejian to show the information of students"<<endl;
    char ch;
    cin.ignore();
    do{
        ch =cin.get();
    }while(ch !=' '&&ch != '\n');
    cout<<"the information of student 1:"<<endl;
    s1.show();
    cout<<endl;
    cout<<"the information of student 2:"<<endl;
    s2.show();
}