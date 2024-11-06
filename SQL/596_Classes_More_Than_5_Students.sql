SELECT 
    cls.class
FROM
    (
        SELECT 
            class,
            COUNT(*) AS class_count
        FROM
            Courses
        GROUP BY
            class
        HAVING 
        class_count >= 5
    ) AS cls
;
