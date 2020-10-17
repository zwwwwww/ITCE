# ITCE - C/C++ oriented  test case
***
ITCE  is a C / C + + program oriented test case suite developed by us on the basis of the original ITC. In this test suite, we divide the cases into positive and negative. In the positive micro programs, defects are injected, and the negative cases are correct code. ITCE contains 1964 microprograms, including 982 positive test cases and 982 negative test cases. It covers 19 defect types and 123 defect subtypes. Therefore, ITCE provides a solid test foundation for evaluating static analysis tools, and can also be used for vulnerability mining in the future.
***
## 1-19-1
***
Folder 1-19-1 contains 982 positive test cases. In other words, the C / C + + programs in 1-19-1 are all injected with defects. When static analysis tool tests 1-19-1, corresponding warning should be reported.

- **Example:**
  >void dynamic_buffer_overrun_002 ()
{  
 short*buf=(short*)calloc(5,sizeof(short));
     if(buf!=NULL)
	 {
	    *(buf+5)=1;/*ERROR: Buffer overrun*/
	  free(buf);
    }
}

***
## 1-19-0
***
Folder 1-19-0 contains 982 negative test cases. In other words, the C / C + + programs in 1-19-0 are correct. When static analysis tool tests 1-19-0, warning should not be reported. If a warning is issued, it will be considered as a false positive.
- **Example:**
  >void dynamic_buffer_overrun_002 ()
{
  short*buf=(short*)calloc(5,sizeof(short));
  if(buf!=NULL)
  {
	*(buf+4)=1;/*NO ERROR: Buffer overrun*/
	free(buf);
  }
}
***

