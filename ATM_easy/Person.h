#ifndef PERSON_H
#define PERSON_H

#include <string>

/**********
  信用卡
 **********/
class Card
{
    private:
	// 卡号
	std::string _id;
	// 密码
	std::string _password;

    public:
	// 默认构造函数
	Card();
	// 一般构造函数
	Card(std::string id, std::string password);
	// 返回卡号
	std::string getId();
	// 返回密码
	std::string getPassword();
};

/**********
  用户
 **********/
class Person
{
    private:
	// 身上的钱
	int _money;
	// 身上的信用卡
	Card *_card;

    public:
	// 默认构造函数
	Person();
	// 一般构造函数
	Person(int cnt, Card *card);
	// 设置信用卡
	void setCard(Card *card);
	// 获取信用卡
	Card* getCard();
	// 查询身上的钱
	int query();
	// 增加钱
	bool addMoney(int cnt);
	// 减少钱
	bool subMoney(int cnt);
};

#endif
