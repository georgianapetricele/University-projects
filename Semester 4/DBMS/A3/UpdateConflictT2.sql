
-- T1 has updated and has a lock on the table
-- T2 will be blocked when trying to update the table

SET TRANSACTION ISOLATION LEVEL SNAPSHOT
BEGIN TRAN
Select * from Lesson where LessonId=1
Waitfor delay '00:00:05'

Update Lesson set LessonName='Transaction 2' where LessonId=1
-- process will block
-- Process will receive Error 3960.
COMMIT TRAN