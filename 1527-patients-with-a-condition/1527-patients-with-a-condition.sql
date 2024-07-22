# Write your MySQL query statement below
# LIKE '% DIAB1%' : Kindly note that there is a space after wildcard '%' which takes care of the 'DIAB1' string that occurs in the 'ACNE DIAB100 ' string as there is a space prior to the DIAB100
# The' conditions like 'DIAB1%'' takes care of the string "DIAB100 MYOP" as it looks for values starting with 'DIAB1'

select * from Patients
where conditions like '% DIAB1%' or conditions like 'DIAB1%';