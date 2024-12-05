with pdiddy as   (
    select num as current_nigga, lead(num,1) over () as next_nigga, lead(num,2) over () as next_to_next_nigga
from logs
)

select distinct(current_nigga) as ConsecutiveNums  from pdiddy 
where (current_nigga = next_nigga) and (next_nigga = next_to_next_nigga);