#ifndef ATM_H
#define ATM_H

#include <list>
#include <string>
#include "Person.h"

/**********
  ATM
 **********/
class CardInfo
{
    private:
	// 卡号
	std::string _id;
	// 密码
	std::string _password;
	// 余额
	int _money;
	// 信息
	std::string _info;

    public:
	// 默认构造函数
	CardInfo();
	// 一般构造函数
	CardInfo(std::string id, std::string password, int money, std::string info);
	// 查询卡号密码是否正确
	bool check(std::string id, std::string password);
	// 存钱
	bool save(int cnt);
	// 取钱
	bool draw(int cnt);
	// 查询余额
	int query();
	// 查新信息
	std::string info();
};

/**********
  ATM
 **********/
class ATM
{
    private:
	// 信用卡数据库
	std::list<CardInfo> *_cardInfoList;
	// 当前使用中的信用卡信息
	CardInfo *_nowCardInfo;
	// 当前使用中的信用卡
	Card *_nowCard;

	// 存钱上限
	const int maxMoney = 9999;
	// 取钱下限
	const int minMoney = 0;

	// 是否存在信用卡
	bool hasCard();
	// 判断卡号密码是否正确
	bool check(Card *card);

    public:
	// 默认构造函数
	ATM();
	// 一般构造函数
	ATM(std::list<CardInfo> *cardInfoList);
	// 插卡
	bool pushCard(Card *card);
	// 退卡
	Card* popCard();
	// 存钱
	bool saveServer(int cnt);
	// 取钱
	bool drawServer(int cnt);
	// 查询余额
	int queryServer();
	// 查询信息
	std::string infoServer();
};

#endif
