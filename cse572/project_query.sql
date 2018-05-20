select c.collection_name, a.title, description, a.artist, date_created, medium, current_value from collection c join artwork a using (collection_id)

/
