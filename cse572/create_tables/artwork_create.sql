create table artwork(
art_id char(6) constraint art_id_PK Primary Key,
title varchar(40) constraint art_title_NN Not Null, description varchar(200),
current_value int, medium varchar(20), storage_location varchar(50),
artist varchar(30), genre varchar(30), method_acquired char(1),
period varchar(30), date_created date, date_of_exhibition date,
height number(10,2), width number(10,2), depth number(10,2), dim_units char(2),
weight_val number(10,2), weight_units char(2), collection_id char(6),
donor_id char(9), date_donated date, acquisition_value int, source varchar(60))
/
