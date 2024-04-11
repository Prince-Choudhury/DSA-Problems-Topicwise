#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Student
{
private:
    string gf;
    
public:
    int id;
    int age;
    bool present;
    string name;
    int nos;

    //Constructor(ctor): Default Ctor
    Student(){
        cout<<"Student ctor called"<<endl;
    }

    //Parametrized ctor
    // Student(int _id, int _age, bool _present, string _name, int _nos, string _gf){
    //     id = _id;
    //     age = _age;
    //     present = _present;
    //     name = _name;
    //     nos = _nos;
    //     gf = _gf;
    //     cout<<"Student Parameterized ctor called"<<endl;

    // }

    Student(int id, int age, bool present, string name, int nos, string gf){
        this->id = id;          //this is a pointer that points at current object
                                // Student *this; -->this variable h and Student name the pointer h
                                //Hamne Student s2; s2 object banaya to this abhi s2 ko hi point kar raha hoga
        this->age = age;
        this->present = present;
        this->name = name;
        this->nos = nos;
        this->gf = gf;
        //Change variable name otherwise wrtie like this
        // this ptointer--> Added by compiler privately
        cout<<"Student Parameterized ctor called"<<endl;
    }

    Student(int _id, int _age, bool _present, string _name, int _nos){
        id = _id;
        age = _age;
        present = _present;
        name = _name;
        nos = _nos;
        cout<<"Student Parameterized ctor w/o gf called"<<endl;

    }

    // Student ek hi h but wo multiple forms dikha raha--> Polimorphism

    void study(){
        cout<<"Studying"<<endl;
    }
    void sleep(){
        cout<<"Sleeping"<<endl;
    }
    void bunk(){
        cout<<"bunking"<<endl;
    }
private:
    void gfchatting(){
        cout<<"Chatting"<<endl;
    }
};

int main(){
    //cout<<sizeof(Student)<<endl;
    Student s1;  // Stack pe allocate hua h

    Student s2(1, 12, 1, "Chota Bheem", 1, "Chutki");
    cout<<s2.name<<endl;  // Stack pe allocate hua h therefore we r using dot
    cout<<s2.id<<endl;

    Student s3(1, 12, 1, "Chota Bheem", 1);
    cout<<s3.name<<endl;
    cout<<s3.id<<endl;

    //int *a = new int(5);
    // Heap pe allocate hua h
    Student *s4 = new Student(3, 34, 1, "Chintu", 6);
    cout<<s4->name<<endl;   //OR
    cout<< (*s4).name<<endl;

    delete s4;  // To prevent from leak
    
    //cout<<s1.age<<endl;
    // s1.name = "Golu";
    // s1.age = 12;
    // s1.id = 1;
    // s1.nos = 5;
    // s1.present = 1;

    // Student s2;
    // s2.name = "Chota Bheem";
    // s2.age = 11;
    // s2.id = 2;
    // s2.nos = 1;
    // s2.present = 0;

    //Baar....2 dot karke likh rahe kuch to asan tarika hona chahiye -->
    //Better tarika h : Constructor(ctor) ->It construct instance of class
    
    return 0;
}