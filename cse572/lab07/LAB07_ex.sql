select ssn, lname, salary
from jmendoza.employee
where salary > (select avg(salary)
		     from jmendoza.employee)
and dno in (select dnumber
		from jmendoza.department d
		join jmendoza.employee e on d.dnumber = e.dno
		where e.lname like '%n%')
/
