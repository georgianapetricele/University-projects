CREATE DATABASE Learning__Platform

CREATE TABLE Student
(
StudentId INT PRIMARY KEY,
FirstName varchar(30),
LastName varchar(30),
Username varchar(30),
Passwrd varchar(30),
Email varchar(50),
Progress decimal(5,2)
);

CREATE TABLE Instructor
(
InstructorId int PRIMARY KEY,
FirstName varchar(30),
LastName varchar(30),
Username varchar(30),
Passwrd varchar(30),
Email varchar(50),
Rating decimal(5,2)
);
/*
course can have one instructor and an instructor belongs to multiple courses
*/
CREATE TABLE Course 
(
CourseId int PRIMARY KEY,
CourseName varchar(30),
CourseDescription varchar(100),
InstructorId int REFERENCES Instructor(InstructorId)
);

/*
A topic can have multiple courses but a course belongs to one topic
*/
CREATE TABLE Topic
(
TopicId int PRIMARY KEY,
TopicName varchar(50)
);

/*
A course can have multiple modules but a module belongs to one course
*/
CREATE TABLE Module
(
ModuleId int PRIMARY KEY,
ModuleName varchar(30),
ModuleDescription varchar(100),
CourseId int REFERENCES Course(CourseId)
);

/*
A module can have multiple lessons but a lesson belongs to one module
*/
CREATE TABLE Lesson
(
LessonId int PRIMARY KEY,
LessonName varchar(30),
Content varchar(200),
ModuleId int REFERENCES Module(ModuleId)
);

/*
Connects the m:n relations from topic to instructor
*/
CREATE TABLE TopicInstructor
(
TopicInstructorId int PRIMARY KEY,
InstructorId int REFERENCES Instructor(InstructorId),
TopicId int REFERENCES Topic(TopicId)
);

/*
Connects the m:n relations from student to course: a student can enroll in multiple courses and a course can have multiple students
*/

CREATE TABLE Enrollments
(
EnrollmentId int PRIMARY KEY,
StudentId int REFERENCES Student(StudentId),
CourseId int REFERENCES Course(CourseId)
);

CREATE TABLE Assignment
(
AssignmentId int PRIMARY KEY,
LessonId int REFERENCES Lesson(LessonId),
StudentId int REFERENCES Student(StudentId),
Content varchar(200),
Deadline date
);

/*
Connects the m:n relations from student to assignment
*/
CREATE TABLE Submissions
(
SubmissionId int PRIMARY KEY,
StudentId int REFERENCES Student(StudentId),
AssignmentId int REFERENCES Assignment(AssignmentId),
SubmissionTime date
);

CREATE TABLE Review
(
ReviewId int PRIMARY KEY,
LessonId int REFERENCES Lesson(LessonId),
StudentId int REFERENCES Student(StudentId),
Rating decimal(5,2),
Comment varchar(100)
);