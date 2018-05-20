select e.fname, e.lname, p.pname 
from jmendoza.employee e join jmendoza.works_on w on e.ssn = w.essn
join jmendoza.project p on w.pno = p.pnumber
order by p.pname, e.lname, e.fname
/
