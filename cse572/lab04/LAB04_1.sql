select p.pnumber, p.dnum, e.lname, e.address, e.bdate
from jmendoza.employee e, jmendoza.department d, jmendoza.project p
where e.ssn = d.mgrssn and d.dnumber = p.dnum and p.plocation = 'Stafford'
/
