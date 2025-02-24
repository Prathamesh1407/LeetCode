# Write your MySQL query statement below
with cte as (
    select person_name,turn,sum(weight) over(order by turn) as turn_sorted from Queue
)
select person_name from cte where turn_sorted <=1000
order by turn desc limit 1;