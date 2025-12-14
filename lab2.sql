--Part – A 
--1.	INSERT Procedures: Create stored procedures to insert records into STUDENT tables (SP_INSERT_STUDENT)


CREATE OR ALTER PROCEDURE PR_INSERT_STUDENT
	@StuID INT,
	@Name VARCHAR(50),
	@Email VARCHAR(30),
	@Phone VARCHAR(20),
	@Department VARCHAR(10),
	@DOB DATE,
	@EnrollmentYear INT,
	@CGPA DECIMAL(3,2)
AS
BEGIN
	INSERT INTO STUDENT VALUES (@StuID, @Name, @Email, @Phone, @Department, @DOB, @EnrollmentYear, @CGPA)
END

EXEC PR_INSERT_STUDENT 10, 'HARSH PARMAR', 'harsh@univ.edu', 9876543219, 'CSE', '2005-09-18', 2023, NULL
EXEC PR_INSERT_STUDENT 11, 'Om Patel', 'om@univ.edu', 9876543220, 'IT', '2002-08-22', 2022, NULL


--2.	INSERT Procedures: Create stored procedures to insert records into COURSE tables (SP_INSERT_COURSE)

CREATE OR ALTER PROCEDURE PR_INSERT_COURSE
	@CourseID VARCHAR(20),
	@CourseName VARCHAR(50),
	@Credits INT,
	@Dept VARCHAR(20),
	@Semester INT
AS
BEGIN
	INSERT INTO COURSE VALUES (@CourseID, @CourseName, @Credits, @Dept, @Semester)
END

EXEC PR_INSERT_COURSE CS330, 'Computer Networks', 4, 'CSE', 5
EXEC PR_INSERT_COURSE EC120, 'Electronic Circuits', 3, 'ECE', 2



--3.	UPDATE Procedures: Create stored procedure SP_UPDATE_STUDENT to update Email and Phone in STUDENT table. (Update using studentID)

CREATE OR ALTER PROCEDURE PR_UPDATE_STUDENT
	@StuID INT,
	@StuEmail VARCHAR(30),
	@StuPhone VARCHAR(20)
AS
BEGIN
	UPDATE STUDENT
	SET StuEmail = @StuEmail, StuPhone = @StuPhone
	WHERE StudentID = @StuID
END

EXEC PR_UPDATE_STUDENT 10, 'DARSHAN@GMAIL.COM', 81739913


--4.	DELETE Procedures: Create stored procedure SP_DELETE_STUDENT to delete records from STUDENT where Student Name is Om Patel.

CREATE OR ALTER PROCEDURE PR_DELETE_STUDENT
	@StuName VARCHAR(30)
AS
BEGIN
	DELETE FROM STUDENT
	WHERE StuName = @StuName
END

EXEC PR_DELETE_STUDENT 'OM PATEL'


--5.	SELECT BY PRIMARY KEY: Create stored procedures to select records by primary key (SP_SELECT_STUDENT_BY_ID) from Student table.

CREATE OR ALTER PROCEDURE PR_STUDENT_SELECTBYID
	@StuID INT
AS
BEGIN
	SELECT * FROM STUDENT
	WHERE StudentID = @StuID
END

EXEC PR_STUDENT_SELECTBYID 10


--6.	Create a stored procedure that shows details of the first 5 students ordered by EnrollmentYear.

CREATE OR ALTER PROCEDURE PR_SELECT_STUDENT_BY_ENROLL
	@EnrollmentYear INT
AS
BEGIN
	SELECT * FROM STUDENT
	WHERE StuEnrollmentYear = @EnrollmentYear
END

EXEC PR_SELECT_STUDENT_BY_ENROLL 2022


----Part – B  
--7.	Create a stored procedure which displays faculty designation-wise count.

CREATE OR ALTER PROCEDURE PR_FACULTY_DESIGNATION_WISE
AS
BEGIN
	SELECT FacultyDesignation, COUNT(FacultyDesignation) AS TOTAL_COUNT FROM FACULTY
	GROUP BY FacultyDesignation
END

EXEC PR_FACULTY_DESIGNATION_WISE


--8.	Create a stored procedure that takes department name as input and returns all students in that department.

CREATE OR ALTER PROCEDURE PR_RETURN_FACULTY
	@FacultyDepartment VARCHAR(20)
AS
BEGIN
	SELECT * FROM FACULTY
	WHERE FacultyDepartment = @FacultyDepartment
END

EXEC PR_RETURN_FACULTY 'CSE'



--Part – C 

--9.	Create a stored procedure which displays department-wise maximum, minimum, and average credits of courses.

CREATE OR ALTER PROCEDURE PR_COURSE_DEPARTMENT_WISE
AS
BEGIN
	SELECT CourseDepartment, MAX(CourseCredits) AS MAXIMUM, MIN(CourseCredits) AS MINIMUM, AVG(CourseCredits) AS AVERAGE
	FROM COURSE
	GROUP BY CourseDepartment
END

EXEC PR_COURSE_DEPARTMENT_WISE

--10.	Create a stored procedure that accepts StudentID as parameter and returns all courses the student is enrolled in with their grades.

CREATE OR ALTER PROCEDURE PR_GRADES
	@StuID INT
AS
BEGIN
	SELECT S.StudentID, E.EnrollmentStatus, E.GradE
	FROM STUDENT S
	JOIN ENROLLMENT E
	ON S.StudentID = E.StudentID
END

EXEC PR_GRADES 3