select q.user_id, round(q.confirm_rate / q.total_rate, 2 )as confirmation_rate from  (select s.user_id, 
sum(if(c.action = 'confirmed', 1, 0)) as confirm_rate,
sum(if(c.action = 'timeout', 1, 1)) as total_rate
from signups s left join confirmations c 
on s.user_id = c.user_id
group by s.user_id) q