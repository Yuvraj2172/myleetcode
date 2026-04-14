with weather_cte as (
SELECT 
id, recordDate, temperature,
LAG(recordDate) over(order by recordDate) as previous_date,
LAG(temperature) over(order by recordDate) as previous_temp
FROM 
Weather
)

SELECT id from 
weather_cte
where 
temperature > previous_temp
and DATEDIFF(recordDate, previous_date) = 1