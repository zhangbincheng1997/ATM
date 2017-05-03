#include <iostream>
#include <list>
#include <string>

#include "Person.h"
#include "ATM.h"

using namespace std;

ATM *server;
list<CardInfo> *cardInfoList;
Person *p;

void init()
{
    // 卡号 密码 余额 信息
    CardInfo c1("111", "000", 111, "我是测试1号");
    CardInfo c2("222", "000", 222, "我是测试2号");
    CardInfo c3("333", "000", 333, "我是测试3号");
    CardInfo c4("444", "000", 444, "我是测试4号");
    CardInfo c5("555", "000", 555, "我是测试5号");

    cardInfoList = new list<CardInfo>();
    cardInfoList->push_back(c1);
    cardInfoList->push_back(c2);
    cardInfoList->push_back(c3);
    cardInfoList->push_back(c4);
    cardInfoList->push_back(c5);

    server = new ATM(cardInfoList);
}

//////////
void print()
{
    printf("----------------------------------------\n");
    printf("[-1]退出        [0]菜单\n");
    printf("[1]进入         [2]离开\n");
    printf("[3]插卡         [4]退卡\n");
    printf("[5]存钱         [6]取钱\n");
    printf("[7]查询余额     [8]查询信息\n");
    printf("[9]身上余额\n");
    printf("----------------------------------------\n");
}
void pushCard()
{
    bool res = server->pushCard(p->getCard());
    if(res)
	printf("插卡成功\n"), p->setCard(NULL);
    else
	printf("插卡失败\n");
}
void popCard()
{
    Card *cc = server->popCard();
    if(cc != NULL)
	printf("退卡成功\n"), p->setCard(cc);
    else
	printf("退卡失败\n");
}
void saveServer()
{
    int m;
    cin >> m;
    if(m <= 0)
    { printf("输入非法\n"); return; }
    if(p->query() < m)
    { printf("穷鬼滚！\n"); return; }

    p->subMoney(m);
    bool res = server->saveServer(m);
    if(res)
	printf("存钱成功\n");
    else
	printf("存钱失败\n"), p->addMoney(m);
}
void drawServer()
{
    int m;
    cin >> m;
    if(m <= 0)
    { printf("输入非法\n"); return; }

    bool res = server->drawServer(m);
    if(res)
	printf("取钱成功\n"), p->addMoney(m);
    else
	printf("取钱失败\n");
}
void queryServer()
{
    int m = server->queryServer();
    if(m == -1)
	cout << "查询失败" << endl;
    else
	cout << "余额：" << m << endl;
}
void infoServer()
{
    string i = server->infoServer();
    if(i == "\0")
	cout << "查询失败" << endl;
    else
	cout << "信息：" << server->infoServer() << endl;
}
//////////

int main()
{
    // 初始化
    init();

    // 打印菜单
    print();

    ////////////////////

    int choice = 0;
    while(scanf("%d", &choice) != EOF && choice != -1)
    {
	// -1 退出
	if(choice == -1)
	{ printf("Bye!!!\n"); break; }
	// 0 菜单
	if(choice == 0)
	{ print(); continue; }

	// 其他
	if(choice != 1 && p == NULL)
	{ printf("没人啊亲！\n"); continue; }
	switch(choice)
	{
	    case 0:
		print();
		break;
	    case 1:
		{
		    // 进入
		    string id, password;
		    cout << "请输入卡号和密码：";
		    cin >> id >> password;

		    int money;
		    cout << "请输入身上余额：";
		    cin >> money;

		    p = new Person(money, new Card(id, password));
		    break;
		}
	    case 2:
		// 离开
		p = NULL;
		break;
	    case 3:
		pushCard();	
		break;
	    case 4:
		popCard();
		break;
	    case 5:
		saveServer();
		break;
	    case 6:
		drawServer();
		break;
	    case 7:
		queryServer();
		break;
	    case 8:
		infoServer();
		break;
	    case 9:
		printf("身上余额：%d\n", p->query());
	    default:
		break;
	}
    }

    // 防止内存泄露
    delete server;
    server = NULL;
    delete cardInfoList;
    cardInfoList = NULL;
    delete p;
    p = NULL;

    printf("OK!!!");

    return 0;
}

