
Use Learning_Platform
go


INSERT INTO Student(StudentId,FirstName,LastName,Username,Passwrd,Email,Progress) VALUES (1,'Maria','Popescu','mariap','1234','mariap@yahoo.com',10.00) 
INSERT INTO Student(StudentId,FirstName,LastName,Username,Passwrd,Email,Progress) VALUES (2,'Andrei','Georgescu','andreig','1234','andreig@yahoo.com',30.60)
INSERT INTO Student(StudentId,FirstName,LastName,Username,Passwrd,Email,Progress) VALUES (3,'Ioana','Pop','ipop','parola1234','ioanap@yahoo.com',50.70)

INSERT INTO Instructor(InstructorId,FirstName,LastName,Username,Passwrd,Email,Rating) VALUES (1,'Maria','Popescu','mp','1234','mp@yahoo.com',90.3)
INSERT INTO Instructor(InstructorId,FirstName,LastName,Username,Passwrd,Email,Rating) VALUES (2,'Andrei','Popescu','andp','a1234','andp@yahoo.com',85.3)
INSERT INTO Instructor(InstructorId,FirstName,LastName,Username,Passwrd,Email,Rating) VALUES (3,'Laura','Popescu','laurap','laura1234','laurap@yahoo.com',70.3)
INSERT INTO Instructor(InstructorId,FirstName,LastName,Username,Passwrd,Email,Rating) VALUES (4,'Mircea','Petrescu','mirceap','mircea1234','mirceap@yahoo.com',5)
INSERT INTO Instructor(InstructorId,FirstName,LastName,Username,Passwrd,Email,Rating) VALUES (5,'Andreea','Cristescu','andreeac','and123','andreeac@yahoo.com',9)


INSERT INTO Enrollments(EnrollmentId,StudentId,CourseId) VALUES (1,1,1)
INSERT INTO Enrollments(EnrollmentId,StudentId,CourseId) VALUES (2,2,2)

INSERT INTO TopicInstructor(TopicInstructorId,InstructorId,TopicId) VALUES(1,1,1)

INSERT INTO Topic(TopicId,TopicName) VALUES(1,'Computer Science')
INSERT INTO Topic(TopicId,TopicName) VALUES(4,'Business')
INSERT INTO Topic(TopicId,TopicName) VALUES(5,'Personal Development')
INSERT INTO Topic(TopicId,TopicName) VALUES(2,'Cooking')
INSERT INTO Topic(TopicId,TopicName) VALUES(3,'Biology')

INSERT INTO Module(ModuleId,ModuleName,ModuleDescription,TopicId) VALUES (1,'Programming','Learn Programming',1)
INSERT INTO Module(ModuleId,ModuleName,ModuleDescription,TopicId) VALUES (2,'Cooking','Learn how to cook',2)

INSERT INTO Course(CourseId,CourseName,CourseDescription,InstructorId,ModuleId) VALUES (1,'Java basics','Learn Java basics',1,1)
INSERT INTO Course(CourseId,CourseName,CourseDescription,InstructorId,ModuleId) VALUES (4,'Python','Learn Python',2,1)
INSERT INTO Course(CourseId,CourseName,CourseDescription,InstructorId,ModuleId) VALUES (4,'Dinner','Dinner meals',4,2)
INSERT INTO Course(CourseId,CourseName,CourseDescription,InstructorId,ModuleId) VALUES (3,'Lunch','Lunch meals',3,2)

INSERT INTO Lesson(LessonId,LessonName,Content,CourseId) VALUES (1,'Learn Java classes','Code..',1)
INSERT INTO Lesson(LessonId,LessonName,Content,CourseId) VALUES (2,'Simple soups','Recipe:..',2)

INSERT INTO Assignment(AssignmentId,LessonId,StudentId,Content,Deadline) VALUES (1,1,3,'Solve a problem','2023-11-10')
INSERT INTO Assignment(AssignmentId,LessonId,StudentId,Content,Deadline) VALUES (5,1,2,'Create a class','2023-11-2')
INSERT INTO Assignment(AssignmentId,LessonId,StudentId,Deadline) VALUES (3,1,1,'2023-11-10')
INSERT INTO Assignment(AssignmentId,LessonId,StudentId,Content,Deadline) VALUES (4,2,1,'Make a cream soup','2023-11-8')


/*Update and delete*/

UPDATE Assignment
SET Content='Practice'
WHERE Content IS NULL;

UPDATE Student
SET Progress=Progress+10
WHERE Progress BETWEEN 10 AND 50;

