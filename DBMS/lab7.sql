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
	SELECT ENAME, MAX(SALARY) AS MAXIMUM
	FROM EMP
	GROUP BY ENAME

	SELECT ENAME, MIN(SALARY) AS MINIMUM
	FROM EMP
	GROUP BY ENAME

--2. Display Total, and Average salary of all employees. Label the columns Total_Sal and Average_Sal, 
--respectively. 
	SELECT ENAME, COUNT(SALARY) AS TOTAL_SAL
	FROM EMP
	GROUP BY ENAME

	SELECT ENAME, AVG(SALARY) AS AVERAGE_SAL
	FROM EMP
	GROUP BY ENAME

--3. Find total number of employees of EMPLOYEE table.
	SELECT COUNT(ENAME) AS TOTAL
	FROM EMP

--4. Find highest salary from Rajkot city.
	SELECT CITY, MAX(SALARY) AS HIGHEST_SAL
	FROM EMP
	WHERE CITY='RAJKOT'
	GROUP BY CITY

--5. Give maximum salary from IT department.
	SELECT DEPARTMENT, MAX(SALARY) AS MAXIMUM
	FROM EMP
	WHERE DEPARTMENT = 'IT'
	GROUP BY DEPARTMENT

--6. Count employee whose joining date is after 8-feb-91.

--7. Display average salary of Admin department. 
--8. Display total salary of HR department. 
--9. Count total number of cities of employee without duplication. 
--10. Count unique departments. 
--11. Give minimum salary of employee who belongs to Ahmedabad. 
--12. Find city wise highest salary. 
--13. Find department wise lowest salary. 
--14. Display city with the total number of employees belonging to each city. 
--15. Give total salary of each department of EMP table. 
--16. Give average salary of each department of EMP table without displaying the respective department 
--name. 
--17. Count the number of employees for each department in every city. 
--18. Calculate the total salary distributed to male and female employees. 
--19. Give city wise maximum and minimum salary of female employees. 
--20. Calculate department, city, and gender wise average salary. 
--Part – B: 
--1. Count the number of employees living in Rajkot. 
--2. Display the difference between the highest and lowest salaries. Label the column DIFFERENCE. 
--3. Display the total number of employees hired before 1st January, 1991. 
--Part – C: 
--1. Count the number of employees living in Rajkot or Baroda. 
--2. Display the total number of employees hired before 1st January, 1991 in IT department. 
--3. Find the Joining Date wise Total Salaries. 
--4. Find the Maximum salary department & city wise in which city name starts with ‘R’. 