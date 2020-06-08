#include<iostream>
#include<string>
#include<cstdlib>
#include "date.h"
using namespace std;
namespace{
    //存储平年某个月1日之前有多少天，便于getMaxDay函数实现
    const int DAYS_BEFORE_MONTH[]={0,31,59,90,120,151,181,212,243,273,304,334,365};
};


Date::Date(int year = 2000,int month = 1,int day = 1):year(year),month(month),day(day){
    if(day<=0||day>getMaxDay()){
        cout<<"Invalid date:";
        show();
        cout<<endl;
        exit(1);
    }
    int years=year-1;
    totalDays = years*365+years/4-years/100+years/400+DAYS_BEFORE_MONTH[month-1]+day;
    if(isLeapYear()&&month>2) totalDays++;
}


void Date::changeDate(int year,int month,int day){
    this->year = year;
    this->month = month;
    this->day = day;
}

int Date::getMaxDay() const{
    if(isLeapYear()&&month==2){
        return 29;
    }else{
        return DAYS_BEFORE_MONTH[month]-DAYS_BEFORE_MONTH[month-1];
    }
}
void Date::show() const{
    cout<<getYear()<<"-"<<getMonth()<<"-"<<getDay();
}

string Date::toString() const{
    return to_string(year) + "-" + to_string(month) + "-" + to_string(day) + "  ";
}