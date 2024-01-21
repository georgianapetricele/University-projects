SELECT * FROM Tests
SELECT * FROM Tables
SELECT * FROM TestTables
SELECT * FROM Views 
SELECT * FROM TestViews 
SELECT * FROM TestRuns
SELECT * FROM TestRunTables 
SELECT * FROM TestRunViews
GO


create database TeaShop

--Create 3 tables: 1 PK + no FK; 1 PK + FK; 2 PK

create table Posibilities --1pk, no fk
(
Sid int,
Type varchar(50),
NoOfTeas int
PRIMARY KEY(Sid)
);


create table ShopsTeas --2 pk
(
Cid int,
Pid int,
PRIMARY KEY(Cid,Pid)
)

create table Ingredients
(
Iid int primary key,
Name varchar(50),
Quantity int,
Price int
);

create table Teas --1pk + 1fk
(
Cid int,
Sid int REFERENCES Posibilities(Sid) on delete cascade,
Iid int REFERENCES Ingredients(Iid) on delete cascade,
Name varchar(50),
Price int,
Quantity int,
PRIMARY KEY(Cid)
);

create table Shops
(
Pid int primary key,
Name varchar(50),
NoOfShops int
);


--Create 3 views
create View ViewOneTable
as
	select * from Posibilities
go


create View ViewTwoTables
as
	select Teas.Name,Teas.Quantity,Teas.Price,Posibilities.Type from Posibilities inner join Teas on Posibilities.Sid=Teas.Sid;
go


create View ViewGroupBy
AS
	select Posibilities.Type,Teas.Name,Shops.Name as Expr1
	from Posibilities inner join Teas on Posibilities.Sid=Teas.Sid cross join
	Shops
	group by Posibilities.Type,Teas.Name,Shops.Name
GO


--Create insert,delete,select procedures
CREATE OR ALTER PROCEDURE insert_table
	@no_of_rows INT,
	@table_name VARCHAR(30)
AS
BEGIN
	DECLARE @input_id INT
	DECLARE @type VARCHAR(30)
	IF @table_name='Posibilities' --for 1 pk
	BEGIN
		SET @input_id = @no_of_rows
		WHILE @no_of_rows > 0
		BEGIN
			SET @type = 'Posibility' + CONVERT (VARCHAR(5), @input_id)
			INSERT INTO Posibilities(Sid,Type) VALUES(@input_id,@type)

			SET @input_id=@input_id+1
			SET @no_of_rows=@no_of_rows-1
		END
	END

	ELSE IF @table_name='Teas'
	BEGIN
	SET @input_id = @no_of_rows

	DECLARE @fk1 INT
	SET @fk1=(SELECT TOP 1 Sid FROM Posibilities)

	DECLARE @fk2 INT
	SET @fk2=(SELECT TOP 1 Iid FROM Ingredients)

	DECLARE @name VARCHAR(50)
		WHILE @no_of_rows > 0
		BEGIN
			SET @name = 'Tea' + CONVERT (VARCHAR(5), @input_id)
			INSERT INTO Teas(Cid,Sid,Iid,Name,Price,Quantity) VALUES(@input_id,@fk1,@fk2,@name,5,10)

			SET @input_id=@input_id+1
			SET @no_of_rows=@no_of_rows-1
		END
	END

	ELSE IF @table_name='ShopsTeas'
	BEGIN
	SET @input_id = @no_of_rows
	PRINT(@input_id)
	DECLARE @input2 INT
		WHILE @no_of_rows > 0
		BEGIN
			SET @input2 = @input_id+1
			INSERT INTO ShopsTeas(Cid,Pid) VALUES(@input_id,@input2)

			SET @input_id = @input_id+1
			SET @no_of_rows=@no_of_rows-1
			
			PRINT(@input_id)
		END
	END

	ELSE
	BEGIN
		PRINT('Not a valid table name')
		RETURN 1
	END
END
GO



CREATE OR ALTER PROCEDURE delete_table
	@no_of_rows INT,
	@table_name VARCHAR(30)
