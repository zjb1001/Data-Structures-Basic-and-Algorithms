#include <iostream>
#include <vector>
#include <map>

class Solution
{
    public:
        std::vector<int> twoSum( std::vector<int> nums, int target )
        {
            std::vector<int> ans;

            std::map<int, int> dictD;
            int i = 0;
            for ( const auto&mem : nums ) 
                if ( dictD.find(mem) == dictD.end() )
                    dictD[mem] = i++;

            for ( int i = 0; i < nums.size(); i++ )
            {
                auto it = dictD.find( target - nums[i] );
                if ( it != dictD.end() )
                {
                    ans.push_back(i); ans.push_back( it->second );
                    break;
                }

                if ( !ans.empty() ) break;
            }

            return ans;
        }
};

int main( int argc, char **argv )
{
    std::vector<int> nums {1, 2, 3, 4, 5};
    std::vector<int> ids  {1, 2, 3, 4, 4};

    // std::map<int, int> dictN;
    // std::map<int, int> dictD;

    // for ( int i = 0; i < nums.size(); i++ )
    //     dictN[nums[i]] = i;
    
    // for ( int i = 0; i < ids.size(); i++ )
    //     dictD[ids[i]] = i;

    // for ( const auto&mem : dictN )
    //     std::cout << "key= " << mem.first << ":" << mem.second << std::endl;

    // for ( const auto&mem : dictD )
    //     std::cout << "key= " << mem.first << ":" << mem.second << std::endl;

    Solution findPair;

    std::vector<std::vector<int>> testArr { nums, ids };
    for ( const auto&mem : testArr )
    {
        std::vector<int> ans = findPair.twoSum( mem, 6 );
        for ( const auto&item : ans )
            std::cout << item << " ";
        std::cout << std::endl;
    }
    
    return 0;
}