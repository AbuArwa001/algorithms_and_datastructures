SELECT
    ROUND(
        COUNT(CASE WHEN a.event_date = DATE_ADD(pa.first_event_date, INTERVAL 1 DAY) THEN 1 END) / 
        (SELECT COUNT(DISTINCT player_id) FROM Activity),
        2
    ) AS fraction
FROM
    Activity a
LEFT JOIN
    (
        SELECT
            player_id,
            MIN(event_date) AS first_event_date
        FROM
            Activity
        GROUP BY
            player_id
    ) pa
ON
    pa.player_id = a.player_id
;
