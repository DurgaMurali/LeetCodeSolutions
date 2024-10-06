class Solution {
public:
    void find_closest_power(int n, int &min_operations)
    {
        int x = 1;
        int pows = 0;
        //std::cout << "n = " << n << std::endl;
        while(x < n)
        {
            x *= 2;
            pows++;
        }

        if(x == n)
        {
            min_operations += 1;
            //std::cout << x << " == " << n << std::endl;
        }
        else
        {
            int remaining = x - n;
            //std::cout << "remaining = " << remaining << std::endl;
            int min_operations_1 = 1;
            find_closest_power(remaining, min_operations_1);
            //std::cout << "min_operations_1 = " << min_operations_1 << std::endl;

            remaining = n - (x/2);
            //std::cout << "remaining = " << remaining << std::endl;
            int min_operations_2 = 1;
            find_closest_power(remaining, min_operations_2);
            //std::cout << "min_operations_2 = " << min_operations_2 << std::endl;

            min_operations += (min_operations_1 < min_operations_2) ? min_operations_1 : min_operations_2;
        }
    }

    int minOperations(int n) {
        int min_operations = 0;
        find_closest_power(n, min_operations);

        return min_operations;
    }
};