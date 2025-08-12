CREATE TABLE PERSON (
    PersonID INT PRIMARY KEY,
    PersonName VARCHAR(100) NOT NULL,
    DepartmentID INT NULL,
    Salary DECIMAL(8,2) NOT NULL,
    JoiningDate DATETIME NOT NULL,
    City VARCHAR(100) NOT NULL,
);   --table-1


CREATE TABLE DEPT (
    DepartmentID INT PRIMARY KEY,
    DepartmentName VARCHAR(100) NOT NULL UNIQUE,
    DepartmentCode VARCHAR(50) NOT NULL UNIQUE,
    Location VARCHAR(50) NOT NULL
);  --table 2


INSERT INTO PERSON (PersonID, PersonName, DepartmentID, Salary, JoiningDate, City)
VALUES
(101, 'Rahul Tripathi', 2, 56000.00, '2000-01-01', 'Rajkot'),
(102, 'Hardik Pandya', 3, 18000.00, '2001-09-25', 'Ahmedabad'),
(103, 'Bhavin Kanani', 4, 25000.00, '2000-05-14', 'Baroda'),
(104, 'Bhoomi Vaishnav', 1, 39000.00, '2005-02-08', 'Rajkot'),
(105, 'Rohit Topiya', 2, 17000.00, '2001-07-23', 'Jamnagar'),
(106, 'Priya Menpara', NULL, 9000.00, '2000-10-18', 'Ahmedabad'),
(107, 'Neha Sharma', 2, 34000.00, '2002-12-25', 'Rajkot'),
(108, 'Nayan Goswami', 3, 25000.00, '2001-07-01', 'Rajkot'),
(109, 'Mehul Bhundiya', 4, 13500.00, '2005-01-09', 'Baroda'),
(110, 'Mohit Maru', 5, 14000.00, '2000-05-25', 'Jamnagar');


INSERT INTO DEPT (DepartmentID, DepartmentName, DepartmentCode, Location)
VALUES
(1, 'Admin', 'Adm', 'A-Block'),
(2, 'Computer', 'CE', 'C-Block'),
(3, 'Civil', 'CI', 'G-Block'),
(4, 'Electrical', 'EE', 'E-Block'),
(5, 'Mechanical', 'ME', 'B-Block');

select * from person;

select * from dept;



--Part – A: 
--1. Combine information from Person and Department table using cross join or Cartesian product. 
select * 
from person cross join dept;

--2. Find all persons with their department name 
select person.PersonName ,  dept.DepartmentName
from person join dept
on person.DepartmentID = dept.DepartmentID;

--3. Find all persons with their department name & code.
select person.PersonName,dept.DepartmentName,dept.DepartmentCode
from person join dept
on person.DepartmentID = dept.DepartmentID;

--4. Find all persons with their department code and location.
select person.PersonName,dept.Location,dept.DepartmentCode
from person join dept
on person.DepartmentID = dept.DepartmentID;

--5. Find the detail of the person who belongs to Mechanical department. 
select person.PersonName,dept.Location,dept.DepartmentCode
from person join dept
on person.DepartmentID = dept.DepartmentID
where dept.DepartmentName = 'mechanical'

--6. Final person’s name, department code and salary who lives in Ahmedabad city.  
select  person.PersonName,dept.DepartmentCode,person.Salary
from person join dept
on person.DepartmentID = dept.DepartmentID
where person.city='Ahmedabad';   --only one record bcz priya's deptid is null

--7. Find the person's name whose department is in C-Block. 
select person.PersonName,dept.DepartmentName
from person join dept
on person.DepartmentID = dept.DepartmentID
where dept.Location = 'c-block';

--8. Retrieve person name, salary & department name who belongs to Jamnagar city.
select person.PersonName,Person.Salary,dept.DepartmentName
from person join dept
on person.DepartmentID = dept.DepartmentID
where person.city='jamnagar';

--9. Retrieve person’s detail who joined the Civil department after 1-Aug-2001. 
select person.PersonName,Person.Salary,dept.DepartmentName
from person join dept
on person.DepartmentID = dept.DepartmentID
where dept.DepartmentCode='ci' and person.JoiningDate > '2001-08-01';

--10. Display all the person's name with the department whose joining date difference with the current date 
--is more than 365 days. 
select person.PersonName,dept.DepartmentName
from person join dept
on person.DepartmentID = dept.DepartmentID
where DATEDIFF(day,JoiningDate,getdate()) > 365;

--11. Find department wise person counts. 
select dept.DepartmentCode,
count(person.PersonID) as departmeent_person
from person join dept
on person.DepartmentID = dept.DepartmentID
group by  dept.DepartmentCode;

--12. Give department wise maximum & minimum salary with department name. 
select dept.DepartmentName,
max(person.Salary) as max_department_salary,
min(PERSON.Salary) as min_department_salary
from person join dept
on person.DepartmentID = dept.DepartmentID
group by dept.DepartmentName;

--13. Find city wise total, average, maximum and minimum salary.
select person.city,
max(person.Salary) as max_city_salary,
min(PERSON.Salary) as min_city_salary,
avg(person.Salary) as avg_city_salary,
sum(person.salary) as total_city_salary
from person join dept
on person.DepartmentID = dept.DepartmentID
group by person.City

--14. Find the average salary of a person who belongs to Ahmedabad city. 
select person.city,
avg(person.Salary) as ahemdabad_avg_salary
from person join dept
on person.DepartmentID = dept.DepartmentID
where person.city='ahmedabad'
group by person.city

--15. Produce Output Like: <PersonName> lives in <City> and works in <DepartmentName> Department. (In 
--single column) 
select PERSON.PersonName + ' lives in ' + PERSON.city + ' and works in ' + dept.DepartmentName
from person join dept
on person.DepartmentID = dept.DepartmentID




--Part – B: 
--1. Produce Output Like: <PersonName> earns <Salary> from <DepartmentName> department monthly. (In 
--single column) 
select PERSON.PersonName + ' earns ' + cast(PERSON.Salary as varchar) + ' from ' + dept.DepartmentName + ' department monthly '
from person join dept
on person.DepartmentID = dept.DepartmentID

--2. Find city & department wise total, average & maximum salaries. 
select PERSON.city,dept.DepartmentName,
sum(person.Salary) as city_dept_total_sal,
avg(person.Salary) as city_dept_avg_sal,
max(PERSON.Salary) as city_dept_max_sal
from person join dept
on person.DepartmentID = dept.DepartmentID
group by person.city,dept.DepartmentName

--3. Find all persons who do not belong to any department. 
select person.PersonName
from person left outer join dept
on person.DepartmentID = dept.DepartmentID
where DEPT.DepartmentID is null;

--4. Find all departments whose total salary is exceeding 100000.
select dept.DepartmentName,
sum(person.Salary) as total_salary
from person  join dept
on person.DepartmentID = dept.DepartmentID
group by DEPT.DepartmentName
having sum(person.Salary) > 100000



--Part – C: 
--1. List all departments who have no person. 
select DEPT.DepartmentName
from person right outer join dept
on person.DepartmentID = dept.DepartmentID
where PERSON.DepartmentID is NULL;

--2. List out department names in which more than two persons are working. 
select DEPT.DepartmentName
from person join dept
on person.DepartmentID = dept.DepartmentID
group by dept.DepartmentName
having count(person.DepartmentID) > 2

--3. Give a 10% increment in the computer department employee’s salary. (Use Update) 
update  person
set salary = PERSON.Salary + (PERSON.Salary * 0.1)
from person join dept
on person.DepartmentID = dept.DepartmentID
where dept.DepartmentCode ='ce';

select * from person;