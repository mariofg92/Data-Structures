#include "String.h"
#include <iostream>

using namespace std;

int main(){
	String s1;
	String s2(s1);
    String s3;
    String s4;
    String s5;
    String s6;
    String s7;
    String s8;
    String s9;
    char c;
	cout << s1.length() << endl;
	if (s2.empty())
		cout << "Está vacio" << endl;
    s1.insert(0, s2);
    s2=s1;
    c = s1[2];
    cout << c;
    s2.resize(30, 'a');
    for (int i=0; i < s2.length(); i++)
        cout << s2[i];
    s1.resize(30, 'b');
    for (int i=0; i < s1.length(); i++)
        cout << s1[i];
    cout << endl << endl;
    s3 = s2+s1;
    for (int i=0; i < s3.length(); i++)
        cout << s3[i];
    
    s5.resize(10, 'c');
    s6.resize(30, 'b');
    
    s3 = s3+s5;
    s3 = s3+s6;
    
    s4.resize(10, 'b');
    for (int i=0; i < s4.length(); i++)
        cout << s4[i];
    cout << endl;
    for (int i=0; i < s3.length(); i++)
        cout << s3[i];
    cout << endl << endl << s3.length() << endl << s3.find(s2) << endl << endl << endl;
    
    s8.resize(10, 'd');

    cout << endl << endl << s3.length() << endl << s3.find(s8) << endl << endl << endl; //Funciona bien si no entuentra el String (devuelve npos)


    s3.replace(8, 12, s8);
    for (int i=0; i < s3.length(); i++){
        cout << s3[i];
        if (s3[i]=='\0')
            cout << " Terminador ";
    }
    cout << endl << endl << endl;

    s7 = s3.substr(20, 90);

    for (int i=0; i < s7.length(); i++){
        cout << s7[i];
        if (s7[i]=='\0')
            cout << " Terminador ";
    }
    cout << endl;

    s9.resize(0, 'z');
    //s9.insert(0, s2);

    cout << " Insert ";
    for (int i=0; i < s4.length(); i++){
        cout << s4[i];
        if (s4[i]=='\0')
            cout << " Terminador ";
    }
    cout << endl;

    s7.erase(31, 60); 

    for (int i=0; i < s7.length(); i++){
        cout << s7[i];
        if (s7[i]=='\0')
            cout << " Terminador ";
    }
    cout << endl;

    for (int i=0; i < s7.length(); i++){
        cout << s7[i];
        if (s7[i]=='\0')
            cout << " Terminador ";
    }
    cout << endl;
}
