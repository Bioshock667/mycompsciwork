select e.fname, e.lname, e.salary + e.salary * 0.1 "Increased Salary"
from jmendoza.employee e, jmendoza.project p, jmendoza.works_on w
where p.pname = 'ProductX' and p.pnumber = w.pno and e.ssn = w.essn
/
