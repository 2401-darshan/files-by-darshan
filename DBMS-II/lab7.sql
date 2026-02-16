CREATE TABLE LOG_LAB_7(
	LOGMESSAGE VARCHAR(100),
	LOGDATE DATETIME
)

--Part – A

--1. Create trigger for blocking student deletion.

	CREATE OR ALTER TRIGGER TR_IN_1
	ON STUDENT
	INSTEAD OF DELETE
	AS
	BEGIN
		PRINT'STUDENT BLOCKED'
	END

	DROP TRIGGER TR_IN_1

--2. Create trigger for making course read-only.

	CREATE OR ALTER TRIGGER TR_IN_2
	ON COURSE
	INSTEAD OF INSERT,UPDATE,DELETE
	AS
	BEGIN
		PRINT'STUDENT ONLY READ TABLE'
	END

	DROP TRIGGER TR_IN_2

--3. Create trigger for preventing faculty removal.

	CREATE OR ALTER TRIGGER TR_IN_3
	ON FACULTY
	INSTEAD OF DELETE
	AS
	BEGIN
		PRINT'FACULTY BLOCKED'
	END

	DROP TRIGGER TR_IN_3

--4. Create instead of trigger to log all operations on COURSE (INSERT/UPDATE/DELETE) into Log table.
--(Example: INSERT/UPDATE/DELETE operations are blocked for you in course table)

	CREATE OR ALTER TRIGGER TR_IN_4
	ON COURSE
	INSTEAD OF INSERT,UPDATE,DELETE
	AS
	BEGIN
		PRINT 'INSERT/UPDATE/DELETE BLOKED'
		INSERT INTO LOG_LAB_7 VALUES('INSERT/UPDATE/DELETE NOT ALLOWED',GETDATE())
	END

	DROP TRIGGER TR_IN_4

--5. Create trigger to Block student to update their enrollment year and print message ‘students are not
--allowed to update their enrollment year’
	
	CREATE OR ALTER TRIGGER TR_IN_5
	ON STUDENT
	INSTEAD OF UPDATE
	AS
	BEGIN
		IF UPDATE(StuEnrollmentYear)
		BEGIN
			PRINT 'STUDENT ENROLLMENT YEAR CANNOT UPDATE'
		END
	END

	DROP TRIGGER TR_IN_5
	
--6. Create trigger for student age validation (Min 18).

	CREATE OR ALTER TRIGGER TR_IN_6
	ON STUDENT
	INSTEAD OF INSERT
	AS
	BEGIN
		DECLARE @AGE INT
		SELECT @AGE=DATEDIFF(YEAR,StuDateOfBirth,GETDATE()) FROM INSERTED
		IF (@AGE<18)
		BEGIN
			PRINT 'STUDENT AGE IS UNDER 18'
		END
	END

	INSERT INTO STUDENT VALUES(12,'YASH','yash@univ.edu','987456125','IT','2010-07-25',2021,8.92)
	DROP TRIGGER TR_IN_6

--Part – B
--7. Create trigger for unique faculty’s email check.
--8. Create trigger for preventing duplicate enrollment.
--Part - C
--9. Create trigger to Allow enrolment in month from Jan to August, otherwise print message enrolment
--closed.
--10. Create trigger to Allow only grade change in enrollment (block other updates)

--EXTRA

--1

CREATE OR ALTER TRIGGER TR_IN_EXTRA_1
	ON STUDENT
	INSTEAD OF INSERT,UPDATE,DELETE
	AS
	BEGIN
		DECLARE @INS INT
		DECLARE @DEL INT
		SELECT @INS=COUNT(*) FROM INSERTED
		SELECT @DEL=COUNT(*) FROM deleted
		IF (@INS>0 AND @DEL=0)
			PRINT 'CAN NOT INSERT'
		ELSE IF (@INS>0 AND @DEL>0)
			PRINT 'CAN NOT UPDATE'
		ELSE IF (@INS=0 AND @DEL>0)
			PRINT 'CAN NOT DELETE'
	END

	DROP TRIGGER TR_IN_EXTRA_1


--2

CREATE OR ALTER TRIGGER TR_IN_EXTRA_2
	ON STUDENT
	INSTEAD OF UPDATE
	AS
	BEGIN
		DECLARE @ID INT,@SNAME VARCHAR(50),@EMAIL VARCHAR(50),@PHONE VARCHAR(50),@SDEPT VARCHAR(50),@DOB DATE,@ENY INT,@CGPA DECIMAL(3,2)
		SELECT @ID=StudentID,@SNAME=StuName,@EMAIL=StuEmail,@PHONE=StuPhone,@SDEPT=StuDepartment,@DOB=StuDateOfBirth,@ENY=StuEnrollmentYear,@CGPA=CGPA FROM INSERTED
		IF UPDATE(StuEnrollmentYear)
		BEGIN
			PRINT 'STUDENT ENROLLMENT YEAR CANNOT UPDATE'
		END
		ELSE
		BEGIN
			UPDATE STUDENT
			SET StuName=@SNAME,StuEmail=@EMAIL,StuPhone=@PHONE,StuDepartment=@SDEPT,StuDateOfBirth=@DOB,StuEnrollmentYear=@ENY,CGPA=@CGPA
			WHERE StudentID=@ID
		END
	END

	DROP TRIGGER TR_IN_EXTRA_2

--3

CREATE OR ALTER TRIGGER TR_IN_EXTRA_2
	ON STUDENT
	INSTEAD OF INSERT
	AS
	BEGIN
		DECLARE @AGE INT
		SELECT @AGE=DATEDIFF(YEAR,StuDateOfBirth,GETDATE()) FROM INSERTED
		IF (@AGE<18)
		BEGIN
			PRINT 'STUDENT AGE IS UNDER 18'
		END
	END

	DROP TRIGGER TR_IN_EXTRA_2