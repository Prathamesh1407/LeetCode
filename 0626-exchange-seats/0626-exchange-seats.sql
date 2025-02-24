# Write your MySQL query statement below
with cte as (
    select id,student,lead(student,1) over() as nxt,lag(student,1) over() as prev from Seat
)

-- select * from cte;
select id,if(id%2=1,ifnull(nxt,student),prev) as student from cte;