/* Write your T-SQL query statement below */
select a.machine_id,  round(avg(abs(a.timestamp - b.timestamp)), 3) processing_time
from Activity a
join Activity b on (a.machine_id = b.machine_id and a.process_id = b.process_id and a.activity_type <> b.activity_type)
group by a.machine_id