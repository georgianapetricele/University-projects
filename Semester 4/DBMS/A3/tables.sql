use lab3

CREATE TABLE Student
(
StudentId INT PRIMARY KEY,
FirstName varchar(30),
LastName varchar(30)
);

CREATE TABLE Lesson
(
LessonId int PRIMARY KEY,
LessonName varchar(30),
Content varchar(200),
);


CREATE TABLE Assignment
(
LessonId int REFERENCES Lesson(LessonId) on delete cascade on update cascade,
StudentId int REFERENCES Student(StudentId) on delete cascade on update cascade,
constraint pk_assignment primary key (LessonId, StudentId),
Title varchar(30),
Content varchar(200),
Grade int,
Deadline date
);

CREATE TABLE LogTable(
	Lid INT IDENTITY PRIMARY KEY,
	TypeOperation VARCHAR(50),
	TableOperation VARCHAR(50),
	ExecutionDate DATETIME);