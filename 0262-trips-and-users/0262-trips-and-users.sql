with cte as (
    select t.request_at,
    t.status
    from trips t 
    join users u1 on t.client_id = u1.users_id
    join users u2 on t.driver_id = u2.users_id
    where t.request_at between"2013-10-01" and "2013-10-03"
    and u1.banned = 'No' and u2.banned = 'No' 

)

select request_at as Day, 
ROUND(SUM(Case 
        when status != "completed" then 1 
        else 0
    End    )/ COUNT(*),2) as "Cancellation Rate" from cte
group by request_at


