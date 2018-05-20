select lname, dno, gender
from jmendoza.employee
where dno in (select dnumber
		     from jmendoza.dept_locations
		     where dlocation = 'Bellaire')
/
