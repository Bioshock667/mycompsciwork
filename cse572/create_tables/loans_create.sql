create table loans
(museum_id char(6), art_id char(6), ship_date date,
return_date date constraint loans_return_NN Not Null, owner_id char(6),
constraint loans_m_a_id_PK Primary Key (museum_id, art_id))
/
