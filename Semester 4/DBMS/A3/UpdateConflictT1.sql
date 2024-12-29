
--ALTER DATABASE lab3 SET ALLOW_SNAPSHOT_ISOLATION ON

waitfor delay '00:00:05'
BEGIN TRAN
UPDATE Lesson SET LessonName='Transaction 1' where LessonId=1
waitfor delay '00:00:05'
COMMIT TRAN


/*
ALTER DATABASE lab3 SET ALLOW_SNAPSHOT_ISOLATION OFF
UPDATE Student SET FirstName='Andrei' where StudentId=1
select * from Student
*/
