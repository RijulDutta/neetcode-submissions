-- Write your query below
SELECT o.customer_id, c.customer_name
FROM orders o
LEFT JOIN customers c
ON o.customer_id = c.customer_id
GROUP BY o.customer_id, c.customer_name
HAVING
    COUNT(CASE WHEN product_name = 'A' THEN 1 END) > 0
    AND COUNT(CASE WHEN product_name = 'B' THEN 1 END) > 0
    AND COUNT(CASE WHEN product_name = 'C' THEN 1 END) = 0
ORDER BY customer_name