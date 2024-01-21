
create table Ta
	(
		aid int primary key,
		a2 int unique,
		x int
	)

create table Tb
	(
	bid int primary key,
	b2 int,
	x int
	)

create table Tc
	(
	cid int primary key,
	aid int foreign key references Ta(aid),
	bid int foreign key references Tb(bid)
	)

-- Procedures to generate and insert random data into tables
go
create or alter procedure insertIntoTa(@rows int) as
    declare @max int
    set @max = @rows*2 + 100
    while @rows > 0 
    begin
        insert into Ta values (@rows, @max, @rows%120)
        set @rows = @rows-1
        set @max = @max-2
    end

go
create or alter procedure insertIntoTb(@rows int) as
    while @rows > 0 
	begin
        insert into Tb values (@rows, @rows%870, @rows%140)
        set @rows = @rows-1
    end

go
create or alter procedure insertIntoTc(@rows int) as
    declare @aid int
    declare @bid int
    while @rows > 0 begin
        set @aid = (select top 1 aid from Ta order by NEWID())
        set @bid = (select top 1 bid from Tb order by NEWID())
        insert into Tc values (@rows, @aid, @bid)
        set @rows = @rows-1
    end

exec insertIntoTa 3000
exec insertIntoTb 4000
exec insertIntoTc 1000

drop table Tc

select * from Ta
select * from Tb
select * from Tc


--a.
select * from Ta order by aid --clustered index scan
select * from Ta where aid>2 --clustered index seek
select a2 from Ta order by a2 --nonclustered index scan (a2 created automatically)
select a2 from Ta where a2=1 --nonclustered index seek
select x from Ta where a2 = 100 -- key lookup - nonclustered index seek + key lookup - the data is found in a nonclustered index, but additional data is needed

--b.
select * from Tb where b2=100  -- cost: 0,0150

drop index Tbindex on Tb
create nonclustered index Tbindex on Tb(b2)  
go

select * from Tb where b2=100 --cost: 0,00328


--c. Create a view that joins at least 2 tables. Check whether existing indexes are helpful; if not, reassess existing indexes / examine the cardinality of the tables.

go
create or alter view view1 as
    select A.aid,C.cid,B.b2
    from Ta A inner join Tb B on A.aid=B.bid
go

select * from view1


drop index Tbindex on Tb
create nonclustered index Tbindex on Tb(b2)  
go

go
create or alter view allTablesView as
    select top 1000 T1.x, T2.b2
    from Tc T3 join Ta T1 on T3.aid = T1.aid join Tb T2 on T3.bid = T2.bid
	where T2.b2 > 500 and T1.x < 15

go

select * from allTablesView

--with index cost: 0,0064
--without: 0,020
