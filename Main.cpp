#include <iostream>
#include <string>
#include <memory>
#include "Person.h"
#include "ATM.h"
using namespace std;

// C++11智能指针
shared_ptr<ATM> server(new ATM());
shared_ptr<Person> p(new Person());

//////////
void MENU_MAIN()
{
    printf("-------------------MAIN---------------------\n");
    printf("[-1]退出	    [0]菜单\n");
    printf("[1]工作	    [2]休息\n");
    printf("[3]状态	    [4]银行\n");
    printf("--------------------------------------------\n");
}
void MENU_ATM()
{
    printf("-------------------ATM----------------------\n");
    printf("[-1]退出	    [0]菜单\n");
    printf("[1]登录	    [2]注册\n");
    printf("[3]存钱	    [4]取钱\n");
    printf("[5]余额	    [6]记录\n");
    printf("[7]口袋	    [8]离开\n");
    printf("--------------------------------------------\n");
}
void PRINT_LOVE()
{
    // 爱心图案
    for (float y = 1.5f; y > -1.5f; y -= 0.1f) {
	for (float x = -1.5f; x < 1.5f; x += 0.05f) {
	    float a = x * x + y * y - 1;
	    putchar(a * a * a - x * x * y * y * y <= 0.0f ? '*' : ' ');
	}
	putchar('\n');
    }
    printf("Bye!!!\n");
}
//////////

int main()
{
    // true MAIN false ATM
    bool isOn = true;
    // 打印菜单
    MENU_MAIN();

    ////////////////////
    //	开始主程序
    ////////////////////

    int choice = 0;
    while(scanf("%d", &choice) != EOF)
    {
	// -1 退出
	if(choice == -1)
	{ PRINT_LOVE(); break; }

	// 在MAIN
	if(isOn)
	{
	    switch(choice)
	    {
		case 0:
		    // 菜单
		    MENU_MAIN();
		    break;
		case 1:
		    // 工作
		    if(p->work())   cout << "工作中......" << endl;
		    else    cout << "体力不足!!!" << endl;
		    break;
		case 2:
		    // 休息
		    if(p->sleep())  cout << "休息中......" << endl;
		    else    cout << "精力充沛!!!" << endl;
		    break;
		case 3:
		    // 状态
		    cout << p;
		    break;
		case 4:
		    // 银行
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
		case 0:
		    // ATM
		    MENU_ATM();
		    break;
		case 1:
		    {
			// 登录
			string username, password;
			cout << "please enter username and password : ";
			cin >> username >> password;
			if(server->loginServer(username, password))	cout << "login successful!!!" << endl;
			else	cout << "login failed!!!" << endl;
			break;
		    }
		case 2:
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
		case 3:
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
		case 4:
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
		case 5:
		    // 余额
		    server->getMoney();
		    break;
		case 6:
		    // 记录
		    server->getRecord();
		    break;
		case 7:
		    // 金钱
		    cout << "金钱 : " << p->getMoney() << endl;
		    break;
		case 8:
		    // 离开
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

