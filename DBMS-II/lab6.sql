CREATE TABLE LOG(
	LOGMESSAGE VARCHAR(100),
	LOGDATE DATETIME
)


--Part – A

--1. Create trigger for printing appropriate message after student registration.


	SELECT * FROM STUDENT

	CREATE OR ALTER TRIGGER TR_1
	ON STUDENT
	AFTER INSERT
	AS
	BEGIN
		PRINT'STUDENT SUCCESSFULLY ADD'
	END

	INSERT INTO STUDENT VALUES(12,'YASH','yash@univ.edu','987456125','IT','2003-07-25',2021,8.92)

	DROP TRIGGER TR_1

--2. Create trigger for printing appropriate message after faculty deletion.
	
	CREATE OR ALTER TRIGGER TR_2
	ON FACULTY
	AFTER DELETE
	AS
	BEGIN
		PRINT'FUCULTY SUCCESSFULLY DELETED'
	END

	DROP TRIGGER TR_2
	
--3. Create trigger for monitoring all events on course table. (print only appropriate message)

	CREATE OR ALTER TRIGGER TR_3
	ON COURSE
	AFTER INSERT,UPDATE,DELETE
	AS
	BEGIN
		PRINT'SOME EVENT OCCUR IN COURSE TABLE'
	END

--4. Create trigger for logging data on new student registration in Log table.

	CREATE OR ALTER TRIGGER TR_4
	ON STUDENT
	AFTER INSERT
	AS
	BEGIN
		INSERT INTO LOG VALUES ('STUDENT INSERTED',GETDATE()) 
	END

--5. Create trigger for auto-uppercasing faculty names.

	CREATE OR ALTER TRIGGER TR_5
	ON FACULTY
	AFTER INSERT
	AS
	BEGIN
		DECLARE @FID INT
		DECLARE @FNAME VARCHAR(30)
		SELECT @FID=FacultyID,@FNAME=FacultyName FROM inserted
		UPDATE FACULTY 
		SET FacultyName=UPPER(@FNAME)
		WHERE FacultyID=@FID
	END

--6. Create trigger for calculating faculty experience (Note: Add required column in faculty table)

	ALTER TABLE FACULTY 
	ADD EXPERIENCE INT
	SELECT * FROM FACULTY

	CREATE OR ALTER TRIGGER TR_6
	ON FACULTY
	AFTER INSERT
	AS
	BEGIN
		DECLARE @FID INT
		DECLARE @JDATE DATETIME
		SELECT @FID=FacultyID,@JDATE=FacultyJoiningDate FROM INSERTED
		UPDATE FACULTY
		SET EXPERIENCE=DATEDIFF(YEAR,@JDATE,GETDATE())
		WHERE FacultyID=@FID
	END

--Part – B

--7. Create trigger for auto-stamping enrollment dates.
--8. Create trigger for logging data After course assignment - log course and faculty detail.
--Part - C
--9. Create trigger for updating student phone and print the old and new phone number.
--10. Create trigger for updating course credit log old and new credits in log table.

--EXTRA

CREATE OR ALTER TRIGGER TR_EXTRA
	ON STUDENT
	AFTER INSERT
	AS
	BEGIN
		DECLARE @SID INT,@SNAME VARCHAR(50),@DEPT VARCHAR(50)
		SELECT @SID=StudentID,@SNAME=StuName,@DEPT=StuDepartment FROM STUDENT
		DECLARE @MSG VARCHAR(100)
		SET @MSG='STUDENT WITH STUDENTID-'+CAST(@SID AS VARCHAR) + ',NAME-' + @SNAME + 'DEPARTMENT-' + @DEPT + 'ADDED SUCCESSFULLY'
		INSERT INTO LOG VALUES(@MSG,GETDATE())
	END

	DROP TRIGGER TR_EXTRA

	INSERT INTO STUDENT VALUES(15,'YASH','yash@univ.edu','987456125','IT','2003-07-25',2021,8.92),
		(16,'YASH','yash@univ.edu','987456125','IT','2003-07-25',2021,8.92)

	SELECT * FROM LOG
