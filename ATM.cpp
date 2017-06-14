#include <iostream>
#include <string>
#include <stdlib.h>
#include <mysql/mysql.h> // MySQL头文件
#include "ATM.h"
using namespace std;

// 构造函数
ATM::ATM()
{
    _uid = "";
    mysql_init(&mysql);
    if(!mysql_real_connect(&mysql, host, user, pwd, db, port, NULL, 0))
	cout << "MySQL failed!!!" << endl, exit(0);
}

// 析构函数
ATM::~ATM()
{
    mysql_free_result(sql_res);
    mysql_close(&mysql);
}

// 登录
bool ATM::loginServer(std::string username, std::string password)
{
    // SQL
    string sql = "SELECT id FROM tb_user WHERE username = '" + username + "' AND password = '" + password + "';";
    cout << sql.c_str() << endl;

    if(mysql_query(&mysql, sql.c_str()))
	cout << "MySQL failed!!!" << endl, exit(0);
    sql_res = mysql_store_result(&mysql);

    // 登录成功
    if(sql_row = mysql_fetch_row(sql_res))
    {
	_uid = sql_row[0];
	return true; 
    }
    return false;
}

// 注册
bool ATM::registerServer(std::string username, std::string password)
{
    // SQL1
    string sql1 = "SELECT id FROM tb_user WHERE username = '" + username + "';";
    cout << sql1.c_str() << endl;

    if(mysql_query(&mysql, sql1.c_str()))
	cout << "MySQL failed!!!" << endl, exit(0);
    sql_res = mysql_store_result(&mysql);

    // 注册失败
    if(mysql_fetch_row(sql_res))
	return false;

    // SQL2
    string sql2 = "INSERT INTO tb_user(username, password) VALUES('" + username + "', '" + password + "');";
    cout << sql2.c_str() << endl;

    return !mysql_query(&mysql, sql2.c_str());
}

// 存钱
bool ATM::saveServer(int sum)
{
    // 未登录
    if(_uid.empty())
    { cout << "尚未登录......" << endl; return false; }

    // SQL1
    string sql1 = "UPDATE tb_user SET money = money + " + to_string(sum) + " WHERE id = " + _uid + ";";
    cout << sql1.c_str() << endl;

    if(mysql_query(&mysql, sql1.c_str()))
	cout << "MySQL failed!!!" << endl, exit(0);

    // SQL2
    string sql2 = "INSERT INTO tb_record(uid, info) VALUES(" + _uid + ", '+" + to_string(sum) + "');";
    cout << sql2.c_str() << endl;

    return !mysql_query(&mysql, sql2.c_str());
}

// 取钱
bool ATM::drawServer(int sum)
{
    // 未登录
    if(_uid.empty())
    { cout << "尚未登录......" << endl; return false; }

    // SQL1
    string sql1 = "UPDATE tb_user SET money = money - " + to_string(sum) + " WHERE id = " + _uid + ";";
    cout << sql1.c_str() << std::endl;

    if(mysql_query(&mysql, sql1.c_str()))
	cout << "MySQL failed!!!" << endl, exit(0);

    // SQL2
    string sql2 = "INSERT INTO tb_record(uid, info) VALUES(" + _uid + ", '-" + to_string(sum) + "');";
    cout << sql2.c_str() << endl;

    return !mysql_query(&mysql, sql2.c_str());
}

// 查询余额
void ATM::queryMoney()
{
    // 未登录
    if(_uid.empty())
	cout << "尚未登录......" << endl;

    // SQL
    string sql = "SELECT money FROM tb_user WHERE id = " + _uid + ";";
    cout << sql.c_str() << endl;

    if(mysql_query(&mysql, sql.c_str()))
	cout << "MySQL Failed!!!" << endl, exit(0);
    sql_res = mysql_store_result(&mysql);

    cout << "余额" << endl;;
    // 获取成功
    if(sql_row = mysql_fetch_row(sql_res))
	cout << "¥" << stoi(sql_row[0]) << endl;;
}

// 查询记录
void ATM::queryRecord()
{
    // 未登录
    if(_uid.empty())
	cout << "尚未登录......" << endl;

    string sql = "SELECT info, date FROM tb_record WHERE uid = " + _uid + ";";
    cout << sql.c_str() << endl;

    if(mysql_query(&mysql, sql.c_str()))
	cout << "MySQL Failed!!!" << endl, exit(0);
    sql_res = mysql_store_result(&mysql);

    cout << "操作\t\t时间" << endl;
    // 获取成功
    while(sql_row = mysql_fetch_row(sql_res))
	cout << sql_row[0] << "\t\t" << sql_row[1] << endl;
}

// 登出
void ATM::logout()
{
    _uid = "";
}

