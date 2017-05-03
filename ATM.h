#ifndef ATM_H
#define ATM_H

#include <string>
#include <mysql/mysql.h>

class ATM
{
    private:
	// 数据库信息
	const char *host = "localhost";
	const char *user = "root";
	const char *pwd = "Zhangbincheng0";
	const char *db = "ATM";
	const int port = 3306;
	const int maxMoney = 9999;
	const int minMoney = 0;
	// 数据库操作
	MYSQL mysql;
	MYSQL_RES *sql_res;
	MYSQL_ROW sql_row;
	// 当前账号
	std::string _uid;
    public:
	ATM();
	~ATM();
	// 登录
	bool loginServer(std::string username, std::string password);
	// 注册
	bool registerServer(std::string username, std::string password);
	// 存钱
	bool saveServer(int sum);
	// 取钱
	bool drawServer(int sum);
	// 余额
	void getMoney();
	// 记录
	void getRecord();
	// 登出
	void logout();
};

#endif
