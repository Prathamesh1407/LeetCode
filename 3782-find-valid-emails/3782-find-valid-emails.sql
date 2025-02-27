# Write your MySQL query statement below
select user_id,email from Users
where email regexp '^[a-zA-Z0-9_]+@[a-zA-Z]+\.com$'