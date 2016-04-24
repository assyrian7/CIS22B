#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

#ifndef STUDENT_H
#define STUDENT_H
#include <string>
using namespace std;


class Student//Information for student
{
      private:
              string first;
              string last;
              string major;
      
      public:
             Student(){
                first = "First"; last = "Last"; major = "Undeclared";}
             Student(string f, string l, string major){
                first = f; last = l; this->major = major;}
             ~Student() {cout << "Welcome";}
             
             //mutators
             void setFirst(string first){ first = first;};
             void setLast(string last){ last = last;};
             void setMajor(string major){major = major;};
             //accessors
             string getFirst() const{return first;};
             string getLast() const {return last;} ;
             string getMajor() const {return major;};
             
             string print(){return last + ", " + first + " " + major;}
};
#endif
             


int main( )
{   string first, last, study;
    cout << " Enter you first name: "; cin >> first;
    cout << "Enter your family name: "; cin >> last; 
    cout << "Enter your major: "; cin >> study;
      
    Student blank;
    Student peer(first, last, study);
    cout << blank.print() << endl;
    cout << peer.print() << endl;
   
    system ("pause");
    return 0;
}