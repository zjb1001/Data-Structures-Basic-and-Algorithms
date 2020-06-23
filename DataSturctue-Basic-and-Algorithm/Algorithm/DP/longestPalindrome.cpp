#include <iostream>
#include <cstring>

using namespace std;

class Solution {
public:
    string longestPalindrome( string s ) 
    {
        const int N = s.size();
        if ( N <= 1 )
            return s;

        bool table[N][N];
        memset( table, false, sizeof(table) );

        // base [i][i]
        for ( int i = 0; i < N; i++ )
            table[i][i] = true;

        int maxlen = 1;
        int start  = 0;
        for ( int i = 0; i < N - 1; i++ )
        {
            if ( s[i] == s[i + 1] )
            {
                start  = i;
                maxlen = 2;
                table[i][i+1] = true;
            }
        } // end check [i][i+1]

        for ( int k = 3; k < N; k++ )
        {
            for ( int i = 0; i < N - k + 1; i++ )
            {
                int j = i + k - 1;

                if ( s[i] == s[j] && table[i+1][j-1] == true )
                {
                    table[i][j] = true;
                                       
                    start = i;
                    maxlen = ( maxlen < k) ? k : maxlen;
                }
            }
        }

        return s.substr( start, maxlen );
    }
};
