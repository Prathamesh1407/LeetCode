# Write your MySQL query statement below

# 1st Approach 
# select w2.id from Weather w1 , Weather w2 
# where datediff(w2.recordDate,w1.recordDate)=1 AND w2.temperature>w1.temperature;

#2nd Approach

# select w2.id from Weather w1 join Weather w2
# on datediff(w2.recordDate,w1.recordDate)=1 AND w2.temperature>w1.temperature;

WITH q1 AS (
  SELECT 
      *,
      LAG(temperature) OVER (ORDER BY recordDate) AS previous_day_temperature,
      LAG(recordDate) OVER (ORDER BY recordDate) AS previous_Date
  FROM Weather
)

-- Select the IDs where the temperature is higher than the previous day
-- and the previous day exists (difference is exactly 1 day)
SELECT id
FROM q1
WHERE temperature > previous_day_temperature
AND DATEDIFF(recordDate, previous_Date) = 1;