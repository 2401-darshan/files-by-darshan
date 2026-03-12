--Math functions
--Part – A:
--1. Display the result of 5 multiply by 30.
	SELECT 5*30

--2. Find out the absolute value of -25, 25, -50 and 50.
	SELECT ABS(-25), 
		   ABS(25), 
		   ABS(-50), 
		   ABS(50)

--3. Find smallest integer value that is greater than or equal to 25.2, 25.7 and -25.2.
	SELECT CEILING(25.2), 
		   CEILING(25.7), 
		   CEILING(-25.2)

--4. Find largest integer value that is smaller than or equal to 25.2, 25.7 and -25.2.
	SELECT FLOOR(25.2), 
		   FLOOR(25.7), 
		   FLOOR(-25.2)

--5. Find out remainder of 5 divided 2 and 5 divided by 3.
	SELECT 5/2, 5/3
	
--6. Find out value of 3 raised to 2nd power and 4 raised 3rd power.
	SELECT POWER(3,2), POWER(4,3)

--7. Find out the square root of 25, 30 and 50.
	SELECT SQUARE(25), SQUARE(30), SQUARE(50)

--8. Find out the square of 5, 15, and 25.
	SELECT SQUARE(5), SQUARE(15), SQUARE(25)

--9. Find out the value of PI.
	SELECT PI()

--10. Find out round value of 157.732 for 2, 0 and -2 decimal points.
	SELECT ROUND(157.732, 2),
		   ROUND(157.732, 0),
		   ROUND(157.732, -2)

--11. Find out exponential value of 2 and 3.
	SELECT EXP(2), EXP(3)

--12. Find out logarithm having base e of 10 and 2.
	SELECT LOG(10), LOG(2)

--13. Find out logarithm having base b having value 10 of 5 and 100.
	SELECT LOG10(5), LOG10(100)
	
--14. Find sine, cosine and tangent of 3.1415.
	SELECT SIN(3.1415), COS(3.1415), TAN(3.1415)

--15. Find sign of -25, 0 and 25.
	SELECT SIGN(-25), SIGN(0), SIGN(25)

--16. Generate random number using function.
	SELECT RAND();            
	SELECT FLOOR(RAND() * 10000);


-------------PART - B:-

CREATE TABLE EMPMASTER(
	EMPNO INT,
	EMPNAME VARCHAR(50),
	JOININGDATE DATE,
	SALARY DECIMAL(7,2),
	COMMISSION INT,
	CITY VARCHAR(20),
	DEPTCODE VARCHAR(10)
);

INSERT INTO EMPMASTER VALUES
(101, 'KEYUR', '2002-01-05', 12000.00, 4500, 'RAJKOT', '3@G'),
(102, 'HARDIK', '2004-02-15', 14000.00, 2500, 'AHMEDABAD', '3@'),
(103, 'KAJAL', '2006-03-14', 15000.00, 3000, 'BARODA', '3-GD'),
(104, 'BHOOMI', '2005-06-23', 12500.00, 1000, 'AHMEDABAD', '1A3D'),
(105, 'HARMIT', '2004-02-15', 14000.00, 2000, 'RAJKOT', '312A');

--1. Display the result of Salary plus Commission.
	SELECT SALARY+COMMISSION FROM EMPMASTER
	
--2. Find smallest integer value that is greater than or equal to 55.2, 35.7 and -55.2.
	SELECT CEILING(55.2), CEILING(35.7), CEILING(-55.2)

--3. Find largest integer value that is smaller than or equal to 55.2, 35.7 and -55.2.
	SELECT FLOOR(55.2), FLOOR(35.7), FLOOR(-55.2)

--4. Find out remainder of 55 divided 2 and 55 divided by 3.
	SELECT 55/2, 55/3

--5. Find out value of 23 raised to 2nd power and 14 raised 3rd power.
	SELECT POWER(23,2), POWER(14,3)

--Part – C:
--1. Retrieve the details of employees whose total earnings (Salary + Commission) are greater than 15000.
	SELECT * FROM EMPMASTER
	WHERE (SALARY + COMMISSION) > 15000

--2. Find the details of employees whose commission is more than 25% of their salary.
	SELECT * FROM EMPMASTER
	WHERE COMMISSION > (SALARY * 0.25)

