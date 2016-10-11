#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

class Person{
	
	private: 
		int age;
		string name;
	public:
		Person();
		void setAge(int age);
		void setName(string name);
		int getAge();
		string getName();
	
}
Person::Person(){
	
}
void Person::setAge(int mAge){
	age = mAge;
}
void Person::setName(string mName){
	name = mName;
}
int Person::getAge(){
	return age;
}
string Person::getName(){
	return name;
}