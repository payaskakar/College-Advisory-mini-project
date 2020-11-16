//COLLEGE RECOMMENDER SYSTEM Admin login-123 admin password-123456
#include<fstream>
#include<iostream>
#include<conio.h>
#include<string.h>
#include<unistd.h>
using namespace std;
//////////////////////////////////////////////////////////
void Admin_login();
void Admin_work();
void Add_college();
void Display_colleges();
void Add_university();
void Display_university();
void Modify_college();
void Modify_university();
void Alumni();
void Alumni_login();
void Alumni_signup();
void delete_account();
void Alumni_work(char user[20]);
void College_rating(char user[20]);
void University_rating(char user[20]);
void Newstudent();
void Newstudent_login();
void Newstudent_signup();
void Newstudent_account();
void Newstudent_work(char user[20]);
void College(char user[20]);
void University(char user[20]);
int main();
//////////////////////////////////////////////////////////
//classes are defined to work on the files stored in the system.
class college{
	public:
		char c_name[50],u_name[50],courses[50];
		void input(){
			cout<<"ENTER COLLEGE NAME:";
			gets(c_name);
			cout<<"ENTER COURSES AVAILABLE IN COLLEGE:";
			gets(courses);
			cout<<"ENTER AFFILIATED UNIVERSITY NAME:";
			gets(u_name);
		}
		void output(){
	  		cout<<"COLLEGE NAME: "<<c_name<<endl;
	  		cout<<"COURSES AVAILABLE IN COLLEGE:"<<courses<<endl;
	  		cout<<"AFFILIATED UNIVERSITY NAME: "<<u_name<<endl;
	  		cout<<"\n";
		}
};
class university{
	public:
		char u_name[50],courses[50];
		void input(){
			cout<<"ENTER UNIVERSITY NAME:";
			gets(u_name);
			cout<<"ENTER COURSES AVAILABLE IN UNIVERSITY:";
			gets(courses);
		}
		void output(){
			cout<<"UNIVERSITY NAME:"<<u_name<<endl;
			cout<<"COURSES AVAILABLE IN UNIVERSITY:"<<courses<<endl;
			cout<<"\n";
		}
};
class signup{
    public:
        char user[20];
        char pass[20];
        void input(){
            cout<<"\n\nENTER USERNAME:";
            gets(user);
            cout<<"ENTER PASSWORD:";
            gets(pass);
        }
};
class rating{
    public:
        int rating;
        char review[100];
        int input(char user[20]){
            cout<<"\nRATING(OUT OF 5):";
            cin>>rating;
            cin.sync();
            if(rating>5 || rating<1){
                cout<<"\n INVALID";
                sleep(1);
                return 0;
            }
            else{
                cout<<"\nREVIEW(WITHIN 100 WORDS)):";
                gets(review);
            }
            return 1;
        }
};
///////////////////////////////////////////////////////
//ADMIN
void Admin_login(){
	system("cls");
	string id="123";
	string password="123456";
	cout<<"\t\t\t\t\t----------------------------------------\n";
	cout<<"\t\t\t\t\t\t       ADMIN LOGIN\n";
	cout<<"\t\t\t\t\t----------------------------------------\n";
	string user;
	string pass;
	cout<<"\n\nENTER USERNAME:";
	getline(cin,user);
	cout<<"\nENTER PASSWORD:";
	getline(cin,pass);
	if(id==user && password==pass){
		cout<<"\nLOGIN SUCCESSFUL";
		sleep(1);
		Admin_work();
	}
	else{
		cout<<"\nINVALID CREDENTIALS!!";
		sleep(1);
		Admin_login();
	}
}
void Admin_work(){
	char val;
	system("cls");
	cout<<"\t\t\t\t\t----------------------------------------\n";
	cout<<"\t\t\t\t\t\t         ADMIN \n";
	cout<<"\t\t\t\t\t----------------------------------------\n";
	cout<<"\nWHAT DO YOU WANT TO DO?\n";
	cout<<"1.ADD COLLEGE\n";
	cout<<"2.DISPLAY COLLEGES\n";
	cout<<"3.ADD UNIVERSITY\n";
	cout<<"4.DISPLAY UNIVERSITIES\n";
	cout<<"5.MODIFY RECORDS OF COLLEGE\n";
	cout<<"6.MODIFY RECORDS OF UNIVERSITY\n";
	cout<<"7.LOGUT\n";
	cout<<"\nENTER AN OPTION:";
	val=getche();
	switch(val){
		case '1':
			Add_college();
			break;
		case '2':
			Display_colleges();
			break;
		case '3':
			Add_university();
			break;
		case '4':
			Display_university();
			break;
		case '5':
			Modify_college();
			break;
		case '6':
			Modify_university();
			break;
		case '7':
			sleep(1);
			system("cls");
			main();
			break;
		default:
			cout<<"\nINVALID CHOICE!!\n";
			sleep(1);
			Admin_work();
	}
}
//ADD COLLEGE IN RECORDS
void Add_college(){
	system("cls");
	fstream fil;
 	college c1;
 	fil.open("collegelist.txt",ios::out|ios::app|ios::binary);
  	c1.input();
  	fil.write((char*)&c1,sizeof (c1));
  	fil.close();
  	cout<<"\n\nALL THE RECORDS ARE STORED"<<endl;
  	sleep(3);
  	Admin_work();
}
//DISPLAY COLLEGE IN RECORDS
void Display_colleges(){
	int i=1;
	system("cls");
 	college c1;
 	fstream fil;
 	fil.open("collegelist.txt",ios::in|ios::binary);
 	while(fil.read((char*)&c1,sizeof c1)){
 		cout<<i<<". ";
		c1.output();
 		i++;
 	}
 	cout<<"---------------------------------------------------\n";
 	getchar();
 	fil.close();
 	Admin_work();
}
//ADD university IN RECORDS
void Add_university(){
	system("cls");
	fstream fil;
 	char ch;
 	university u1;
 	fil.open("universitylist.txt",ios::out|ios::app|ios::binary);
  	u1.input();
  	fil.write((char*)&u1,sizeof (u1));
  	fil.close();
  	cout<<"\n\nALL THE RECORDS OF UNIVERSITY ARE STORED"<<endl;
  	sleep(3);
  	Admin_work();
}
//DISPLAY university IN RECORDS
void Display_university(){
	int i=1;
	system("cls");
 	university u1;
 	fstream fil;
 	fil.open("universitylist.txt",ios::in|ios::binary);
 	while(fil.read((char*)&u1,sizeof u1)){
 		cout<<i<<". ";
		u1.output();
 		i++;
 	}
 	fil.close();
 	cout<<"-----------------------------------------------------------\n";
	getchar();
 	Admin_work();
}
//MODIFY THE RECORDS OF COLLEGE
void Modify_college(){
	system("CLS");
 	int a=0;
 	char c_name[50];
 	college c1;
 	fstream fil;
 	cout<<"ENTER THE NAME OF COLLEGE:";
 	gets(c_name);
 	fil.open("collegelist.txt",ios::in|ios::out|ios::binary);
 	while(fil.read((char*)&c1,sizeof c1)){
  		if (strcmp(c1.c_name,c_name)==0){
  			a++;
            fil.seekp(fil.tellg()-sizeof(c1),ios::beg);
            c1.input();
            fil.write((char*)&c1,sizeof(c1));
  			break;
		}
 	}
 	if(a==0)
 		cout<<"NO COLLEGE FOUND!"<<endl;
 	else
 		cout<<"\n\nRECORDS OF COLLEGE ARE MODIFIED.";
	fil.close();
 	sleep(3);
 	Admin_work();
}
//MODIFY THE RECORDS OF UNIVERSITY
void Modify_university(){
	system("CLS");
 	int a=0;
 	char u_name[50];
 	university u1;
 	fstream fil;
 	cout<<"ENTER THE NAME OF UNIVERSITY:";
 	gets(u_name);
 	fil.open("universitylist.txt",ios::in|ios::out|ios::binary);
 	while(fil.read((char*)&u1,sizeof u1)){
  		if (strcmp(u1.u_name,u_name)==0){
  			a++;
            fil.seekp(fil.tellg()-sizeof(u1),ios::beg);
            u1.input();
            fil.write((char*)&u1,sizeof(u1));
  			break;
		}
 	}
 	if(a==0)
 		cout<<"NO UNIVERSITY FOUND!"<<endl;
 	else
 		cout<<"\n\nRECORDS OF UNIVERSITY ARE MODIFIED.";
	fil.close();
 	sleep(3);
 	Admin_work();
}
//////////////////////////////////////////////////////////////////////////
//ALUMNI
void Alumni(){
	system("cls");
	cout<<"\t\t\t\t\t----------------------------------------\n";
	cout<<"\t\t\t\t\t          ALUMNI LOGIN/SIGNUP\n";
	cout<<"\t\t\t\t\t----------------------------------------\n";
	cout<<"\n\n1.LOGIN";
	cout<<"\n2.SIGNUP";
	cout<<"\n3.DELETE ACCOUNT";
	cout<<"\n4.BACK TO MENU";
	cout<<"\n\nENTER AN OPTION:";
	char val;
	val=getche();
	switch(val){
		case '1':
			Alumni_login();
			break;
		case '2':
			Alumni_signup();
			break;
        case '3':
            delete_account();
            break;
        case '4':
			system("cls");
			main();
            break;
		default:
			cout<<"\n\nINVALID OPTION!!";
			sleep(2);
			Alumni();
	}
}
void Alumni_login(){
    system("cls");
	cout<<"\t\t\t\t\t----------------------------------------\n";
	cout<<"\t\t\t\t\t            ALUMNI LOGIN\n";
	cout<<"\t\t\t\t\t----------------------------------------\n";
	fstream fil;
 	signup a1;
 	fil.open("alumnidetails.txt",ios::in|ios::binary);
    char user[20],pass[20];
    cin.sync();
    cout<<"\n\nENTER USERNAME:";
    gets(user);
    cout<<"\nENTER PASSWORD:";
    gets(pass);
    int a;
    while(fil.read((char*)&a1,sizeof a1)){
  		if (strcmp(a1.user,user)==0 && strcmp(a1.pass,pass)==0){
            a=1;
            break;
		}
 	}
 	fil.close();
 	if(a==1){
        cout<<"\n LOGIN SUCCESSFUL";
        sleep(2);
        Alumni_work(user);
 	}
 	else{
        cout<<"\nINVALID CREDENTIALS!!";
        sleep(2);
        Alumni_login();
 	}
}
void Alumni_signup(){
    system("cls");
	cout<<"\t\t\t\t\t----------------------------------------\n";
	cout<<"\t\t\t\t\t            ALUMNI SIGNUP\n";
	cout<<"\t\t\t\t\t----------------------------------------\n";
    signup a1;
	fstream fil;
 	fil.open("alumnidetails.txt",ios::out|ios::in|ios::binary);
  	char user[20],pass[20];
  	string pass1;
  	int a=0;
    cout<<"\n\nENTER USERNAME:";
    gets(user);
    cin.sync();
    cout<<"\nENTER PASSWORD:";
    getline(cin,pass1);
    if(pass1.length()==0){
        cout<<"\n INVALID";
        sleep(2);
        Alumni_signup();
    }
    else{
        strcpy(pass,pass1.c_str());
        while(fil.read((char*)&a1,sizeof a1)){
            if (strcmp(a1.user,user)==0){
                a=1;
                break;
            }
        }
        fil.close();
        if(a==1){
            cout<<"\nUSERNAME ALREADY EXISTS.";
            sleep(2);
            Alumni_signup();
        }
        else{
            cout<<"\n\nSIGNUP SUCCESSFUL"<<endl;
            strcpy(a1.user,user);
            strcpy(a1.pass,pass);
            fil.open("alumnidetails.txt",ios::out|ios::app|ios::binary);
            fil.write((char*)&a1,sizeof(a1));
            fil.close();
            sleep(3);
            Alumni_login();
        }
    }
}
void delete_account(){
    signup a1;
    system("cls");
    cout<<"\t\t\t\t\t----------------------------------------\n";
	cout<<"\t\t\t\t\t            DELETE ACCOUNT\n";
	cout<<"\t\t\t\t\t----------------------------------------\n";
	fstream fin,fout;
	fin.open("alumnidetails.txt",ios::in|ios::binary);
    fout.open("tempfile.txt",ios::out|ios::binary);
    char user[20],pass[20];
    cout<<"\n\nENTER USERNAME:";
    gets(user);
    cout<<"\nENTER PASSWORD:";
    gets(pass);
    int a=0;
    while(fin.read((char*)&a1,sizeof a1)){
  		if (!strcmp(a1.user,user)){
            if(!strcmp(a1.pass,pass))
                a=1;
		}
		else
            fout.write((char*)&a1,sizeof(a1));
 	}
 	fin.close();
    fout.close();
 	if(a==1){
        cout<<"\nACCOUNT DELETED SUCCESSFULLY";
        remove("alumnidetails.txt");
        rename("tempfile.txt","alumnidetails.txt");
        sleep(2);
        Alumni();
 	}
 	else{
        cout<<"\nNO USERNAME EXISTS";
        remove("tempfile.txt");
        sleep(2);
        delete_account();
 	}
}
void Alumni_work(char user[20]){
    system("cls");
    cout<<"\t\t\t\t\t----------------------------------------\n";
	cout<<"\t\t\t\t\t                ALUMNI \n";
	cout<<"\t\t\t\t\t----------------------------------------\n";
    cout<<"\nHi "<<user<<",";
    cout<<"\n\n1. COLLEGE";
    cout<<"\n2. UNIVERSITY";
    cout<<"\n3. LOGOUT";
    cout<<"\n\nENTER YOUR OPTION:";
    char val;
    val=getche();
    switch(val){
        case '1':
            College_rating(user);
            break;
        case '2':
            University_rating(user);
            break;
        case '3':
            sleep(2);
            Alumni();
            break;
    }
}
void College_rating(char user[20]){
    system("cls");
    char c_name[20];
    int a;
    college c1;
    cout<<"\t\t\t\t\t----------------------------------------\n";
	cout<<"\t\t\t\t\t               "<<user;
	cout<<"\n\t\t\t\t\t----------------------------------------\n";
    cout<<"\n\nENTER COLLEGE NAME:";
    gets(c_name);
    fstream fil;
    fil.open("collegelist.txt",ios::in|ios::binary);
    while(fil.read((char*)&c1,sizeof c1)){
        if(strcmp(c1.c_name,c_name)==0){
            a=1;
            break;
        }
        else
            a=0;
    }
    fil.close();
    if(a==0){
        cout<<"\nNO COLLEGE FOUND.";
        sleep(3);
        College_rating(user);
    }
    else{
        fil.open(c_name,ios::out|ios::app|ios::binary);
        rating r1;
        if(!r1.input(user))
            College_rating(user);
        else{
            fil.write((char*)&r1,sizeof(r1));
            fil.close();
            sleep(1);
            cout<<"\nYOUR REVIEWS ARE SAVED SUCCESSFULLY";
            sleep(2);
            Alumni_work(user);
        }
    }
}
void University_rating(char user[20]){
    system("cls");
    char u_name[20];
    int a;
    university u1;
    cout<<"\t\t\t\t\t----------------------------------------\n";
	cout<<"\t\t\t\t\t               "<<user;
	cout<<"\n\t\t\t\t\t----------------------------------------\n";
    cout<<"\n\nENTER UNIVERSITY NAME:";
    gets(u_name);
    fstream fil;
    fil.open("universitylist.txt",ios::in|ios::binary);
    while(fil.read((char*)&u1,sizeof u1)){
        if(strcmp(u1.u_name,u_name)==0){
            a=1;
            break;
        }
        else
            a=0;
    }
    fil.close();
    if(a==0){
        cout<<"\nNO UNIVERSITY FOUND.";
        sleep(3);
        University_rating(user);
    }
    else{
        fil.open(u_name,ios::out|ios::app|ios::binary);
        rating r1;\
        if(!r1.input(user))
            University_rating(user);
        else{
            fil.write((char*)&r1,sizeof(r1));
            fil.close();
            sleep(1);
            cout<<"\nYOUR REVIEWS ARE SAVED SUCCESSFULLY";
            sleep(2);
            Alumni_work(user);
        }
    }
}
///////////////////////////////////////////////////
//NEW STUDENT
void Newstudent(){
	system("cls");
	cout<<"\t\t\t\t\t----------------------------------------\n";
	cout<<"\t\t\t\t\t       NEW STUDENT LOGIN/SIGNUP\n";
	cout<<"\t\t\t\t\t----------------------------------------\n";
	cout<<"\n\n1.LOGIN";
	cout<<"\n2.SIGNUP";
	cout<<"\n3.DELETE ACCOUNT";
	cout<<"\n4.BACK TO MENU";
	cout<<"\n\nENTER AN OPTION:";
	char val;
	val=getche();
	switch(val){
		case '1':
			Newstudent_login();
			break;
		case '2':
			Newstudent_signup();
			break;
        case '3':
            Newstudent_account();
            break;
        case '4':
			system("cls");
			main();
            break;
		default:
			cout<<"\n\nINVALID OPTION!!";
			sleep(2);
			Newstudent();
	}
}
void Newstudent_login(){
    system("cls");
	cout<<"\t\t\t\t\t----------------------------------------\n";
	cout<<"\t\t\t\t\t          NEW STUDENT LOGIN\n";
	cout<<"\t\t\t\t\t----------------------------------------\n";
	fstream fil;
 	signup a1;
 	fil.open("newstudentdetails.txt",ios::in|ios::binary);
    char user[20],pass[20];
    cin.sync();
    cout<<"\n\nENTER USERNAME:";
    gets(user);
    cout<<"\nENTER PASSWORD:";
    gets(pass);
    int a;
    while(fil.read((char*)&a1,sizeof a1)){
  		if (strcmp(a1.user,user)==0 && strcmp(a1.pass,pass)==0){
            a=1;
            break;
		}
 	}
 	fil.close();
 	if(a==1){
        cout<<"\n LOGIN SUCCESSFUL";
        sleep(2);
        Newstudent_work(user);
 	}
 	else{
        cout<<"\nINVALID CREDENTIALS!!";
        sleep(2);
        Newstudent_login();
 	}
}
void Newstudent_signup(){
    system("cls");
	cout<<"\t\t\t\t\t----------------------------------------\n";
	cout<<"\t\t\t\t\t          NEW STUDENT SIGNUP\n";
	cout<<"\t\t\t\t\t----------------------------------------\n";
    signup a1;
	fstream fil;
 	fil.open("newstudentdetails.txt",ios::out|ios::in|ios::binary);
  	char user[20],pass[20];
  	string pass1;
  	int a=0;
  	cin.sync();
    cout<<"\n\nENTER USERNAME:";
    gets(user);
    cout<<"\nENTER PASSWORD:";
    getline(cin,pass1);
    if(pass1.length()==0){
        cout<<"\n INVALID";
        sleep(2);
        Newstudent_signup();
    }
    else{
        strcpy(pass,pass1.c_str());
        while(fil.read((char*)&a1,sizeof a1)){
            if (strcmp(a1.user,user)==0){
                a=1;
                break;
            }
        }
        fil.close();
        if(a==1){
            cout<<"\nUSERNAME ALREADY EXISTS.";
            sleep(2);
            Newstudent_signup();
        }
        else{
            cout<<"\n\nSIGNUP SUCCESSFUL"<<endl;
            strcpy(a1.user,user);
            strcpy(a1.pass,pass);
            fil.open("newstudentdetails.txt",ios::out|ios::app|ios::binary);
            fil.write((char*)&a1,sizeof(a1));
            fil.close();
            sleep(3);
            Newstudent_login();
        }
    }
}
void Newstudent_account(){//delete account of new student
    signup a1;
    system("cls");
    cout<<"\t\t\t\t\t----------------------------------------\n";
	cout<<"\t\t\t\t\t            DELETE ACCOUNT\n";
	cout<<"\t\t\t\t\t----------------------------------------\n";
	fstream fin,fout;
	fin.open("newstudentdetails.txt",ios::in|ios::binary);
    fout.open("tempfile.txt",ios::out|ios::binary);
    char user[20],pass[20];
    cout<<"\n\nENTER USERNAME:";
    gets(user);
    cout<<"\nENTER PASSWORD:";
    gets(pass);
    int a=0;
    while(fin.read((char*)&a1,sizeof a1)){
  		if (!strcmp(a1.user,user)){
            if(!strcmp(a1.pass,pass))
                a=1;
		}
		else
            fout.write((char*)&a1,sizeof(a1));
 	}
 	fin.close();
 	fout.close();
 	if(a==1){
        cout<<"\nACCOUNT DELETED SUCCESSFULLY";
        remove("newstudentdetails.txt");
        rename("tempfile.txt","newstudentdetails.txt");
        sleep(2);
        Newstudent();
 	}
 	else{
        cout<<"\nNO USERNAME EXISTS";
        remove("tempfile.txt");
        sleep(2);
        Newstudent();
 	}
}
void Newstudent_work(char user[20]){
    system("cls");
    cout<<"\t\t\t\t\t----------------------------------------\n";
	cout<<"\t\t\t\t\t                NEW STUDENT \n";
	cout<<"\t\t\t\t\t----------------------------------------\n";
    cout<<"\nHi "<<user<<",";
    cout<<"\n\n1. COLLEGE";
    cout<<"\n2. UNIVERSITY";
    cout<<"\n3. LOGOUT";
    cout<<"\n\nENTER YOUR OPTION:";
    char val;
    val=getche();
    switch(val){
        case '1':
            College(user);
            break;
        case '2':
            University(user);
            break;
        case '3':
            sleep(2);
            Newstudent();
            break;
    }
}
void College(char user[20]){
    system("cls");
    char c_name[20];
    int a;
    college c1;
    cout<<"\t\t\t\t\t----------------------------------------\n";
	cout<<"\t\t\t\t\t               "<<user;
	cout<<"\n\t\t\t\t\t----------------------------------------\n";
    cout<<"\n\nENTER COLLEGE NAME:";
    gets(c_name);
    fstream fil;
    fil.open("collegelist.txt",ios::in|ios::binary);
    while(fil.read((char*)&c1,sizeof c1)){
        if(strcmp(c1.c_name,c_name)==0){
            a=1;
            break;
        }
        else
            a=0;
    }
    fil.close();
    if(a==0){
        cout<<"\nNO COLLEGE FOUND.";
        sleep(3);
        College(user);
    }
    else{
        system("cls");
        fil.open(c_name,ios::in|ios::binary);
        cout<<"\t\t\t\t\t----------------------------------------\n";
        cout<<"\t\t\t\t\t               "<<user;
        cout<<"\n\t\t\t\t\t----------------------------------------\n";
        cout<<"\nCOLLEGE NAME:"<<c1.c_name;
        cout<<"\nAFFILIATED UNIVERSITY NAME:"<<c1.u_name;
        cout<<"\nAVAILABLE COURSES:"<<c1.courses;
        if(!fil){
            cout<<"\n\nNO RATINGS AND REVIEWS ARE AVAILABLE";
            sleep(2);
            Newstudent_work(user);
        }
        else{
            int sum=0,count=0;
            rating r1;
            while(fil.read((char*)&r1,sizeof(r1))){
                count++;
                sum=sum+r1.rating;
            }
            fil.close();
            sum=sum/count;
            count=0;
            cout<<"\n\nAVG. RATING:";
            while(sum>0){
                cout<<"*";
                sum--;
            }
            cout<<"\n-----------";
            cout<<"\n\nREVIEWS:\n";
            cout<<"-------";
            fil.open(c_name,ios::in|ios::binary);
            while(fil.read((char*)&r1,sizeof(r1))){
                count++;
                cout<<endl<<count<<".";
                cout<<r1.review<<"\n";
            }
            fil.close();
            getchar();
            Newstudent_work(user);
        }
    }
}
void University(char user[20]){
    system("cls");
    char u_name[20];
    int a;
    university u1;
    cout<<"\t\t\t\t\t----------------------------------------\n";
	cout<<"\t\t\t\t\t               "<<user;
	cout<<"\n\t\t\t\t\t----------------------------------------\n";
    cout<<"\n\nENTER UNIVERSITY NAME:";
    gets(u_name);
    fstream fil;
    fil.open("universitylist.txt",ios::in|ios::binary);
    while(fil.read((char*)&u1,sizeof u1)){
        if(strcmp(u1.u_name,u_name)==0){
            a=1;
            break;
        }
        else
            a=0;
    }
    fil.close();
    if(a==0){
        cout<<"\nNO UNIVERSITY FOUND.";
        sleep(3);
        University(user);
    }
    else{
        system("cls");
        fil.open(u_name,ios::in|ios::binary);
        cout<<"\t\t\t\t\t----------------------------------------\n";
        cout<<"\t\t\t\t\t               "<<user;
        cout<<"\n\t\t\t\t\t----------------------------------------\n";
        cout<<"\nUNIVERSITY NAME:"<<u1.u_name;
        cout<<"\nAVAILABLE COURSES:"<<u1.courses;
        if(!fil){
            cout<<"\n\nNO RATINGS AND REVIEWS ARE AVAILABLE";
            sleep(2);
            Newstudent_work(user);
        }
        else{
            int sum=0,count=0;
            rating r1;
            while(fil.read((char*)&r1,sizeof(r1))){
                count++;
                sum=sum+r1.rating;
            }
            fil.close();
            sum=sum/count;
            count=0;
            cout<<"\n\nAVG. RATING:";
            while(sum>0){
                cout<<"*";
                sum--;
            }
            cout<<"\n-----------";
            cout<<"\n\nREVIEWS:\n";
            cout<<"-------";
            fil.open(u_name,ios::in|ios::binary);
            while(fil.read((char*)&r1,sizeof(r1))){
                count++;
                cout<<endl<<count<<".";
                cout<<r1.review<<"\n";
            }
            fil.close();
            getchar();
            Newstudent_work(user);
        }
    }
}
///////////////////////////////////////////////////////////////////
int main(){
	char val;
	cout<<"\t\t\t\t\t----------------------------------------\n";
	cout<<"\t\t\t\t\t       COLLEGE RECOMMENDER SYSTEM\n";
	cout<<"\t\t\t\t\t----------------------------------------\n";
	cout<<"\n\nYOU WANT TO ENTER AS:\n\n";
	cout<<"1.ADMIN\n";
	cout<<"2.ALUMNI \n";
	cout<<"3.NEW STUDENT\n";
	cout<<"4.EXIT\n\n";
	cout<<"ENTER AN OPTION:";
	val=getche();
	switch(val){
		case '1':
			Admin_login();
			break;
		case '2':
			Alumni();
			break;
		case '3':
			Newstudent();
			break;
		case '4':
			exit(0);
			break;
		default:
			cout<<"\nINVALID OPTION";
			sleep(1);
			system("cls");
			main();
	}
}
