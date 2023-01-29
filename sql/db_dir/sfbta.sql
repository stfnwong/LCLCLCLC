-- Stuff from "SQL: Beginner to Advanced" on educative.io
-- That course does everything in MySQL, so some adjustments are needed to get it to 
-- run on Postgres

-- This file covers the stuff in the "Basic SQL" section of the course

\echo 'Deleting and recreating [actors_db] database'
DROP DATABASE actors_db;
CREATE DATABASE actors_db;
\connect actors_db;

-- In Postgres it looks like we don't have the ENUM keyword. Instead we create a new 
-- type using the CREATE TYPE name AS ENUM and then use that type in the CREATE TABLE
-- section.

CREATE TYPE GENDER AS ENUM ('Male', 'Female', 'Other');
CREATE TYPE MARITAL_STATUS AS ENUM ('Married', 'Divorced', 'Single', 'Unknown');

CREATE TABLE IF NOT EXISTS actors (
    -- The SERIAL type is the equivalent of INT AUTO_INCREMENT in MySQL
    id SERIAL,
    first_name VARCHAR(20) NOT NULL,
    second_name VARCHAR(20) NOT NULL,
    dob DATE NOT NULL,
    gender GENDER NOT NULL,
    marital_status MARITAL_STATUS DEFAULT 'Unknown',
    net_worth_millions DECIMAL NOT NULL,
    PRIMARY KEY(id));

-- Show something in the shell
\d actors;

-- Insert some data 
INSERT INTO actors (first_name, second_name, dob, gender, marital_status, net_worth_millions)
VALUES ('Brad', 'Pitt', '1963-12-18', 'Male', 'Single', 240.00);


-- In MySQL its possible to have multple VALUES statements together 
INSERT INTO actors (first_name, second_name, dob, gender, marital_status, net_worth_millions)
VALUES ('Jennifer', 'Aniston', '1969-11-02', 'Female', 'Single', 240.00),
('Angelina', 'Jolie', '1975-06-4', 'Female', 'Single', 100.00),
('Johnny', 'Depp', '1963-06-09', 'Male', 'Single', 200.00);

-- We don't need to list all the column names if the set of values is complete. 
INSERT INTO actors 
VALUES (DEFAULT, 'Dream', 'Actress', '9999-01-01', 'Female', 'Single', 000.00);

-- Insert these as well to give some extra rows to work with 
INSERT INTO actors 
VALUES (DEFAULT, 'Oleg', 'Yankovsky', '1944-02-23', 'Male', 'Married', 1),
(DEFAULT, 'Domiziana', 'Giordano', '1959-11-04', 'Female', 'Unknown', 2),
(DEFAULT, 'Henri', 'Attal', '1936-01-01', 'Male', 'Unknown', 0);


-- Display again
\d actors;

-- Query the table 
\echo 'SELECT * FROM actors'
SELECT * FROM actors;

SELECT first_name, second_name FROM actors;

SELECT first_name, second_name FROM actors WHERE first_name = 'Travolta'; -- expect no output
SELECT first_name. second_name FROM actors WHERE first_name = 'Brad';
SELECT first_name, second_name FROM actors WHERE net_worth_millions > 500; -- no actor is worth this much...
SELECT first_name, second_name FROM actors WHERE net_worth_millions > 1;


-- LIKE operator 
\echo '[SELECT * FROM actors WHERE first_name LIKE Jen%]'
SELECT * FROM actors WHERE first_name LIKE 'Jen%';      -- '%' is wildcard operator
\echo '[SELECT * FROM actors WHERE first_name LIKE %]'
SELECT * FROM actors WHERE first_name LIKE '%';
\echo '[SELECT first_name, second_name FROM actors WHERE first_name LIKE _enn%]'
SELECT first_name, second_name FROM actors WHERE first_name LIKE '_enn%';


-- Can we show databases in postgres this way?
-- SHOW DATABASES LIKE 'a%';
-- But we can query the pg_database catalog for a database name 
SELECT datname FROM pg_database;

-- This (below) doesn't work
-- SELECT datname FROM pg_database LIKE '%tors';
-- But this (below) does
SELECT datname FROM pg_database WHERE datname LIKE '%tors';


-- Multi-Conditional select 
SELECT * FROM actors WHERE first_name > 'B' AND net_worth_millions > 200;
SELECT * FROM actors WHERE first_name > 'B' AND net_worth_millions > 0;
SELECT * FROM actors WHERE first_name > 'D' AND net_worth_millions > 0;


\echo 'net worth = 200' 
SELECT first_name, second_name FROM actors WHERE net_worth_millions = 200;
\echo 'net worth != 200' 
SELECT first_name, second_name FROM actors WHERE NOT net_worth_millions = 200;

-- MySQL has an XOR keyword, but Postgres does not. This means we can't do
-- SELECT first_name, second_name FROM actors WHERE first_name > 'B' XOR net_worth_millions > 200;
-- And instead have to do
SELECT first_name, second_name, dob FROM actors WHERE 
    (first_name > 'B' AND NOT net_worth_millions > 200) OR 
    (NOT first_name > 'B' AND net_worth_millions > 200);

-- ORDER BY
SELECT first_name, second_name FROM actors ORDER BY first_name;
SELECT first_name, second_name FROM actors ORDER BY second_name DESC;
\echo 'first_name, second_name, ordered by net worth (descending)'
SELECT first_name, second_name FROM actors ORDER BY net_worth_millions DESC;

-- Does Postgres have the BINARY keyword? (no)
--SELECT first_name, dob FROM actors ORDER BY BINARY first_name;

-- Can order by multiple columns
SELECT * FROM actors ORDER BY first_name ASC, net_worth_millions DESC;


-- LIMIT
\echo 'Selecting with limit in increasing order (2, 3, 4)'
SELECT first_name, second_name FROM actors ORDER BY net_worth_millions DESC LIMIT 2;
SELECT first_name, second_name FROM actors ORDER BY net_worth_millions DESC LIMIT 3;
SELECT first_name, second_name FROM actors ORDER BY net_worth_millions DESC LIMIT 4;


\echo 'Limit with OFFSET'
SELECT first_name, second_name FROM actors ORDER BY net_worth_millions DESC LIMIT 2 OFFSET 4;
-- In MySQL, "LIMIT 2 OFFSET 4" is equivalent to LIMIT 2,4
-- But this is not the case in Postgres
-- SELECT first_name, second_name FROM actors ORDER BY net_worth_millions DESC LIMIT 2,4;

-- DELETING DATA 
DELETE FROM actors WHERE first_name = 'priyanka';       -- has no effect
DELETE FROM actors WHERE gender = 'Male';       -- how could Biden do this?
\echo 'Table after delete'
SELECT first_name, second_name, gender FROM actors;
-- This next query deletes the 3 most valuable remaining actors
-- NOTE: you can do the below query in SQL but not in Postgres
-- DELETE FROM actors ORDER BY net_worth_millions DESC LIMIT 3; 
-- Instead we need to do something like 
DELETE FROM actors WHERE id IN (SELECT id FROM actors DESC LIMIT 3);    -- NOTE: error here...
\echo 'Table after compound delete'
SELECT first_name, second_name, gender FROM actors;
