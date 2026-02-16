--Part-A


--1. Write a scalar function to print "Welcome to DBMS Lab".
	
	CREATE OR ALTER FUNCTION FN_WELCOME_MSG()
	RETURNS VARCHAR(25)
	AS
	BEGIN
		RETURN 'WELCOME'
	END
	
	SELECT DBO.FN_WELCOME_MSG()

--2. Write a scalar function to calculate simple interest.

	CREATE OR ALTER FUNCTION FN_SIMPLE_INTEREST(
	@P FLOAT,
	@R FLOAT,
	@T FLOAT
	)
	RETURNS FLOAT
	AS
	BEGIN
		RETURN (@P * @R * @T)/100
	END
	
	SELECT DBO.FN_SIMPLE_INTEREST(10,10,10)

--3. Function to Get Difference in Days Between Two Given Dates

	CREATE OR ALTER FUNCTION FN_DATE_DIFF(
	@D1 DATE,
	@D2 DATE
	)
	RETURNS INT
	AS
	BEGIN
		RETURN DATEDIFF(DAY,@D1,@D2)
	END
	
	SELECT DBO.FN_DATE_DIFF('2025-01-01','2025-02-01')

--4. Write a scalar function which returns the sum of Credits for two given CourseIDs.

	CREATE OR ALTER FUNCTION FN_SUM_CREDITS(
	@CID1 VARCHAR(10),
	@CID2 VARCHAR(10)
	)
	RETURNS INT
	AS
	BEGIN
		DECLARE @TOTAL INT
		SELECT @TOTAL=SUM(COURSECREDITS) FROM COURSE
		WHERE CourseID IN (@CID1,@CID2)
		RETURN @TOTAL
	END
	
	SELECT DBO.FN_SUM_CREDITS('CS101','CS201')
	
--5. Write a function to check whether the given number is ODD or EVEN.

	CREATE OR ALTER FUNCTION FN_ODD_EVEN(
	@NUM1 INT
	)
	RETURNS VARCHAR(10)
	AS
	BEGIN
		DECLARE @FINAL VARCHAR(20)
		RETURN CASE
			WHEN @NUM1%2=0 THEN 'EVEN'
			ELSE 'ODD'
		END
	END
	
	SELECT DBO.FN_ODD_EVEN(10)
	
--6. Write a function to print number from 1 to N. (Using while loop)

	CREATE OR ALTER FUNCTION FN_PRINT_1_TO_N(
	@NUM INT
	)
	RETURNS VARCHAR(50)
	AS
	BEGIN
		DECLARE @RESULT VARCHAR(50)='',@I INT=1
		WHILE @I<=@NUM
		BEGIN
			SET @RESULT=@RESULT+ '' + CAST(@I AS VARCHAR) 
			SET @I=@I+1
		END
		RETURN @RESULT
	END
	
	SELECT DBO.FN_PRINT_1_TO_N(10)

--7. Write a scalar function to calculate factorial of total credits for a given CourseID.

	CREATE OR ALTER FUNCTION FN_FAC(
	@CID VARCHAR(20)
	)
	RETURNS INT
	AS
	BEGIN
		DECLARE @CREDITS INT;
		DECLARE @FAC INT = 1;
		DECLARE @I INT = 1;
		SELECT @CREDITS = CourseCredits
		FROM COURSE
		WHERE CourseID = @CID;
		WHILE @I<= @CREDITS
		BEGIN
			SET @FAC = @FAC * @I;
			SET @I = @I + 1;
		END

    RETURN @FAC;
	END;
	
	SELECT DBO.FN_FAC('CS101')
	
--8. Write a scalar function to check whether a given EnrollmentYear is in the past, current or future (Case
--statement)

	CREATE OR ALTER FUNCTION FN_DATE_CHECK(
	@D1 DATE
	)
	RETURNS VARCHAR(20)
	AS
	BEGIN
		RETURN CASE
			WHEN @D1<GETDATE() THEN 'PAST'
			WHEN @D1>GETDATE() THEN 'FUTURE'
			ELSE 'CURRENT'
			END
	END
	
	SELECT DBO.FN_DATE_CHECK('2025-01-01')

--9. Write a table-valued function that returns details of students whose names start with a given letter.

	CREATE OR ALTER FUNCTION FN_STU_NAME(
	@CHAR VARCHAR(10)
	)
	RETURNS TABLE
	AS
		RETURN(SELECT * FROM STUDENT WHERE STUNAME LIKE @CHAR + '%')

	SELECT * FROM DBO.FN_STU_NAME('R')
		
