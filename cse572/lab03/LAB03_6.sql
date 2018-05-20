select lname "Employee", salary "Annual Salary"
from jmendoza.employee
where salary < 27000 or salary > 45000
and dno in (4, 5)
/
