/*
delete from Lesson where LessonId=3
*/

INSERT INTO Lesson(LessonId,LessonName, Content) VALUES (3,'Learn C++','Pointers')
BEGIN TRAN
WAITFOR DELAY '00:00:05'
UPDATE Lesson SET Content='Working with files' WHERE
LessonName='Learn C++'
COMMIT TRAN