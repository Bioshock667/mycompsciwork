select e.fname, e.lname, p.pname 
from jmendoza.employee e, jmendoza.project p, jmendoza.works_on w
where w.essn = e.ssn and w.pno = p.pnumber
order by p.pname, e.lname, e.fname
/
