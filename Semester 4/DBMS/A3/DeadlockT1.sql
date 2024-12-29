--table A: Student, table B: Lesson

BEGIN TRAN
UPDATE Student SET LastName='Whatever1' WHERE StudentId=1
WAITFOR DELAY '00:00:10'
UPDATE Lesson SET LessonName='Whatever1' WHERE LessonId=2
COMMIT TRAN