--10. Write a table-valued function that returns unique department names from the STUDENT table.

	CREATE OR ALTER FUNCTION FN_FIND_DEPT_NAME()
	RETURNS TABLE
	AS
	RETURN
	(
		SELECT DISTINCT StuDepartment
		FROM STUDENT
	);

	SELECT * FROM DBO.FN_FIND_DEPT_NAME()

--Part-B

--11. Write a scalar function that calculates age in years given a DateOfBirth.

	CREATE OR ALTER FUNCTION FN_CALCULATEAGE
	(
		@DATEOFBIRTH DATE
	)
	RETURNS INT
	AS
	BEGIN
		RETURN DATEDIFF(YEAR, @DATEOFBIRTH, GETDATE());
	END;
	GO
	SELECT DBO.FN_CALCULATEAGE('2002-05-10');

--12. Write a scalar function to check whether given number is palindrome or not.

	CREATE OR ALTER FUNCTION FN_ISPALINDROME_MANUAL
	(
		@NUMBER INT
	)
	RETURNS VARCHAR(15)
	AS
	BEGIN
		DECLARE @TEMP INT = @NUMBER;
		DECLARE @REVERSE INT = 0;
		DECLARE @DIGIT INT;

		WHILE @TEMP > 0
		BEGIN
			SET @DIGIT = @TEMP % 10;
			SET @REVERSE = (@REVERSE * 10) + @DIGIT;
			SET @TEMP = @TEMP / 10;
		END

		IF @REVERSE = @NUMBER
			RETURN 'PALINDROME';
			RETURN 'NOT PALINDROME';
	END;
	GO
	SELECT DBO.FN_ISPALINDROME_MANUAL(121) AS RESULT;

--13. Write a scalar function to calculate the sum of Credits for all courses in the 'CSE' department.

	CREATE OR ALTER FUNCTION FN_TOTALCSECREDITS()
	RETURNS INT
	AS
	BEGIN
		DECLARE @TOTALCREDITS INT;

		SELECT @TOTALCREDITS = SUM(COURSECREDITS )
		FROM COURSE
		WHERE COURSEDEPARTMENT = 'CSE';

		RETURN @TOTALCREDITS;
	END;
	SELECT DBO.FN_TOTALCSECREDITS();

--14. Write a table-valued function that returns all courses taught by faculty with a specific designation.

	CREATE OR ALTER FUNCTION FN_COURSESBYFACULTYDESIGNATION
	(
		@DESIGNATION VARCHAR(50)
	)
	RETURNS TABLE
	AS
	RETURN
	(
		SELECT COURSE.COURSEID,COURSENAME,FACULTYNAME,FACULTYDESIGNATION 
		FROM FACULTY
		JOIN COURSE_ASSIGNMENT
		ON COURSE_ASSIGNMENT.FACULTYID= FACULTY.FACULTYID
		JOIN COURSE
		ON COURSE_ASSIGNMENT.COURSEID=COURSE.COURSEID
		WHERE FACULTYDESIGNATION= @DESIGNATION
	);
	GO
	SELECT * FROM DBO.FN_COURSESBYFACULTYDESIGNATION('PROFESSOR');

--Part-C
                                                   
--15. Write a scalar function that accepts StudentID and returns their total enrolled credits (sum of credits from all active enrollments).

	CREATE OR ALTER FUNCTION FN_STUDENTTOTALCREDITS
	(
		@STUDENTID INT
	)
	RETURNS INT
	AS
	BEGIN
		DECLARE @TOTALCREDITS INT;

		SELECT @TOTALCREDITS = SUM(COURSECREDITS)
		FROM ENROLLMENT
		JOIN COURSE
		ON ENROLLMENT.COURSEID = COURSE.COURSEID
		WHERE STUDENTID = @STUDENTID
		  AND ENROLLMENTSTATUS='ACTIVE';

		RETURN ISNULL(@TOTALCREDITS, 0);
	END;
	GO
	SELECT DBO.FN_STUDENTTOTALCREDITS(1);

--16. Write a scalar function that accepts two dates (joining date range) and returns the count of faculty who joined in that period.

	CREATE OR ALTER FUNCTION FN_FACULTYCOUNTBYJOININGDATE
	(
		@FROMDATE DATE,
		@TODATE DATE
	)
	RETURNS INT
	AS
	BEGIN
		DECLARE @FACULTYCOUNT INT;

		SELECT @FACULTYCOUNT = COUNT(*)
		FROM FACULTY
		WHERE FACULTYJOININGDATE BETWEEN @FROMDATE AND @TODATE;

		RETURN @FACULTYCOUNT;
	END;
	GO
	SELECT DBO.FN_FACULTYCOUNTBYJOININGDATE('2012-08-20', '2018-01-15');
