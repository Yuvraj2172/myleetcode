WITH cnn_cte as (
    SELECT id,
num,
lead(num) over(order by id ) as next,
lag(num) over(order by id) as prev
from logs
)

SELECT distinct(num) as ConsecutiveNums
from cnn_cte
where num = prev and num = next
