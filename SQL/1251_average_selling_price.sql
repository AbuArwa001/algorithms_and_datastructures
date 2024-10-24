SELECT
    us.product_id,
    ROUND(SUM(us.units * P.price) / SUM(us.units), 2) AS average_price
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
