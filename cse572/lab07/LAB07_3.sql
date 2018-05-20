select ssn, lname
from jmendoza.employee
where dno in (select dno
 		   from jmendoza.employee
		   where lname like '%l%')
/
