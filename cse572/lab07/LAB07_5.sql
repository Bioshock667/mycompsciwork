select lname, salary
from jmendoza.employee
where superssn in (select ssn
			from jmendoza.employee
			where lname = 'Wallace')
or dno = (select d.dnumber
		from jmendoza.department d
		join jmendoza.employee m on d.mgrssn = m.ssn
		where lname = 'Wallace')
/
