#include <iostream>
#include <string>
#include <memory> // 智能指针头文件

#include "Person.h"
#include "ATM.h"
#include "Debug.h"
using namespace std;

// C++11智能指针
shared_ptr<ATM> server(new ATM());
shared_ptr<Person> p(new Person());

int main()
{
    // true MAIN false ATM
    bool isOn = true;
    // 打印菜单
    MENU_MAIN();

    ////////////////////
    //	开始主程序
    ////////////////////

    char choice;
    while(scanf("%c", &choice) != EOF)
    {
	// -1 退出
	if(choice == 'q')
	{ DEBUG(); break; }

	// 在MAIN
	if(isOn)
	{
	    switch(choice)
	    {
		case '0':
		    // MAIN
		    MENU_MAIN();
		    break;
		case '1':
		    // 工作
		    if(p->work())   LOAD(), cout << "工作完毕......" << endl;
		    else    cout << "体力下限......无法工作......" << endl;
		    break;
		case '2':
		    // 休息
		    if(p->sleep())  LOAD(), cout << "休息完毕......" << endl;
		    else    cout << "体力上限.......无需休息......" << endl;
		    break;
		case '3':
		    // 状态
		    cout << p;
		    break;
		case '4':
		    // ATM
		    isOn = false;
		    MENU_ATM();
		    break;
		default:
		    break;
	    }
	}
	// 在ATM
	else
	{
	    switch(choice)
	    {
		case '0':
		    // ATM
		    MENU_ATM();
		    break;
		case '1':
		    {
			// 登录
			string username, password;
			cout << "please enter username and password : ";
			cin >> username >> password;
			if(server->loginServer(username, password))	cout << "login successful!!!" << endl;
			else	cout << "login failed!!!" << endl;
			break;
		    }
		case '2':
		    {
			// 注册
			string username, password;
			cout << "please enter username and password : ";
			cin >> username >> password;
			if(server->registerServer(username, password))	cout << "register successful!!!" << endl;
			else	cout << "register failed!!!" << endl;
			break;
		    }
		    break;
		case '3':
		    {
			// 存钱
			int sum;
			cout << "please enter sum : ";
			cin >> sum;
			bool res = false;

			if(sum > 0 && sum <= p->getMoney())
			    res = server->saveServer(sum);
			if(res) 
			    p->subMoney(sum), cout << "save successful!!!" << endl;
			else
			    cout << "save failed!!!" << endl;
		    }
		    break;
		case '4':
		    {
			// 取钱
			int sum;
			cout << "please enter sum : ";
			cin >> sum;
			bool res = false;

			if(sum > 0)
			    res = server->drawServer(sum);
			if(res)
			    p->addMoney(sum), cout << "draw successful!!!" << endl;
			else
			    cout << "draw failed!!!" << endl;
		    }
		    break;
		case '5':
		    // 查询余额
		    server->queryMoney();
		    break;
		case '6':
		    // 查询记录
		    server->queryRecord();
		    break;
		case '7':
		    // 口袋余额
		    cout << p->getMoney() << endl;
		    break;
		case '8':
		    // MAIN
		    server->logout();
		    isOn = true;
		    MENU_MAIN();
		    break;
		default:
		    break;
	    }
	}
	putchar('\n');
    }

    // 无需释放指针

    return 0;
}

