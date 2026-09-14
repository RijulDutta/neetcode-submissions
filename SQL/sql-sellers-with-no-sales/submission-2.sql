-- Write your query below
SELECT seller_name
FROM seller
WHERE seller_id NOT IN (
    SELECT DISTINCT seller_id
    FROM orders
    WHERE TO_CHAR(sale_date, 'YYYY') = '2020'
)
ORDER BY seller_name
