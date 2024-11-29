select m.employee_id,
m.name 
,count(e.employee_id) as reports_count,
round(avg(e.age)) as average_age
from employees m inner join employees e 
on e.reports_to = m.employee_id
group by employee_id
order by m.employee_id