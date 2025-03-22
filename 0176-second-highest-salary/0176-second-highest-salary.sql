# Write your MySQL query statement below
select (select distinct salary as SecondHighestSalary from Employee  
order by SecondHighestSalary desc LIMIT 1 OFFSET 1) as SecondHighestSalary