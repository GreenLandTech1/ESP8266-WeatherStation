-- Select and Delete a Database weather_station in MySql if exist
DROP DATABASE IF EXISTS weather_station;

-- Creating and Selecting a Database weather_station in MySql
CREATE DATABASE weather_station;

-- Select and Delete a Table Notifications in MySql if exist
DROP TABLE IF EXISTS Notifications;

-- Creating and Selecting a Table Notifications in MySql
CREATE TABLE Notifications (
id INT(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY,
Temperature VARCHAR(30) NOT NULL,
Humidity VARCHAR(30) NOT NULL,
Light_Intensity VARCHAR(30) NOT NULL,
bmp_temperature VARCHAR(30) NOT NULL,
Pressure VARCHAR(30) NOT NULL,
Altitude VARCHAR(30) NOT NULL,
reg_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP
);
