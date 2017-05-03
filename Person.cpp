#include <iostream>
#include "Person.h"

bool Person::work()
{
    if(_hp - workHp < minHp)
	return false;

    _hp -= workHp, _money += pay;
    return true;
}

bool Person::sleep()
{
    if(_hp >= maxHp)
	return false;

    (_hp + sleepHp > maxHp) ? _hp = maxHp : _hp += sleepHp;
    return true;
}

void Person::addMoney(int sum)
{
    _money += sum;
}

void Person::subMoney(int sum)
{
    _money -= sum;
}

std::ostream& operator<<(std::ostream &os, const Person *p)
{
    os << "体力 : $" << p->_hp << " | " << "金钱 : ¥" << p->_money << std::endl;
}

