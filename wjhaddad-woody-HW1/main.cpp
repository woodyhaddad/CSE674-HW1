
#include "singleList.h"
#include "doubleList.h"


int main() {

	singleList S1_single;
	singleList S2_single;
	doubleList S1_double;
	doubleList S2_double;
	singleList S2_single2;
	doubleList S2_double2;

	for (int i = 1; i <= 100; i++)											// Create linked lists
	{
		S1_single.add_node(i);
		S1_double.add_node(i);
		if (i%2 == 0)
		{
			S2_single.add_node(-8*i);
			S2_double.add_node(-8 * i);
			S2_single2.add_node(-8 * i);
			S2_double2.add_node(-8 * i);
		}
		else
		{
			S2_single.add_node(3*i);
			S2_double.add_node(3 * i);
			S2_single2.add_node(3 * i);
			S2_double2.add_node(3 * i);

		}
	}


	//printf("address of S1 single is %d, address of S1 single dup is %d \n", S1_single, S1_singledup);

	cout << "\n\n ************Test Case 0: Initial lists************ \n\n" << endl;


	cout << "\n\n S1_single" << endl;
	S1_single.transverse();

	cout << "\n\n S2_single" << endl;
	S2_single.transverse();

	cout << "\n\n S1_double" << endl;
	S1_double.transverse();
	cout << "\n\n S1_double backwards" << endl;
	S1_double.reverseTransverse();

	cout << "\n\n S2_double" << endl;
	S2_double.transverse();
	cout << "\n\n S2_double backwards" << endl;
	S2_double.reverseTransverse();



	cout << "\n\n S1_single teamOfFour" << endl;
	S1_single.teamOfFour(&S1_single);
	S1_single.transverse();


	cout << "\n\n S2_single" << endl;
	S2_single.transverse();

	cout << "\n\nTest Case 1: S2_single teamOfFour" << endl;
	
	cout << "S2_single before teamOfFour " << endl;
	S2_single.transverse();
	S2_single.teamOfFour(&S2_single);

	cout << "S2_single after teamOfFour " << endl;
	S2_single.transverse();

	cout << "\n\n ************Test Case 2: S2_double teamOfFour************ \n\n" << endl;
	S2_double.teamOfFour(&S2_double);
	cout << "\n\n S2_double" << endl;
	S2_double.transverse();
	cout << "\n\n S2_double backwards" << endl;
	S2_double.reverseTransverse();

	cout << "\n\n ************test case 3: s1_single reverse************ \n\n" << endl;
	S1_single.reverse(&S1_single);
	S1_single.transverse();
	S1_single.reverse(&S1_single);								// Reverse again to reset S1



	cout << "\n\n ************Test Case 4: S1_double reverse************ \n\n" << endl;
	S1_double.reverse(&S1_double);
	cout << "\n\n S1_double" << endl;
	S1_double.transverse();
	cout << "\n\n S1_double backwards" << endl;
	S1_double.reverseTransverse();
	S1_double.reverse(&S1_double);


	cout << "\n\n ************Test Case 5: S2_single reverse************ \n\n" << endl;
	S2_single2.reverse(&S2_single2);
	S2_single2.transverse();
	S2_single2.reverse(&S2_single2);



	cout << "\n\n ************Test Case 6: S2_double reverse************ \n\n" << endl;
	S2_double2.reverse(&S2_double2);
	cout << "\n\n S2_double" << endl;
	S2_double2.transverse();
	cout << "\n\n S2_double backwards" << endl;
	S2_double2.reverseTransverse();
	S2_double2.reverse(&S2_double2);


	cout << "\n\n ************Test Case 7: S1_single shuffle************ \n\n" << endl;
	S1_single.shuffle(&S1_single);
	S1_single.transverse();

	cout << "\n\n ************Test Case 8: S1_double shuffle************ \n\n" << endl;
	S1_double.shuffle(&S1_double);
	cout << "\n\n S1_double" << endl;
	S1_double.transverse();
	cout << "\n\n S1_double backwards" << endl;
	S1_double.reverseTransverse();

	cout << "\n\n ************Test Case 9: S2_single shuffle************ \n\n" << endl;
	S2_single2.shuffle(&S2_single);
	S2_single2.transverse();

	cout << "\n\n ************Test Case 10: S2_double shuffle************ \n\n" << endl;
	S2_double2.shuffle(&S2_double2);
	cout << "\n\n S2_double" << endl;
	S2_double2.transverse();
	cout << "\n\n S2_double backwards" << endl;
	S2_double2.reverseTransverse();

	return 0;
}