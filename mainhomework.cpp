#include<iostream>
#include<string>
#include"employee.cpp"
#include<vector>
using namespace std;
int main(){
    vector<employee*> bubble_sort(vector<employee*> v);
    vector<employee*>vec;
    int i,w = 1;
    int number = 0;
    cout << "How many people import?"<<endl;
    cin >> w;
    //录入信息
    for(int j = 1;j<=w;j++){
        cout << "choose a section to import: "<<endl<<"1-technician,2-salesman,3-manager,4-salesmanger"<<endl;
        cin >> i;
        employee *employee;
        
        int year,month,day,grade;
        char a[20];
        switch(i){
            case 1:
            cout << "enter the message like: Year,Month,Day,Name,Grade,Workinghours" << endl;
            int wh;
            cin >> year >> month >> day >> a >> grade >> wh;
            employee = new technician(year,month,day,a,grade,wh);
            /*employee->setName((char*)"technician");
            employee->setDate(2020,10,1);
            dynamic_cast<technician*>(employee)->SetworkHours(123);
            dynamic_cast<technician*>(employee)->pay();*/
            vec.push_back(employee);
            number++;
            break;
            case 2:
            cout << "enter the message like: Year,Month,Day,Name,Grade,Sales" << endl;
            int sl;
            cin >> year >> month >> day >> a >> grade >> sl;
            employee = new salesman(year,month,day,a,grade,sl);
            vec.push_back(employee);
            number++;
            break;
            case 3:
            cout << "enter the message like: Year,Month,Day,Name,Grade" << endl;
            cin >> year >> month >> day >> a >> grade;
            employee = new manager(year,month,day,a,grade);
            vec.push_back(employee);
            number++;
            break;
            case 4:
            cout << "enter the message like: Year,Month,Day,Name,Grade,Sales" << endl;
            int sl_4;
            cin >> year >> month >> day >> a >> grade >> sl_4;
            employee = new salesmanager(year,month,day,a,grade,sl);
            vec.push_back(employee);
            number++;
            break;
        }
    }
    cout <<"Date\t\tidNum\tName\tGrade\tSalary"<< endl;


    //遍历结果
    for(int i = 0;i<vec.size();i++){
        try{
        vec[i]->pay();
        cout << vec[i]->getDate()<<"\t"<< vec[i]->getIndividualEmpNo() <<"\t"<< vec[i]->getName() << "\t"
        << vec[i]->getGrade()<<"\t"<<vec[i]->getaccumPay()<<endl;
        }catch(const char* msg){
            cout <<msg<<endl;
        }
    }

    vector<employee*> vec1 = bubble_sort(vec);

    cout <<"\t Sort by monthy money(Increase)"<< endl;
    cout <<"Date\t\tidNum\tName\tGrade\tSalary"<< endl;

    for(int i = 0;i<vec.size();i++){
        try{
        vec1[i]->capName(vec1[i]->getName());
        vec1[i]->pay();
        cout << vec1[i]->getDate()<<"\t"<< vec1[i]->getIndividualEmpNo() <<"\t"<< vec1[i]->getName() << "\t"
        << vec1[i]->getGrade()<<"\t"<<vec1[i]->getaccumPay()<<endl;
        }catch(const char* msg){
            cout <<msg<<endl;
        }
    }
}


//冒泡排序月薪降序输出名单
vector<employee*> bubble_sort(vector<employee*> v){
    employee *p;
	for(int i = 0; i < v.size() - 1; i ++){
		for (int j = 0; j < v.size() - 1 - i; j++){
			if (*v[j] > *v[j + 1]) {
				p = v[j];
				v[j] = v[j + 1];
				v[j + 1] = p;
			}
		}
    }
	return v;
}