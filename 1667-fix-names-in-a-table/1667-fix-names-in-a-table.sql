# Write your MySQL query statement below
# A1:
# select user_id,concat(upper(substr(name,1,1)),lower(substr(name,2))) as name from Users
# order by user_id;

# A2:
select user_id,concat(upper(left(name,1)),lower(right(name,length(name)-1))) as name from Users
order by user_id;