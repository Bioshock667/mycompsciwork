select s.fname || ' ' || s.lname "Supervisor",
min(e.salary) "Lowest salary of Supervisee"
from jmendoza.employee e
join jmendoza.employee s on s.ssn = e.superssn
group by s.fname, s.lname
order by min(e.salary) desc
/
