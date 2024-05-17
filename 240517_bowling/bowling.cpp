#include <vector>
using namespace std;

class Game {
public:
    void Roll(int point) {
        vPoints.push_back(point);
    }
    int Score() {
        int result = 0;
        for (int& point : vPoints) {
            result += point;
        }
        return result;
    }
private:
    vector<int> vPoints;
};