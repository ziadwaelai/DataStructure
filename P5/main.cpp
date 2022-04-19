#include <iostream>
#include"StudentName.h"
using namespace std;

int main()
{
    cout<<endl<<"----------S1-------------"<<endl;
    StudentName s1("ziad");
    s1.print();
    cout<<endl;
    s1.replace(0,5);
    s1.print();
    cout<<endl<<"-----------S2------------"<<endl;
    StudentName s2("ziad wael");
    s2.print();
    cout<<endl;
    s2.replace(1,2);
    s2.print();
    cout<<endl<<"----------S3-------------"<<endl;
    StudentName s3("ziad wael abulhamed");
    s3.print();
    cout<<endl;
    s3.replace(3,2);
    s3.print();
    cout<<endl<<"-----------S4------------"<<endl;
    StudentName s4("ziad wael abdulhamed abdlRahed");
    s4.print();
    cout<<endl;
    s4.replace(22,10);
    s4.print();
    cout<<endl<<"-----------S5------------"<<endl;
    StudentName s5("ziad wael abdulhamed");
    s5.print();
    cout<<endl;
    s5.replace(1,3);
    s5.print();




}
