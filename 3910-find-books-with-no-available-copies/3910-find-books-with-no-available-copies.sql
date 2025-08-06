SELECT q.book_id,
lb.title,
lb.author,
lb.genre, 
lb.publication_year,
q.br_count as current_borrowers
from 

(SELECT book_id,
count(*) as br_count
from 
(SELECT record_id, 
book_id,
borrower_name, 
borrow_date,
return_date
from 
borrowing_records
where return_date is null)q
group by book_id)q

join library_books lb
on q.book_id = lb.book_id
where lb.total_copies = q.br_count
order by q.br_count desc,lb.title