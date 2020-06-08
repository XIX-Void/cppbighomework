//date.h
#include<string>
using namespace std;

#ifndef __DATE_H__
#define __DATE_H__
class Date{
private:
    int year;
    int month;
    int day;
    int totalDays; //从00年1月1日开始的第n天
public:
    Date(int year,int month,int day);
    void changeDate(int year,int month,int day);
    int getYear() const{return year;}
    int getMonth() const{return month;}
    int getDay() const{return day;}
    int getMaxDay() const;
    bool isLeapYear() const{
        return year%4 == 0 && year%100!=0||year%400==0;
    }
    void show() const;
    string toString()const;
    //计算两个日期差多少天
    int distance(const Date &date){
        return totalDays-date.totalDays;
    }
};
#endif