# ATM

## 实验环境
1、操作系统`Deepin` 15.4  
// 安装Deepin  
https://www.deepin.org/download/  
2、数据库`MySQL` 5.7.15  
// 安装MySQL  
sudo apt-get install mysql-server mysql-client  
// 安装MySQL++库  
sudo apt-get install libmysql++-dev  
3、编译器`G++` 6.2.0  
// 安装G++  
sudo apt-get install g++  

## 使用Make脚本
![此处输入图片的描述][1]
```
Main:Person.cpp ATM.cpp Main.cpp
	g++ Person.cpp ATM.cpp Main.cpp -o Main -lmysqlclient -std=c++11
clean:
	rm -f Main
```
`make` # 编译  
`clean` # 清理  
`./Main` # 运行  

## 使用SQL脚本
![此处输入图片的描述][2]
```
# 创建数据库
CREATE DATABASE ATM;

# 选择数据库
USE ATM;

# 创建用户表
CREATE TABLE tb_user
(
    id INT(11) NOT NULL AUTO_INCREMENT,
    username VARCHAR(32) NOT NULL,
    password VARCHAR(32) NOT NULL,
    money INT(11) default 0,
    PRIMARY KEY(id)
);

# 创建记录表
CREATE TABLE tb_record
(
    id INT(11) NOT NULL AUTO_INCREMENT,
    uid INT(11) NOT NULL,
    info VARCHAR(32) NOT NULL,
    date datetime default now(),
    PRIMARY KEY(id)
);
```
`mysql -uroot -p` # 回车输入密码  
`SOURCE db.sql;` # 导入数据库  
`SHOW DATABASES;` # 查看数据库  
`SHOW TABLES;` # 查看表  
`SHOW COLUMNS FROM tb_***;` # 查看列  


## C++重要函数
```
// string转C语言的字符串
string.c_str()
// int转string
string to_string(int)
// string转int
int stoi(string) 
// 智能指针
shared_ptr<T>
```

## MySQL++重要函数
```
// 初始化数据库
MySQL *mysql_init(MYSQL *mysql)
// 建立数据库连接
MYSQL *mysql_real_connect(MYSQL *mysql, const char *host, const char *user, const char *passwd, const char *db, unsigned int port, const char *unix_socket, unsigned int client_flag)
// 执行SQL语句
int mysql_real_query(MYSQL *mysql, const char *query, unsigned int length)
// 查询结果集
MYSQL_RES *mysql_store_result(MYSQL *mysql)
// 结果集的下一行
MYSQL_ROW mysql_fetch_row(MYSQL_RES *result)
// 释放结果内存
void mysql_free_result(MYSQL_RES *result)
// 关闭数据库连接
void mysql_close(MYSQL *mysql)
```

## 主程序效果
```
-------------------MAIN---------------------
[-1]退出 [0]菜单
[1]工作 [2]休息
[3]状态 [4]银行
--------------------------------------------

-------------------ATM----------------------
[-1]退出 [0]菜单
[1]登录 [2]注册
[3]存钱 [4]取钱
[5]余额 [6]记录
[7]口袋 [8]离开
--------------------------------------------
```

  [1]: https://github.com/littleredhat1997/ATM/blob/master/Img/1.png
  [2]: https://github.com/littleredhat1997/ATM/blob/master/Img/2.png
  