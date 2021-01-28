#include <iostream>

const unsigned short int ARR_SIZE = 6;
int arr[ARR_SIZE][ARR_SIZE];

void swap_arr(int*);

void SpiralFilling();

void SnakeFilling();

void OutArr();

void swap_first_four_block(int*);

void swap_second_third_block(int*);

void change_block_var_b();

void multi_2();

void sort_arr();

using namespace std;

void main(){
	setlocale(LC_ALL, "rus");
	cout << "1 - Заполнить массив спиралью.\n2 - Заполнить массив змейкой.";
	cout << "\n3 - Поменять блоки по варианту Б.\n4 - Сортировать массив.\n5 - Умножить на 2." << endl;
	int change;
	do
	{
	  cin >> change;
	  if (change == 1 || change == 2 || change == 3 || change == 4 || change == 5 )
	  {
		  switch (change)
		  {
		  case 1:
			  SpiralFilling();
			  OutArr();
			  break;
		  case 2:
			  SnakeFilling();
			  OutArr();
			  break;
		  case 3:
			  change_block_var_b();
			  OutArr();
			  break;
		  case 4:
			  sort_arr();
			  OutArr();
			  break;
		  case 5:
			  multi_2();
			  OutArr();
			  break;
		  default:
			  break;
		  }
	  }
	  else
	  {
		  break;
	  }
	 
	} while (true);

	system("pause");
}

void change_block_var_b(){
	int* chelnok = arr[0];
	int count = 0;
	for (int i = 0; i < ARR_SIZE/2; ++i)
	{
		for (int j = 0; j < ARR_SIZE/2; ++j)
		{
			swap_first_four_block(chelnok);
			++chelnok;
		}
		for (int j = 0; j < ARR_SIZE/2; ++j)
		{
			swap_second_third_block(chelnok);
			++chelnok;
		}
	}
}

void swap_first_four_block(int* first){
	int temp = *first;
	int* second = first + (ARR_SIZE * (ARR_SIZE / 2)) + ARR_SIZE / 2 ;
	*first = *second;
	*second = temp;
}

void swap_second_third_block(int* first){
	int temp = *first;
	int* second = first + ( ( (ARR_SIZE/2) * ARR_SIZE ) + 1 ) - ( ARR_SIZE/2 +1 );
	*first = *second;
	*second = temp;
}

void OutArr(){
	
	for (int i = 0; i < ARR_SIZE; i++)
	{
		for (int j = 0; j < ARR_SIZE; j++)
		{
			cout.width(4);
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
}

void SpiralFilling(){
	int min = 0, max = ARR_SIZE, count = 0;

	int* arr_begin = arr[0];
	int* arr_end = arr_begin + ARR_SIZE*ARR_SIZE;
	int* chelnok = arr_begin;

	while (min != max)
	{
		for (; chelnok < arr_begin + min*ARR_SIZE + max; ++chelnok)
		{
			*chelnok = ++count;

		}


		--chelnok;
		chelnok += ARR_SIZE;

		for (; chelnok < (arr_begin + (ARR_SIZE*max)); chelnok += ARR_SIZE)
		{
			*chelnok = ++count;
		}

		chelnok -= ARR_SIZE;
		--chelnok;

		for (; chelnok >= arr_begin + ((max - 1) * ARR_SIZE) + min; chelnok = chelnok - 1)
		{
			*chelnok = ++count;
		}

		++min;
		--max;
		++chelnok;
		chelnok -= ARR_SIZE;

		for (; chelnok >= arr_begin + (min)*ARR_SIZE; chelnok -= ARR_SIZE)
		{
			*chelnok = ++count;
		}

		chelnok += ARR_SIZE;
		++chelnok;
	}
}

void SnakeFilling(){
	int* arr_begin = arr[0];
	int* chelnok = arr_begin;
	int count = 0;
	while (true)
	{
		for (int i = 0; i < ARR_SIZE; ++i)
		{
			
			*chelnok = ++count;
			chelnok = chelnok + ARR_SIZE;
		}
		++chelnok;
		chelnok -= ARR_SIZE;
		for (int i = 0; i < ARR_SIZE; ++i)
		{
			
			*chelnok = ++count;
			chelnok = chelnok - ARR_SIZE;
		}
		++chelnok;
		chelnok += ARR_SIZE;
		if (chelnok == arr_begin + ARR_SIZE){ break; }
	}
}

void swap_arr(int* value){
		int temp = *(value + 1);
		*(value + 1) = *value;
		*value = temp;
}

void sort_arr(){
	bool flag = true;
	while (flag)
	{
		flag = false;
		for (int* i = arr[0]; i < arr[0] + ARR_SIZE*ARR_SIZE -1; ++i)
		{
			if (*i > *(i + 1))
			{
				swap_arr(i);
				flag = true;
			}
		}
	}
}

void multi_2(){
	for (int* i = arr[0]; i < arr[0] + (ARR_SIZE*ARR_SIZE); ++i)
	{
		*i *= 2;
	}
}
