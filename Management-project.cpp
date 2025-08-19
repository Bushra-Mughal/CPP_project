#include<iostream>
#include<windows.h>
#include<fstream>
#include<string>
using namespace std;
class muet
   {
	 private:
		string Name,Ftname,Rollno,Dist;
	 public:
		muet():Name(" "),Ftname(" "),Rollno(" "),Dist(" "){}
				                         
	 void setName(string name){Name=name;}
	 void setFtname(string ftname){Ftname=ftname;}
	 void setRollno(string rollno){Rollno=rollno;}
	 void setDist(string dist){Dist=dist;}
	 
	 string getName(){return Name;}
	 string getFtname(){return Ftname;}
   	 string getRollno(){return Rollno;}
	 string getDist(){return Dist;}
   };
void add(muet student)     
{
  	 string name,ftname,rollno,dist;
     cout<<"\n\n\t\033[1;34mEnter student's name:\033[0m"<<endl;
     cout<<"\t";cin>>name;
     student.setName(name);
     
     cout<<"\t\033[1;34mEnter student's father name:\033[0m"<<endl;
     cout<<"\t";cin>>ftname;
     student.setFtname(ftname);
     
     cout<<"\t\033[1;34mEnter student's rollnumber:\033[0m"<<endl;
     cout<<"\t";cin>>rollno;
     student.setRollno(rollno);
     
     cout<<"\t\033[1;34mEnter student's district:\033[0m"<<endl;
     cout<<"\t";cin>>dist;
     student.setDist(dist);

     ofstream hout("st project.txt",ios::app);
     if(!hout)
	   {
	     cout<<"ERROR: File can't open."<<endl;
       }
     else
       { 
	     hout<<"\t "<<student.getName()<<" : "<<student.getFtname()
         <<" : "<<student.getRollno()<<" : "<<student.getDist()<<endl<<endl;
	   }
     hout.close();
     cout<<"\n\t\033[1;32mData successfuly added to file!\033[0m\n"<<endl;
 }
void update(muet student)
   {
 	string rollno;
 	cout<<"\n\n\tEnter roll no. of student:  ";
 	cin>>rollno;
 	ifstream infile("st project.txt");
 	ofstream outfile("st project temp.txt");
 	string line;  //Note: find(),find_last_of() are member-functions of 'std::string class' and 'line' is object of that class
 	bool found= false;
 	while(getline(infile,line))    
	   {
	 	int pos=line.find(rollno);  //find() is used to find position of first occurence of sub-string(rollno) of a string (line)
	 	if(pos!=string::npos)  //find() returns 'position' of sub-string , if not found it returns 'string::npos'. ie: 'pos=-1' if 'rollno' not found
	       {
		 	string dist;
		 	cout<<"\n\tEnter district to update:  ";
		 	cin>>dist;
		 	student.setDist(dist);
		 	int newpos = line.find_last_of(':'); //is used to find position of last occurence of sub-string.works backwards.works same as 'find()'
		 	line.replace(newpos + 2, string::npos, student.getDist()); //replace() is to replace part of a string in 'line'.replace(starting point,length,new string).here 'string::npos' means 'end of string'
		 	cout<<"\n\t\033[1;32mData Updated!\033[0m\n"<<endl;
		 	found=true;
		   }
		 outfile<<line<<endl;
	   }
	 if(found==false)
	   {cout<<"\n\t\033[1;31mStudent not found !\033[0m\n"<<endl;}
	
 	outfile.close(); //file should close as we open( ofstream,ifstream)
 	infile.close();
 	remove("This PC/Documents/st project.txt");
 	rename("This PC/Documents/st project temp.txt", "This PC/Documents/st project.txt");
    }

int main()
{
	muet student;
	bool exit=false;
	while(!exit)
	{
		system("cls"); //'cls' is command used in command prompt to clear screen.system() is windows-based system's function
		int val;
		cout<<"\n\t\t\033[1;32mWELCOME!\033[0m\n";
		cout<<"\t\033[1;33m........................\033[0m\n";
		cout<<"\t\033[1;31m MUET management system\033[0m\n";
		cout<<"\t\033[1;33m************************\033[0m\n\n\n";
		cout<<"\t1. Enter student's data."<<endl;
		cout<<"\t2. Update student's data."<<endl;
		cout<<"\t3. Exit (recommended)"<<endl;
		cout<<"\n\t\033[1;34mEnter your choice:\033[0m\n";
		cout<<"\t";cin>>val;
		
	 if(val==1)
	   {
		 system("cls");
		 add(student);
		 Sleep(6000); //to pause execution of program for specified period of time.
       }              //6000 milliseconds=6 secs, 1000 msec=1 sec
   	 else if(val==2)
	   { system("cls");
	     update(student);
	     Sleep(6000);
	    }
     else if(val==3)
	   {
	     system("cls");
         exit=true;
         cout<<"\n\n\n\tThanks for your time\n"<<endl;
         cout<<"\t\033[1;31m*********************\033[0m\n";
         cout<<"\t\033[1;33m***********************\033[0m\n";
         cout<<"\t\033[1;34m*************************\033[0m\n";
         cout<<"\t\033[1;32m*****    *     *   ******\n\t*    *    *   *    *     \n\t*    *     * *     *     \n\t*****       *      ***** \n\t*    *      *      *     \n\t*    *      *      *     \n\t*****       *      ******\033[0m\n";
         cout<<"\t\033[1;35m*************************\033[0m\n";
         cout<<"\t\033[1;36m************************\033[0m\n";
         cout<<"\t\033[1;37m***********************\033[0m\n";
         Sleep(3000);	
       }		
   }
return 0;
}
