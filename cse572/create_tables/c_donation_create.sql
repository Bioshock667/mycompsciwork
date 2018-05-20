create table c_donation (
patron_id char(9), date_donated date, cash_donated int,
constraint c_don_p_id_date_PK Primary Key(patron_id, date_donated))
/
