# Write your MySQL query statement below
# select name from SalesPerson
# where sales_id not in 
# (
#     select o.sales_id from Orders o 
#     left join Company c on c.com_id=o.com_id
#     where c.name='RED'
# )
select salesperson.name
from orders o join company c on (o.com_id = c.com_id and c.name = 'RED')
right join salesperson on salesperson.sales_id = o.sales_id
where o.sales_id is null