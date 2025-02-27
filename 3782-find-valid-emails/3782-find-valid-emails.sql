# Write your MySQL query statement below
select user_id,email from Users
where email regexp '^[a-zA-z0-9_]+@[a-zA-z]+\.com$'