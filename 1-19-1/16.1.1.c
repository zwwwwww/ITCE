/*
From:ITC
16
Macros defects
16.1
Constant macros
16.1.1
Constant not defined
*/

#define PI           /*Tool should detect this line as error*/ /*ERROR:Macros error*/       
float constant_macros_001() {
	float r;
	printf(" ‰»Î‘≤µƒ∞Îæ∂£∫");
	scanf("%f", &r);
	float area;
	area = PI * r * r;

}

