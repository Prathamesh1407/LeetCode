# Write your MySQL query statement below

# [a-zA-Z] = means mail should start from small or capital letter.
# [a-zA-Z0-9_.-] = after that any letter or number or _ or . or -
# @leetcode = after that combine with  @leetcode
# [.] = must come . after @leetcode
# com = then com.
# regex ends with $

SELECT *
FROM Users
WHERE mail REGEXP '^[a-zA-Z][a-zA-Z0-9_.-]*@leetcode[.]com$';