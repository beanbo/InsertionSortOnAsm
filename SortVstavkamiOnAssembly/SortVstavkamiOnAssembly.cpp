#include <iostream>

int main()
{
	int massAsm[10], massC[10];

	int temp;
	for (int counter = 0; counter < 10; counter++) // input numbers
	{
		std::cout << "Enter mass[" << counter << "]: ";
		std::cin >> temp;

		massAsm[counter] = temp;
		massC[counter] = temp;
	}

	system("cls"); // clear console

	int begA, endA, begC, endC;
	// Assembly selection sort
	__asm
	{
		rdtsc  // instruction for calculate number of processor cycles in "eax"
		mov begA, eax  // begA = eax(result of instruction)

		mov ecx, 0		// ecx = 0 <= used for main cycle
		
		MainCycle:
			mov edx, ecx	// edx = ecx <= used for minimum
			mov edi, ecx	// edi = ecx <= used for cycle

			Cycle:
				// if (massAsm[edx*4] > massAsm[edi*4]) edx = edi
				mov eax, massAsm[edi*4]
				cmp eax, massAsm[edx*4]
				jg endStatement
					mov edx, edi	// edx = edi
				endStatement:

				inc edi			// edi++
				cmp edi, 10		// if (edi != 10) 
				jl Cycle		// goto Cycle;
				
				
			// swap values
			mov eax, massAsm[ecx*4]
			mov ebx, massAsm[edx*4]
			mov massAsm[ecx*4], ebx
			mov massAsm[edx*4], eax

			inc ecx			// ecx++
			cmp ecx, 10		// if (ecx != 10) 
			jl MainCycle	// goto MainCycle;
					
		rdtsc  // instruction for calculate number of processor cycles in "eax"
		mov endA, eax  // endA = eax(result of instruction)
					
		rdtsc  // instruction for calculate number of processor cycles in "eax"
		mov begC, eax  // endA = eax(result of instruction)
	}

	// C selection sort
	for (int mainCounter = 0; mainCounter < 10; mainCounter++)
	{
		int min = mainCounter;
		for (int counter = mainCounter; counter < 10; counter++)
		{
			if (massC[min] > massC[counter])
				min = counter;
		}
		std::swap(massC[mainCounter], massC[min]);
	}
	
	__asm
	{
		rdtsc  // instruction for calculate number of processor cycles in "eax"
		mov endC, eax  // endA = eax(result of instruction)
	}

	for (int counter = 0; counter < 10; counter++) // show mass
	{
		std::cout << "MassAsm[" << counter << "]: " << massAsm[counter]
			<< "\t\tMassC[" << counter << "]: " << massC[counter] << std::endl;
	}

	std::cout << "\nNumber of processor cycles for asm: " << endA - begA;
	std::cout << "\nNumber of processor cycles for C:   " << endC - begC;
}
