# Write your MySQL query statement below
# select id,if(p_id is null,'Root',if(count(id)=2,'Inner','Leaf')) as type from Tree;

select distinct t1.id,if(t1.p_id is null,'Root',if(t2.p_id is not null,'Inner','Leaf')) as type from Tree t1 left join Tree t2 on t1.id=t2.p_id;