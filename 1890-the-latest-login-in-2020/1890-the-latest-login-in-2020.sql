# Write your MySQL query statement below
select l.user_id,max(l.time_stamp) as last_stamp from Logins l 
where year(l.time_stamp)=2020
group by l.user_id;
