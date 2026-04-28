1. Foreign key.

create table temp(cust_id int,FOREIGN KEY (cust_id) refrences customer(id));


2. Default keyword

salary int default 25000


3. check
create table newage(
    age int check(age>=18)
);

4. Distinct 

select distinct city from students;

5. and, or, not, in, between, all, like, any

select * from students where marks between 80 and 90;   //80 and 90 inclusive 

select * from students where city in("delhi", "mumbai");

select * from students where city not in("delhi", "mumbai");


6. LIMIT clause
 select * from students limit 3;        //will only select 3 rows max

 
