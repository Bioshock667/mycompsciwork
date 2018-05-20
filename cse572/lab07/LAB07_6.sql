select dno, lname, gender
from jmendoza.employee
where dno in (select dnumber
		   from jmendoza.department
		   where dname = 'Administration')
/
