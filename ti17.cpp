#include<iostream>
using namespace std;

class Cost{
private:
    int part;
    double single_cost;
    double total_cost;

public:
    Cost():total_cost(0.0),single_cost(0.0),part(0){}

    void setpart(int my_part){
        part=my_part;
    }
    void setsinglecost(double my_single_cost){
        single_cost=my_single_cost;
    }

    void countcost(int my_single_cost,int my_part){
        total_cost=single_cost*part;
    }

    void outputcost(){
        cout<<fixed<<"The total cost of the service is:"<<total_cost<<" yuan"<<endl;
    }
};

int main(){
    Cost S,J;
    int part1,part2;
    double single_cost1,single_cost2;
    cout<<"Input the part of service S(kuai):"<<endl;
    cin>>part1;
    cout<<"Input the single cost of service S(yuan):"<<endl;
    cin>>single_cost1;
    S.setpart(part1);
    S.setsinglecost(single_cost1);
    S.countcost(single_cost1,part1);
    cout<<"Input the part of service J(kuai):"<<endl;
    cin>>part2;
    cout<<"Input the single cost of service J(yuan):"<<endl;
    cin>>single_cost2;
    J.setpart(part2);
    J.setsinglecost(single_cost2);
    J.countcost(single_cost2,part2);
    S.outputcost();
    J.outputcost();
    return 0;
}