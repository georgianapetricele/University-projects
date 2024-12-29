begin tran
	select Name from Project where ProjectID=7
	WAITFOR DELAY '00:00:10'

	select name from Project where ProjectID=7
	update Project set Name='Disaster'

commit tran