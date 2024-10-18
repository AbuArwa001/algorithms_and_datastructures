# Write your MySQL query statement below
SELECT
    E.name
FROM
    Employee AS E
JOIN
    (
        SELECT
            emp.managerId,
            count(emp.managerId)
        FROM 
            Employee AS emp
        GROUP BY 
            emp.managerId
        HAVING COUNT(emp.managerId) >= 5
    )AS mIc
ON
    E.id = mIc.managerId;