--3. List the employees who joined before 2005 and whose total earnings (Salary + Commission) are greater
--than 15000.
	SELECT * FROM EMPMASTER
	WHERE (JOININGDATE < '2005-06-23') AND (SALARY + COMMISSION)>15000

--4. Find employees whose total earnings (Salary + Commission) are at least double their salary.
	SELECT * FROM EMPMASTER
	WHERE (SALARY + COMMISSION) >= 2 * Salary;
 

-- String functions

----------Part – A:
-- 1. Length of NULL, 'hello', Blank ('')
	SELECT LEN(NULL), LEN('hello'), LEN('')

-- 2. Your name in lower and upper case
	SELECT LOWER('YourName'), UPPER('YourName')

-- 3. First three characters of your name
	SELECT SUBSTRING('YourName', 1, 3)

-- 4. 3rd to 10th character of your name
	SELECT SUBSTRING('YourName', 3, 8)

-- 5. Replace '123' with 'XYZ' in 'abc123efg' and 'abc' with '5ab' in 'abcabcabc'
	SELECT REPLACE('abc123efg', '123', 'XYZ'), REPLACE('abcabcabc', 'abc', '5ab')

-- 6. ASCII code for 'a','A','z','Z','0','9'
	SELECT ASCII('a'), ASCII('A'), ASCII('z'), ASCII('Z'), ASCII('0'), ASCII('9')

-- 7. Character for ASCII codes 97, 65, 122, 90, 48, 57
	SELECT CHAR(97), CHAR(65), CHAR(122), CHAR(90), CHAR(48), CHAR(57)

-- 8. Remove spaces from left of 'hello world '
	SELECT LTRIM('   hello world ')

-- 9. Remove spaces from right of ' hello world '
	SELECT RTRIM(' hello world   ')

-- 10. First 4 and last 5 characters of 'SQL Server'
	SELECT LEFT('SQL Server', 4) + RIGHT('SQL Server', 5)

-- 11. Convert '1234.56' to number using CAST and CONVERT
	SELECT CAST('1234.56' AS FLOAT), CONVERT(FLOAT, '1234.56')

-- 12. Convert float 10.58 to integer using CAST and CONVERT
	SELECT CAST(10.58 AS INT), CONVERT(INT, 10.58)

-- 13. Put 10 spaces before your name
	SELECT REPLICATE(' ', 10) + 'YourName'

-- 14. Combine two strings using + and CONCAT()
	SELECT 'Hello' + 'World', CONCAT('Hello', 'World')

-- 15. Reverse of 'Darshan'
	SELECT REVERSE('Darshan')

-- 16. Repeat your name 3 times
	SELECT REPLICATE('YourName', 3)


--------------------Part – B: Perform following queries on EMPMASTER table.


-- 1. Length of EMP Name and City
	SELECT LEN(EMPNAME), LEN(CITY) FROM EMPMASTER

-- 2. EMP Name and City in lower and upper case
	SELECT LOWER(EMPNAME), UPPER(EMPNAME), LOWER(CITY), UPPER(CITY) FROM EMPMASTER

-- 3. First three characters of EMP Name
	SELECT SUBSTRING(EMPNAME, 1, 3) FROM EMPMASTER

-- 4. 3rd to 10th character of City
	SELECT SUBSTRING(CITY, 3, 8) FROM EMPMASTER

-- 5. First 4 and last 5 characters of EMP Name
	SELECT LEFT(EMPNAME, 4) + RIGHT(EMPNAME, 5) FROM EMPMASTER



--------------------Part – C: Perform following queries on EMPMASTER table.

-- 1. Put 10 spaces before EMP Name
	SELECT REPLICATE(' ', 10) + EMPNAME FROM EMPMASTER

-- 2. Combine EMP Name and City using + and CONCAT()
	SELECT EMPNAME + CITY, CONCAT(EMPNAME, CITY) FROM EMPMASTER

-- 3. Combine all columns using + and CONCAT()
	SELECT CAST(EMPNO AS VARCHAR) + EMPNAME + CITY, CONCAT(CAST(EMPNO AS VARCHAR), EMPNAME, CITY) FROM EMPMASTER

-- 4. Combine as '<EMP Name> Lives in <City>'
	SELECT EMPNAME + ' Lives in ' + CITY FROM EMPMASTER

