with duration_cte as (
select emp_id, event_day, (out_time - in_time) as time_spent 
from employees)
select event_day as day, emp_id, sum(time_spent) as total_time from duration_cte
group by event_day, emp_id