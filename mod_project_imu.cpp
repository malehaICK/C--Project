#include<bits/stdc++.h>
using namespace std;

/*vectors*/
vector<string> name1;
vector<string> id1;
vector<string> dept;
vector<string> course;
/*done*/
/*student info*/
class logininfo{
public:
    string name;
    char id[15];
    string depertment;
    void get_student()
    {
    cout<<"Student Details:"<<endl<<endl;
    cout<<"Name:";
    cin>>name;
    cout<<"Id:";
    cin>>id;
    }

    void details_update()
    {
    int p,i;
    p=strlen(id);
    for(i=0;i<p;i++)
    {
    if(id[p/2+1]=='6' && id[p/2+2]=='0')
    {
        depertment = "Dept. of  CSE";
        break;
    }else if(id[p/2+1]=='4' && id[p/2+2]=='0')
    {
        depertment = "Dept of English";
        break;
    }else if(id[p/2+1]=='5' && id[p/2+2]=='5')
    {
        depertment = "Dept of EEE";
        break;
    }else{
        depertment = "is not found";
             break;
    }
    }
    name1.push_back(name);
    id1.push_back(id);
    dept.push_back(depertment);
    }
};
/*end*/

/*course details*/
class coursedetailes:public logininfo{
public:
    void getcourses()
    {
        logininfo::get_student();
        cout<<"\n\t\tCourse details (choose it as given)"<<endl<<endl;
        cout<<endl;
        cout<<"course name   credit    weekday        Time       "<<endl;
        cout<< " ENG101        3         ST          8:00-9:00   "<<endl;
        cout<<endl;
        cout<< " MAT101        3         MW          8:00-9:00   "<<endl;
        cout<<endl;
        cout<< " ENG102        3         ST          9:00-10:00  "<<endl;
        cout<<endl;
        cout<< " MAT102        3         MW          9:00-10:00  "<<endl;
        cout<<endl;
        cout<< " MAT104        3         ST          10:00-11:00 "<<endl;
        cout<<endl;
        cout<< " GEN201        3         ST          11:00-12:00 "<<endl;
        cout<<endl;
        cout<< " STA102        3         MW          12:00-1:00  "<<endl;
        cout<<endl;
        cout<< " CSE205        3         MW          10:00-11:00 "<<endl;
        cout<<endl;
        cout<< " OGEN-1        3         ST          12:00-1:00  "<<endl;
        cout<<endl;
        cout<< " MAT205        3         MW          11:00-12:00 "<<endl;
        cout<<endl;
        cout<< " OGEN-2        3         MW          2:00-3:00   "<<endl;
        cout<<endl;
        cout<< " PHY209        3         ST          1:00-2:00   "<<endl;
        cout<<endl;
        cout<< " CSE248        3         MW          3:00-4:00   "<<endl;
        cout<<endl;
        cout<< " CSE105        4         MW          4:00-5:00   "<<endl;
        cout<< " Lab                     SAT         8:00-9:30   "<<endl;
        cout<<endl;
        cout<< " CSE107        4         ST          5:00-6:00   "<<endl;
        cout<< " Lab                     SAT         9:00-10:00  "<<endl;
        cout<<endl;
        cout<< " PHY109        4         ST          2:00-3:00   "<<endl;
        cout<< " Lab                     SAT         10:00-11:00 "<<endl;
        cout<<endl;
        cout<< " CHE109        4         MW          1:00-2:00   "<<endl;
        cout<< " Lab                     SAT         11:00-12:00 "<<endl;
        cout<<endl;
        cout<< " CSE109        4         ST          3:00-4:00   "<<endl;
        cout<< " Lab                     SAT         1:00-2:00   "<<endl;
        cout<<endl;
        cout<< " CSE207        4         MW          5:00-6:00   "<<endl;
        cout<< " Lab                     SAT         2:00-3:00   "<<endl;
        cout<<endl;
        cout<< " CSE245        4         ST          04:00-5.00   "<<endl;
        cout<< " Lab                     SAT         5:00-6:00   "<<endl;
        cout<<endl;
    }
};
/*done*/

/*new course*/
class newcourse:public coursedetailes{
protected:
	int i,nfc,cf=0,cft,sft,total=0;
	string coursename;
public:
    void getnewcourses()
    {
        coursedetailes::getcourses();
        cout<<"\nEnter the No. of courses you want to take(not less than 2 or not more than 4):"<<endl;
        cin>>nfc;
        cout<<endl;
        if(nfc<=4 && nfc>=2)
        {
            cout<<"Enter courses names with code:"<<endl;
            for(i=0;i<nfc;i++)
            {
                cin>>coursename;
                course.push_back(coursename);
            }
        }else{
            cout<<"You can not take less than 2 or more than 4 courses";
        }
            cout<<endl;
		}

