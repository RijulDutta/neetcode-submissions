-- Write your query below
-- WITH tab AS(
--     SELECT 
--         left_operand,
--         operator,
--         right_operand,
--         (SELECT value FROM variables WHERE name = left_operand) AS left_val,
--         (SELECT value FROM variables WHERE name = right_operand) AS right_val
--     FROM expression
-- )

WITH tab AS(
    SELECT 
        left_operand,
        operator,
        right_operand,
        (SELECT value FROM variables WHERE name = left_operand) AS left_val,
        (SELECT value FROM variables WHERE name = right_operand) AS right_val
    FROM expressions
)
SELECT 
    left_operand,
    operator,
    right_operand,
    CASE
        WHEN operator = '>' AND left_val > right_val THEN 'true'
        WHEN operator = '<' AND left_val < right_val THEN 'true'
        WHEN operator = '=' AND left_val = right_val THEN 'true'
        ELSE 'false'
    END AS value
FROM tab
