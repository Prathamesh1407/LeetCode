# Write your MySQL query statement below

# 1st Approach 
# select w2.id from Weather w1 , Weather w2 
# where datediff(w2.recordDate,w1.recordDate)=1 AND w2.temperature>w1.temperature;

#2nd Approach

select w2.id from Weather w1 join Weather w2
on datediff(w2.recordDate,w1.recordDate)=1 AND w2.temperature>w1.temperature;