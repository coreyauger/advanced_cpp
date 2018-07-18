#include <iostream>
#include <map>
#include <string>

#include "ring.hpp"

using namespace std;

class Person{
    public:
    string name;
    int age;

    Person() : name(""), age(0) {}   
    Person( string name, int age): name(name), age(age){} 

    bool operator<(const Person& other) const{
        name < other.name;
    }
};

int main(){
    map<Person, string> test;

    test[Person("rarg", 10)] = "mr rarg face";
    test[Person("derp", 15)] = "ding ding";


    for(auto it = test.begin(); it != test.end(); it++){
        cout<< it->first.name << " " << it->second << endl;
    }

    Ring<string> numbers(3);
    numbers.add("one");
    numbers.add("two");
    numbers.add("three");
    numbers.add("four");

    //for( int i=0; i<numbers.size(); i++){
    //    cout<< numbers[i] << endl;
    //}

    cout<< "size: " << numbers.size() <<endl;
    cout << endl;

    for(auto r : numbers){
        cout<< r << endl;
    }

    return 0;
}