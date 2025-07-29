CREATE TABLE SALES_DATA(
	REGION VARCHAR(20),
	PRODUCT VARCHAR(30),
	SALES_AMT DECIMAL(6,2),
	YEAR INT
);

INSERT INTO SALES_DATA VALUES
('NORTH AMERICA', 'WATCH', 1500.00, 2023),
('EUROPE', 'MOBILE', 1200.00, 2023),
('ASIA', 'WATCH', 1800.00, 2023),
('NORTH AMERICA', 'TV', 900.00, 2024),
('EUROPE', 'WATCH', 2000.00, 2024),
('ASIA', 'MOBILE', 1000.00, 2024),
('NORTH AMERICA', 'MOBILE', 1600.00, 2023),
('EUROPE', 'TV', 1500.00, 2023),
('ASIA', 'TV', 1100.00, 2024),
('NORTH AMERICA', 'WATCH', 1700.00, 2024);

SELECT * FROM SALES_DATA

--Part – A: 
--1. Display Total Sales Amount by Region.
	SELECT REGION, SUM(SALES_AMT) AS TOTAL_SALES
	FROM SALES_DATA
	GROUP BY REGION

--2. Display Average Sales Amount by Product 
	SELECT PRODUCT, AVG(SALES_AMT) AS AVG_SALES
	FROM SALES_DATA
	GROUP BY PRODUCT

--3. Display Maximum Sales Amount by Year
	SELECT YEAR, MAX(SALES_AMT) AS MAXIMUM
	FROM SALES_DATA
	GROUP BY YEAR

--4. Display Minimum Sales Amount by Region and Year
	SELECT REGION, YEAR, MIN(SALES_AMT) AS MINIMUM 
	FROM SALES_DATA
	GROUP BY REGION, YEAR

--5. Count of Products Sold by Region
	SELECT REGION, COUNT(PRODUCT) AS TOTAL_SOLD
	FROM SALES_DATA
	GROUP BY REGION

--6. Display Sales Amount by Year and Product
	SELECT YEAR, PRODUCT, SUM(SALES_AMT)
	FROM SALES_DATA
	GROUP BY YEAR, PRODUCT

--7. Display Regions with Total Sales Greater Than 5000 
	SELECT REGION, SUM(SALES_AMT) AS TOTAL_SALES
	FROM SALES_DATA
	GROUP BY REGION
	HAVING SUM(SALES_AMT)>5000

--8. Display Products with Average Sales Less Than 10000
	SELECT PRODUCT, AVG(SALES_AMT) AS AVERAGE
	FROM SALES_DATA
	GROUP BY PRODUCT
	HAVING AVG(SALES_AMT)<10000

--9. Display Years with Maximum Sales Exceeding 500
	SELECT YEAR, MAX(SALES_AMT) AS MAXIMUM
	FROM SALES_DATA
	GROUP BY YEAR
	HAVING MAX(SALES_AMT)>500

--10. Display Regions with at Least 3 Distinct Products Sold.
	SELECT REGION, COUNT(DISTINCT PRODUCT) AS TOTAL_SOLD
	FROM SALES_DATA
	GROUP BY REGION

--11. Display Years with Minimum Sales Less Than 1000
	SELECT YEAR, MIN(SALES_AMT) AS MINIMUM
	FROM SALES_DATA
	GROUP BY YEAR
	HAVING MIN(SALES_AMT)<1000

--12. Display Total Sales Amount by Region for Year 2023, Sorted by Total Amount
	SELECT REGION, YEAR, SUM(SALES_AMT) AS TOTAL_SALES
	FROM SALES_DATA
	GROUP BY REGION, YEAR
	HAVING YEAR='2023'
	ORDER BY SUM(SALES_AMT)

--13. Find the Region Where 'Mobile' Had the Lowest Total Sales Across All Years.
	SELECT REGION, YEAR, MIN(SALES_AMT) AS LOWEST
	FROM SALES_DATA
	WHERE PRODUCT='MOBILE'
	GROUP BY REGION, YEAR

--14. Find the Product with the Highest Sales Across All Regions in 2023.
	SELECT PRODUCT, REGION, MAX(SALES_AMT) AS HIGHEST
	FROM SALES_DATA
	WHERE YEAR='2023'
	GROUP BY PRODUCT, REGION

--15. Find Regions Where 'TV' Sales in 2023 Were Greater Than 1000.
	SELECT REGION, SUM(SALES_AMT) AS TOTAL_SALES
	FROM SALES_DATA
	WHERE PRODUCT='TV' AND YEAR='2023'
	GROUP BY REGION
	HAVING SUM(SALES_AMT)>1000

--Part – B: 
--1. Display Count of Orders by Year and Region, Sorted by Year and Region 
	SELECT YEAR, REGION, COUNT(PRODUCT) AS TOTAL
	FROM SALES_DATA
	GROUP BY YEAR, REGION
	ORDER BY YEAR, REGION

--2. Display Regions with Maximum Sales Amount Exceeding 1000 in Any Year, Sorted by Region
	SELECT REGION, MAX(SALES_AMT) AS MAXIMUM
	FROM SALES_DATA
	GROUP BY REGION
	HAVING MAX(SALES_AMT)>1000
	ORDER BY REGION

--3. Display Years with Total Sales Amount Less Than 10000, Sorted by Year Descending
	SELECT YEAR, SUM(SALES_AMT) AS TOTAL
	FROM SALES_DATA
	GROUP BY YEAR
	HAVING SUM(SALES_AMT)<10000
	ORDER BY YEAR DESC

--4. Display Top 3 Regions by Total Sales Amount in Year 2024 
	

--5. Find the Year with the Lowest Total Sales Across All Regions. 
--Part – C: 
--1. Display Products with Average Sales Amount Between 1000 and 2000, Ordered by Product Name 
--2. Display Years with More Than 1 Orders from Each Region 
--3. Display Regions with Average Sales Amount Above 1500 in Year 2023 sort by amount in descending. 
--4. Find out region wise duplicate product. 
--5. Find out year wise duplicate product. 