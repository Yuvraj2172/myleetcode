with logs_cte as 
(
SELECT 
num,
LAG(num) over(order by id) as prev_num,
LEAD(num) over(order by id) as next_num
from logs
)

SELECT distinct(num) as ConsecutiveNums
from logs_cte
where 
num = prev_num 
and 
num = next_num