AS
BEGIN
	DECLARE @last_row INT

	IF @table_name='Posibilities'
	BEGIN
	IF (SELECT COUNT(*) FROM Posibilities)<@no_of_rows
	BEGIN
		PRINT ('Too many rows to delete')
		RETURN 1
	END
	ELSE
	BEGIN
		SET @last_row = (SELECT MAX(Sid) FROM Posibilities) - @no_of_rows

		DELETE FROM Posibilities
		WHERE Sid>@last_row
	END
	END

	ELSE IF @table_name='Teas'
	BEGIN
	IF (SELECT COUNT(*) FROM Teas)<@no_of_rows
	BEGIN
		PRINT ('Too many rows to delete')
		RETURN 1
	END
	ELSE
	BEGIN
		SET @last_row = (SELECT MAX(Teas.Cid) FROM Teas) - @no_of_rows

		DELETE FROM Teas
		WHERE Teas.Cid>@last_row
	END
	END

	ELSE IF @table_name='ShopsTeas'
	BEGIN	
	IF (SELECT COUNT(*) FROM ShopsTeas)<@no_of_rows
	BEGIN
		PRINT ('Too many rows to delete')
		RETURN 1
	END

	ELSE
	BEGIN
		DELETE FROM ShopsTeas
		WHERE ShopsTeas.Cid>=@no_of_rows
	END
	END

	ELSE
	BEGIN
		PRINT('Not a valid table name')
		RETURN 1
	END
END
GO


CREATE OR ALTER PROCEDURE select_view
	@view_name VARCHAR(30)
AS
BEGIN
	IF @view_name='ViewOneTable'
	BEGIN 
		SELECT * FROM ViewOneTable
	END

	ELSE IF @view_name='ViewTwoTables'
	BEGIN 
		SELECT * FROM ViewTwoTables
	END

	ELSE IF @view_name='ViewGroupBy'
	BEGIN 
		SELECT * FROM ViewGroupBy
	END

	ELSE
	BEGIN 
		PRINT('Not a valid view name')
		RETURN 1
	END
END
GO



DELETE FROM Tables
INSERT INTO Tables VALUES ('Posibilities'),('Teas'),('ShopsTeas')
GO

DELETE FROM Views
INSERT INTO Views VALUES ('ViewOneTable'),('ViewTwoTables'),('ViewGroupBy')
GO

DELETE FROM Tests
INSERT INTO Tests VALUES ('test_10'),('test_100'),('test_1000'),('test_5000')
GO

DELETE FROM TestViews
INSERT INTO TestViews(TestID,ViewID) VALUES (1,1)
INSERT INTO TestViews(TestID,ViewID) VALUES (1,2)
INSERT INTO TestViews(TestID,ViewID) VALUES (1,3)
INSERT INTO TestViews(TestID,ViewID) VALUES (2,1)
INSERT INTO TestViews(TestID,ViewID) VALUES (2,2)
INSERT INTO TestViews(TestID,ViewID) VALUES (2,3)
INSERT INTO TestViews(TestID,ViewID) VALUES (3,1)
INSERT INTO TestViews(TestID,ViewID) VALUES (3,2)
INSERT INTO TestViews(TestID,ViewID) VALUES (3,3)
INSERT INTO TestViews(TestID,ViewID) VALUES (4,1)
INSERT INTO TestViews(TestID,ViewID) VALUES (4,2)
INSERT INTO TestViews(TestID,ViewID) VALUES (4,3)
GO

DELETE FROM TestTables
INSERT INTO TestTables(TestId, TableID, NoOfRows, Position) VALUES (1,10,10,1)
INSERT INTO TestTables(TestId, TableID, NoOfRows, Position) VALUES (1,11,10,2)
INSERT INTO TestTables(TestId, TableID, NoOfRows, Position) VALUES (1,12,10,3)
INSERT INTO TestTables(TestId, TableID, NoOfRows, Position) VALUES (2,10,100,1)
INSERT INTO TestTables(TestId, TableID, NoOfRows, Position) VALUES (2,11,100,2)
INSERT INTO TestTables(TestId, TableID, NoOfRows, Position) VALUES (2,12,100,3)
INSERT INTO TestTables(TestId, TableID, NoOfRows, Position) VALUES (3,10,1000,1)
INSERT INTO TestTables(TestId, TableID, NoOfRows, Position) VALUES (3,11,1000,2)
INSERT INTO TestTables(TestId, TableID, NoOfRows, Position) VALUES (3,12,1000,3)
INSERT INTO TestTables(TestId, TableID, NoOfRows, Position) VALUES (4,10,5000,1)
INSERT INTO TestTables(TestId, TableID, NoOfRows, Position) VALUES (4,11,5000,2)
INSERT INTO TestTables(TestId, TableID, NoOfRows, Position) VALUES (4,12,5000,3)

