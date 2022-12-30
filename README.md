# Structure-in-C
In this assignment you have to process some information related to employees working under certain
departments in a company. After processing you need to output some processed information related to the
departments.

### Here are the inputs:

• The first line of input M will contain of the no. of departments in the company. After that the M
following lines will contain information about a single department. Each line will contain a department
ID (integer), department name (string, will not contain spaces, maximum length 50) and manager ID
(integer), all separated by spaces.

• The (M + 2)th line of input N will denote the total no. of employees in the whole company. After that
the N following lines each will contain information about a single employee. Each line of input have
an employee ID (integer), department ID (integer), salary (double), and joining date (in the form of
DD-MM-YYYY, take necessary steps to process this form of date as input), all separated by spaces.
You can assume that the department ID of employees will be of one of the M departments given as input,
and the manager ID of the departments will be one of the N employee’s employee ID given as input. You
can also assume the manager of each department will be an employee of that department.

### And the outputs are:

• The department with the seniormost manager, that is, with the earliest joining date. You have to
output the department name, and the corresponding manager ID and his joining date (in the form of
DD-MM-YYYY) in first brackets.

• Each department’s information sorted by the average salary of all the employees in the department, in descending order.. You have to find the average salary of all the employees in each of the M departments. Then you have to output M lines, one for each of the department. Each line will contain the department ID, department name, average salary of all the employees in that department, and the no. of employees in that department.

Additionally, you must create structures departmentInfo and employeeInfo to contain information about the departments and employees respectively. departmentInfo structure must contain department ID (integer) , department name (string) and manager ID (integer). employeeInfo structure must contain employee ID (integer), department ID (integer, the department in which the employee belongs to)
and salary (double). You can add additional fields to the structures as you need to do your assignment.
