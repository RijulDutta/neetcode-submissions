--Write your query below
SELECT name
FROM sales_person 
WHERE sales_id NOT IN (
    SELECT DISTINCT sales_id
    FROM orders o
    JOIN company c
    ON o.com_id = c.com_id
    AND c.name = 'CRIMSON'
)

-- SELECT DISTINCT sales_id
-- FROM orders o
-- JOIN company c
-- ON o.com_id = c.com_id
-- AND c.name = 'CRIMSON'