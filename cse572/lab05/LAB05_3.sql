select e.fname, e.lname, e.salary + e.salary * 0.1 "Increased Salary"
from jmendoza.employee e join jmendoza.works_on w on e.ssn = w.essn
join jmendoza.project p on p.pnumber = w.pno
where p.pname = 'ProductX'

/
