select e.fname ||' '|| e.lname "Employee",
s.fname ||' '|| s.lname "Supervisor"
from jmendoza.employee e
join jmendoza.employee s on s.ssn = e.superssn
/
