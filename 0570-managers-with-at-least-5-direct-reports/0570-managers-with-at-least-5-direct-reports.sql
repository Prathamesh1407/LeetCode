# Write your MySQL query statement below

# 1st Approach
# select e2.name from Employee e1
# inner join Employee e2 on e1.managerId=e2.id
# group by e1.managerId
# having count(e1.id)>=5;

#2nd Approach


select name from Employee
where id in
(select managerId from Employee
group by managerId having count(id)>=5)