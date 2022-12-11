#include "iostream"
#include <cstdio>
#include <fstream>
#include <ios>
#include <string>
using namespace std;

class Node{
public:
    string timestamp;
    string name;
    int age;
    int pref1;
    int pref2;
    string vtype;
    int petrol;
    string air;
    Node* next;

    // Constructor
    Node(string time,string Na,int a,int p1,int p2,string vty,int pet,string ai){
        timestamp=time;
        name=Na;
        age=a;
        pref1=p1;
        pref2=p2;
        vtype=vty;
        petrol=pet;
        air=ai;
        next=NULL;
    }
};




int main ()
{
    
    ifstream myfile("Satellite_data.csv");
    string s;
    
    getline(myfile,s); // So that we don't take the first row
    while (myfile.peek()!=EOF)
    {
        getline(myfile,s,',');

    }

    myfile.close();
    // 
    return 0;
}
