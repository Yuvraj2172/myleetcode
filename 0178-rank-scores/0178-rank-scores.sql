SELECT score, 
DENSE_RANK() OVER (
    ORDER BY score desc
) as 'rank'
from scores