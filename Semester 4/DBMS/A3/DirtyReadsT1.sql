/*
UPDATE Lesson SET LessonName='Learn Python'
WHERE LessonId=1
*/

BEGIN TRAN
UPDATE Lesson SET LessonName='Learn anything'
WHERE LessonId=1
WAITFOR DELAY '00:00:10'
ROLLBACK TRAN
