# Write your MySQL query statement below
(select u.name as results from Users u join MovieRating m on m.user_id=u.user_id 
group by m.user_id
order by count(m.user_id) desc,u.name
limit 1)

union all

(select m.title as results from MovieRating m2 left join Movies m
using (movie_id)
where year(m2.created_at)=2020 and month(m2.created_at)=2
group by m2.movie_id
order by avg(m2.rating) desc,m.title
limit 1)