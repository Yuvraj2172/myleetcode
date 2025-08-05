with product_count as (
    SELECT store_id, count(*) 
    from inventory
    group by store_id
    having count(*) >= 3
)
, 
most_expensive_product as (SELECT store_id, product_name,
quantity, price,
row_number() over(partition by store_id order by price desc) as rno
from inventory

)
,
least_expensive_product as (SELECT store_id, product_name,
quantity, price,
row_number() over(partition by store_id order by price) as lsrno
from inventory
)

SELECT l.* from (SELECT 
l.store_id, r.store_name, r.location, l.most_exp_product, l.cheapest_product, l.imbalance_ratio
from (select mep.store_id, mep.product_name as most_exp_product,lep.product_name as cheapest_product ,
mep.quantity as expensive_quantity, 
lep.quantity as cheap_quantity,
round(lep.quantity/mep.quantity,2)  as imbalance_ratio
from 
most_expensive_product mep 
inner join least_expensive_product lep
on mep.store_id = lep.store_id
where mep.rno = 1 and lep.lsrno = 1
and mep.quantity < lep.quantity) l 
left join 
stores r 
on l.store_id = r.store_id)l
join product_count r 
on l.store_id = r.store_id
order by l.imbalance_ratio desc,l.store_name asc


