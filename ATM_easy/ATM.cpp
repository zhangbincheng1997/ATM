#include <iostream>

#include <list>
#include <string>
#include "Person.h"
#include "ATM.h"

CardInfo::CardInfo()
{
    _id = "0";
    _password = "0";
    _money = 0;
    _info = "";
}

CardInfo::CardInfo(std::string id, std::string password, int money, std::string info)
{
    _id = id;
    _password = password;
    _money = money;
    _info = info;
}

// 查询账号密码是否正确
bool CardInfo::check(std::string id, std::string password)
{
    return id == _id && password == _password;
}

// 存钱
bool CardInfo::save(int cnt)
{
    _money += cnt;
    return true;
}

// 取钱
bool CardInfo::draw(int cnt)
{
    _money -= cnt;
    return true;
}

// 查询余额
int CardInfo::query()
{
    return _money;
}

// 查询信息
std::string CardInfo::info()
{
    return _info;
}

ATM::ATM()
{
    _cardInfoList = NULL;
    _nowCardInfo = NULL;
    _nowCard =  NULL;
}

ATM::ATM(std::list<CardInfo> *cardInfoList)
{
    _cardInfoList = cardInfoList;
    _nowCardInfo = NULL;
    _nowCard =  NULL;
}

// 是否存在信用卡
bool ATM::hasCard()
{
    return _nowCard != NULL;
}

// 判断账号密码是否正确
bool ATM::check(Card *card)
{
    std::list<CardInfo>::iterator i;
    for(i = _cardInfoList->begin(); i != _cardInfoList->end(); ++i)
    {
	if(i->check(card->getId(), card->getPassword()))
	{
	    _nowCardInfo = &(*i);
	    _nowCard = card;
	    return true;
	}
    }
    return false;
}

// 插卡
bool ATM::pushCard(Card *card)
{
    if(hasCard())
	return false;
    return check(card);
}

// 退卡
Card* ATM::popCard()
{
    if(hasCard())
    {
	Card *c = _nowCard;
	_nowCardInfo = NULL;
	_nowCard = NULL;
	return c;
    }
    return NULL;
}

// 存钱
bool ATM::saveServer(int cnt)
{
    if(!hasCard() || _nowCardInfo->query() + cnt > maxMoney)
	return false;
    return _nowCardInfo->save(cnt);
}

// 取钱
bool ATM::drawServer(int cnt)
{
    if(!hasCard() || _nowCardInfo->query() - cnt < minMoney)
	return false;
    return _nowCardInfo->draw(cnt);
}

// 查询余额
int ATM::queryServer()
{
    if(hasCard())
	return _nowCardInfo->query();
    return -1;
}

// 返回交易信息
std::string ATM::infoServer()
{
    if(hasCard())
	return _nowCardInfo->info();
    return "\0";
}
