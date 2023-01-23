-- Stuff from "SQL: Beginner to Advanced" on educative.io
-- That course does everything in MySQL, so some adjustments are needed to get it to 
-- run on Postgres

\echo 'Deleting and recreating [sample_db] database'
DROP DATABASE sample_db;
CREATE DATABASE sample_db;
\connect sample_db;

-- I understand that SERIAL is the Postgres equivalent of AUTO_INCREMENT on MySQL
-- In Postgres it looks like we don't have the ENUM keyword. Instead we create a new 
-- type using the CREATE TYPE name AS ENUM and then use that type in the CREATE TABLE
-- section.

CREATE TYPE GENDER AS ENUM ('Male', 'Female', 'Other');
CREATE TYPE MARTIAL_STATUS AS ENUM ('Married', 'Divorced', 'Single', 'Unknown');

CREATE TABLE IF NOT EXISTS actors (
    id IN SERIAL,
    first_name VARCHAR(20) NOT NULL,
    second_name VARCHAR(2) NOT NULL,
    dob DATE NOT NULL,
    gender GENDER NOT NULL,
    marital_status MARITAL_STATS DEFAULT "Unknown",
    net_worth_millions DECIMAL NOT NULL,
    PRIMARY KEY(id)
);

-- Show something in the shell
\d actors;

-- Insert some data 
INSERT INTO actors (first_name, second_name, dob, gender, martial_status, net_worth_millions)
VALUES ('Brad', 'Pitt', '1963-12-18', 'Male', 'Single', 240.00);


-- In MySQL its possible to have multple VALUES statements together 
INSERT INTO actors (first_name, second_name, dob, gender, martial_status, net_worth_millions)
VALUES ('Jennifer', 'Aniston', '1969-11-02', 'Female', 'Single', 240.00),
VALUES ('Angelina', 'Jolie', '1975-06-4', 'Female', 'Single', 100.00),
VALUES ('Johnny', 'Depp', '1963-06-09', 'Male', 'Single', 200.0),

-- We don't need to list all the column names if the set of values is complete. 
INSERT INTO actors 
VALUES (DEFAULT, 'Dream', 'Actress', '9999-01-01', 'Female', 'Single', 000.00);
