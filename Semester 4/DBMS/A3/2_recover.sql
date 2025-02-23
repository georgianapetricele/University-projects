create database lab3

--grade 3


CREATE OR ALTER FUNCTION ufValidateString (@str VARCHAR(30))
RETURNS INT
AS
BEGIN
	DECLARE @return INT
	SET @return = 1
	IF(@str IS NULL OR LEN(@str) < 2 OR LEN(@str) > 200)
	BEGIN
		SET @return = 0
	END
	RETURN @return
END
GO

CREATE OR ALTER FUNCTION ufValidateInt (@int integer)
RETURNS INT
AS
BEGIN
	DECLARE @return INT
	SET @return = 1
	IF(@int < 0)
	BEGIN
		SET @return = 0
	END
	RETURN @return
END
GO

CREATE OR ALTER FUNCTION ufValidateGrade (@grade INT)
RETURNS INT
AS
BEGIN
    DECLARE @return INT
    SET @return = 1

    IF(@grade < 0 OR @grade > 10)
    BEGIN
        SET @return = 0
    END

    RETURN @return
END
GO

use lab3
CREATE PROCEDURE uspAddStudentRecover @firstName varchar(30), @lastName varchar(30) AS
BEGIN
	BEGIN TRAN
	BEGIN TRY
		SET NOCOUNT ON
		DECLARE @maxId INT
		SET @maxId = 1
		SELECT TOP 1 @maxId = StudentId + 1 FROM Student ORDER BY StudentId DESC
		DECLARE @error VARCHAR(max)
		SET @error = ''
		IF (dbo.ufValidateString(@firstName) <> 1)
		BEGIN
			SET @error = 'First name must be string'
			RAISERROR('First name must be string', 16, 1);
		END
		IF (dbo.ufValidateString(@lastName) <> 1)
		BEGIN
			SET @error = 'Last name must be string'
			RAISERROR('Last name must be string', 16, 1);
		END
	
		INSERT INTO Student values (@maxId, @firstName, @lastName)
		INSERT INTO LogTable VALUES ('add', 'student', GETDATE())
		COMMIT TRAN
	END TRY
	BEGIN CATCH
		ROLLBACK TRAN
		RETURN
	END CATCH
END


CREATE PROCEDURE uspAddLessonRecover @name varchar(30), @content varchar(200) AS
BEGIN
	BEGIN TRAN
	BEGIN TRY
		SET NOCOUNT ON
		DECLARE @maxId INT
		SET @maxId = 1
		SELECT TOP 1 @maxId = LessonId + 1 FROM Lesson ORDER BY LessonId DESC
		DECLARE @error VARCHAR(max)
		SET @error = ''
		IF (dbo.ufValidateString(@name) <> 1)
		BEGIN
			SET @error = 'Lesson name must be string'
			RAISERROR('Lesson name must be string', 16, 1);
		END
		IF (dbo.ufValidateString(@content) <> 1)
		BEGIN
			SET @error = 'Content must be string'
			RAISERROR('Content must be string', 16, 1);
		END
	
		INSERT INTO Lesson values (@maxId, @name, @content)
		INSERT INTO LogTable VALUES ('add', 'lesson', GETDATE())
	COMMIT TRAN
	END TRY
	BEGIN CATCH
		ROLLBACK TRAN
		RETURN
	END CATCH
END

CREATE PROCEDURE uspAddAssignmentRecover @title varchar(50), @content varchar(200), @grade int, @deadline date AS
BEGIN
	SET NOCOUNT ON
	BEGIN TRAN
	BEGIN TRY
		DECLARE @maxId INT
		DECLARE @error VARCHAR(max)
		SET @error = ''
		IF (dbo.ufValidateString(@title) <> 1)
		BEGIN
			SET @error = 'Assignment title must be string'
			RAISERROR('Assignment title must be string', 16, 1);
		END
		IF (dbo.ufValidateString(@content) <> 1)
		BEGIN
			SET @error = 'Assignment content must be string'
			RAISERROR('Assignment content must be string', 16, 1);
		END
		IF (dbo.ufValidateGrade(@grade) <> 1)
		BEGIN
			SET @error = 'Assignment grade must be betweeen 1 and 10'
			RAISERROR('Assignment grade must be betweeen 1 and 10', 16, 1);
		END
		IF(@deadline  IS NULL)
		BEGIN
			SET @error = 'Deadline date must be non null'
			RAISERROR('Deadline date must be non null', 16, 1);
		END

		DECLARE @studentId INT
		SET @studentId = (SELECT TOP 1 StudentId FROM Student ORDER BY StudentId DESC)
		DECLARE @lessonId INT
		SET @lessonId = (SELECT TOP 1 LessonId FROM Lesson ORDER BY LessonId DESC)
	
	
		INSERT INTO Assignment values (@lessonId,@studentId,@title,@content,@grade,@deadline)
		INSERT INTO LogTable VALUES ('add', 'assignment', GETDATE())
		COMMIT TRAN
	END TRY
	BEGIN CATCH
		ROLLBACK TRAN
		RETURN
	END CATCH
END


CREATE OR ALTER PROCEDURE uspAddCommitScenarioRecover
AS
	
		EXEC dbo.uspAddStudentRecover 'Andrei', 'Popescu'
		EXEC dbo.uspAddLessonRecover 'Learn Python', 'Data Types'
		EXEC uspAddAssignmentRecover 'Solve a problem','Find the cmmdc of two numbers',8,'2024-05-10'
	
GO

CREATE OR ALTER PROCEDURE uspAddRollbackScenarioRecover
AS
		EXEC dbo.uspAddStudentRecover 'Andrei', ''
		EXEC dbo.uspAddLessonRecover 'Learn Python', 'Data Types'
		EXEC uspAddAssignmentRecover 'Solve a problem','Find the cmmdc of two numbers',100,'2024-05-10'
GO



EXEC uspAddCommitScenarioRecover
EXEC uspAddRollbackScenarioRecover

SELECT * FROM Student
SELECT * FROM Lesson
SELECT * FROM Assignment
SELECT * FROM LogTable


delete from Student
delete from Lesson
delete from Assignment
delete from LogTable