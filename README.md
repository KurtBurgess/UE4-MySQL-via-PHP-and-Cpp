# UE4-MySQL-via-PHP-and-Cpp
Using C++ exposed to UE4's blueprints you can query a MySQL database via PHP and return data wrapped in JSON


1) Call the C++ code via blueprints
2) Pass as inputs the URL and parameter to query (in this example it's the userID)
3) The code will call a PHP script hosted locally to query the MySQL database for all entries with the userID
4) The PHP script then returns all data as a string wrapped in JSON
