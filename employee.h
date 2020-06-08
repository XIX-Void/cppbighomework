//employee.h
#include"date.cpp"
#include<string>
using namespace std;

class employee //虚类
{
protected:
	Date e_date;
	char name[20];            //姓名
	int individualEmpNo;      //个人编号
	int grade;                //级别
	float accumPay;           //月薪总额
	static int employeeNo;    //本公司职员编号目前最大值
public:
	employee();               //构造函数
	~employee();              //析构函数
	void setDate(int a,int b, int c);
	virtual void pay() = 0;   //计算月薪函数（纯虚函数）
	virtual void promote(int increment = 0) = 0;//升级函数（虚函数）
	void setName(char*);      //设置姓名函数
	char * getName();          //提取姓名函数
	int getIndividualEmpNo(); //提取编号函数
	int getGrade();           //提取级别函数
	float getaccumPay();      //提取月薪函数
	template<typename T>T * capName(T *abc);
	string getDate();

	bool operator> (const employee & emp) {      //运算符重载，比较职员工资大小
		if (accumPay > emp.accumPay)
			return true;
		else return false;
	}


};


class technician :public employee
{
private:
	float hourlyRate;        //每小时金额        
	int workHours;           //当月工作时数
public:
	technician();            //构造函数
	technician(int year,int month,int day,char a[20],int grade,int wh);
	void SetworkHours(int wh);//设置工作时数函数
	void pay();              //计算月薪函数
	void promote(int);       //升级函数
};


class salesman :virtual public employee
{
protected:
	float CommRate;        //按照销售额提取酬金的百分比        
	float sales;           //当月销售额
public:
	salesman();            //构造函数
	salesman(int year,int month,int day,char a[20],int grade,int sl);
	void Setsales(float sl);//设置销售额函数
	void pay();              //计算月薪函数
	void promote(int);       //升级函数
};


class manager :virtual public employee //经理类
{
protected:
	float monthlyPay;        //固定月薪数
public:
	manager();               //构造函数
	manager(int year,int month,int day,char a[20],int grade);
	void pay();              //计算月薪函数
	void promote(int);       //升级函数
};


class salesmanager : public manager, public salesman
{
public:
	salesmanager();            //构造函数
	salesmanager(int year,int month,int day,char a[20],int grade,int sl);
	void pay();              //计算月薪函数
	void promote(int);       //升级函数
}; 
