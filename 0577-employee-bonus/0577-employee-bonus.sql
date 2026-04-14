SELECT 
emp.name, 
bonus.bonus
FROM
employee emp
left join 
bonus
on 
emp.empID = bonus.empID
where bonus.empID is NULL
or bonus.bonus < 1000