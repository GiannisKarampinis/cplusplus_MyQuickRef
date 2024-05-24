#include <iostream>
using namespace std;

template<typename T, int N>
class Array {
    private:
        T m_Array[N];
    public:
        int GetSize() const { return N; }
};

int main()
{
    Array<int, 5> array;

    std::cout << array.GetSize() << std::endl;
}