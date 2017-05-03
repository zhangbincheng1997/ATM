#include <string>
#include "Person.h"

Card::Card()
{
    _id = "0";
    _password = "0";
}

Card::Card(std::string id, std::string password)
{
    _id = id;
    _password = password;
}

// 返回账号
std::string Card::getId()
{
    return _id;
}

// 返回密码
std::string Card::getPassword()
{
    return _password;
}

//////////

Person::Person()
{
    _money = 0;
    _card = NULL;
}

Person::Person(int cnt, Card *card)
{
    _money = cnt;
    _card = card;
}

// 设置信用卡
void Person::setCard(Card *card)
{
    _card = card;
}

// 获取信用卡
Card* Person::getCard()
{
    return _card;
}

// 查询身上的钱
int Person::query()
{
    return _money;
}

// 增加钱
bool Person::addMoney(int cnt)
{
    _money += cnt;
    return true;
}

// 减少钱
bool Person::subMoney(int cnt)
{
    _money -= cnt;
    return true;
}
