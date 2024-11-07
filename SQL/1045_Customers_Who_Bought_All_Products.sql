
SELECT
    customer_id
FROM
    (
        SELECT
            customer_id,
            product_key
        FROM
            Customer c
        GROUP BY
            customer_id,
            product_key
    ) AS cust
GROUP BY
    customer_id
HAVING
    COUNT(customer_id) = (SELECT COUNT(*) FROM Product);
    