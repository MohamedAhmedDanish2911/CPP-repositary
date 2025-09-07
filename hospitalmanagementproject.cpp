#include<iostream>
#include<vector>
#include<string>
using namespace std;
class person{
    protected:
    string name,gender;
    int age;
    public:
    person(string n,int  a,string  g):name(n),age(a), gender(g) {}
    virtual void display();
};
class patient:public person{
    public:
    string disease;
    int patientID;
    patient(string n,int a,string g,string d,int id):person(n,a,g),disease(d),patientID(id){}
    void display() override{
        cout<<"patientID:"<<patientID;
        cout<<"name:"<<name;
        cout<<"age:"<<age;
        cout<<"disease:"<<disease;

    }
};
class doctor:public person{
    public:
    string specialization;
    int doctorID;
    doctor(string n,int a,string g,int id,string spec):person(n,a,g),doctorID(id),specialization(spec){}
    void display() override {
        cout<<"doctorID:"<<doctorID;
        cout<<"name:"<<name;
        cout<<"age:"<<age;
        cout<<"gender:"<<gender;
         cout<<"spectialization:"<<specialization;


    }

};
int main(){
    vector<patient> patients;
    vector<doctor> doctors;
    int choice;
    do{
        cout<<"...Hospitalmanagement....\n";
        cout<<"1. Add patient\n";
        cout<<"2.doctor..\n";
        cout<<"3.display patient data\n";
        cout<<"4.dispaly doctor..\n";
        cout<<"5. exit\n";
        cout<<"enter your choice..\n";
        cin>>choice;
        if(choice ==1){
            string name,gender,disease;
            int age,id;
            cout<<"enter patient id:";cin>>id;
            cout<<"enter name:";cin>>name;
            cout<<"enter age:";cin>>age;
            cout<<"enter gender:";cin>>gender;
            cout<<"disease:";cin>>disease;
            patients.push_back(patient(name,age,gender,disease,id));
            
        }
        else if(choice == 2){
             string name,gender,specialization;
            int age,id;
            cout<<"enter doctor id:";cin>>id;
            cout<<"enter name:";cin>>name;
            cout<<"enter age:";cin>>age;
            cout<<"enter gender:";cin>>gender;
            cout<<"specialization:";cin>>specialization;
            doctors.push_back(doctor(name,age,gender,id,specialization));
        }
        else if(choice ==3){
            cout<<"patient records";
            for(auto &p:patients){
                p.display();

            }
        }
        else if(choice ==4){
            cout<<"doctor record:";
            for(auto &d: doctors){
                d.display();
            }
        }
        else if(choice == 5){
            cout<<"existing";

        }
        else{
            cout<<"invalid data entry";
        }
    }while(choice !=5);
    return 0;
}