    void shownewcourses()
    {
        logininfo::details_update();
        string name12 = "course.txt";
        remove(name12.c_str());
        ofstream cash("course.txt");
        if(nfc<=4 && nfc>=2)
        {
            cout<<"\t\tName:"<<name1[0]<<"               ";
            cash<<"\t\tName:"<<name1[0]<<"               ";
            cout<<"Student ID:"<<id1[0]<<endl;
            cash<<"Student ID:"<<id1[0]<<endl;
            cout<<"\t\t\t";
            cash<<"\t\t\t";
            cout<<dept[0]<<endl;
            cash<<dept[0]<<endl;
            cout<<"\t\tTaken courses in this semester:"<<endl;
            cash<<"\t\tTaken courses in this semester:"<<endl;
            cout<<"                "<<"Course name"<<"\t\t\t"<<"Credit"<<endl;
            cash<<"                "<<"Course name"<<"\t\t\t"<<"Credit"<<endl;
          	for(i=0;i<nfc;i++)
          	{
                cout<<i+1<<"                "<<course[i];
                cash<<i+1<<"                "<<course[i];
          		string str(course[i]);
                str.erase(str.begin()+3, str.end());
                string str1("cse");
                string str2("che");
                string str3("phy");
            if(str.compare(str1)==0||str.compare(str2)==0||str.compare(str3)==0)
            {
                cf=4;
                cout<<"\t\t\t\t"<<cf<<endl;
                cash<<"\t\t\t"<<cf<<endl;
			 }
			 else{
                cf=3;
                cout<<"\t\t\t\t"<<cf<<endl;
                cash<<"\t\t\t"<<cf<<endl;
			 }
			 total=total+cf;
          	}
                cout<<endl;
                cash<<endl;
                cout<<"Credit = "<<total<<endl;
                cash<<"Credit = "<<total<<endl;
                cft=total*4900;
                cout<<"Total credit fee: "<<cft<<" taka"<<endl;
                cash<<"Total credit fee: "<<cft<<" taka"<<endl;
                cout<<endl;
                cash<<endl;
                sft=total*4900+510;
                cout<<"Semester fee: "<<sft<<" taka"<<endl;
                cash<<"Semester fee: "<<sft<<" taka"<<endl;
                cout<<endl;
                cash<<endl;
                cash.close();

        }
    }
};
/*done*/

/*adding courses*/
class addcourse:public newcourse
{
protected:
    int ndc,i,nsf,acf,cf,total=0;
    string coursename;
public:
    void getaddcourses()
    {
        cout<<"Add Courses"<<endl;
        cout<<"Enter the No. of courses you want to take:"<<endl;
        cin>>ndc;
        cout<<endl;
        if(ndc<=2 && ndc>=1)
        {
            cout<<"Enter courses names and code:"<<endl;
            for(i=0;i<ndc;i++)
            {
             	cin>>coursename;
             	course.push_back(coursename);
            }
        }else{
                cout<<"You can not take less than 2 or more than 4 courses";
        }
                cout<<endl;
		}

    void showaddcourses()
    {
    int sft;
    logininfo::details_update();
    string name12 = "course.txt";
    remove(name12.c_str());
    ofstream cash("course.txt");
    newcourse::shownewcourses();
    if(newcourse::nfc+ndc<=4 && newcourse::nfc+ndc>=1)
    {
            cout<<"Courses after add:"<<endl;
            cout<<endl;
            cout<<"\t\tName:"<<name1[0]<<"               ";
            cash<<"\t\tName:"<<name1[0]<<"               ";
            cout<<"Student ID:"<<id1[0]<<endl;
            cash<<"Student ID:"<<id1[0]<<endl;
            cout<<"\t\t\t";
            cash<<"\t\t\t";
            cout<<dept[0]<<endl;
            cash<<dept[0]<<endl;
            cout<<"\t\tTaken courses in this semester:"<<endl;
            cash<<"\t\tTaken courses in this semester:"<<endl;
            cout<<"                "<<"Course name"<<"\t\t\t"<<"Credit"<<endl;
            cash<<"                "<<"Course name"<<"\t\t\t"<<"Credit"<<endl;
          	for(i=0;i<newcourse::nfc+ndc;i++)
          	{
                cout<<i+1<<"                "<<course[i];
                cash<<i+1<<"                "<<course[i];
          		string str(course[i]);
                str.erase(str.begin()+3, str.end());
                string str1("cse");
                string str2("che");
                string str3("phy");
            if(str.compare(str1)==0||str.compare(str2)==0||str.compare(str3)==0)
            {
                cf=4;
                cout<<"\t\t\t\t"<<cf<<endl;
                cash<<"\t\t\t"<<cf<<endl;
			 }
			 else{
                cf=3;
                cout<<"\t\t\t\t"<<cf<<endl;
                cash<<"\t\t\t"<<cf<<endl;
			 }
			 total=total+cf;
          	}
                cout<<endl;
                cash<<endl;
                cout<<"Credit = "<<total<<endl;
                cash<<"Credit = "<<total<<endl;
                cft=total*4900;
                cout<<"Total credit fee: "<<cft<<" taka"<<endl;
                cash<<"Total credit fee: "<<cft<<" taka"<<endl;
                cout<<endl;
                cash<<endl;
                sft=total*4900+510;
                cout<<"Semester fee: "<<sft<<" taka"<<endl;
                cash<<"Semester fee: "<<sft<<" taka"<<endl;
                cout<<endl;
                cash<<endl;
                cash.close();
        }
	}
};
/*done*/

