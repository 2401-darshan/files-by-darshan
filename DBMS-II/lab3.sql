--Part – A 
--1.	Create a stored procedure that accepts a date and returns all faculty members who joined on that date.
CREATE OR ALTER PROCEDURE PR_DATE
	@DATE DATE
AS
BEGIN
	SELECT * FROM FACULTY
	WHERE FacultyJoiningDate = @DATE
END

EXEC PR_DATE '2008-03-25'

--2.	Create a stored procedure for ENROLLMENT table where user enters either StudentID and returns EnrollmentID, EnrollmentDate, Grade, and Status.

CREATE OR ALTER PROCEDURE PR_ENROLL
	@StuID INT
AS
BEGIN
	SELECT EnrollmentID, EnrollmentDate, Grade, EnrollmentStatus 
	FROM STUDENT S
	JOIN ENROLLMENT E
	ON S.STUDENTID = E.STUDENTID
	WHERE S.StudentID = @StuID
END

EXEC PR_ENROLL 3

--3.	Create a stored procedure that accepts two integers (min and max credits) and returns all courses whose credits fall between these values.

CREATE OR ALTER PROCEDURE PR_CourseByCredits
    @MinCredits INT,
    @MaxCredits INT
AS
BEGIN
    SELECT * FROM COURSE
    WHERE CourseCredits BETWEEN @MinCredits AND @MaxCredits
END

EXEC PR_CourseByCredits 2, 5


--4.	Create a stored procedure that accepts Course Name and returns the list of students enrolled in that course.

CREATE OR ALTER PROCEDURE PR_StudentsByCourse
    @CourseName VARCHAR(100)
AS
BEGIN
    SELECT S.StudentID, S.StuName
    FROM STUDENT S
    JOIN ENROLLMENT E ON S.StudentID = E.StudentID
    JOIN COURSE C ON E.CourseID = C.CourseID
    WHERE C.CourseName = @CourseName
END

EXEC PR_StudentsByCourse 'Database Management Systems'


--5.	Create a stored procedure that accepts Faculty Name and returns all course assignments.

CREATE OR ALTER PROCEDURE PR_CoursesByFaculty
    @FacultyName VARCHAR(100)
AS
BEGIN
    SELECT C.CourseName, CA.Semester, CA.Year, CA.Classroom
    FROM COURSE_ASSIGNMENT CA
    JOIN COURSE C ON CA.CourseID = C.CourseID
    JOIN FACULTY F ON CA.FacultyID = F.FacultyID
    WHERE F.FacultyName = @FacultyName
END

EXEC PR_CoursesByFaculty 'Dr. Patel'


--6.	Create a stored procedure that accepts Semester number and Year, and returns all course assignments with faculty and classroom details.

CREATE OR ALTER PROCEDURE PR_AssignmentsBySemYear
    @Semester INT,
    @Year INT
AS
BEGIN
    SELECT C.CourseName, F.FacultyName, CA.Classroom
    FROM COURSE_ASSIGNMENT CA
    JOIN COURSE C ON CA.CourseID = C.CourseID
    JOIN FACULTY F ON CA.FacultyID = F.FacultyID
    WHERE CA.Semester = @Semester AND CA.Year = @Year
END

EXEC PR_AssignmentsBySemYear 5, 2024


--Part – B 

--7.	Create a stored procedure that accepts the first letter of Status ('A', 'C', 'D') and returns enrollment details.

CREATE OR ALTER PROCEDURE PR_EnrollmentByStatus
    @Status CHAR(1)
AS
BEGIN
    SELECT * FROM ENROLLMENT
    WHERE EnrollmentStatus LIKE @Status + '%'
END

EXEC PR_EnrollmentByStatus 'A'


--8.	Create a stored procedure that accepts either Student Name OR Department Name and returns student data accordingly.

CREATE OR ALTER PROCEDURE PR_StudentByNameOrDept
    @StudentName VARCHAR(100),
    @DepartmentName VARCHAR(100)
AS
BEGIN
    SELECT * FROM STUDENT
    WHERE StuName = @StudentName
       OR StuDepartment = @DepartmentName
END

EXEC PR_StudentByNameOrDept 'Ravi', 'CSE'


--9.	Create a stored procedure that accepts CourseID and returns all students enrolled grouped by enrollment status with counts.

CREATE OR ALTER PROCEDURE PR_EnrollmentStatusCount
    @CourseID VARCHAR(20)
AS
BEGIN
    SELECT EnrollmentStatus, COUNT(*) AS TotalStudents
    FROM ENROLLMENT
    WHERE CourseID = @CourseID
    GROUP BY EnrollmentStatus
END

EXEC PR_EnrollmentStatusCount CS101


--Part – C 

--10.	Create a stored procedure that accepts a year as input and returns all courses assigned to faculty in that year with classroom details.

CREATE OR ALTER PROCEDURE PR_CoursesByYear
    @Year INT
AS
BEGIN
    SELECT C.CourseName, F.FacultyName, CA.Classroom
    FROM COURSE_ASSIGNMENT CA
    JOIN COURSE C ON CA.CourseID = C.CourseID
    JOIN FACULTY F ON CA.FacultyID = F.FacultyID
    WHERE CA.Year = @Year
END

EXEC PR_CoursesByYear 2024

--11.	Create a stored procedure that accepts From Date and To Date and returns all enrollments within that range with student and course details.

CREATE OR ALTER PROCEDURE PR_EnrollmentsByDate
    @FromDate DATE,
    @ToDate DATE
AS
BEGIN
    SELECT S.StuName, C.CourseName, E.EnrollmentDate
    FROM ENROLLMENT E
    JOIN STUDENT S ON E.StudentID = S.StudentID
    JOIN COURSE C ON E.CourseID = C.CourseID
    WHERE E.EnrollmentDate BETWEEN @FromDate AND @ToDate
END

EXEC PR_EnrollmentsByDate '2022-01-05', '2023-07-01'

--12.	Create a stored procedure that accepts FacultyID and calculates their total teaching load (sum of credits of all courses assigned).

CREATE OR ALTER PROCEDURE PR_FacultyTeachingLoad
    @FacultyID INT
AS
BEGIN
    SELECT SUM(C.CourseCredits) AS TotalCredits
    FROM COURSE_ASSIGNMENT CA
    JOIN COURSE C 
    ON CA.CourseID = C.CourseID
    JOIN FACULTY F 
    ON CA.FacultyID = F.FacultyID
    WHERE CA.FacultyID = @FacultyID
END

EXEC PR_FacultyTeachingLoad 101