/*
From:ITC
17
Sharing defects
17.1
Unique parameters
17.1.1
sharing unique parameter
*/

# ifndef EXPOSED_TYPE_gender
typedef enum { MALE, FEMALE, gender_ANY } gender;
# endif


# ifndef EXPOSED_TYPE_job
typedef enum { MGR, NONMGR, job_ANY } job;
# endif

# define maxEmployeeName (20)
# ifndef EXPOSED_TYPE_employee
typedef struct {
    int ssNum;
    char name[maxEmployeeName];
    int salary;
    gender gen;
    job j;
} employee;
# endif

bool employee_setName(employee* e, char na[])
{
    size_t i;

    for (i = 0; na[i] != '\0'; i++)
    {
        if (i == maxEmployeeName) return false;
    }
    strcpy(e->name, na);/*Tool should detect this line as error*/ /*ERROR: Sharing error*/
    return true;
}

void unique_parameter_001() {
    employee e;
    e.ssNum = 45;
    //e.name[maxEmployeeName] = ""zhangsan"";
    e.salary = 100000;
    e.gen = "MALE";
    e.j = "MGR";
    char na[] = "wangwu";
    employee_setName(&e, na);
}

