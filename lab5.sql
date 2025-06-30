USE Bsc_Hons_506

------------------ALTER, RENAME OPERATION------------------------
------------------PART - A :-------------------------------------
--From the above given tables perform the following queries (ALTER, RENAME Operation): 
--1. Add two more columns City VARCHAR (20) and Pincode INT. 
	ALTER TABLE DEPOSIT
	ADD CITY VARCHAR(20), PINCODE INT

	SELECT * FROM DEPOSIT

--2. Add column state VARCHAR(20). 
	ALTER TABLE DEPOSIT
	ADD STATE VARCHAR(20)

--3. Change the size of CNAME column from VARCHAR (50) to VARCHAR (35). 
	ALTER TABLE DEPOSIT
	ALTER COLUMN CNAME VARCHAR(35)

--4. Change the data type DECIMAL to INT in amount Column. 
	ALTER TABLE DEPOSIT
	ALTER COLUMN AMOUNT INT

--5. Delete Column City from the DEPOSIT table.
	ALTER TABLE DEPOSIT
	DROP COLUMN CITY

--6. Rename Column ActNo to ANO. 
	EXEC SP_RENAME 'ACTNO', 'ANO'

--7. Change name of table DEPOSIT to DEPOSIT_DETAIL.
	EXEC SP_RENAME 'DEPOSIT', 'DEPOSIT_DETAIL'
	
	SELECT * FROM DEPOSIT_DETAIL

----------------------Part – B-------------------: 
--1. Rename Column ADATE to AOPENDATE OF DEPOSIT_DETAIL table.
	EXEC SP_RENAME 'DEPOSIT_DETAIL.ADATE', 'AOPENDATE'

--2. Delete Column AOPENDATE from the DEPOSIT_DETAIL table.
	ALTER TABLE DEPOSIT_DETAIL
	DROP COLUMN AOPENDATE

--3. Rename Column CNAME to CustomerName.
	EXEC SP_RENAME 'DEPOSIT_DETAIL.CNAME', 'CUSTOMERNAME'

--4. Add Column country. 
	ALTER TABLE DEPOSIT_DETAIL
	ADD COUNTRY VARCHAR(20)
 
----------------Part – C-------------: 

CREATE TABLE STUDENT_DETAIL(
	ENROLLMENT_NO VARCHAR(20),
	NAME VARCHAR(25),
	CPI DECIMAL(5,2),
	BIRTHDATE DATETIME
);
SELECT * FROM STUDENT_DETAIL

--From the above given tables perform the following queries (ALTER, RENAME Operation): 
--1. Add two more columns City VARCHAR (20) (Not null) and Backlog INT (Null).
	

--2. Add column department VARCHAR (20) Not Null. 
--3. Change the size of NAME column of student_detail from VARCHAR (25) to VARCHAR (35). 
--4. Change the data type DECIMAL to INT in CPI Column. 
--5. Delete Column City from the student_detail table. 
--6. Rename Column Enrollment_No to ENO. 
--7. Change name of table student_detail to STUDENT_MASTER.