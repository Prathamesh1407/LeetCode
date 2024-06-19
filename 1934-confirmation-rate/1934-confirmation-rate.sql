# Write your MySQL query statement below
# The AVG() function calculates the average confirmation rate for each user. It does this by assigning a value of 1 for confirmed actions and 0 for non-confirmed actions. It then adds up these values and divides by the total count, giving us the average proportion of confirmed actions.
# For example, let's say a user has 3 confirmations (action='confirmed') and 2 non-confirmations (action='not_confirmed'). The IF() function would produce a set [1, 1, 1, 0, 0], and the AVG() function would calculate (1 + 1 + 1 + 0 + 0) / 5 = 0.6, representing a confirmation rate of 60%.


select s.user_id,round(avg(if(c.action='confirmed',1,0)),2) as confirmation_rate
from Signups s
left join Confirmations c on c.user_id=s.user_id
group by s.user_id;