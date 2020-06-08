#include <iostream>
#include<iostream>
#include<cstring>
#include<string>
#include"employee.h"
using namespace std;
int employee::employeeNo = 1000;       //设置员工编号基数1000

employee::employee()
{   
    Date e_date;
    individualEmpNo = employeeNo++;    //设置编号
    grade = 1;                         //设置初始等级为1
    accumPay = 3000.0;                    //月薪初始为0
}    //构造函数 


void employee::setDate(int a,int b, int c){
    e_date.changeDate(a,b,c);
}

string employee::getDate(){
    return e_date.toString();
}

employee::~employee()
{}

void employee::promote(int increment)
{
    grade += increment;                //升级由increment决定
}

void employee::setName(char* names)
{
    strcpy_s(name, names);          //设置名字
}

char* employee::getName()//提取成员姓名
{
    return name;
}

int employee::getIndividualEmpNo()    //提取成员编号
{
    return individualEmpNo;
}

int employee::getGrade()    //提取成员级别
{
    return grade;
}

float employee::getaccumPay()    //提取月薪
{   
    if( accumPay >= 50000 ){
      throw "This man's salary has problem!";
    }
    return accumPay;
}

technician::technician()    //每小时酬金设置
{
    hourlyRate=100;
}

technician::technician(int year,int month,int day,char a[20],int grade,int wh){
    e_date.changeDate(year,month,day);
    strcpy(this->name,a);
    this->grade = grade;
    workHours = wh;
    hourlyRate=100;
}

void technician::SetworkHours(int wh)    //设置工作时间
{
    workHours = wh;
}

void technician::pay()    //计算月薪，按小时
{
    accumPay = hourlyRate * workHours;
}

void technician::promote(int)    //调用基类升级函数，升两级
{
    employee::promote(2);
}

salesman::salesman()      //销售提成比例
{
    CommRate = 0.04; 
}

salesman::salesman(int year,int month,int day,char a[20],int grade,int sl){
    e_date.changeDate(year,month,day);
    strcpy(this->name,a);
    this->grade = grade;
    sales = sl;
    CommRate = 0.04; 
}

void salesman::Setsales(float sl) //设置销售额
{
    sales = sl;
}

void salesman::pay()  //月薪=销售提成
{
   accumPay=sales*CommRate;
}

void salesman::promote(int)  //调用基类升级函数，升0级
{
    employee::promote(0);
}


manager::manager()   //固定月薪8000
{
    monthlyPay = 8000;
}

manager::manager(int year,int month,int day,char a[20],int grade){
    e_date.changeDate(year,month,day);
    strcpy(this->name,a);
    this->grade = grade;
    monthlyPay = 8000;
}
void manager::pay()   //月薪总额 为固定月薪数
{
    accumPay = monthlyPay;
}

void manager::promote(int) ////调用基类升级函数，升3级
{
    employee::promote(3);
}

salesmanager::salesmanager()
{
    monthlyPay = 5000;
    CommRate = 0.005;
}

salesmanager::salesmanager(int year,int month,int day,char a[20],int grade,int sl){
    e_date.changeDate(year,month,day);
    strcpy(this->name,a);
    this->grade = grade;
    sales = sl;
    monthlyPay = 5000;
    CommRate = 0.005;
}

void salesmanager::pay()  //月薪=基本月薪+销售提成
{
    accumPay=monthlyPay+CommRate*sales;
 }

void salesmanager::promote(int)  //月薪=基本月薪+销售提成
{
    employee::promote(2);
}

template<typename T>
T * employee::capName(T *abc){
    T *p,*temp;
    p = abc;
    temp = abc;
    for(;*p;){
        if(*p>='a'&&*p<='z'){
            *p = *p + 'A'-'a';
        }
        p++;
    }
    return temp;
}
