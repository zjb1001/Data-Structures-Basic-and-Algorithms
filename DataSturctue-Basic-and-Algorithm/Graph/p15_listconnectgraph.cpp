#include <iostream>
#include <vector>
#include <map>
#include <queue>

class Graph
{
private:
    int Vnum;
    int Enum;
    std::map<int, std::vector<int>> listTable;
public:
    Graph(int v, int e) : Vnum{v}, Enum{e} { }
    void addEdge(int, int);
    // void hasEdge(int, int);
    // void _DFS( int, int* );
    // void DFS( );
    // void _BFS( int, std::queue<int> Q );
    void BFS();
    std::vector<int> Indegree( int va );
    void prtGraph();
};

void Graph::addEdge( int va, int vb )
{
    listTable[va].push_back( vb );
}

std::vector<int> Graph::Indegree( int va )
{
    std::vector<int> ans;

    for ( auto iter = listTable.begin(); iter != listTable.end(); iter++ )
    {
        for ( auto& m : iter->second )
        {
            if ( m == va ) 
            {
                ans.push_back( iter->first );
                break;
            }
        }
    }

    return ans;
}

void Graph::prtGraph( )
{
    for ( const auto& m : listTable )
    {
        std::cout << m.first << ": ";

        for ( const auto& item : m.second )
            std::cout << item << " ";

        std::cout << '\n';
    }
}

// void Graph::DFS( )
// {
//     int visited[Vnum];
//     for ( int i = 0; i < Vnum; i++ ) visited[i] = 0;

//     for ( int i = 0; i < Vnum; i++ )
//     {
//         std::vector<int> revisit;
//         if ( !visited[i] ) 
//         {
//             std::cout << "{ ";
//             _DFS( i, visited );                
//             std::cout << "}" << '\n';
//         }
//     }
// }

// void Graph::_DFS( int va, int *visited )
// {
//     if ( !visited[va] )
//     {
//         std::cout << va << " ";
//         visited[va] = 1;
//     }

//     std::vector<int> next;
//     std::vector<int> outV;
//     if ( listTable.find( va ) != listTable.end() )
//     {
//         outV = listTable[va];

//         for ( auto &m : outV ) next.push_back( m );
//     }        

//     std::vector<int> inV = Indegree( va );
//     if ( !inV.empty() )
//     {
//         for ( auto &m : inV ) next.push_back( m );
//     }

//     if ( !next.empty() )
//     {

//         _DFS( min, visited );
//     }
// }

void Graph::BFS( )
{
    int visited[Vnum];
    for ( int i = 0; i < Vnum; i++ ) visited[i] = 0;

    std::queue<int> Q;
    for ( int i = 0; i < Vnum; i++ )
    {
        if (!visited[i] ) 
        {
            Q.push( i );
            std::cout << "{ ";
        
            while ( !Q.empty() )
            {
                int curr = Q.front();
                std::cout << curr << " ";
                Q.pop();
                
                if ( listTable.find( curr ) != listTable.end() )
                {
                    for ( auto & mem : listTable[curr] ) Q.push( mem );
                }
                std::vector<int> inV = Indegree( curr );
                for ( auto & mem : inV ) Q.push( mem );
            }

            std::cout << "}" << '\n';
        }
    }
}
void prtVec( std::vector<int> V )
{
    for ( const auto& mem : V )
        std::cout << mem << " ";
    std::cout << std::endl;
}

int main( int argc, char **argv )
{
    int Vnum, Enum;
    scanf( "%d %d", &Vnum, &Enum );

    Graph city { Vnum, Enum };
    int va, vb;
    for ( int i = 0; i < Enum; i++ )
    {
        scanf( " %d %d", &va, &vb );
        city.addEdge( va, vb );
    }

    // city.prtGraph();

    // std::vector<int> tmp;
    // for ( int i = 0; i < Enum; i++ )
    // {
    //     tmp = city.Indegree( i );
    //     std::cout << i << ": ";
    //     prtVec( tmp );
    // }

    city.BFS();

    return 0;
}