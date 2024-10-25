# Write your MySQL query statement below
USE CompanyDB;
SELECT
     p.project_id,
     ROUND(SUM(emp.experience_years) / COUNT(emp.employee_id), 2) AS average_years
FROM
    CompanyDB.Project p
LEFT JOIN
    CompanyDB.Employee emp
ON
    emp.employee_id = p.employee_id
GROUP BY
    p.project_id;
