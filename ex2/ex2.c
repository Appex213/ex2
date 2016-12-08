/******************************************
* Matan Ben Moshe
* 208583070
* 83-120-04
* ex2
******************************************/

#include <stdio.h>
#include <math.h>

/*------------------------------------------------------Github Commit v0.56-------------------------------------------------------------*/

/*************************************************************************
Function name: Main
Input: Number (1,2,3,4,-1)
Output: Called function according to input.
The function operation: Recieves number and calls the correct function (or quits) according to user input.
************************************************************************/

int main()
{
	int userChoice;


	do
	{
		printf("Choose 1 for triangle, 2 for ID, 3 for carpets, 4 for equation, -1 for exit\n");
		scanf("%d", &userChoice);
		switch (userChoice)
		{
		case 1:
			Triangle();
			break;
		case 2:
			ID();
			break;
		case 3:
			Carpets();
			break;
		case 4:
			Equation();
			break;
		case -1:
			break;
		default:
			printf("No such option!\n");


		}
	} while (userChoice != -1);



	return 0;
}



/*************************************************************************
Function name: Triangle
Input: Left and right borders.
Output: All triangular numbers within bordered area.
The function operation: Calculates all triangular numbers up to upper limit, prints only numbers within requested area.
************************************************************************/

Triangle()
{
	int limitR;
	int limitL;
	int doesExist = 0;
	int triNum = 0;
	int i;
	int doReturn;

	do
	{
		doReturn = 0;
		printf("Enter 2 numbers (left and right):\n");
		scanf("%d", &limitL);
		scanf("%d", &limitR);
		if (limitR >= limitL)
		{
			for (i = 1; triNum <= limitR; i++)
			{
				triNum = i*i + i;
				triNum = triNum / 2;
				if (triNum >= limitL&&triNum <= limitR)
				{
					printf("%d\n", triNum);
					doesExist = 1;
				}
			}
		}
		else
		{
			printf("Error input!\n");
			doesExist = 1;
			//	doReturn = 1;																					<<<<<<doReturn
		}
		if (doesExist == 0)
		{
			printf("None\n");
		}
	} while (doReturn != 0);

	return;
}

/*************************************************************************
Function name: ID
Input: ID number (9 digits)
Output: Valid\Invalid ID number
The function operation: Recieves ID number, adds all odd place numbers to sum. Doubles, separetes and sums all even place numbers, adds to sum. If number % 10 = 0 --> ID is valid.
************************************************************************/

ID()
{

	int n = 1;
	int i = 1;
	int temp, temp1, temp2;
	int sum = 0;
	unsigned long int idNum;
	scanf("%d", &idNum);
	while (n <= 9)
	{
		switch (i)
		{
		case 0:
			temp = idNum % 10;
			temp = temp * 2;
			temp2 = temp % 10;
			temp1 = temp / 10;
			temp = temp1 + temp2;
			sum = sum + temp;
			idNum = idNum / 10;
			n++;
			i = 1;
			break;
		case 1:
			temp = idNum % 10;
			sum = sum + temp;
			idNum = idNum / 10;
			n++;
			i = 0;
			break;
		default:
			printf("How did this even happened?");
			break;
		}
	}

	if (sum % 10 == 0)
		printf("Valid ID number\n");
	else
		printf("Invalid ID number\n");

	return;
}

/*************************************************************************
Function name: Carpets
Input: Width 1 , width 2.
Output: Different designs of "carpets", size according to width.
The function operation: Prints a specific pattern in size according to provided width. 3 carpets total.
************************************************************************/