/*drop courses*/
class dropcourse:public newcourse
{
protected:
    int ndc,i,nsf,acf,cf,total=0;
    string coursename;
public:
		void getdropcourses()
		{
            cout<<"Drop Course"<<endl;
		    cout<<"Enter the No. of courses you want to drop:"<<endl;
		    cin>>ndc;
            cout<<endl;
            if(ndc>0 && ndc<3)
            {
            cout<<"Enter courses names and code:"<<endl;
            for(i=0;i<ndc;i++)
            {
             	cin>>coursename;
             	for(int j=0; j<course.size(); j++)
                {
                    if(coursename==course[j])
                    {
                    course.erase(course.begin()+j);
                    }
                }
            }
            }else{
                cout<<"You can not drop more than 2 courses";
            }
                cout<<endl;
		}

        void showdropcourses()
        {
            int sft,cft;
            logininfo::details_update();
            string name12 = "course.txt";
            remove(name12.c_str());
            ofstream cash("course.txt");
          	cout<<"Courses after drop:"<<endl;
            cout<<endl;
            cout<<"\t\tName:"<<name1[0]<<"               ";
            cash<<"\t\tName:"<<name1[0]<<"               ";
            cout<<"Student ID:"<<id1[0]<<endl;
            cash<<"Student ID:"<<id1[0]<<endl;
            cout<<"\t\t\t";
            cash<<"\t\t\t";
            cout<<dept[0]<<endl;
            cash<<dept[0]<<endl;
            cout<<"\t\tTaken courses in this semester:"<<endl;
            cash<<"\t\tTaken courses in this semester:"<<endl;
            cout<<"                "<<"Course name"<<"\t\t\t"<<"Credit"<<endl;
            cash<<"                "<<"Course name"<<"\t\t\t"<<"Credit"<<endl;
          	for(i=0;i<course.size();i++)
          	{
                cout<<i+1<<"                "<<course[i];
                cash<<i+1<<"                "<<course[i];
          		string str(course[i]);
                str.erase(str.begin()+3, str.end());
                string str1("cse");
                string str2("che");
                string str3("phy");
            if(str.compare(str1)==0||str.compare(str2)==0||str.compare(str3)==0)
            {
                cf=4;
                cout<<"\t\t\t\t"<<cf<<endl;
                cash<<"\t\t\t"<<cf<<endl;
			 }
			 else{
                cf=3;
                cout<<"\t\t\t\t"<<cf<<endl;
                cash<<"\t\t\t"<<cf<<endl;
			 }
			 total=total+cf;
          	}
                cout<<endl;
                cash<<endl;
                cout<<"Credit = "<<total<<endl;
                cash<<"Credit = "<<total<<endl;
                cft=total*4900;
                cout<<"Total credit fee: "<<cft<<" taka"<<endl;
                cash<<"Total credit fee: "<<cft<<" taka"<<endl;
                cout<<endl;
                cash<<endl;
                sft=total*4900+510;
                cout<<"Semester fee: "<<sft<<" taka"<<endl;
                cash<<"Semester fee: "<<sft<<" taka"<<endl;
                cout<<endl;
                cash<<endl;
                cash.close();
		  }
};
/*done*/

/*main menu*/
int main()
{
int choise;
char ch;

do{
cout<<"MAIN MENU"<<endl;;
cout<<"01. New course"<<endl;
cout<<"02. ADD course menu"<<endl;
cout<<"03. Drop course "<<endl;
cout<<"04. Exit the program"<<endl;
cout<<"Please Select Your Option (1-4) :"<<endl;
cin>>choise;
cout<<endl;
switch(choise)
{
case 1:
    {
    newcourse s1;
    s1.getnewcourses();
    s1.shownewcourses();
    break;
    }
case 2:
    {
    addcourse a1;
    a1.getaddcourses();
    a1.showaddcourses();
    break;
    }
case 3:
    {
    dropcourse d1;
    d1.getdropcourses();
    d1.showdropcourses();
    break;
    }
case 4:
    exit(1);
default:
    cout<<"error"<<endl;
}
cout<<"Do you want to continue and see main menu again?:(y/n)"<<endl;
cin>>ch;
}while(ch!='n');
return 0;
}
/*done*/
