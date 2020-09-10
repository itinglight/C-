# C++
 Sophomore first semester final assessment

大一下学期期末考核设计

````c++
//
//  main.cpp
//  c++wark
//
//  Created by 姜斌 on 2020/9/9.
//  Copyright © 2020 姜斌. All rights reserved.
//

#include<iostream>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<vector>


using namespace std;

class IDCard{
    
    private:
        string stuId;
        string cardId;
        string sname;
        double blance;
        string pwd;
        int status;
        
    public:
        IDCard(){
            
        }
        IDCard(string stuId,string cardId,string sname, double blance,string pwd, int status ){
            
            this -> stuId = stuId;
            this -> cardId = cardId;
            this -> sname = sname;
            this -> blance = blance;
            this -> pwd = pwd;
            this -> status = status;
            
        }
        
        void setStuId(string stuId){
            this -> stuId =stuId;
            
        }
};

//方法控制类
class Controller{
    
    public:
        void showCopy();    //显示版权
        bool login();       // 登录
        void menu();        //菜单
        
        void openCard();        //1。开卡
        void increment();    //2.充值
        void payment();     //3.付款
        void viewInfo();   //4.浏览
        void removeCard();  //8.删除数据
        
    
};

void Controller::openCard(){//1.开卡
    
    
}
void Controller::increment(){//2.充值
    
    
}

void Controller::viewInfo(){//3.浏览
    
    
}

void Controller::removeCard(){//8.删除数据
    
    
}
void Controller::showCopy(){//显示版权
    system("cls");
    cout<<"\n\n\t ********************湖南交通工程学院学籍管理系统****************************"<<endl;
    cout<<"\n\n\t ******************** 版权归 ITingLight 所有  ****************************"<<endl;
    
}

bool Controller::login(){//登录
        string account;
        string mypwd;
    char pwd[20];
    char ch;
    int index=0;
    
   
        showCopy();//显示版权
    
        cout<<" \n请输入您的账号：";
        cin>>account;
        
        cout<<" \n请输入您的密码：";
    while(ch =getch()!=13){
        
        if(ch==8){
                    if(index <= 0){
                        index =0;
                    }
                    else {
                        cout<<"\b \b";
                        index--;
                    }
        else{
            pwd[index++]=ch;
            cout<<"*";
        }
        }
    }
    pwd[index]='\0';
    
        cin>>mypwd;
        
    if(account == "itinglight" && mypwd == "mishuyi")
        return true;
    else
        cout<<"你输入的账号或密码不对，请确认后重新输入。";
        return false;
    
   }

void Controller::menu(){
    int choice=0;
    do{
        
        system("cls");
        showCopy();
        cout<<"\n\n\t********************主菜单********************";
        cout<<"\n\n\t********************1,开卡********************";
        cout<<"\n\n\t********************2.充值********************";
        cout<<"\n\n\t********************3.刷卡********************";
        cout<<"\n\n\t********************4.浏览********************";
        cout<<"\n\n\t********************5.查询********************";
        cout<<"\n\n\t********************6.挂失********************";
        cout<<"\n\n\t********************7.改密********************";
        cout<<"\n\n\t********************8.删除********************";
        cout<<"\n\n\t********************9.退出********************";
        
        cout<<"请选择您要进行的操作：（1-9）";
    
    cin>>choice;
    }while(choice>=1 && choice<=9);
    
    //开始判断选择
    switch(choice){
            
            case 1: menu(); break;
            case 2: increment();break;
            case 3:increment();break;
            case 4:;break;
            case 5:;break;
            case 6:;break;
            case 7:;break;
            case 8:removeCard();break;
            case 9:isEnd=true;break;
            
    }
}


int main() {
    
    Controller controller;//创建一个Controller的对象
   
    if(controller.login()){
        
        do{
            controller.menu();
        }while(!isEnd);
        
    }
    controller.menu();
    
    
   
    return 0;
}


````

**.gitgnore文件的作用：**

如果打开项目的时候，报“Could not open '***.VC.opendb'”之类的错误，说明git版本控制中加入了***.VC.opendb。

***.VC.opendb是在项目打开的时候产生的零时文件，每次打开*.sln都会重新产生一个新的，然后在关闭工程的时候，该文件会自动删除。

因此，每次重新打开工程项目的时候，git会报错说找不到正确的该文件。

解决方案：

在 "项目路径\.git\info\" 路径下找到 "exclude" 文件，用文本编辑工具打开，在末尾加上 "*.opendb" 以忽略上述文件。