select 
eu.unique_id, e.name
from employees e left join 
employeeuni eu
using(id)