UPDATE Instructor
SET Rating=Rating+20.0
WHERE Rating IN (3,4,5,10,9)

DELETE FROM Student
WHERE StudentId=4 OR StudentId=5 AND FirstName LIKE 'Ioana%';

DELETE FROM Assignment
WHERE Deadline < CURRENT_TIMESTAMP;


--Select
--a. 2 queries with the union operation; use UNION [ALL] and OR;
-- At the end of the year all users that have Progress/Rating>90.00 will be awarded
-- The list contains students and instructors
select FirstName, LastName, Progress from Student where Progress>90.00
union
select FirstName, LastName, Rating from Instructor where Rating>90.00
-- All modules that contain Java, Python or C++ in their name
select * from Module where ModuleName LIKE '%Java%' or ModuleName LIKE '%Python%' or ModuleName LIKE '%C++%'


--b. 2 queries with the intersection operation; use INTERSECT and IN;
-- All instructors that are also students
select FirstName, LastName from Student
intersect
select FirstName, LastName from Instructor
-- All instructors that are also students(alternative)
select FirstName, LastName from Student where FirstName in (select FirstName from Instructor) and LastName in (select LastName from Instructor)


--c. 2 queries with the difference operation; use EXCEPT and NOT IN;
-- All students that aren't also instructors
select FirstName, LastName from Student
except
select FirstName, LastName from Instructor
-- All students that aren't also instructors (alternative)
select FirstName, LastName from Student where FirstName not in (select FirstName from Instructor) or LastName not in (select LastName from Instructor)



--d. 4 queries with INNER JOIN, LEFT JOIN, RIGHT JOIN, and FULL JOIN (one query per operator);
--one query will join at least 3 tables, while another one will join at least two many-to-many relationships;

/*
INNER JOIN: select all students that have enrolled in topics teached by the best rated instructor 
            USED: JOIN 2 many to many relationships, TOP, ORDER BY
*/
select S.FirstName,S.LastName from Student S 
inner join Enrollments E on S.StudentId = E.StudentId 
inner join Course C on C.CourseId = E.CourseId
inner join Module M on M.ModuleId=C.ModuleId
inner join Topic T on T.TopicId=M.TopicId
inner join TopicInstructor Ti on Ti.TopicId=T.TopicId
inner join Instructor I on I.InstructorId=Ti.InstructorId
where I.FirstName in (SELECT TOP 1 FirstName FROM Instructor ORDER BY Rating DESC);

--LEFT JOIN: select all courses with their enrolled students, including those with no students enrolled
select C.CourseName,S.FirstName,S.LastName from Course as C 
left join Enrollments as E on C.CourseId =E.CourseId
left join Student as S on E.StudentId = S.StudentId

--RIGHT JOIN: select all students with the courses they enrolled in, including those with no courses
select S.FirstName,S.LastName,C.CourseName from Student as S
left join Enrollments as E on E.StudentId = S.StudentId
left join Course as C on C.CourseId =E.CourseId

--FULL JOIN: select all topic-instructor relationships, and if one of them doesn't have the other print it anyway
select * from Topic as T 
full join  TopicInstructor as Ti on T.TopicId=Ti.TopicId
full join Instructor as I on I.InstructorId=Ti.InstructorId



--e. 2 queries with the IN operator and a subquery in the WHERE clause; 
--in at least one case, the subquery must include a subquery in its own WHERE clause;

--IN operator in WHERE clause and a subclause: -- select all the courses that have the best 3 rated instructors
-- USED: top
select DISTINCT C.CourseName,C.InstructorId from Course as C
where C.InstructorId in
(
select top 3 I.InstructorId from Instructor as I order by I.Rating
)

--IN operator in WHERE clause and a 2 subclauses: -- select the assignments from the students with the progress lower than average
--USED: arithmetic op <
SELECT A.Content, A.Deadline
FROM Assignment AS A
WHERE A.StudentId IN (
    SELECT S.StudentId
    FROM Student AS S
    WHERE S.Progress < (SELECT AVG(Progress) FROM Student)
);



--f.2 queries with the EXISTS operator and a subquery in the WHERE clause;
--EXISTS operator and a subquery in the WHERE clause: select assignments from students with progress>50 and with deadline bigger than current date
SELECT DISTINCT A.Content,A.Deadline
FROM Assignment as A
WHERE EXISTS 
(
SELECT *
FROM Student as S
WHERE S.StudentId=A.StudentId AND A.Deadline>CURRENT_TIMESTAMP AND S.Progress>50
);


