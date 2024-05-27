/* Write your T-SQL query statement below */
select id
from Weather a
where a.temperature > (
    select temperature
    from Weather b
    WHERE b.recordDate = DATEADD(DAY, -1, a.recordDate)
) 