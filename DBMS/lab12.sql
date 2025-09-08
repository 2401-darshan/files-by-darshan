--Part – A:
--1. Combine information from Person and Department table using cross join or Cartesian product.
	SELECT * FROM PERSON
	CROSS JOIN DEPT

--2. Find all persons with their department name
	SELECT P.PERSONNAME, D.DEPARTMENTNAME
	FROM PERSON P
	JOIN DEPT D
	ON P.DEPARTMENTID = D.DEPARTMENTID

--3. Find all persons with their department name & code.
	SELECT P.PERSONNAME, D.DEPARTMENTNAME, D.DEPARTMENTCODE
	FROM PERSON P
	JOIN DEPT D
	ON P.DEPARTMENTID = D.DEPARTMENTID

--4. Find all persons with their department code and location.
	SELECT P.PERSONNAME, D.DEPARTMENTCODE, D.LOCATION
	FROM PERSON P
	JOIN DEPT D
	ON P.DEPARTMENTID = D.DEPARTMENTID

--5. Find the detail of the person who belongs to Mechanical department.
	SELECT P.PERSONNAME, D.DEPARTMENTNAME
	FROM PERSON P
	JOIN DEPT D
	ON P.DEPARTMENTID = D.DEPARTMENTID
	WHERE DEPARTMENTNAME = 'MECHANICAL'
	
--6. Final person’s name, department code and salary who lives in Ahmedabad city.
	SELECT P.PERSONNAME, D.DEPARTMENTCODE, P.SALARY
	FROM PERSON P
	JOIN DEPT D
	ON P.DEPARTMENTID = D.DEPARTMENTID
	WHERE CITY = 'AHMEDABAD'

--7. Find the person's name whose department is in C-Block.
	SELECT P.PERSONNAME, D.DEPARTMENTNAME
	FROM PERSON P
	JOIN DEPT D
	ON P.DEPARTMENTID = D.DEPARTMENTID
	WHERE LOCATION = 'C-BLOCK'

--8. Retrieve person name, salary & department name who belongs to Jamnagar city.
	SELECT P.PERSONNAME, D.DEPARTMENTNAME, P.SALARY
	FROM PERSON P
	JOIN DEPT D
	ON P.DEPARTMENTID = D.DEPARTMENTID
	WHERE CITY = 'JAMNAGAR'
	
--9. Retrieve person’s detail who joined the Civil department after 1-Aug-2001.
	SELECT P.PERSONNAME
	FROM PERSON P
	JOIN DEPT D
	ON P.DEPARTMENTID = D.DEPARTMENTID
	WHERE DEPARTMENTNAME = 'CIVIL' AND JoiningDate>'2001-08-01'

--10. Display all the person's name with the department whose joining date difference with the current date
--is more than 365 days.
	SELECT P.PERSONNAME, D.DEPARTMENTNAME
	FROM PERSON P
	JOIN DEPT D
	ON P.DEPARTMENTID = D.DEPARTMENTID
	WHERE DATEDIFF(DAY, JOININGDATE, GETDATE()) > 365

--11. Find department wise person counts.
	SELECT D.DEPARTMENTNAME, COUNT(P.PERSONNAME) AS TOTAL
	FROM PERSON P
	JOIN DEPT D
	ON P.DEPARTMENTID = D.DEPARTMENTID
	GROUP BY D.DEPARTMENTNAME

--12. Give department wise maximum & minimum salary with department name.
	SELECT D.DEPARTMENTNAME, MAX(P.SALARY), MIN(P.SALARY)
	FROM PERSON P
	JOIN DEPT D
	ON P.DEPARTMENTID = D.DEPARTMENTID
	GROUP BY D.DEPARTMENTNAME

--13. Find city wise total, average, maximum and minimum salary.
	SELECT P.CITY,
		MIN(P.SALARY) AS MINIMUM,
		MAX(P.SALARY) AS MAXIMUM,
		AVG(P.SALARY) AS AVERAGE,
		SUM(P.SALARY) AS TOTAL
	FROM PERSON P
	JOIN DEPT D
	ON P.DEPARTMENTID = D.DEPARTMENTID
	GROUP BY P.CITY

--14. Find the average salary of a person who belongs to Ahmedabad city.
	SELECT P.CITY, AVG(P.SALARY) AS AVERAGE
	FROM PERSON P
	JOIN DEPT D
	ON P.DEPARTMENTID = D.DEPARTMENTID
	WHERE CITY = 'AHMEDABAD'
	GROUP BY P.CITY

--15. Produce Output Like: <PersonName> lives in <City> and works in <DepartmentName> Department. (In
--single column)
	SELECT P.PERSONNAME + ' lives in ' + P.CITY + ' and works in ' + D.DEPARTMENTNAME + ' department'
	FROM PERSON P
	JOIN DEPT D
	ON P.DEPARTMENTID = D.DEPARTMENTID



--Part – B:
--1. Produce Output Like: <PersonName> earns <Salary> from <DepartmentName> department monthly. (In
--single column)
	SELECT P.PERSONNAME + ' earns ' + CAST(P.SALARY AS VARCHAR(50)) + ' from ' + D.DEPARTMENTNAME + ' department monthly.'
	 FROM PERSON P
	 JOIN DEPT D
	 ON P.DEPARTMENTID = D.DEPARTMENTID

--2. Find city & department wise total, average & maximum salaries.
	SELECT P.CITY, D.DEPARTMENTNAME,
		SUM(P.SALARY) AS TOTAL,
		AVG(P.SALARY) AS AVERAGE,
		MAX(P.SALARY) AS MAXIMUM
	FROM PERSON P
	JOIN DEPT D
	ON P.DEPARTMENTID = D.DEPARTMENTID

--3. Find all persons who do not belong to any department.
	SELECT P.PERSONNAME
	FROM PERSON P
	LEFT OUTER JOIN DEPT D
	ON P.DEPARTMENTID = D.DEPARTMENTID
	WHERE D.DEPARTMENTID IS NULL

--4. Find all departments whose total salary is exceeding 100000.
	SELECT D.DEPARTMENTNAME, SUM(P.SALARY) AS TOTAL
	FROM PERSON P
	JOIN DEPT D
	ON P.DEPARTMENTID = D.DEPARTMENTID
	GROUP BY D.DEPARTMENTNAME
	HAVING SUM(P.SALARY) > 100000

--Part – C:
--1. List all departments who have no person.
--2. List out department names in which more than two persons are working.

--3. Give a 10% increment in the computer department employee’s salary. (Use Update)
