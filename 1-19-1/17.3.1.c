/*
From:ITC
17
Sharing defects
17.3
Read-only storage
17.3.1
Read-only string literal storage used as initial value for unqualified storage
*/
# ifndef EXPOSED_TYPE_gender
typedef enum { MALE, FEMALE, gender_ANY } gender;
# endif

# ifndef EXPOSED_TYPE_job
typedef enum { MGR, NONMGR, job_ANY } job;
# endif
void read_only_storage_001() {
	static char* gender[] = { "male", "female", "?" };/*Tool should detect this line as error*/ /*ERROR: Sharing error*/
	static char* jobs[] = { "manager", "non-manager", "?" };/*Tool should detect this line as error*/ /*ERROR: Sharing error*/
}
