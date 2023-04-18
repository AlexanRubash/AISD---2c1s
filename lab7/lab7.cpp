#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

int main()
{
	srand(time(NULL));

	size_t length;
	cout << "Enter the number of sequence numbers: "; cin >> length;

	vector<size_t> sequence;
	vector<size_t> passedElements;
	vector<size_t> indexes(1);

	size_t number;

	//sequence.push_back(rand() % 100);
	//cout << sequence[0] << "\t";
	/*for (size_t i = 1; i < length; i++)
	{
		for (;;)
		{
			number = rand() % 100;
			if (number <= sequence[0]) continue;
			sequence.push_back(number);
			break;
		}

		cout << sequence[i] << "\t";
	}*/

	for (size_t i = 0; i < length; i++)
	{
		cin >> number;

		sequence.push_back(number);
	}

	indexes[0] = 1;
	size_t max = sequence[0];

	for (size_t a = 1; a < sequence.size(); a++)
	{
		if (max > sequence[a])
		{
			size_t index = 0;

			for (size_t b = 0; b < passedElements.size(); b++)
			{
				if (passedElements[b] < sequence[a])
				{
					size_t temp = distance(sequence.begin(), find(sequence.begin(), sequence.end(), passedElements[b]));

					if (index >= (indexes[temp] + 1)) continue;

					index = indexes[temp] + 1;
					continue;
				}

				if (passedElements[b] == sequence[a])
				{
					size_t temp = distance(sequence.begin(), find(sequence.begin(), sequence.end(), passedElements[b]));

					if (index <= indexes[temp])
						index = indexes[temp];
					break;
				}
			}

			if (index == *max_element(indexes.begin(), indexes.end())) index = index - 1;

			passedElements.push_back(sequence[a]);

			indexes.push_back(index);
		}

		else if (max < sequence[a])
		{

			indexes.push_back((*max_element(indexes.begin(), indexes.end())) + 1);

			passedElements.push_back(max);

			max = sequence[a];
		}

		else if (max == sequence[a])
		{
			passedElements.push_back(sequence[a]);

			indexes.push_back(*max_element(indexes.begin(), indexes.end()));
		}
	}

	cout << endl;
	for (size_t i = 0; i < indexes.size(); i++)
	{
		cout << indexes[i] << "\t";
	}
	cout << endl;

	cout << "Length of largest increasing subsequence: " << *max_element(indexes.begin(), indexes.end()) << endl;

	vector<pair<size_t, size_t>> buf3;

	for (size_t i = 0; i < sequence.size(); i++)
	{
		buf3.emplace_back(indexes[i], sequence[i]);
	}

	cout << "Largest increasing subsequence: ";

	auto endPoiner = buf3.rbegin();
	auto maxElement = *max_element(indexes.begin(), indexes.end());



	struct compareFirst
	{
		compareFirst(char size_t)
		{
			_symbol = size_t;
		}

		bool operator() (pair<size_t, size_t> const& p)
		{
			return (p.first == _symbol);
		}

		char _symbol;
	};

	list<size_t> list;
	for (size_t i = 0; i < maxElement; i++)
	{
		endPoiner = find_if(endPoiner, buf3.rend(), compareFirst(maxElement - i));

		list.push_front((*endPoiner).second);
	}

	for (auto i = list.begin(); i != list.end(); i++)
	{
		cout << *i << " ";
	}

	cout << endl << endl;
}