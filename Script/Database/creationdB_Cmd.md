# Creating user, database and adding access on PostgreSQL

## First way to create user, database and adding access on PostgreSQL*

### running on Ubuntu

```
sudo -u postgres psql
postgres=# create database weather_station;
postgres=# create user myuser with encrypted password 'root';
postgres=# grant all privileges on database weather_station to myuser;
```

or

## Second way to create user, database and adding access on PostgreSQL

### entire PostgreSQL instance running on your OS
```
$ sudo -u postgres psql
```

### Creating user
```
$ sudo -u postgres createuser myuser
```

### Creating Database
```
$ sudo -u postgres createdb weather_station
```

### Giving the user a password
```
$ sudo -u postgres psql
psql=# alter user myuser with encrypted password 'root';
```

### Granting privileges on database
```
psql=# grant all privileges on database weather_station to myuser ;
```

#### And yeah, that should be pretty much it !


### Script MySql to create table Notifications
```
"CREATE TABLE Notifications (
id INT(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY,
Temperature VARCHAR(30) NOT NULL,
Humidity VARCHAR(30) NOT NULL,
Light_Intensity VARCHAR(30) NOT NULL,
bmp_temperature VARCHAR(30) NOT NULL,
Pressure VARCHAR(30) NOT NULL,
Altitude VARCHAR(30) NOT NULL,
reg_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP
)";
```
