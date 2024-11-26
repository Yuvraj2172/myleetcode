Select 'Low Salary' as category,sum(income < 20000) as accounts_count
 from accounts
union 
Select 'Average Salary' as category  ,sum(income >= 20000 and income <= 50000) as accounts_count  from accounts
union 
Select 'High Salary' as category,sum(income > 50000) as accounts_count from accounts


