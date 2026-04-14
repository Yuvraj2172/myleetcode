WITH seat_cte
as 
(SELECT
id,
student,
LEAD(student) over(order by id) as next_stu,
LAG(student) over(order by id) as prev_stu
FROM 
seat)

SELECT 
id,
CASE 
    when id % 2 != 0 THEN
        CASE 
            WHEN next_stu is null THEN student
            ELSE next_stu
        END
    WHEN id % 2 = 0 THEN prev_stu
    END 
    as student
FROM seat_cte
