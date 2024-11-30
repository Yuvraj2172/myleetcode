select users.name ,q.balance
from users inner join 
(
select account, sum(amount) as BALANCE
from transactions
group by account 
having sum(amount) > 10000) q

on users.account = q.account