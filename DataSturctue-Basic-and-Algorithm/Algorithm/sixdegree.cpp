#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

bool hasMember( std::vector<int> v, int mem )
{
    for ( auto it = v.begin(); it != v.end(); it++ )
        if ( *it == mem ) 
            return true;

    return false;
}

void prtVec( std::vector<int> v )
{
    for ( auto & mem : v )
        std::cout << mem << " ";
    std::cout << '\n';
}

template <typename T>
class Graph {
private:
    int EN;
    int VN;
    int base;
    std::map<int, std::vector<int>> Edge;

public:
    Graph( int e, int v, int b) : EN(e), VN(v), base(b) {}
    void addEdge( int, int );
    std::vector<int> findAdj( int );
    void DFS();
    void _DFS( int, int *, int, std::vector<int> & );
    void BFS();
    void _BFS( int, int * );
    std::vector<int> sixDegree( int );
};

template <typename T>
void Graph<T>::addEdge( int va, int vb )
{
    auto found = Edge.find( va );
    if ( found != Edge.end() )
        found->second.push_back( vb );
    else 
        Edge.insert( std::pair<int, std::vector<int>>(va, {vb}) );
}

template <typename T>
void Graph<T>::BFS( )
{
    int visited[VN];
    for ( int i = base; i < VN + base; i++ )
        visited[i] = 0;

    for ( int i = base; i < VN + base; i++ )
    {
        if ( !visited[i] )
        {
            printf( "{" );
            _BFS( i, visited );
            printf( " }\n" );
        }
    }
}

template <typename T>
void Graph<T>::_BFS( int pt, int *visited )
{
    std::vector<int> Q { pt };
    while ( !Q.empty() )
    {
        int curr = Q.front();
        printf( " %d", curr );
        visited[curr] = 1;
 
        std::vector<int> adjv = findAdj( curr );
        for ( auto & item : adjv )
        {
            if ( !visited[item] && !hasMember( Q, item ))
                Q.insert( Q.end(), item );
        }
        
        Q.erase( Q.begin() );
    }   
}

template <typename T>
std::vector<int> Graph<T>::findAdj( int va )
{
    std::vector<int> adjv;

    auto found = Edge.find( va );
    if ( found != Edge.end() )
        adjv.insert( adjv.begin(), Edge[va].begin(), Edge[va].end() );

    for ( auto & member :  Edge )
    {
        if ( member.first != va )
        {
            for ( auto & item : member.second )
                if ( item == va )
                {
                    adjv.push_back( member.first );
                    break;
                }
        }
    }

    std::sort( adjv.begin(), adjv.end() );
    return adjv;
}

template <typename T>
void Graph<T>::_DFS( int pt, int *visited, int degree, std::vector<int> &ans )
{
    if ( !visited[pt] && (degree <= 6) )
    {
        // printf( " %d", pt );
        ans.push_back( pt );
        visited[pt] = 1;
    }

    std::vector<int> adjv = findAdj( pt );
    for ( auto & mem : adjv )
        if ( !visited[mem] && (degree <= 6) )
            _DFS( mem, visited, degree + 1, ans );
}

template <typename T>
void Graph<T>::DFS()
{
    int visited[VN];
    for ( int i = base; i < VN + base; i++ ) visited[i] = 0;

    for ( int i = base; i < VN + base; i++ )
    {
        if ( !visited[i] )
        {
            printf( "{" );
            _DFS( i, visited, 0 );
            printf( " }\n" );
        } 
    }
}

template <typename T>
std::vector<int> Graph<T>::sixDegree( int pt )
{
    int visited[VN];
    for ( int i = base; i < VN + base; i++ ) visited[i] = 0;

    std::vector<int> ans;
    _DFS( pt, visited, 0, ans );
    // prtVec( ans );
    return  ans;
}


int main( int argc, char **argv )
{
    int v, e;
    std::cin >> v >> e;
    Graph<int> tgrap( e, v, 1 );

    // int pa, pb;
    // for ( int i = 0; i < e; i++ )
    // {
    //     std::cin >> pa >> pb;
    //     tgrap.addEdge( pa, pb );
    // }
    int amount = 0;
    for ( int k = 1; k < v; k++ )
        for ( int i = 1; i <= v - k; i++ )
            if ( amount < e )
                {
                    tgrap.addEdge( i , i + k);
                    amount++;
                }          

    // tgrap.DFS( );
    // tgrap.BFS( );

    for ( int i = 1; i < v + 1; i++ )
    {
        std::vector<int> ans = tgrap.sixDegree( i );
        printf("%d: %.2f\%\n", i, (ans.size()) * 100 / v / 1.0);
        ans.clear();
    }

    return 0;
}