SELECT p.product_name, s.year, s.price
FROM 
Sales s join Product p
on s.product_id = p.product_id 

order by sale_id