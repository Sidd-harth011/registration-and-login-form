#include<iostream>
#include<fstream>
#include<windows.h>
#include<sstream>
using namespace std;

class Login{
    private:
    string LoginID , Password;
    public:
    Login():LoginID(""),Password(""){}
    void setID(string id){
        LoginID = id;
    }
    void setPW(string pw){
        Password = pw;
    }
    string getID(){
        return LoginID;
    }
    string getPW(){
        return Password;
    }
};

void registration(Login log){
    system("cls");
    string id,pw;
    cout<<"\tenter loginID:";
    cin>>id;
    log.setID(id);
    start:
    cout<<"\tenter a strong password: ";
    cin>>pw;
    if(pw.length()>=8){
        log.setPW(pw);
    }else{
        cout<<"\tenter minimun password of 8 characters"<<endl;
        goto start;
    }
    ofstream outfile("C:\\Users\\Siddharth\\Desktop\\C++ Projects\\registration_and_login_form\\loginData.txt", ios::app);
    if(!outfile){
        cout<<"\terror : file cannot open";
    }else{
        outfile<<"\t"<<log.getID()<<" : "<<log.getPW()<<'\n'<<'\n';
        cout<<"\tuser registered successfully"<<endl;
    };
    outfile.close();
    Sleep(3000);
};

void login1(){
system("cls");
string id,pw;
cout<<"\tenter login id : ";
cin>>id;
cout<<"\tenter login password : ";
cin>>pw;
ifstream infile("C:\\Users\\Siddharth\\Desktop\\C++ Projects\\registration_and_login_form\\loginData.txt");
if(!infile){
    cout<<"\terror : file cannot open"<<'\n';
}else{
    string line;
    bool found = false;
    while(getline(infile,line)){
        stringstream ss;
        ss<<line;
        string userID,userPW;
        char delimiter;
        ss>>userID>>delimiter>>userPW;
        if(id==userID && pw == userPW){
            found = true;

            cout<<"\tplease wait"<<endl;
            for(int i = 0 ; i < 3 ; i++){
                cout<<".";
                Sleep(800);
            }
            system("cls");
            cout<<"\twelcome to this page"<<endl;
        }
    }
    if(!found){
        cout<<"\terror : incorrect loginID or password"<<endl;
    }
    infile.close();
}
Sleep(5000);
}

int main(){
    Login log;
    bool exit = false;
    while(!exit){
        system("cls");
        int val;
        cout<<"\tWelcome to registration & login form"<<endl;
        cout<<"\t************************************"<<'\n';
        cout<<"\t1.register."<<endl;
        cout<<"\t2.login."<<endl;
        cout<<"\t3.exit."<<endl;
        cout<<"\tenter choice : ";
        cin>>val;
        if(val==1){
            registration(log);
        }else if(val==2){
            login1();
        }
        else if(val == 3){
            system("cls");
            exit=true;
            cout<<"\tgood luck"<<endl;
            Sleep(3000);
        }
        Sleep(3000);
            
    };
};