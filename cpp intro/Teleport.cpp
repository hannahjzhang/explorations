#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    
    int direct = abs(b - a);
    int way1 = abs(y - a) + abs(x - b);
    int way2 = abs(x - a) + abs(y - b);

    int teleport = min(way1, way2);
    int shortest = min(direct, teleport);
    cout << shortest << endl;
}
