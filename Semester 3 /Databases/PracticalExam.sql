create database Exam
  
create table Categories
(
	cid int primary key,
	name varchar(50) unique,
	descrip varchar(50)
)

create table Plants
(
	pid int primary key,
	name varchar(50) unique,
	descrip varchar(50),
	acc date,
	lastw date
)

create table Locations
(
	lid int primary key,
	name varchar(50) unique,
	descrip varchar(50)
)

create table PlantsLocations 
(
	pid int foreign key references Plants(pid),
	lid int foreign key references Locations(lid),
	constraint pk_ploc primary key (pid,lid)
)

create table Images
(
	iid int primary key,
	path varchar(50),
	caption varchar(50),
	upload date
)

create table PlantsImages
(
	pid int foreign key references Plants(pid),
	iid int foreign key references Images(iid),
	constraint pk_pimg primary key(pid,iid)
)

create table PlantsCategories
(
	pid int foreign key references Plants(pid),
	cid int foreign key references Categories(cid),
	constraint pk_pcat primary key(pid,cid)
)

create table CareHistory
(
	pid int foreign key references Plants(pid),
	lastwaterd date,
	lastwatert time,
	notes varchar(50)
)

INSERT INTO Categories (cid, name, descrip)
VALUES
    (1, 'Flowering Plants', 'Plants'),
    (2, 'Succulents', 'Plants '),
    (3, 'Ferns', 'plants');


INSERT INTO Plants (pid, name, descrip, acc, lastw)
VALUES
    (101, 'Rose', 'Beautiful', '2023-01-01', '2023-01-10'),
    (102, 'Aloe Vera', 'Succulent', '2023-02-15', '2023-02-25'),
    (103, 'Boston Fern', 'plant', '2023-03-20', '2023-03-30');
INSERT INTO Locations (lid, name, descrip)
VALUES
    (201, 'Living Room', 'Indoor'),
    (202, 'Balcony', 'Outdoor '),
    (203, 'Office', 'Indoor');

INSERT INTO PlantsLocations (pid, lid)
VALUES
    (101, 201),  
    (102, 202),  
    (103, 203);  

INSERT INTO Images (iid, path, caption, upload)
VALUES
    (301, '/images/plant1.jpg', 'beautiful', '2023-01-05'),
    (302, '/images/plant2.jpg', 'beautiful', '2023-02-20'),
    (303, '/images/plant3.jpg', 'beautiful', '2023-03-25');

INSERT INTO PlantsImages (pid, iid)
VALUES
    (101, 301),  
    (102, 302),  
    (103, 303);  
INSERT INTO PlantsCategories (pid, cid)
VALUES
    (101, 1),  
    (102, 2),  
    (103, 3);  

INSERT INTO CareHistory (pid, lastwaterd, lastwatert, notes)
VALUES
    (101, '2023-01-09', '12:00 PM', 'Watered'),
    (102, '2023-02-23', '02:30 PM', 'Sprayed'),
    (103, '2023-03-28', '11:00 AM', 'Added');

--2.
CREATE or ALTER procedure addPlant @pid int, @name varchar(50), @descrip varchar(50), @acc date,@lastw date
as
	DECLARE @nr int;
	SET @nr = 0;
	SELECT @nr = COUNT(*) FROM Plants WHERE pid=@pid and name=@name

	IF(@nr<>0) BEGIN
		UPDATE Plants
		SET pid=@pid,name=@name,descrip=@descrip,acc=@acc,lastw=@lastw
		WHERE pid=@pid
	END
	ELSE BEGIN
		INSERT INTO Plants Values(@pid, @name, @descrip, @acc,@lastw)
	END
go

select * from Plants

EXEC addPlant 1000, 'Plant1000', 'beautiful', '2023-01-01','2023-01-12'
select * from Plants
go


--3.
create or alter view displayTotal
as 
	select count(p.pid) Nr,p.acc from Plants p 
	inner join PlantsLocations pl
	on p.pid=pl.pid 
	inner join Locations l
	on l.lid=pl.lid
	group by p.pid,l.lid,p.acc

select * from displayTotal

--4.
create or alter function printPlant(@t int)
returns table
as
return
	select distinct p.pid, p.name, count(p.pid) as NrImg,p.lastw
	from Plants p inner join PlantsImages pi on p.pid=pi.pid
	inner join Images i on pi.iid=i.iid
	group by p.pid,p.name,p.lastw
	having count(i.upload) >= @t and p.lastw=(select top 1 lastw from Plants order by lastw desc)
go

select * from Plants
select * from Images
select * from PlantsImages
select * from printPlant(1)
