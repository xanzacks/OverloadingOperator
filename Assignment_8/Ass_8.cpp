//  Zeyu Zhao
//  Xcode on Mac
//  Assignment_8
//
//  Created by zhaozeyu on 08/03/2018.
//  Copyright © 2018 zhaozeyu. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class String{
private:
    char* attribute;
    static int count;
public:
    String();
    String(const char*);
    String(const String&);
    static int a_count();
    ~String();
    static int finda(const char*);
    bool operator>(const String&) const;
    bool operator<(const String&) const;
    bool operator==(const String&) const;
    String& operator=(const String&);
    const char* operator*() const;
    size_t operator!() const;
    String operator+(const String&);
    String operator+=(const String&);
    char operator[](size_t) const;
    friend ostream& operator<<(ostream&, const String&);
};

int String::count = 0;

int String::finda(const char* a){
    int num = 0;
    const char* ptr;
    ptr = strchr(a,'a');
    while(ptr!=NULL){
        num++;
        ptr = strchr(ptr+1,'a');
    }
    return num;
}

String::String(const char* a){
    attribute = new char[strlen(a) + 1];
    strcpy(attribute, a);
    count+=finda(attribute);
}

String::String():attribute(new char(NULL)){}

String::String(const String& a){
    attribute = new char[strlen(a.attribute) + 1];
    strcpy(attribute, a.attribute);
    count+=finda(attribute);
}

String::~String(){
    delete [] attribute;
    attribute = nullptr;
    cout<<"I am been calling right now"<<endl;
}

bool String::operator<(const String& a) const{
    if(strcmp(attribute, a.attribute)<0){
        return true;
    }
    else{
        return false;
    }
}

bool String::operator==(const String& a) const{
    if(strcmp(attribute, a.attribute)==0){
        return true;
    }
    else{
        return false;
    }
}

String& String::operator=(const String& a){
    int mines = finda(attribute);
    delete [] attribute;
    attribute = new char[strlen(a.attribute) + 1];
    strcpy(attribute, a.attribute);
    count = count-mines+finda(attribute);
    return *this;
}

size_t String::operator!() const{
    size_t a;
    a = strlen(attribute);
    return a;
}

const char* String::operator*() const{
    return attribute;
}

String String::operator+(const String& a){
    String temp;
    temp.attribute = new char[strlen(attribute)+strlen(a.attribute)+1];
    strcpy(temp.attribute, attribute);
    strcat(temp.attribute, a.attribute);
    //count = count - finda(temp.attribute)-finda(v);
    return temp;
}

String String::operator+=(const String& a){
    int mines = finda(attribute);
    char v[30];
    strcpy(v, attribute);
    strcat(v, a.attribute);
    delete attribute;
    attribute = new char[strlen(v)+1];
    attribute = strcpy(attribute, v);
    count=count-mines;
    return attribute;
}

char String::operator[](size_t a) const{
    return attribute[a];
}

ostream& operator<<(ostream& out, const String& a){
    out<<a.attribute;
    return out;
}

int String::a_count(){
    return count;
}

int main()
{
    // Constructors
    String A("apple");
    String B("banana");
    String C("cantaloupe");
    String D(B);
    String E;
    
    // static member function
    cout << "Number of a's = " << String::a_count() << endl << endl;
    
    // Overloaded insertion operator
    cout << "A = " << A << endl;
    cout << "B = " << B << endl;
    cout << "C = " << C << endl;
    cout << "D = " << D << endl;
    cout << "E = " << E << endl << endl;
    
    // Relational operators
    cout << boolalpha;
    cout << "A < B " << (A < B) << endl;
    cout << "B < A " << (B < A) << endl;
    cout << "A == B " << (A == B) << endl << endl;
    
    // Assignment operator
    A = B;
    cout << "A = " << A << endl;
    cout << "A == B " << (A == B) << endl << endl;
    
    // Size (bang) operator
    cout << "A size = " << !A << endl;
    cout << "E size = " << !E << endl << endl;
    
    // Unary * operator
    cout << "C text = " << *C << endl << endl;
    
    // Plus operator
    cout << "A + B = " << A + B << endl << endl;
    
    // Plus equal operator
    A += C;
    cout << "A = " << A << endl << endl;
    
    // Index operator
    cout << "A[3] = " << A[3] << endl << endl;
    
    // static member function
    cout << "Number of a's = " << String::a_count() << endl;
}