--EXISTS: select topics that currently have modules added
select T.TopicName
from TOPIC as T
where exists(
    select *
    from Module as M
    where M.TopicId=T.TopicId
);



--g. 2 queries with a subquery in the FROM clause: select the courses teached by instructors with subquery in the FROM clause: select all the lastnames from instructors with rating>=50

select DISTINCT Ir.LastName
from 
(select * from Instructor as I where I.Rating>50.0) as Ir, Instructor as I 
where I.InstructorId=Ir.InstructorId

--select all the students that have their username ending with p
select S.FirstName,S.LastName,S.Username
from 
(select * from Student as S where S.Username LIKE '%p' ) as Sp, Student as S
where S.StudentId=Sp.StudentId



--h. 4 queries with the GROUP BY clause, 3 of which also contain the HAVING clause;
--2 of the latter will also have a subquery in  the HAVING clause; use the aggregation operators: 
--COUNT, SUM, AVG, MIN, MAX;

-- Print the topic name of each topic, with the nr of modules for each
select M.TopicId, count(*) as number_of_modules
from Module M
group by M.TopicId

--count the number of students enrolled in each course and filter courses with minimum 1 student
SELECT CourseId, COUNT(StudentId) AS StudentCount
FROM Enrollments
GROUP BY CourseId
HAVING COUNT(StudentId) > 0;

--find instructors with the highest and lowest average course ratings, along with the corresponding averages
SELECT InstructorId, MAX(Rating) AS MaxRating, MIN(Rating) AS MinRating
FROM Instructor
GROUP BY InstructorId
HAVING MAX(Rating) > (SELECT AVG(Rating) FROM Instructor)
    OR MIN(Rating) < (SELECT AVG(Rating) FROM Instructor);

--find the students with assignments which passed their deadline
SELECT S.FirstName,S.LastName
from Student S
inner join Assignment A on A.StudentId=S.StudentId
group by S.StudentId,S.FirstName,S.LastName
having S.StudentId in (select A.StudentId from Assignment A where A.Deadline>CURRENT_TIMESTAMP) 




--i. 4 queries using ANY and ALL to introduce a subquery in the WHERE clause
--(2 queries per operator); rewrite 2 of them with aggregation operators, and
--the other 2 with IN / [NOT] IN.

--ALL:  Print instructors better than ones from 'Python' course
select I.FirstName,I.LastName,I.Rating
from Instructor I
where I.Rating > all (
    select I2.Rating
    from Instructor I2
	inner join Course C on C.InstructorId=I2.InstructorId
    where C.CourseName='Python')

--ALL: Print instructors better than ones from 'Python' course (aggregation operator)
SELECT I.FirstName, I.LastName, I.Rating
FROM Instructor I
WHERE I.Rating > (
    SELECT MAX(I2.Rating)
    FROM Instructor I2
    INNER JOIN Course C ON C.InstructorId = I2.InstructorId
    WHERE C.CourseName = 'Python'
);

--ALL: select all instructors who don't teach 'Programming'
SELECT I.FirstName,I.LastName
FROM Instructor I
INNER JOIN TopicInstructor Ti on Ti.InstructorId=I.InstructorId
WHERE Ti.TopicId <> ALL (SELECT T.TopicId FROM Topic T WHERE T.TopicName ='Cooking')

--rewritten with NOT IN:
SELECT I.FirstName,I.LastName
FROM Instructor I
INNER JOIN TopicInstructor Ti on Ti.InstructorId=I.InstructorId
WHERE Ti.TopicId NOT IN (SELECT T.TopicId FROM Topic T WHERE T.TopicName ='Cooking')


--ANY: select all instructors whose rating is smaller than any progress of any student
SELECT I.FirstName,I.LastName,I.Rating
FROM Instructor I
WHERE I.Rating < ANY (SELECT Progress from Student)
ORDER BY I.Rating

--ANY: select all instructors whose rating is smaller than any progress of any student(agreg op)
SELECT I.FirstName,I.LastName,I.Rating
FROM Instructor I
WHERE I.Rating < (SELECT MAX(Progress) from Student)
ORDER BY I.Rating

--ANY: Print the topics that have modules
SELECT T.TopicName
FROM Topic T
WHERE T.TopicId = ANY (SELECT M.TopicId FROM Module M)

--ANY: Print the topics that have modules ( with IN)
SELECT T.TopicName
FROM Topic T
WHERE T.TopicId In (SELECT M.TopicId FROM Module M)
