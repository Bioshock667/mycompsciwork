select d.dname, d.dnumber, count(dnum) "# of Projects"
from jmendoza.department d join jmendoza.project p on d.dnumber = p.dnum
group by d.dname, d.dnumber
/