GO



CREATE OR ALTER PROCEDURE mainTest
	@testID INT
AS
BEGIN
	INSERT INTO TestRuns VALUES ((SELECT Name FROM Tests WHERE TestID=@testID),GETDATE(),GETDATE())
	DECLARE @testRunID INT
	SET @testRunID=(SELECT MAX(TestRunID) FROM TestRuns)

	DECLARE @noOfRows INT
	DECLARE @tableID INT
	DECLARE @tableName VARCHAR(30)
	DECLARE @startAt DATETIME
	DECLARE @endAt DATETIME
	DECLARE @viewID INT
	DECLARE @viewName VARCHAR(30)

	DECLARE testDeleteCursor CURSOR FOR
	SELECT TableID,NoOfRows
	FROM TestTables
	WHERE TestID=@testID
	ORDER BY Position DESC

	OPEN testDeleteCursor

	FETCH NEXT 
	FROM testDeleteCursor
	INTO @tableID,@noOfRows

	WHILE @@FETCH_STATUS=0  --test for all 3 deletes
	BEGIN
		SET @tableName=(SELECT Name FROM Tables WHERE TableID=@tableID)

		EXEC delete_table @noOfRows,@tableName

		FETCH NEXT 
		FROM testDeleteCursor
		INTO @tableID,@noOfRows
	END

	CLOSE testDeleteCursor
	DEALLOCATE testDeleteCursor

	DECLARE testInsertCursor CURSOR FOR
	SELECT TableID,NoOfRows
	FROM TestTables
	WHERE TestID=@testID
	ORDER BY Position ASC

	OPEN testInsertCursor

	FETCH NEXT 
	FROM testInsertCursor
	INTO @tableID,@noOfRows

	WHILE @@FETCH_STATUS=0 --test for all 3 inserts
	BEGIN
		SET @tableName=(SELECT Name FROM Tables WHERE TableID=@tableID)

		SET @startAt=GETDATE()
		EXEC insert_table @noOfRows,@tableName
		SET @endAt=GETDATE()

		INSERT INTO TestRunTables VALUES (@testRunID,@tableID,@startAt,@endAt)

		FETCH NEXT 
		FROM testInsertCursor
		INTO @tableID,@noOfRows
	END

	CLOSE testInsertCursor
	DEALLOCATE testInsertCursor

	DECLARE testViewCursor CURSOR FOR
	SELECT ViewID
	FROM TestViews
	WHERE TestID=@testID

	OPEN testViewCursor

	FETCH NEXT 
	FROM testViewCursor
	INTO @viewID

	WHILE @@FETCH_STATUS=0 -- test for all 3 selects
	BEGIN
		SET @viewName=(SELECT Name FROM Views WHERE ViewID=@viewID)

		SET @startAt=GETDATE()
		EXEC select_view @viewName
		SET @endAt=GETDATE()

		INSERT INTO TestRunViews VALUES (@testRunID,@viewID,@startAt,@endAt)

		FETCH NEXT 
		FROM testViewCursor
		INTO @viewID
	END

	CLOSE testViewCursor
	DEALLOCATE testViewCursor

	UPDATE TestRuns
	SET EndAt=GETDATE()
	WHERE TestRunID=@testRunID

END
GO

DELETE FROM TestRuns
DELETE FROM TestRunTables
DELETE FROM TestRunViews
GO

EXEC mainTest 1
EXEC mainTest 2
EXEC mainTest 3
EXEC mainTest 4

select * from TestRuns

select count(*) from Posibilities
select count(*) from Teas
select count(*) from ShopsTeas

EXEC insert_table 10,Posibilities
EXEC insert_table 10,Teas
EXEC insert_table 10,ShopsTeas



EXEC delete_table 5000,Posibilities
EXEC delete_table 5000,Teas
EXEC delete_table 5000,ShopsTeas
