create table person
(person_id char(9) constraint person_id_PK Primary Key,
name varchar(60) constraint person_name_NN Not Null,
address varchar(100), mem_discrim number(1) constraint person_mem_dis_NN Not Null,
member_status char, member_year number(4), member_type varchar(20))
/
