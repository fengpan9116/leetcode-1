#include <iostream>
#include <string>

using namespace std;

bool isRotation(string& s1, string& s2){
    if (s1.size() != s2.size() || s1.size() < 1)
        return false;
    if (s1.compare(s2) == 0) return false;
    string ss = s1 + s1;
    auto found = ss.find(s2);
    return found != string::npos;
}

int main()
{
    string s1 = "AACD";
    string s2 = "ACDA";
    string s3 = "AACD";
    string s4 = "CDAA";
   cout << isRotation(s1,s2) << endl; 
   cout << isRotation(s1,s3) << endl;
   cout << isRotation(s1,s4) << endl; 
   
   return 0;
}

