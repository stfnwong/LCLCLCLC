# SQL
This is a staging area where I can play with SQL. For the SQL engine I will use the
`bitnami/postgresql:15` docker image to run stuff.  

Some of the contents are taken from `SQLZoo`, others from `educative.io`, some from 
other places.


## Data sources 
I use data sources from wherever. 


#### HadCET UK mean temperature data
This is taken from [here](https://www.metoffice.gov.uk/hadobs/hadcet/data/download.html).
The daily mean temperature data can be accessed from [this](https://www.metoffice.gov.uk/hadobs/hadcet/data/meantemp_daily_totals.txt) direct link.
There is a `python` script to transform the data into a Pandas `DataFrame`.
