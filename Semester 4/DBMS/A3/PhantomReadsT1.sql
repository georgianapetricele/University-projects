/*
delete from Lesson where LessonId=4
*/

BEGIN TRAN
WAITFOR DELAY '00:00:04'
INSERT INTO Lesson(LessonId,LessonName, Content) VALUES (4,'Learn Java','Interfaces')
COMMIT TRAN