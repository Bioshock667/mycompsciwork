select e.lname, d.dname
from jmendoza.employee e join jmendoza.department d on e.dno = d.dnumber
where e.lname like '%a%'
/
