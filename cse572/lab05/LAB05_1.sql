select p.pnumber, p.dnum, e.lname, e.address, e.bdate
from jmendoza.employee e join jmendoza.department d on e.ssn = d.mgrssn 
join jmendoza.project p  on d.dnumber = p.dnum
where  p.plocation = 'Stafford'
/
