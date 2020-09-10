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
#pragma warning(disable : 4996)//关闭vs2019版本的 4996警告


using namespace std;

bool isEnd = false;
string arr[4] = { "注销","正常","冻结","挂失" };

class IDCard {

    private:
        string stuId;//学号
        string cardId;//卡号
        string sname;//姓名
        double blance;//余额
        string pwd;//密码
        int status;//状态

    public:
        IDCard(){

        }
        IDCard(string stuId, string cardId, string sname, double blance, string pwd, int status) {

            this->stuId = stuId;
            this->cardId = cardId;
            this->sname = sname;
            this->blance = blance;
            this->pwd = pwd;
            this->status = status;

        }

        //公开的方法，让其他对象可以访问到私有化的属性  get/set

        void setStuId(string stuId) {
            this->stuId = stuId;
        }
        string getStuId() {
            return stuId;
        }
        void setCardId(string cardId) {
            this->cardId = cardId;
        }
        string getCardId() {
            return cardId;
        }
        void setSname(string sname) {
            this->sname = sname;
        }
        string getSname() {
            return sname;
        }
        void setBlance(double blance) {
            this->blance = blance;
        }
        double getBlance() {
            return blance;
        }
        void setPwd(string pwd) {
            this->pwd = pwd;
        }
        string getPwd() {
            return pwd;
        }

        void setStatus(int status) {
            this->status = status;
        }
        int  gerStatus() {

            return status;
        }

        //在对象的里面，再来定义一个方法。
        void show() {

            cout << "\n\t" << stuId << "\t" << cardId << "\t" << sname << "\t" << blance << "\t" << arr[status];
        }
};

//方法控制类
class Controller { 

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
void Controller::showCopy() {//显示版权
  
    cout << "\n\n\t ********************湖南交通工程学院学籍管理系统****************************" << endl;
    cout << "\n\n\t ******************** 版权归 ITingLight 所有  ****************************" << endl;

}

bool Controller::login() {//登录
  

        string account;
        char pwd[20];
        char ch;
        int index = 0;

        showCopy();//显示版权
        cout << " \n请输入您的账号：";
        cin >> account;

        cout << " \n请输入您的密码：";
        while ((ch = getch()) != 13) {

            if (ch == 8) {

                if (index <= 0) {
                    index = 0;
                }
                else {
                    cout << "\b \b";
                    index--;
                }
            }
            else {
                pwd[index++] = ch;
                cout << "*";

            }
        }
        pwd[index] = '\0';

        if (account == "itinglight" &&  strcmp(pwd,"123")==0) {//检查账号密码是否正确

            //当密码正确时
            return false;
        }
        else
        {
           // cout << "\n\n你输入的账号或密码不对，请确认后重新输入。\n";
        }
        return true;
   

}
//定义一个vector集合，单纯用来存放IDCard对象

vector<IDCard>cards;

void Controller::openCard() {//1.开卡

    showCopy();//显示版权

    cout << "\n\n\t\t***********************1.开卡************************";

    string stuId, cardId, sname, pwd;
    double balance;

    cout << "\n\t请输入学号：";
    cin >> stuId;

    cout << "\n\t请输入卡号：";
    cin >> cardId;

    cout << "\n\t请输入姓名：";
    cin >> sname;

    cout << "\n\t请输入密码：";
    cin >> pwd;

    cout << "\n\t请输入充值金额：";
    cin >> balance;

    //创建对象 
    IDCard card = IDCard(stuId, cardId, sname, balance, pwd, 1);

    //提示框
    int result = MessageBox(NULL, TEXT("您确定要添加此数据吗？"),TEXT("确认提示"), MB_YESNO | MB_ICONQUESTION);
    // TEXT的作用为：把中文转换成不会乱码的格式，在vs2019中不使用会报错

    if (result == 6) {
        //用户点击确认添加数据
        cards.push_back(card);
        cout << "\n\n\t开卡成功";
    }
    else {
        cout << "已取消开卡！";
    }
    cout << "\n\n\t";
    system("pause");

}
void Controller::increment() {//2.充值


}

void Controller::viewInfo() {//4.浏览

    //显示版权
    showCopy();
    cout << "\n\n\t\t***********************4.浏览************************";

    if (cards.size() <= 0) {

        cout << "\n\n\t暂无数据。。。\n\n\t";
        system("pause");
    }
    else {
        //有数据，显示数据
        cout << "\n\t学号\t卡号\t姓名\t余额\t状态";
            for (int i = 0,len = cards.size(); i < len; i++) {
                cards[i].show();
            }

            cout << "\n\n\t";
            system("pause");
    }
    
}

void Controller::removeCard() {//8.删除数据


}



void Controller::menu() { //菜单
    int choice = 0;
    do {
      
        showCopy();
        cout << "\n\n\t********************主菜单********************";
        cout << "\n\n\t********************1,开卡********************";
        cout << "\n\n\t********************2.充值********************";
        cout << "\n\n\t********************3.刷卡********************";
        cout << "\n\n\t********************4.浏览********************";
        cout << "\n\n\t********************5.查询********************";
        cout << "\n\n\t********************6.挂失********************";
        cout << "\n\n\t********************7.改密********************";
        cout << "\n\n\t********************8.删除********************";
        cout << "\n\n\t********************9.退出********************";

        cout << "\n\n\t请选择您要进行的操作：（1-9）";

        cin >> choice;
        //开始判断选择
        switch (choice) {

        case 1: openCard(); break; //开卡
        case 2: increment(); break;
        case 3:; break;
        case 4:viewInfo(); break;//4.浏览
        case 5:; break;
        case 6:; break;
        case 7:cout << "hello"; break;
        case 8:removeCard(); break;
        case 9:isEnd = true; break;

        }

    } while (choice <=0 || choice < 9);


}


int main() {

    Controller controller;//创建一个Controller的对象

 
        while (controller.login()) {

            
            cout << "\n\n你输入的账号或密码不对，请确认后重新输入。\n";

        }
        do {

            controller.menu();
             
        } while (!isEnd);
  
    



    return 0;
}