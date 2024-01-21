Use Learning_Platform
go


--g. create / drop a table.
create or alter procedure createTableGrades
as
	create table Grades(
		GradeId int primary key,
		ExamId int,
		Value int
	)
go



--undo g
create or alter procedure dropTableGrades
as
	drop table if exists Grades
go



--a. a. modify the type of a column;
create or alter procedure changeValueType
as 
		alter table Grades
		alter column Value bigint
go

--undo a
create or alter procedure restoreValuetype
as
		alter table Grades
		alter column Value int
go


--b.add / remove a column;
create or alter procedure addColumnContent
as
		alter table Exam
		add Content varchar(100)
go

--undo b
create or alter procedure remColumnContent
as
		alter table Exam
		drop column Content
go


--c.add / remove a DEFAULT constraint;
create or alter procedure addDefaultConstraintValue
as
		alter table Grades
		add constraint Value_default
		default 1 for Value
go

--undo c
create or alter procedure remDefaultConstraintValue
as
		alter table Grade
		drop constraint Value_default
go


--d.add / remove a primary key;
create or alter procedure addPrimaryKeyExamId
as
		alter table Exam
		add constraint pk_Exam PRIMARY KEY(ExamId)
go


--undo d
create or alter procedure remPrimaryKeyExamId
as
begin
		alter table Exam
		drop constraint pk_Exam
end;
go



--e.add / remove a candidate key; 
create or alter procedure addCandidateKeyExaminationTime
as
	alter table Exam
	add constraint uniqTimeExam unique(ExaminationTime)
go

--undo e
create or alter procedure remCandidateKeyExaminationTime
as
	alter table Exam
	drop constraint uniqTimeExam
go



--f.add / remove a foreign key;
create or alter procedure addForeignKeyExam
as
	alter table Exam
	add constraint GradeId_FK FOREIGN KEY (GradeId) REFERENCES Grades(GradeId)
go

--undo f
create or alter procedure remForeignKeyExam
as
	alter table Exam
	drop constraint GradeId_FK
go




Create Table ListProcedures(
	versionNr INT PRIMARY KEY,
	nameProcedure varchar(100),
	nameUndoProcedure varchar(100)
);



INSERT INTO ListProcedures(versionNr, nameProcedure, nameUndoProcedure)
VALUES
(0, '', ''),
(1, 'createTableGrades', 'dropTableGrades'),
(2, 'changeValueType', 'restoreValueType'),
(3, 'addColumnContent', 'remColumnContent'),
(4, 'addDefaultConstraintValue', 'remDefaultConstraintValue'),
(5, 'addPrimaryKeyExamId', 'remPrimaryKeyExamId'),
(6,'addCandidateKeyExaminationTime','remCandidateKeyExaminationTime'),
(7,'addForeignKeyExam','remForeignKeyExam');

GO


CREATE TABLE VersionDB(
	versionNr INT,
);


INSERT INTO VersionDB(versionNr) VALUES (0);
GO





CREATE OR ALTER  PROCEDURE changeVersion @newVersion INT
AS
BEGIN
	 IF @newVersion > 7 OR @newVersion < 0
	 BEGIN
		 RAISERROR('Incorrect version', 16, 1);
		RETURN;
	 END

	 DECLARE @currentVersion AS INT
	 SELECT @currentVersion = versionNr
	 FROM VersionDB;

	 IF @newVersion = @currentVersion
	 BEGIN
		PRINT 'You are already at current version!';
		RETURN;
	 END

	 PRINT 'Current version is : '; 
	 PRINT @currentVersion;
	 PRINT 'Change to version : '; 
	 PRINT @newVersion;

	 DECLARE @Procedure AS varchar(100);


	 IF @newVersion > @currentVersion
	 BEGIN
		WHILE @newVersion != @currentVersion
		BEGIN
			SET @currentVersion = @currentVersion + 1;

			SELECT @Procedure = nameProcedure
			FROM ListProcedures
			WHERE @currentVersion = versionNr;

			EXECUTE @Procedure;

		END

		UPDATE VersionDB
		SET versionNr = @newVersion;

		RETURN;
	 END
	 
	 -- altfel daca  @Versiune < @Versiune_actuala

	 WHILE @newVersion != @currentVersion
		BEGIN

			SELECT @Procedure = nameUndoProcedure
			FROM ListProcedures
			WHERE @currentVersion = versionNr;

			EXECUTE @Procedure;

			SET @currentVersion = @currentVersion - 1;

		END
	 
	 UPDATE VersionDB
	 SET versionNr = @newVersion;
	 RETURN;
END
GO


EXEC changeVersion 4;


SELECT versionNr FROM VersionDB

