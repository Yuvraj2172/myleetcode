SELECT employee_id, department_id
from EMPLOYEE
WHERE primary_flag = 'Y'
or employee_id in (
    SELECT employee_id
    from employee
    group by employee_id
    having count(department_id) = 1
)