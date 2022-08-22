#include<process.h>
#include<iostream.h>
#include<conio.h>
#include<iomanip.h>
#include<string.h>
#include<fstream.h>
#include<stdio.h>
#include<dos.h>
class admindetails
{
char username[20];
int password;
public:
char *retusername()
{
return username;
}
int retuserpassword()
{
return password;
}
admindetails()
{
strcpy(username,"admin");
password=0;
}
void admindetails1();
}a;
void admindetails::admindetails1()
{
cout<<"\n ENTER ADMIN NAME:";
cin>>username;
cout<<"\n ENTER PASSWORD:";
cin>>password;
}
class staff
{
public:
char sname[20],dept[20];
int empno,deptno;
long phno;
void staffinfo();
void staffupdate(int n);
void deletedata(int n);
void display();
}p;
void staff::staffinfo()            //FUNCTION WHICH INPUTS STAFF DATA//
{

cout<<"\n ENTER NAME:";
gets(sname);
cout<<"\n ENTER DEPARTMENT NAME:";
gets(dept);
cout<<"\n ENTER DEPARTMENT NUMBER:";
cin>>deptno;
cout<<"\n ENTER PHONE NUMBER:";
cin>>phno;
cout<<"\n ENTER EMPLOYEE NUMBER:";
cin>>empno;
}
void staff::staffupdate(int n)        //FUNCTION TO PERFORM MODIFICATION OF
{                                        //STAFF DETAILS
fstream f;
int c,l,i,pos,h;
char o[20];
long a;
f.open("file.dat",ios::in|ios::binary|ios::out);
f.seekg(0,ios::beg);
cout<<"\n MODIFICATION ";
cout<<"\n 1.UPDATE NAME \n 2.UPDATE DEPARTMENT NAME \n 3.UPDATE DEPARTMENT NUMBER \n 4.UPDATE PHONE NUMER";
cin>>c;
cout<<"\n ENTER EMPLOYEE NUMBER";
cin>>l;
switch(c)
{
case 1:
cout<<"\n ENTER NEW NAME";
cin>>o;
for(i=0;i<n;i++)
{
pos=f.tellg();
f.read((char*)&p,sizeof(p));
if(p.empno==l)
{
strcpy(p.sname,o);
f.seekg(pos);
f.write((char*)&p,sizeof(p));
}
}
break;
case 2:
cout<<"\n ENTER NEW DEPARTMENT NAME";
cin>>o;
for(i=0;i<n;i++)
{
pos=f.tellg();
f.read((char*)&p,sizeof(p));
if(p.empno==l)
{
strcpy(p.dept,o);
f.seekp(pos);
f.write((char*)&p,sizeof(p));
}
}
break;
case 3:
cout<<"\n ENTER NEW DEPARTMENT NUMBER";
cin>>h;
for(i=0;i<n;i++)
{
pos=f.tellg();
f.read((char*)&p,sizeof(p));
if(p.empno==l)
{
p.deptno=h;
f.seekp(pos);
f.write((char*)&p,sizeof(p));
}
}
break;
case 4:
cout<<"\n ENTER NEW PHONE NUMBER";
cin>>a;
for(i=0;i<n;i++)
{
pos=f.tellg();
f.read((char*)&p,sizeof(p));
if(p.empno==l)
{
p.phno=a;
f.seekp(pos);
f.write((char*)&p,sizeof(p));
}
}
break;
}
}
void staff::deletedata(int n)       /*FUNCTION TO DELETE THE DESIRED RECORD*/
{
int l;
fstream f,f1;
char c[5];
cout<<"\n DELETE A RECORD";
cout<<"\n ENTER EMPLOYEE NUMBER";
cin>>l;
f.open("file.dat",ios::in|ios::binary);
f1.open("temp.dat",ios::out|ios::binary);
for(int i=0;i<n;i++)
{
 f.read((char*)&p,sizeof(p));
 if(p.empno==l)
 {
  cout<<"\n DO YOU WANT TO DELETE";
  cin>>c;
  if(strcmpi(c,"no")==0)
  f1.write((char*)&p,sizeof(p));
 }
  else
  f1.write((char*)&p,sizeof(p));
}
  remove("file.dat");
}
void staff::display()               /*FUNCTION TO DISPLAY STAFF DETIALS*/
{
cout<<"\n  NAME: "<<sname;
cout<<"\n  DEPARTMENT NAME: "<<dept;
cout<<"\n  DEPARTMENT NUMBER: "<<deptno;
cout<<"\n  PHONE NUMBER: "<<phno;
cout<<"\n  EMPLOYEE NUMBER "<<empno;
}
void main()
{
clrscr();
int ch,c;
char l[10],b[10];
void  patient(int n);
void staffrelated(int n);
void medicine();
fstream fio;
for(int i=0;i<27;i++)
cout<<"*";
cout<<"WELCOME TO SRUSTI HOSPITAL" ;
for(i=0;i<27;i++)
cout<<"*";
cout<<"\n "<<"\t"<<setw(52)<<"No.5,park avenue street,chennai-600073";
cout<<"\n"<<"\n";
fio.open("file.dat",ios::app|ios::out|ios::binary|ios::in);
fio.seekg(0,ios::end);
int n=fio.tellg()/sizeof(p);
fio.seekg(0,ios::beg);
do
{
cout<<"\n ENTER YOUR CHOICE"<<"\n 1.PATIENT "<<"\n 2.STAFF"<<"\n 3.MEDICINE" ;
cin>>ch;
switch(ch)
{
case 1:
patient(n);
break;
case 2:
cout<<"\n ENTER ADMIN NAME";
cin>>b;
cout<<"\n ENTER ADMIN PASSWORD";
cin>>c;
if(strcmp(b,a.retusername())==0 && c==a.retuserpassword())
staffrelated(n);
else
cout<<"\n ADMIN ACCES DENIED";
break;
case 3:
medicine();
break;
default:cout<<"\nYOU HAVE PRESSED THE WRONG CHOICE:";
}
cout<<"\n DO YOU WANT TO CONTINUE(YES/NO)";
cin>>l;
}while((strcmp(l,"yes")==0)||(strcmp(l,"YES")==0));
cout<<"\n THANK YOU FOR YOUR COOPERATION:";
delay(3000);
exit(0);
getch();
}
void staffrelated(int n)        //FUNCTION TO PERFORM STAFF RELATED
{                                 //INSERTION,MODIFICATION,DELETION
int ch;
fstream fio;
cout<<"\n1.ENTER DATA \n2.MODIFY \n3.DELETE \n4.DISPLAY";
cin>>ch;
fio.open("file.dat",ios::ate|ios::out|ios::binary|ios::in);
switch(ch)
{
case 1:
p.staffinfo();
fio.write((char*)&p,sizeof(p));
break;
case 2:
p.staffupdate(n);
cout<<"\nSUCESSFULLY MODIFIED:";
break;
case 3:
p.deletedata(n);
rename("temp.dat","file.dat");
cout<<"\n SUCCESSFULLY DELETED:";
break;
case 4:
 fio.seekg(0,ios::beg);
for(int i=0;i<n;i++)
{
fio.read((char*)&p,sizeof(p));
p.display();
 }
break;
}
}
void patient(int n)                      //FUNCTION TO ENTER PATIENT DETAILS
{                                        //AND DISPLAY THE DESIRED RECORDS
fstream f;
f.open("file.dat",ios::in|ios::binary);
char pname[50],padd[30],cr[76];
int h;
int age,admn,ad,ph;
char ch1,yes[80];
cout<<"\nARE YOU AN OLD PATIENT:";
cin>>yes;
if(strcmp(yes,"yes")==0)
{
cout<<"\ndo you have the same previous complaints????????......";
cin>>yes;
if(strcmp(yes,"yes")==0)
{
 cout<<"\n oops!!, sorry to hear that";
 cout<<"\n\n SUBMIT YOUR PREVIOUS VISIT REPORT IN THE RECEPTION:";
 goto z;
}
else
{
cout<<"\noh!!!!....happy to hear that";
cout<<"\n\n SUBMIT YOUR PREVIOUS VISIT REPORT IN THE RECEPTION:";
 goto z;
}
}

else
{
 cout<<"\n ENTER THE PATIENT NAME:";
 gets(pname);
 cout<<"\nENTER PATIENT AGE:";
 cin>>age;
 cout<<"\nENTER CARETAKER NAME:";
 gets(cr);
 cout<<"\nENTER PATIENT ADDRESS:";
 gets(padd);
 cout<<"\n ENTER PHONE NUMBER:";
 cin>>ph;
z: cout<<"\n CHOOSE THE DOCTOR WHOM YOU WANT TO VISIT:";
   cout<<"\n1.HEART SPECIALIST:";
   cout<<"\n2.GENERAL SURGEON:";
   cout<<"\n3.ORTHOPEDIC:";
   cout<<"\n4.VETERINARIAN:";
   cout<<"\n5.PHYSIOLOGIST:";
cin>>h;
switch(h)
{
case 1:
  for(int i=0;i<n;i++)
  {
   f.read((char*)&p,sizeof(p));
   if(p.deptno==10)
   p.display();
  }
   cout<<"\nTIMINGS:8.30AM-5.00PM";
 break;
 case 2:
  for(i=0;i<n;i++)
  {
  f.read((char*)&p,sizeof(p));
   if(p.deptno==20)
   p.display();
   }
   cout<<"\nTIMINGS:10.00AM-9.00PM";

 break;
 case 3:
   for(i=0;i<n;i++)
  {
   f.read((char*)&p,sizeof(p));
  if(p.deptno==30)
   p.display();
   }
   cout<<"\nTIMINGS:7.00AM-6.00PM";
 break;
 case 4:
 for(i=0;i<n;i++)
  {
  f.read((char*)&p,sizeof(p));
   if(p.deptno==40)
   p.display();
   }
   cout<<"\nTIMINGS:11.00AM-7.00PM";

 break;
 case 5:
for(i=0;i<n;i++)
 {
  f.read(
  (char*)&p,sizeof(p));
   if(p.deptno==50)
   p.display();
   }
   cout<<"\nTIMINGS:10.30AM-9.00PM";

 break;
 }
}
}
void medicine()             /*FUNCTION TO DISPLAY MEDICINE DETAILS:*/
{
 cout<<"\nWE ALSO PROVIDE MEDICINES FOR FEW COMMON DISEASES:";
cout<<"\nTHE MEDICINES ARE:";
int ch;
cout<<"\n1.DIARRHOEA\n2.BLOOD PRESSURE\n3.FEVER\n4.CONSTIPATION\n5.TONSIL";
cout<<"\nENTER YOUR CHOICE";
cin>>ch;
switch(ch)
{
case 1:
cout<<"\nDIARRHOEA IS THE CONDITION OF HAVING ATLEAST THREE LOOSE,LIQUID,OR WATERY";
cout<<"\nBOWEL MOVEMENTS EACH DAY";
cout<<"\n\nTHE MEDICINE AVAILABLE FOR DIARRHOEA:LOPERAMIDE";
cout<<"\nPRICE:Rs.240";
break;
case 2:
cout<<"\nIT IS THE PRESSURE OF THE BLOOD IN THE CIRCULATORY SYSTEM";
cout<<"\nHEART FAILURE IS COMMON IN PATIENTS WITH HIGH BP";
cout<<"\n\nTHE MEDICINE AVAILABLE FOR BLOOD PRESSURE:FELODIPINE";
cout<<"\nPRICE:Rs.190";
break;
case 3:
cout<<"\nAN ABNORMAL HIGH BODY TEMPERATURE,USUALLY ACCOMPANIED BY SHIVERING AND HEADACHE";
cout<<"\n\nTHE MEDICINE AVAILABLE FOR FEVER:ACETAMINOPHEN";
cout<<"\nPRICE:Rs.145";
break;
case 4:
cout<<"\nA CONDITION IN WHICH THERE IS DIFFICULTY IN EMPTYING THE BOWELS,";
cout<<"\nUSUALLY ASSOCIATED WITH HARDENED FAECES";
cout<<"\n\nTHE MEDICINE AVAILABLE FOR CONSTIPATION:BISACODYL";
cout<<"\nPRICE:Rs.250";
break;
case 5:
cout<<"\nTWO SMALL MASSES OF LYMPHOID TISSUE IN THE THROAT,";
cout<<"\nONE ON EACH SIDE OF THE ROOT OF THE TONGUE";
cout<<"\n\nTHE MEDICINE AVAILABLE FOR TONSILE:AMOXIL";
cout<<"\n PRICE:250";
break;
default:
cout<<"\nIF THERE ARE ANY OTHER MEDICINES THAT YOU WANT,";
cout<<"\nIT CAN BE INFORMED TO OUR RECEPTIONIST";
cout<<"\n WE WILL MAKE SURE THAT YOU GET THE DESIRED MEDICINE WITHIN A WEEK";
}

}
