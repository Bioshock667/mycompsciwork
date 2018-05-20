select p.pname, count(w.essn) "# of workers",
sum(w.hours) "Total Hours"
from jmendoza.project p join
jmendoza.works_on w on p.pnumber = w.pno
group by p.pname
/
