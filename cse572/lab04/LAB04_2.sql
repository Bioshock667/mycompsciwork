select e.fname ||' '|| e.lname "Employee",
s.fname ||' '|| s.lname "Supervisor"
from jmendoza.employee e, jmendoza.employee s
where s.ssn = e.superssn
/
