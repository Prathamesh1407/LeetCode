# Write your MySQL query statement below

# Here salary will sort as descending order after that the offset 1 will omit the 1st row if we take the 1st TC 300 will be omitted now 200 100 remains then by limit 1 answer will be 200 only

select ifnull((select distinct salary from Employee 
order by salary desc limit 1 offset 1),null) as SecondHighestSalary;