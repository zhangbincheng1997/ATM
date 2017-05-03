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
