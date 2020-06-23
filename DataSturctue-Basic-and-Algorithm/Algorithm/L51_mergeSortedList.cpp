#include <iostream>
#include <vector>

using namespace std;

void prtVect ( vector<int> &v )
{
    const int NN = v.size();
    for ( int i = 0; i < NN; i++ )
    {
        if ( i == 0 )
            cout << v[i];
        else
            cout << " " << v[i];
    }
    if ( NN == 0 )
        cout << "NULL\n";
    else
        cout << "\n";
}

void readVec( vector<int> & vec )
{
    int num;
    cin >> num;
    while ( num != -1 )
    {
        vec.push_back( num );
        cin >> num;
    }
}


void mergeVec( vector<int> &V1, vector<int> &V2, vector<int> &V )
{
    const int N1 = V1.size();
    const int N2 = V2.size();
    for ( int i=0, j=0; i < N1 || j < N2;  )
    {
        if ( (i == N1) && (j < N2) )
        {
            V.push_back( V2[j] );
            j++;
        }

        else if ( (j == N2) && (i < N1) )
        {
            V.push_back( V1[i] );
            i++;
        }

        else if ( V1[i] >= V2[j] )
        {
            V.push_back( V2[j] );
            j++;
        }
        else
        {
            V.push_back( V1[i] );
            i++;
        }
    }
}

class mergerSolve {
  public:
    void mergeVec( vector<int> &V1, vector<int> &V2, vector<int> &V )
    {
        const int N1 = V1.size();
        const int N2 = V2.size();
        int i = 0, j = 0;
        for (  ; i < N1 && j < N2;  )
        {
            if ( V1[i] >= V2[j] )
            {
                V.push_back( V2[j] );
                j++;
            }
            else
            {
                V.push_back( V1[i] );
                i++;
            }
        }
        
        for (  ; i < N1; i++ )
            V.push_back( V1[i] );
        
        for (  ; j < N2; j++ )
            V.push_back( V2[j] );
    }
};

int main()
{
    vector<int> va, vb, vm;
    readVec( va );
    readVec( vb );
    
    mergerSolve sovle;
    sovle.mergeVec( va, vb, vm );
    //mergeVec( va, vb, vm );
    prtVect( vm );
}