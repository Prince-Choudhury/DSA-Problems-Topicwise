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
    int *v;  

    //Constructor(ctor): Default Ctor
    Student(){
        cout<<"Student ctor called"<<endl;
    }

    Student(int id, int age, bool present, string name, int nos, string gf){
        this->id = id;          
        this->age = age;
        this->present = present;
        this->name = name;
        this->nos = nos;
        this->gf = gf;
        this->v = new int(10);    //you have allocated memory. Make sure that you have deleted also
         // CPP Rule--> The memory which will be allocated has to be destroyed by you otherwise memory leakng problem can be faced                      
       
        cout<<"Student Parameterized ctor called"<<endl;
    }

    //copy constructor(ctor)
    // Copy constructor har baar banana jaruri h : No
    //Jaise default ctor apne aap add ho jata h waise hi ye bhi add ho jata h
    Student(const Student &srcobj){

        cout<<"Student copy constructor called"<<endl;
        this->name = srcobj.name;
        this->age = srcobj.age;
        this->gf = srcobj.gf;
        this->nos = srcobj.nos;
        this->present = srcobj.present;
        this->id = srcobj.id;
        
    }

    //getter/setter

    //getter--> you can access private data
    string getGfName(){
        return gf; //OR
        //return this->gf;
    }

    //setter --> you can change private data
    void setGfName(string gf){
        this->gf = gf;
    }


    void study(){
        cout<<"Studying"<<endl;
    }
    void sleep(){
        cout<<"Sleeping"<<endl;
    }
    void bunk(){
        cout<<"bunking"<<endl;
    }
    //Destructor(dtor)
    ~Student(){
        cout<<"Student dtor called"<<endl;
        delete v;
    }

private:
    void gfchatting(){
        cout<<"Chatting"<<endl;
    }
};

int main(){
    // Copy ctor
    //Student s1(1, 12, 1, "Chota Bheem", 1, "Chutki");
    //Student s2 = s1;    //s2 ke liye to koi parametrized ctor call nahi hua
    //Student s2(s1); //0R

    //Now default ctor will be called
    //Student s2;
    //s2 = s1;     // s1 ka data member s2 me copy ho raha h
                // Simple copy ho raha h constructor ke through nahi ho raha h
                // therefore copy ctor call nahi hua iss case me

    //cout<<s1.name<<endl;
    //cout<<s2.name<<endl;

    /*
    {
    Student s1(1, 12, 1, "Chota Bheem", 1, "Chutki");
    cout<<s1.name<<endl;
    }            //--->dtor call hua
    Student s2;
    */


    Student s1(1, 12, 1, "Chota Bheem", 1, "Chutki");
    cout<<s1.name<<endl;

    cout<<s1.getGfName()<<endl;  //getter

    s1.setGfName("Indumati");    //setter
    cout<<s1.getGfName()<<endl;

    return 0;
}             