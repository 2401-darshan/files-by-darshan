CREATE DATABASE Bsc_Hons_506

CREATE TABLE STU_INFO(
	RNO INT,
	NAME VARCHAR(50),
	BRANCH VARCHAR(20),
);

INSERT INTO STU_INFO VALUES
(101, 'RAJU', 'CE'),
(102, 'AMIT', 'CE'),
(103, 'SANJAY', 'ME'),
(104, 'NEHA', 'EC'),
(105, 'MEERA', 'EE'),
(106, 'MAHESH', 'ME');

SELECT * FROM STU_INFO

CREATE TABLE RESULT(
	RNO INT,
	SPI DECIMAL(2,1),
);

INSERT INTO RESULT VALUES
(101, 8.8),
(102, 9.2),
(103, 7.6),
(104, 8.2),
(105, 7.0),
(107, 8.9);

SELECT * FROM RESULT

CREATE TABLE EMP_MASTER(
	EMPNO CHAR(20),
	NAME VARCHAR(50),
	MNGNO CHAR(20),
);

INSERT INTO EMP_MASTER VALUES
('E01', 'TARUN', 'NULL'),
('E02', 'ROHAN', 'E02'),
('E03', 'PRIYA', 'E01'),
('E04', 'MILAN', 'E03'),
('E05', 'JAY', 'E01'),
('E06', 'ANJANA', 'E04');

SELECT * FROM EMP_MASTER


-----------Part – A:

--1. Combine information from student and result table using cross join or Cartesian product.
	SELECT S.RNO, S.NAME, S.BRANCH, R.SPI
	FROM STU_INFO S
	CROSS JOIN RESULT R

--2. Perform inner join on Student and Result tables.
	SELECT S.RNO, S.NAME, S.BRANCH, R.SPI
	FROM STU_INFO S
	INNER JOIN RESULT R
	ON S.RNO = R.RNO;

--3. Perform the left outer join on Student and Result tables.
	SELECT S.RNO, S.NAME, S.BRANCH, R.SPI
	FROM STU_INFO S
	LEFT OUTER JOIN RESULT R
	ON S.RNO = R.RNO;

--4. Perform the right outer join on Student and Result tables.
	SELECT S.RNO, S.NAME, S.BRANCH, R.SPI
	FROM STU_INFO S
	RIGHT OUTER JOIN RESULT R
	ON S.RNO = R.RNO;

--5. Perform the full outer join on Student and Result tables.
	SELECT S.RNO, S.NAME, S.BRANCH, R.SPI
	FROM STU_INFO S
	FULL OUTER JOIN RESULT R
	ON S.RNO = R.RNO;

--6. Display Rno, Name, Branch and SPI of all students.
	SELECT S.RNO, S.NAME, S.BRANCH, R.RNO, R.SPI
	FROM STU_INFO S
	LEFT JOIN RESULT R
	ON S.RNO = R.RNO;
	
--7. Display Rno, Name, Branch and SPI of CE branch’s student only.
	SELECT S.RNO, S.NAME, S.BRANCH, R.SPI
	FROM STU_INFO S
	JOIN RESULT R
	ON S.RNO = R.RNO
	WHERE S.BRANCH = 'CE'

--8. Display Rno, Name, Branch and SPI of other than EC branch’s student only.
	SELECT S.RNO, S.NAME, S.BRANCH, R.SPI
	FROM STU_INFO S
	JOIN RESULT R
	ON S.RNO = R.RNO
	WHERE S.BRANCH !='EC'

--9. Display average result of each branch.
	SELECT S.BRANCH, AVG(R.SPI) AS AVERAGE_RESULT
	FROM STU_INFO S
	JOIN RESULT R
	ON S.RNO = R.RNO
	GROUP BY S.BRANCH

--10. Display average result of CE and ME branch.
	SELECT S.BRANCH, AVG(R.SPI) AS AVERAGE_RESULT
	FROM STU_INFO S
	JOIN RESULT R
	ON S.RNO = R.RNO
	WHERE S.BRANCH = 'CE'
	GROUP BY S.BRANCH

	SELECT S.BRANCH, AVG(R.SPI) AS AVERAGE_RESULT
	FROM STU_INFO S
	JOIN RESULT R
	ON S.RNO = R.RNO
	WHERE S.BRANCH = 'ME'
	GROUP BY S.BRANCH

--11. Display Maximum and Minimum SPI of each branch.
	SELECT S.BRANCH, MAX(R.SPI) AS MAXIMUM, MIN(R.SPI) AS MINIMUM
	FROM STU_INFO S
	JOIN RESULT R
	ON S.RNO = R.RNO
	GROUP BY S.BRANCH;
	
--12. Display branch wise student’s count in descending order.
	SELECT S.BRANCH, COUNT(S.NAME) AS TOTAL
	FROM STU_INFO S
	GROUP BY S.BRANCH
	ORDER BY COUNT(S.NAME) DESC

--Part – B:
--1. Display average result of each branch and sort them in ascending order by SPI.
	SELECT S.BRANCH, AVG(R.SPI) AS AVERAGE
	FROM STU_INFO S
	JOIN RESULT R
	ON S.RNO = R.RNO
	GROUP BY S.BRANCH
	ORDER BY AVG(R.SPI) 

--2. Display highest SPI from each branch and sort them in descending order.
	SELECT S.BRANCH, MAX(R.SPI) AS HIGHEST
	FROM STU_INFO S
	JOIN RESULT R
	ON S.RNO = R.RNO
	GROUP BY S.BRANCH
	ORDER BY MAX(R.SPI) DESC

--Part – C:
--1. Retrieve the names of employee along with their manager’s name from the Employee table.
	SELECT E.NAME, E.MNGNO 
	FROM EMP_MASTER E