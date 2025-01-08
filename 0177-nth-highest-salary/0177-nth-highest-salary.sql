CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
SET N = N-1;
  RETURN (
    SELECT DISTINCT(SALARY) FROM EMPLOYEE order by salary desc
    limit 1 offset n

  );
END
