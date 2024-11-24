# Write your MySQL query statement below


# select customer_number from orders
# group by customer_number
# order by count(customer_number) desc 
# limit 1;

#Follow up
# SELECT customer_number
# FROM orders
# GROUP BY customer_number
# HAVING COUNT(order_number) = (
# 	SELECT COUNT(order_number) cnt
# 	FROM orders
# 	GROUP BY customer_number
# 	ORDER BY cnt DESC
# 	LIMIT 1
# )

with cte as 
(
    select customer_number,
    rank() over(order by count(order_number) desc) as order_rank
    from orders
    group by customer_number
)

select customer_number from cte
where order_rank = 1