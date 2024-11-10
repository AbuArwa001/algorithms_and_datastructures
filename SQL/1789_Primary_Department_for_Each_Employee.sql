# Write your MySQL query statement below
SELECT
    e.employee_id,
    e.department_id
FROM
    Employee e
JOIN 
    (
        SELECT
            emp.employee_id,
            emp.department_id,
            COUNT(emp.employee_id) AS emp_count
        FROM
            Employee emp
        GROUP BY
            emp.employee_id
    ) AS dr_tb
ON 
    e.employee_id = dr_tb.employee_id
WHERE
    dr_tb.emp_count > 1 AND e.primary_flag = 'Y'
    OR dr_tb.emp_count = 1
;

