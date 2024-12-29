--table A: Student, table B: Lesson
--solution
--SET DEADLOCK_PRIORITY HIGH
BEGIN TRAN
UPDATE Lesson SET LessonName='Whatever2' WHERE LessonId=2
WAITFOR DELAY '00:00:10'
UPDATE Student SET LastName='Whatever2' WHERE StudentId=1
COMMIT TRAN

select * from Student
select * from Lesson