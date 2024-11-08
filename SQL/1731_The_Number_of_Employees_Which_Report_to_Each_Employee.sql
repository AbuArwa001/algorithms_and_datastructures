SELECT 
    e.employee_id,
    e.name,
    COUNT(r.reports_to) AS reports_count,
    ROUND(AVG(r.age)) AS average_age
FROM
    Employees e
JOIN 
    (
        SELECT
            reports_to,
            age
        FROM 
            Employees
        WHERE
            reports_to IS NOT NULL
    ) AS r
ON 
    r.reports_to = e.employee_id
GROUP BY
    e.employee_id, e.name
ORDER BY
    employee_id
;
