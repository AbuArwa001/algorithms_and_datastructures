WITH cte AS (
    SELECT
        id,
        num,
        LAG(num) OVER() AS lagg,
        LEAD(num) OVER() AS leadd
    FROM
        Logs
)
SELECT
    DISTINCT num AS ConsecutiveNums
FROM
    cte
WHERE
    lagg = leadd AND num = lagg;
