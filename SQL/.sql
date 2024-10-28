# Write your MySQL query statement below
SELECT 
    -- (cast(month(trans_date) as varchar) + '-' + cast(year(trans_date) as varchar)) AS months,
    -- (CONCAT( CAST(YEAR(trans_date) AS CHAR), '-', CAST(MONTH(trans_date) AS CHAR))) AS month,
    DATE_FORMAT(trans_date, '%Y-%m') AS month,
    -- cast(month(trans_date) as varchar) AS month,
    -- month(trans_date) AS month,
    country,
    COUNT(*) AS trans_count,
    COUNT(CASE WHEN state = 'approved' THEN 1 END) AS approved_count,
    SUM(amount) AS trans_total_amount,
    SUM(CASE WHEN state="approved" THEN amount ELSE 0 END) AS approved_total_amount
FROM 
    Transactions
GROUP BY
    month,
    country;
