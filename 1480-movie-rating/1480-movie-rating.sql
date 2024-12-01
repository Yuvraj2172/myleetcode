(select name as results
from users join 
movierating using(user_id)
group by name
order by count(movie_id) desc, name 
LIMIT 1
)
union all 

(select title as results 
from movies join movierating 
using(movie_id)
where month(created_at) = '02' and year(created_at) = '2020'
group by title
order by avg(rating) desc, title

limit 1)

