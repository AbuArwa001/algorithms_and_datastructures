SELECT
    st.student_id,
    st.student_name,
    sj.subject_name,
    COUNT(ex.student_id) AS attended_exams
FROM
    Students AS st
CROSS JOIN
    Subjects AS sj
LEFT JOIN
    Examinations AS ex
ON
    st.student_id = ex.student_id AND sj.subject_name = ex.subject_name
GROUP BY
    st.student_id,
    st.student_name,
    sj.subject_name
ORDER BY
    st.student_id,
    sj.subject_name;
