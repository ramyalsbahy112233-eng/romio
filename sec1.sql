create database Tamrhenna;
create table products(
	prductID INT PRIMARY KEY,
    FirstName VARCHAR(50) NOT NULL,
    kind VARCHAR(50) NOT NULL);
    
use products;

insert into products values(
1,"pen","stdying"
),(2,"book","books");

select * from products;

