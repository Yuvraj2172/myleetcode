-- select a.*,
-- b.*
-- from stocks a left join 
-- stocks b 
-- using(stock_name)
-- and a.operation = 'Buy' and b.operation.

select stock_name,
sum(case 
    when operation = 'Buy' then -price
    when operation = 'Sell' then price
    End) as capital_gain_loss
from stocks
group by stock_name 