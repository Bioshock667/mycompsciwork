select lname, dno, gender
from jmendoza.employee e
join jmendoza.dept_locations l on e.dno = l.dnumber
where l.dlocation = 'Bellaire'
/
