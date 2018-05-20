select e.lname, d.dname
from jmendoza.employee e, jmendoza.department d
where e.lname like '%a%' and e.dno = d.dnumber
/
