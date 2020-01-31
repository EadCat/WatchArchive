#include <iostream>
#include <vector>

using namespace std;

class vector_space {
private:
    unsigned int *space;
    unsigned int maximum;
    vector<unsigned int> answer;

public:
    vector_space(); // default constructor
    vector_space(unsigned int max_num); // constructor
    ~vector_space(); // destructor
    
    void sieve(unsigned int testnumber);
    void copier();
    void dyarray_printer();
    int dyarray_size();
};

int main()
{
    unsigned int target;
    
    cout << "This program is for searching prime number, using Eratosthenes's sieve algorithm" << endl;
    cout << "Input Number (Not negative) : ";
    cin >> target;

    cout << endl << "The target number is " << target << endl;

    if (target == 0 || target == 1) {
        cout << "Illegal input.\n";
    }
    else {
        vector_space list(target);
        for (unsigned int i = 2; i <= target; i++) {
            list.sieve(i);
        }
        list.copier();
        list.dyarray_printer();
        cout << "size : " << list.dyarray_size() << endl;
    }

    return 0;
}

vector_space::vector_space() {
    maximum = 1;
    space = new unsigned int[maximum];
    space[0] = 1;
}

vector_space::vector_space(unsigned int max_num) {
    maximum = max_num;
    space = new unsigned int[maximum];
    for (unsigned int i = 0; i < maximum; i++) {
        space[i] = i + 1;
    }
}

vector_space::~vector_space() {
    delete[] space;
}

void vector_space::sieve(unsigned int testnumber) {
    int i = 2;
    if (this->space[testnumber-1] == 0)
        return; // zero jump
    while (i * testnumber <= this->maximum) {
        space[i * testnumber - 1] = 0;
        i++;
    }
}

void vector_space::copier() {
    for (unsigned int i = 1; i < maximum; i++) {
        if (space[i] != 0) {
            answer.push_back(space[i]);
        }
    }
}

void vector_space::dyarray_printer() {
    unsigned int end = answer.size();
    for (unsigned int i = 0; i < end; i++) {
        cout << answer[i] << " ";
    }
    cout << endl;
}

int vector_space::dyarray_size() {
    return answer.size();
}