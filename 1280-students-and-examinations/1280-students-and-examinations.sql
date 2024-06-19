# Write your MySQL query statement below
#https://leetcode.com/problems/students-and-examinations/discuss/3913946/Easy-to-follow-MySQL-solution!-oror-Step-by-step-explanation-for-beginners!

select s.student_id,s.student_name,su.subject_name,count(e.subject_name) as attended_exams from Subjects su 
cross join Students s
left join Examinations e on s.student_id=e.student_id and su.subject_name=e.subject_name
group by s.student_id,s.student_name,su.subject_name
order by s.student_id;