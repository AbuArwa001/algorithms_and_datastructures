SELECT
    us.product_id,
    ROUND(COALESCE(SUM(us.units * p.price) / SUM(us.units), 0), 2) AS 
FROM
    UnitsSold us
LEFT JOIN
    Prices P
ON
    us.product_id = P.product_id
    AND us.purchase_date BETWEEN P.start_date AND P.end_date
GROUP BY
    us.product_id
ORDER BY
    us.product_id;
