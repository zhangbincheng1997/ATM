#include <iostream>
#include "Person.h"

// 工作
bool Person::work()
{
    if(_hp - workHp < minHp)
	return false;

    // 减少体力 增加金钱
    _hp -= workHp, _money += pay;
    return true;
}

// 休息
bool Person::sleep()
{
    if(_hp >= maxHp)
	return false;

    // 判断大小 增加体力
    (_hp + sleepHp > maxHp) ? _hp = maxHp : _hp += sleepHp;
    return true;
}

// 收入
void Person::addMoney(int sum)
{
    _money += sum;
}

// 支出
void Person::subMoney(int sum)
{
    _money -= sum;
}

// 友元输出
std::ostream& operator<<(std::ostream &os, const Person *p)
{
    os << "体力 : $" << p->_hp << " | " << "金钱 : ¥" << p->_money << std::endl;
}

