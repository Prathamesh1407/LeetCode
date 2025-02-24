# Write your MySQL query statement below
-- select u.user_id,u.join_date,count() as 'orders_in_2019' from Users u
select u.user_id as buyer_id,u.join_date,sum(o.order_id is not null) as 'orders_in_2019' from Users u left join Orders o on u.user_id=o.buyer_id and year(o.order_date)=2019
group by u.user_id
