select stock_name,
sum(case 
    when operation = 'Buy' then -price
    when operation = 'Sell' then price
    End) as capital_gain_loss
from stocks
group by stock_name 