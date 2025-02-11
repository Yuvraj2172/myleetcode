SELECT MAX(SALARY) as SecondHighestSalary FROM 
employee where salary < 
(SELECT MAX(salary) from employee)