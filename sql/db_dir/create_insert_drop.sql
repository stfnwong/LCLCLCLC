-- This is from "Database Design Fundamentals for Software Engineers" on educative.io
-- Init the DB here each time
\echo 'Deleting and recreating [sample_db] database'
DROP DATABASE sample_db;
CREATE DATABASE sample_db;
\connect sample_db;


-- Note that in postgres there is no USE statement (use \c instead)
CREATE TABLE customers (
    id INT NOT NULL,
    name VARCHAR(20) NOT NULL,
    age INT NOT NULL,
    address CHAR(128),
    salary DECIMAL(18, 2),  -- what an odd field to have in a table of customers...
    PRIMARY KEY(id)
);

-- Note that in Postgres there is no DESC statement (use \d instead)
\d customers;

-- Now insert some values into the table
-- This is the most vanilla shit possible to put in a table like this, but whatever
-- its just an example.
INSERT INTO customers (id, name, age, address, salary)
VALUES (1, 'Mark', 32, 'Texas', 50000.00);

-- Note here that we are manually incrementing the id which I assume is not something
-- we ever care to do by hand in general. It also turns out we can omit the columns in
-- the case where we are inserting values for every column in the table. 
INSERT INTO customers (id, name, age, address, salary)
VALUES (2, 'John', 25, 'NY', 65000,00);
-- Its also a bit weird that the course is written by Indians but they still try to
-- genericize the input but making them all American.
INSERT INTO customers (id, name, age, address, salary)
VALUES (3, 'Emily', 23, 'Ohio', 20000.00);

INSERT INTO customers (id, name, age, address, salary)
VALUES (4, 'Bill', 25, 'Chicago', 75000.00);

INSERT INTO customers (id, name, age, address, salary)
VALUES (5, 'Tom', 27, 'Washington', 35000.00);

INSERT INTO customers (id, name, age, address, salary)
VALUES (6, 'Jane', 22, 'Texas', 45000.00);