Carpets()
{
	int w, j, i, o, x, n;
	int doReturn;
	do
	{
	doReturn = 0;
	// First and second carpets
	scanf("%d", &w);
	/*__________________________________________________

	-----------------First carpet loop------------------
	____________________________________________________*/
	if (w >= 2 && w <= 10)
	{
		for (j = 1;j <= w;j++)
		{
			if (j % 2 == 0)
			{
				for (i = 1;i <= w;i++)
				{
					if (i % 2 != 0)
						printf("O");
					else
						printf("X");
				}
			}
			else
			{
				for (i = 1;i <= w;i++)
				{
					if (i % 2 == 0)
						printf("O");
					else
						printf("X");
				}
			}
			printf("\n");
		}
		/*__________________________________________________

		-----------------Second carpet loop------------------
		____________________________________________________*/
		n = 0;
		for (j = 0;j <= w + 1;j++)
		{
			for (o = 1;o < n;o++)
				printf("O");
			if (n != 0)
				for (x = w + 1;x > n;x--)
					printf("X");

			printf("\n");
			n++;
		}
	}
	else
	{
		printf("Error input!\n");
	//	doReturn = 1;																					<<<<<<doReturn
	}
	/*__________________________________________________

	-----------------Third carpet loop------------------
	____________________________________________________*/
	if (w >= 2 && w <= 10 && w % 2 == 0)
	{
		printf("\n");
		j, n, i = 0;
		for (j = 1;j <= w / 2;j++)
		{
			for (i = 1;i <= w / 2;i++)
				printf("X");
			for (i = w;i > w / 2;i--)
				printf("O");
			printf("\n");
		}
		for (j = w;j > (w / 2);j--)
		{
			for (i = 1;i <= w / 2;i++)
				printf("O");
			for (i = w;i > w / 2;i--)
				printf("X");
			printf("\n");
		}
	}
	} while (doReturn != 0);

	return;
}

/*************************************************************************
Function name: Equation.
Input: 3 numbers.
Output: Equation + solution.
The function operation: Recieves 3 numbers. Prints correct equation according to numbers. Then calculates square roots of the equation and prints them.
************************************************************************/

Equation()
{
	float a, b, c;
	float determinant;
	float root1, root2, reX, imX;

	printf("Enter three numbers:\n");
	scanf("%f %f %f", &a, &b, &c);

	// Equation print code
	if (a == 0 && b == 0 && c == 0)
	{
		printf("0 = 0\n");
		printf("Infinite solutions!\n");
	}
	else if (a == 0 && b == 0 && c != 0)
	{
		printf("%.0f = 0\n", c);
		printf("No solution!\n");
	}
	else if (a == 0 && b != 0 && c == 0)
	{
		printf("x = 0\n");
		printf("x1 = %.2f\n");
	}
	else if (a != 0 && b == 0 && c == 0)
	{
		printf("x1 = 0\n");
	}
	else
	{
		// a*x^2
		if (a == 0)
		{}
		else if (a == 1)
			printf("x^2");
		else if (a == -1)
			printf("-x^2");
		else
			printf("%.0fx^2", a);
		if (a==0)
		{ }
		else if (b >= 1)
			printf("+");
		// b*x
		if (b == 0)
		{}
		else if (b == 1)
			printf("x");
		else if (b == -1)
			printf("-x");
		else
			printf("%.0fx", b);
		// c
		if (c == 0)
		{}
		else if (c > 0)
			printf("+%.0f", c);
		else
			printf("%.0f", c);
		

		printf(" = 0\n");

		// Roots calculation code

		determinant = b*b - 4 * a*c;
		if (a == 0)
		{
			root1 = -c / b;
			printf("x1 = %.2f\n", root1);
		}
		else if (determinant > 0)
			{
				root1 = (-b + sqrt(determinant)) / (2 * a);
				root2 = (-b - sqrt(determinant)) / (2 * a);
				//Display 0 as 0.00 not -0.00
				if (root1 == 0)
					root1 = 0;
				if (root2 == 0)
					root2 = 0;
				if (root1 < root2)
				{
					printf("x1 = %.2f\n", root1);
					printf("x2 = %.2f\n", root2);
				}
				else
				{
					printf("x1 = %.2f\n", root2);
					printf("x2 = %.2f\n", root1);

				}
			}
			else if (determinant == 0)
			{
				root1 = root2 = -b / (2 * a);
				printf("x1 = %.2f\n", root1);
			}
			else
			{
				reX = -b / (2 * a);
				imX = sqrt(-determinant) / (2 * a);
				if (reX != 0)
				{
					printf("x1 = %.2f - %.2fi\n", reX, imX);
					printf("x2 = %.2f + %.2fi\n", reX, imX);
				}
				else if (imX<0)
				{
					printf("x1 = -%.2fi\n", -imX);
					printf("x2 = %.2fi\n", -imX);
				}
				else
				{
					printf("x1 = -%.2fi\n", imX);
					printf("x2 = %.2fi\n", imX);
				}
			}
		}
	

	return;
}