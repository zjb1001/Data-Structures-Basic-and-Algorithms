#include <iostream>
#include <vector>

using namespace std;

class Print {
  public:
    void print( vector<int> &Vec ) const 
    {
        for ( auto it=Vec.begin(); it < Vec.end(); it++ )
        {
            if ( it == Vec.begin() )
                cout << *it;
            else
                cout << " " << *it;
        }
        if ( Vec.empty() )
            cout << "NULL\n";
        else
            cout << "\n"; 
    }
};

class Read {
  public:
    int write( vector<int> &Vec )
    {
        int num, size = 0;
        cin >> num;
        while ( num != -1 )
        {
            Vec.push_back( num ); size++;
            cin >> num;
        }
        
        return size;
    }
};

class JoinSet {
  public:
    vector<int> find( vector<int> &va, vector<int> &vb )
    {
        vector<int> ans;
        
        for ( auto ita=va.begin(), itb=vb.begin(); ita < va.end() && itb < vb.end();  )
        {
            if ( *ita > *itb )
            {
                itb++;
            }
            else if ( *ita == *itb )
            {
                ans.push_back( *ita );
                ita++;
                itb++;
            }
            else
            {
                ita++;
            }
        }
        
        return ans;
    }
};

int main()
{
    vector<int> va, vb;
    Read reader;
    JoinSet join;
    Print prt;
    
    reader.write( va );
    reader.write( vb );
    vector<int> vj = join.find( va, vb );
    // cout << "size = " << vj.size();
    prt.print( vj );
    
    return 0;
}