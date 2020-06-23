#include <iostream>
#include <vector>
#include <map>

class Solution {
  public:
    std::vector<int> jointSet(std::vector<int> &Va, std::vector<int> &Vb) {
        std::vector<int> res;

        const int szA = Va.size(); 
        const int szB = Vb.size();
        int sz = 0;
        for (int i = 0, j = 0; i < szA || j < szB; ) {
            bool bothExist = i < szA && j < szB;

            if (bothExist && Va[i] <= Vb[j]) {
                res.push_back( Va[i] );
                i++;
            }
            else if (bothExist && Va[i] > Vb[j]) {
                res.push_back( Vb[j] );
                j++;
            }
            else if (i < szA) {
                res.push_back( Va[i] );
                i++;
            }
            else {
                res.push_back( Vb[j] );
                j++;
            }

            sz++;
            if ( sz == (szA + szB + 1) / 2 ) 
                break;
        }

        return res;
    }
};

int main()
{
    int size, tmp;
    std::cin >> size;

    std::vector<int> va(size, 0), vb(size, 0);
    for (int i = 0; i < size; i++) {
        std::cin >> va[i];
    }

    for (int i = 0; i < size; i++) 
        std::cin >> vb[i];

    Solution solve;
    std::cout << solve.jointSet(va, vb).back() << "\n";

    return 0;
}