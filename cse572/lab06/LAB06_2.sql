select e.lname || ', ' || e.fname "Employee", count(d.dependent_name) "# of Dependents"
from jmendoza.employee e join jmendoza.dependent d on e.ssn = d.essn
group by e.fname, e.lname

/
