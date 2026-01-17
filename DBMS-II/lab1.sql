--Part – A 
--1.	Retrieve all unique departments from the STUDENT table.
		SELECT DISTINCT StuDepartment FROM STUDENT

--2.	Insert a new student record into the STUDENT table.
--(9, 'Neha Singh', 'neha.singh@univ.edu', '9876543218', 'IT', '2003-09-20', 2021)
		INSERT INTO STUDENT VALUES
		(9, 'Neha Singh', 'neha.singh@univ.edu', '9876543218', 'IT', '2003-09-20', 2021)

--3.	Change the Email of student 'Raj Patel' to 'raj.p@univ.edu'. (STUDENT table)
		UPDATE STUDENT
		SET StuEmail = 'raj.p@univ.edu'
		where StuName = 'Raj Patel'

--4.	Add a new column 'CGPA' with datatype DECIMAL(3,2) to the STUDENT table.
		ALTER TABLE STUDENT
		ADD CGPA DECIMAL(3,2)

--5.	Retrieve all courses whose CourseName starts with 'Data'. (COURSE table)
		select CourseName from course
		where CourseName like 'Data%'

--6.	Retrieve all students whose Name contains 'Shah'. (STUDENT table)
		select * from student
		where StuName like '%Shah%'

--7.	Display all Faculty Names in UPPERCASE. (FACULTY table)
		select UPPER(FacultyName) from Faculty 

--8.	Find all faculty who joined after 2015. (FACULTY table)
		select FacultyName from Faculty
		where FacultyJoiningDate > '2015-12-31'

--9.	Find the SQUARE ROOT of Credits for the course 'Database Management Systems'. (COURSE table)
		select sqrt(CourseCredits) from course
		where CourseName = 'Database Management Systems'

--10.	Find the Current Date using SQL Server in-built function.
		select getdate() as Currentdate
		
--11.	Find the top 3 students who enrolled earliest (by EnrollmentYear). (STUDENT table)
		select top 3 * from student
		order by StuEnrollmentYear 

--12.	Find all enrollments that were made in the year 2022. (ENROLLMENT table)
		select * from enrollment
		where EnrollmentDate > '2022-01-01' and EnrollmentDate < '2022-12-31'

--13.	Find the number of courses offered by each department. (COURSE table)
		select count(courseID), CourseName from Course
		group by CourseName

--14.	Retrieve the CourseID which has more than 2 enrollments. (ENROLLMENT table)
		select CourseID from Enrollment
		group by CourseID
		having count(courseID)>2

--15.	Retrieve all the student name with their enrollment status. (STUDENT & ENROLLMENT table)
		select distinct s.StuName, e.EnrollmentStatus 
		from Student s
		join Enrollment e
		on s.StudentID = e.StudentID

--16.	Select all student names with their enrolled course names. (STUDENT, COURSE, ENROLLMENT table)
		select s.StuName, c.CourseName
		from Student s
		join Enrollment e
		on s.StudentID = e.StudentID
		join Course c
		on e.CourseID = c.CourseID

--17.	Create a view called 'ActiveEnrollments' showing only active enrollments with student name and  course name. (STUDENT, COURSE, ENROLLMENT,  table)
		create view ActiveEnrollments as
		select s.StuName, c.CourseName, e.EnrollmentStatus
		from Student s
		join Enrollment e
		on s.StudentID = e.StudentID
		join Course c
		on e.CourseID = c.CourseID
		where e.EnrollmentStatus = 'Active'

--18.	Retrieve the student’s name who is not enrol in any course using subquery. (STUDENT, ENROLLMENT TABLE)
		select StuName from Student
		where StudentId not in (select StudentID from Enrollment)

--19.	Display course name having second highest credit. (COURSE table)
		SELECT courseName
		FROM Course
		WHERE CourseCredits = (SELECT MAX(CourseCredits) FROM Course
							  WHERE CourseCredits < (SELECT MAX(CourseCredits) FROM Course)
		);


--Part – B 
--20.	Retrieve all courses along with the total number of students enrolled. (COURSE, ENROLLMENT table)
		SELECT c.CourseID, c.CourseName, COUNT(e.StudentID) AS TotalStudents
		FROM COURSE c
		LEFT JOIN ENROLLMENT e 
		ON c.CourseID = e.CourseID
		GROUP BY c.CourseID, c.CourseName;


--21.	Retrieve the total number of enrollments for each status, showing only statuses that have more than 2 enrollments. (ENROLLMENT table)
		SELECT enrollmentStatus, COUNT(*) AS TotalEnrollments
		FROM ENROLLMENT
		GROUP BY enrollmentStatus
		HAVING COUNT(*) > 2;


--22.	Retrieve all courses taught by 'Dr. Sheth' and order them by Credits. (FACULTY, COURSE, COURSE_ASSIGNMENT table)
		SELECT c.CourseID, c.CourseName, c.CourseCredits
		FROM COURSE c
		JOIN COURSE_ASSIGNMENT ca 
		ON c.CourseID = ca.CourseID
		JOIN FACULTY f
		ON ca.FacultyID = f.FacultyID
		WHERE f.FacultyName = 'Dr. Sheth'
		ORDER BY c.CourseCredits;


--Part – C 
--23.	List all students who are enrolled in more than 3 courses. (STUDENT, ENROLLMENT table)
		SELECT s.StudentID,s.StuName,COUNT(e.CourseID) AS TotalCourses
		FROM STUDENT s
		JOIN ENROLLMENT e
		ON s.StudentID = e.StudentID
		GROUP BY s.StudentID, s.StuName
		HAVING COUNT(e.CourseID) > 3;

--24.	Find students who have enrolled in both 'CS101' and 'CS201' Using Sub Query. (STUDENT, ENROLLMENT table)
		SELECT StudentID, StuName
		FROM STUDENT
		WHERE StudentID IN (SELECT StudentID FROM ENROLLMENT 
							WHERE CourseID = 'CS101'
							)
		AND StudentID IN (SELECT StudentID FROM ENROLLMENT 
						  WHERE CourseID = 'CS201'
		);

--25.	Retrieve department-wise count of faculty members along with their average years of experience (calculate experience from JoiningDate). (Faculty table)
		SELECT FacultyDepartment, COUNT(*) AS TotalFaculty,
		AVG(DATEDIFF(YEAR, FacultyJoiningDate, GETDATE())) AS AvgExperience
		FROM FACULTY
		GROUP BY FacultyDepartment;