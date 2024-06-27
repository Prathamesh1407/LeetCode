# Write your MySQL query statement below
select p.product_name,sum(o.unit) as unit from Products p
left join Orders o on p.product_id=o.product_id
where substr(order_date,1,7)="2020-02" 
group by p.product_name
having unit>=100;
