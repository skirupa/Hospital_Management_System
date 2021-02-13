#include<iostream>
#include "doctor.h"
#include <fstream>
#include <string.h>
using namespace std;

Doctor::Doctor(int i):p(1)
{
    if(i==0)
    {
    char ch='y';
    while(ch=='y')
    {
    cout<<"Enter the name of the doctor: "<<endl;
    cin>>name;
    cout<<"Enter the id of the doctor: "<<endl;
    cin>>id_doc;
    cout<<"Enter the Speciality of the doctor: "<<endl;
    cin>>speciality;
    cout<<"Enter the Qualification of the doctor: "<<endl;
    cin>>qualification;
    cout<<"Enter the Salary of the doctor: "<<endl;
    cin>>salary;
    ofstream file1;
    file1.open("Doctor.txt",ios::out | ios::app);
    if(!file1)
    {
        cout<<"Error opening file"<<endl;
    }
    file1.write((char*)this,sizeof(Doctor));
    cout<<"want to add more doctor record?[yes or no]"<<endl;
    cin>>ch;
    file1.close();
    }
    }
}
void Doctor::getDoctordetails()
{
    cout<<"Doctor name: "<<name<<endl;
    cout<<"Doctor id: "<<id_doc<<endl;
    cout<<"Doctor Speciality: "<<speciality<<endl;
    cout<<"Doctor Qualification: "<<qualification<<endl;
    cout<<"Doctor salary: "<<salary<<endl;
}
void Doctor::add_doctor()
{
    Doctor d;
}
void Doctor::Disp_alld()
{
    ifstream kr;
    Doctor d(1);
    cout<<"Displaying all Doctor details..."<<endl;
    kr.open("Doctor.txt",ios::in);
    kr.read((char *)&d,sizeof(d));
    if(!kr)
    {
        cout<<"Error opening file"<<endl;
        return;
    }
    while(!kr.eof())
    {
        d.getDoctordetails();
        kr.read((char *)&d,sizeof(d));
    }
    kr.close();
}
void Doctor::getHospitaldetails()
{
    ifstream new_file;
    new_file.open("hospital_details.txt");
    cout<<"\n\n\n\n\n\n\n\t\t\t\t\t   ...........................Information about the Hospital.............................\n\n";
    string line;
    while(!new_file.eof())
    {
        getline(new_file,line);
        cout<<line<<"\n\t\t";
    }
    cout<<"\n\n\t\t";
}
void Doctor::checkPatients(int p_id)
{
    ifstream pat;
    Patient p(1);
    pat.open("Patient.txt",ios::in);
    if(!pat)
    {
        cout<<"Error in opening file"<<endl;
        return;
    }
    pat.read((char *)&p,sizeof(p));
    char found='n';

    while(!pat.eof())
    {
        if(p.getpat_id()==p_id)
        {
            cout<<"Displaying patient details..."<<endl;
            found='f';
            p.getPatientdetails();
        }
        pat.read((char *)&p,sizeof(p));
    }
    if(found=='n')
    {
        cout<<"File record not found"<<endl;
    }
    pat.close();
}
void Doctor::Disp_doc(int d_id)
{
    ifstream pat;
    Doctor p(1);
    pat.open("Doctor.txt",ios::in);
    if(!pat)
    {
        cout<<"Error in opening file"<<endl;
        return;
    }
    pat.read((char *)&p,sizeof(p));
    char found='n';

    while(!pat.eof())
    {
        if(p.id_doc==d_id)
        {
            cout<<"Displaying Doctor details..."<<endl;
            found='f';
            p.getDoctordetails();
        }
        pat.read((char *)&p,sizeof(p));
    }
    if(found=='n')
    {
        cout<<"File record not found"<<endl;
    }
    pat.close();
}
void Doctor::prescribeDrugs(int p_id)
{
    ifstream li;
    Patient p2(1);
    li.open("Patient.txt");
    if(!li)
    {
        cout<<"Error in opening file\n";
        return;
    }
    li.read((char *)&p2,sizeof(p2));

    while(!li.eof())
    {
        if(p_id==p2.getpat_id())
        {
            ofstream od;
            od.open("pat_det.txt",ios::app);
            if(!od)
            {
                cout<<"Error\n";
            }
            p2.check();
            od.write((char *)&p2,sizeof(p2));
            od.close();
        }
        li.read((char *)&p2,sizeof(p2));
    }
    li.close();
}
