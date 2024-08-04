# Write your MySQL query statement below
select d.name as Department,e.name as Employee,e.salary as Salary from Employee e
join Department d on d.id=e.departmentId where 3>(select count(distinct(emp.salary)) from Employee emp where e.salary<emp.salary and e.departmentId=emp.departmentId); 