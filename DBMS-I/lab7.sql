USE Bsc_Hons_506

CREATE TABLE EMP(
	EID INT,
	ENAME VARCHAR(50),
	DEPARTMENT VARCHAR(50),
	SALARY DECIMAL(7,2),
	JOININGDATE DATE,
	CITY VARCHAR(50),
	GENDER VARCHAR(50)
);

INSERT INTO EMP VALUES
(101, 'RAHUL', 'ADMIN', 56000.00 , '1990-01-01', 'RAJKOT', 'MALE'),
(102, 'HARDIK', 'IT', 18000.00 , '1990-09-25', 'AHMEDABAD', 'MALE'),
(103, 'BHAVIN', 'HR', 25000.00 , '1991-05-14', 'BARODA', 'MALE'),
(104, 'BHOOMI', 'ADMIN', 39000.00 , '1991-02-08', 'RAJKOT', 'FEMALE'),
(105, 'ROHIT', 'IT', 17000.00 , '1990-07-23', 'JAMNAGAR', 'MALE'),
(106, 'PRIYA', 'IT', 9000.00 , '1990-10-18', 'AHMEDABAD', 'FEMALE'),
(107, 'BHOOMI', 'HR', 34000.00 , '1991-12-25', 'RAJKOT', 'FEMALE');

SELECT * FROM EMP


-----------------PART A :-

--1. Display the Highest, Lowest, Label the columns Maximum, Minimum respectively. 
	SELECT MAX(SALARY) AS MAXIMUM
	FROM EMP

	SELECT MIN(SALARY) AS MINIMUM
	FROM EMP

--2. Display Total, and Average salary of all employees. Label the columns Total_Sal and Average_Sal, 
--respectively. 
	SELECT COUNT(SALARY) AS TOTAL_SAL
	FROM EMP

	SELECT AVG(SALARY) AS AVERAGE_SAL
	FROM EMP

--3. Find total number of employees of EMPLOYEE table.
	SELECT COUNT(ENAME) AS TOTAL
	FROM EMP

--4. Find highest salary from Rajkot city.
	SELECT MAX(SALARY) AS HIGHEST_SAL
	FROM EMP
	WHERE CITY='RAJKOT'

--5. Give maximum salary from IT department.
	SELECT MAX(SALARY) AS MAXIMUM
	FROM EMP
	WHERE DEPARTMENT = 'IT'

--6. Count employee whose joining date is after 8-feb-91.
	SELECT COUNT(ENAME) AS COUNT
	FROM EMP
	WHERE JOININGDATE>'1991-02-08'

--7. Display average salary of Admin department.
	SELECT AVG(SALARY) AS AVERAGE_SAL
	FROM EMP
	WHERE DEPARTMENT='ADMIN'

--8. Display total salary of HR department.
	SELECT SUM(SALARY) AS TOTAL_SAL
	FROM EMP
	WHERE DEPARTMENT='HR'

--9. Count total number of cities of employee without duplication.
	SELECT COUNT(DISTINCT CITY) AS TOTAL_CITY
	FROM EMP

--10. Count unique departments.
	SELECT COUNT(DISTINCT DEPARTMENT) AS TOTAL
	FROM EMP

--11. Give minimum salary of employee who belongs to Ahmedabad.
	SELECT ENAME, MIN(SALARY) AS MINIMUM_SAL
	FROM EMP
	WHERE CITY='AHMEDABAD'
	GROUP BY ENAME

--12. Find city wise highest salary.
	SELECT CITY, MAX(SALARY) AS HIGHEST
	FROM EMP
	GROUP BY CITY

--13. Find department wise lowest salary.
	SELECT DEPARTMENT, MIN(SALARY) AS MINIMUM
	FROM EMP
	GROUP BY DEPARTMENT

--14. Display city with the total number of employees belonging to each city.
	SELECT CITY, COUNT(ENAME) AS TOTAL
	FROM EMP
	GROUP BY CITY

--15. Give total salary of each department of EMP table.
	SELECT DEPARTMENT, SUM(SALARY) AS TOTAL_SAL
	FROM EMP
	GROUP BY DEPARTMENT

--16. Give average salary of each department of EMP table without displaying the respective department 
--name. 
	SELECT AVG(SALARY) AS AVERAGE
	FROM EMP

--17. Count the number of employees for each department in every city.
	SELECT DEPARTMENT, CITY, COUNT(ENAME) AS COUNT_NAME
	FROM EMP
	GROUP BY DEPARTMENT, CITY

--18. Calculate the total salary distributed to male and female employees.
	SELECT GENDER, SUM(SALARY) AS TOTAL
	FROM EMP
	WHERE GENDER='MALE'
	GROUP BY GENDER

	SELECT GENDER, SUM(SALARY) AS TOTAL
	FROM EMP
	WHERE GENDER='FEMALE'
	GROUP BY GENDER

--19. Give city wise maximum and minimum salary of female employees.
	SELECT CITY, MAX(SALARY) AS MAXIMUM
	FROM EMP
	WHERE GENDER='FEMALE'
	GROUP BY CITY

	SELECT CITY, MIN(SALARY) AS MINIMUM
	FROM EMP
	WHERE GENDER='FEMALE'
	GROUP BY CITY

--20. Calculate department, city, and gender wise average salary.
	SELECT DEPARTMENT, AVG(SALARY) AS AVERAGE
	FROM EMP
	GROUP BY DEPARTMENT

	SELECT CITY, AVG(SALARY) AS AVERAGE
	FROM EMP
	GROUP BY CITY

	SELECT GENDER, AVG(SALARY) AS AVERAGE
	FROM EMP
	GROUP BY GENDER

---------------------Part – B:

--1. Count the number of employees living in Rajkot.
	SELECT COUNT(ENAME) AS TOTAL_EMP
	FROM EMP
	WHERE CITY='RAJKOT'

--2. Display the difference between the highest and lowest salaries. Label the column DIFFERENCE.
	SELECT (MAX(SALARY) - MIN(SALARY)) AS DIF_SAL
	FROM EMP

--3. Display the total number of employees hired before 1st January, 1991.
	SELECT COUNT(ENAME) AS TOTAL
	FROM EMP
	WHERE JOININGDATE>'1991-01-01'

--Part – C: 
--1. Count the number of employees living in Rajkot or Baroda.
	SELECT COUNT(ENAME) AS TOTAL_EMP
	FROM EMP
	WHERE CITY IN('RAJKOT', 'BARODA')

--2. Display the total number of employees hired before 1st January, 1991 in IT department.
	SELECT COUNT(ENAME) AS TOTAL_EMP
	FROM EMP
	WHERE DEPARTMENT='IT' AND JOININGDATE<'1991-01-01'

--3. Find the Joining Date wise Total Salaries.
	SELECT JOININGDATE, SUM(SALARY) AS TOTAL
	FROM EMP
	GROUP BY JOININGDATE

--4. Find the Maximum salary department & city wise in which city name starts with ‘R’. 
	SELECT DEPARTMENT, MAX(SALARY) AS MAXIMUM
	FROM EMP
	WHERE CITY LIKE 'R%'
	GROUP BY DEPARTMENT

	SELECT CITY, MAX(SALARY) AS MAXIMUM
	FROM EMP
	WHERE CITY LIKE 'R%'
	GROUP BY CITY