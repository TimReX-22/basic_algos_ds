#include <vector>

template<typename T>
class Sorting {
    public:
    Sorting() = delete;

    static void InsertionSort(std::vector<T>& array);
    static void MergeSort(std::vector<T>& array);

private:
[[nodiscard]] static std::vector<T> merge(std::vector<T> const& array_L, std::vector<T>const & array_R);
};
