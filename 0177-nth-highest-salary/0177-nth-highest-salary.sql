CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      SELECT salary from (SELECT salary, dense_rank() over(order by salary desc) as 'salary_rank'
      FROM employee ) q
      where N = q.salary_rank
      LIMIT 1

  );
END