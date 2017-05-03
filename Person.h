#ifndef PERSON_H
#define PERSON_H

#include <iostream>

class Person
{
    private:
	// 最小体力
	const int minHp = 0;
	// 最大体力
	const int maxHp = 100;
	// 工作体力
	const int workHp = 10;
	// 休息体力
	const int sleepHp = 5;
	// 工资
	const int pay = 100;
	// 体力
	int _hp;
	// 金钱
	int _money;
    public:
	Person() : _hp(0), _money(0) {}
	int getHp() { return _hp; }
	int getMoney() { return _money; };
	// 工作
	bool work();
	// 休息
	bool sleep();
	// 加钱
	void addMoney(int sum);
	// 减钱
	void subMoney(int sum);
	// 友元
	friend std::ostream& operator<<(std::ostream &os, const Person *p);
};

#endif
