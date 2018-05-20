create table exchanges
(museum_id char(6), art_id char(6),
 ship_date date, art_id_traded_in char(6),
constraint exchanges_m_a_id_PK Primary Key (museum_id, art_id))
/
