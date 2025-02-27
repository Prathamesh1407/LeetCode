# Write your MySQL query statement below
with first_exam as
(
    select * , min(exam_date) as date from Scores
    group by student_id,subject
),
last_exam as (
    select * , max(exam_date) as date from Scores
    group by student_id,subject
),
first_exam_marks as (
    select f.student_id,f.subject,s.exam_date,s.score score from first_exam f left join Scores s on f.student_id=s.student_id and f.date=s.exam_date and f.subject=s.subject
),
last_exam_marks as (
    select l.student_id,l.subject,s.exam_date,s.score score from last_exam l left join Scores s on l.student_id=s.student_id and l.date=s.exam_date and l.subject=s.subject
)
-- final_exams as
-- (select * from first_exam_marks
-- union 
-- select * from last_exam_marks),
-- cte4 as
-- (select * from final_exams 
-- order by student_id,subject,exam_date)

select f.student_id,f.subject,f.score as "first_score",l.score as "latest_score" from first_exam_marks f join last_exam_marks l on f.student_id=l.student_id and l.subject=f.subject and f.exam_date<>l.exam_date
where f.score<l.score
order by 1,2;

