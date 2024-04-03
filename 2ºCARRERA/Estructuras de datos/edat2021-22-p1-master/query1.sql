-- http://www.dpriver.com/pp/sqlformat.htm  
-- IMPORTANT: this is just an example.
-- You will need to rewrite both the description
-- and the query.
-- 
-- List the total amount of money paid by the customers that have ordered 
-- the 1940 Ford Pickup Truck (the money may be paid to purchase other items)
-- Order the result by the amount of money paid. Use descending order.
-- Each row should show customernumber, customername and total amount
WITH buyers as (
    SELECT distinct customernumber, customername
    FROM products
        natural JOIN orderdetails
        natural JOIN orders
        natural JOIN customers
    WHERE productname = '1940 Ford Pickup Truck'
)
SELECT customernumber, customername, sum(amount) AS amount
FROM buyers
    natural JOIN payments
GROUP BY customernumber, customername
ORDER BY amount desc;
