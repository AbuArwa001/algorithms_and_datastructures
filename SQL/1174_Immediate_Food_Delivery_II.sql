# Write your MySQL query statement below
SELECT
    ROUND((SUM(CASE WHEN first_order.order_date = first_order.customer_pref_delivery_date THEN 1 ELSE 0 END) 
          / COUNT(*)) * 100, 2) AS immediate_percentage
FROM (
    SELECT
        D.customer_id,
        D.order_date,
        D.customer_pref_delivery_date
    FROM
        Delivery AS D
    WHERE
        order_date = (
            SELECT MIN(order_date)
            FROM Delivery
            WHERE customer_id = D.customer_id
        )
) AS first_order;
