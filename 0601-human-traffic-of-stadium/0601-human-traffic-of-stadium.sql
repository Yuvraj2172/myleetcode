SELECT id, visit_date, people
FROM 
(SELECT id, 
    visit_date,
    lag(people,2) over (ORDER BY id) as pre2,
    lag(people,1) over (ORDER BY id) as pre1,
    people,
    lead(people,1) over (ORDER BY id) as next1,
    lead(people,2) over (ORDER BY id) as next2
    from Stadium) cte
Where (cte.people >= 100 AND cte.pre1 >= 100 AND cte.pre2 >= 100)
OR 
(cte.people >= 100 AND cte.pre1 >= 100 AND cte.next1 >= 100)
OR 
(cte.people >= 100 AND cte.next1 >= 100 AND cte.next2 >= 100)
