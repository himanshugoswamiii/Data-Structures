#include <iostream>
#include <string>
using namespace std;
int hashcode(string key){
    int index=1;
    int code=0;
    for(char ch : key)
    {
        code+=(int(ch)+index+10);        
    }
    return code;
}
int main (int argc, char *argv[])
{

    string str;
    cout<<"Enter the string \n";
    getline(cin,str);
    cout<<"Hashcode is :"<<hashcode(str);
    
    return 0;
}