-- 5. Combine as 'EMP no of <EMP Name> is <EmpNo>'
	SELECT 'EMP no of ' + EMPNAME + ' is ' + CAST(EMPNO AS VARCHAR) FROM EMPMASTER

-- 6. Names where 3rd character is a vowel (a,e,i,o,u)
	SELECT EMPNAME FROM EMPMASTER WHERE SUBSTRING(EMPNAME, 3, 1) IN ('a','e','i','o','u','A','E','I','O','U')

-- 7. Concatenate name and city where name ends with 'r' and city starts with 'R'
	SELECT EMPNAME + CITY FROM EMPMASTER WHERE EMPNAME LIKE '%r' AND CITY LIKE 'R%'


-------------DATE FUNCTIONS-----------


------PART - A: -

-- 1. Current date & time
	SELECT GETDATE()

-- 2. New date after 365 days
	SELECT DATEADD(DAY, 365, GETDATE())

-- 3. Current date as 'May 5 1994 12:00AM' format
	SELECT CONVERT(VARCHAR, GETDATE(), 109)

-- 4. Current date as '03 Jan 1995'
	SELECT CONVERT(VARCHAR, GETDATE(), 106)

-- 5. Current date as 'Jan 04, 96'
	SELECT CONVERT(VARCHAR, GETDATE(), 6)

-- 6. Months between 31-Dec-08 and 31-Mar-09
	SELECT DATEDIFF(MONTH, '2008-12-31', '2009-03-31')

-- 7. Hours between 25-Jan-12 7:00 and 26-Jan-12 10:30
	SELECT DATEDIFF(HOUR, '2012-01-25 07:00', '2012-01-26 10:30')

-- 8. Extract Day, Month, Year from '12-May-16'
	SELECT DAY('2016-05-12'), MONTH('2016-05-12'), YEAR('2016-05-12')

-- 9. Add 5 years to current date
	SELECT DATEADD(YEAR, 5, GETDATE())

-- 10. Subtract 2 months from current date
	SELECT DATEADD(MONTH, -2, GETDATE())

-- 11. Extract month from current date using DATENAME and DATEPART
	SELECT DATENAME(MONTH, GETDATE()), DATEPART(MONTH, GETDATE())

-- 12. Last date of current month
	SELECT EOMONTH(GETDATE())

-- 13. Calculate age in years and months (assume DOB = '2000-05-15')
	SELECT DATEDIFF(YEAR, '2000-05-15', GETDATE()), DATEDIFF(MONTH, '2000-05-15', GETDATE()) % 12



------PART - B: -
-- 1. New date after 365 days from JoiningDate
	SELECT DATEADD(DAY, 365, JOININGDATE) FROM EMP_MASTER

-- 2. Total number of months between JoiningDate and 31-Mar-09
	SELECT DATEDIFF(MONTH, JOININGDATE, '2009-03-31') FROM EMP_MASTER

-- 3. Total number of years between JoiningDate and 14-Sep-10
	SELECT DATEDIFF(YEAR, JOININGDATE, '2010-09-14') FROM EMP_MASTER




-------PART - C :-

-- 1. Extract Day, Month, Year from JoiningDate
	SELECT DAY(JOININGDATE), MONTH(JOININGDATE), YEAR(JOININGDATE) FROM EMP_MASTER

-- 2. Add 5 years to JoiningDate
	SELECT DATEADD(YEAR, 5, JOININGDATE) FROM EMP_MASTER

-- 3. Subtract 2 months from JoiningDate
	SELECT DATEADD(MONTH, -2, JOININGDATE) FROM EMP_MASTER

-- 4. Extract month from JoiningDate using DATENAME and DATEPART
	SELECT DATENAME(MONTH, JOININGDATE), DATEPART(MONTH, JOININGDATE) FROM EMP_MASTER

-- 5. Employees who joined between 1st and 15th of any month
	SELECT * FROM EMP_MASTER WHERE DAY(JOININGDATE) BETWEEN 1 AND 15

-- 6. Employees whose JoiningDate is last day of any month
	SELECT * FROM EMP_MASTER WHERE JOININGDATE = EOMONTH(JOININGDATE)

-- 7. Employees whose JoiningDate is in a leap year
	SELECT * FROM EMP_MASTER WHERE (YEAR(JOININGDATE) % 4 = 0 AND (YEAR(JOININGDATE) % 100 <> 0 OR YEAR(JOININGDATE) % 400 = 0))

