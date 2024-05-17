#include <vector>
using namespace std;

class Game {
public:
    Game() :
        vPoints{ {} },
        eachFramePoint{ 0 },
        isFirstTry{ true },
        isSpare { false}
    {

    }
    void Roll(int point) {
        vPoints.push_back(point);
    }

    int Score() {
        int result = 0;
        for (auto it = vPoints.begin(); it != vPoints.end(); ++it) {
            if (*it == 0) continue;

            if (isFirstTry) {
                if (isSpare) {
                    result += *it;
                    isSpare = false;
                }
                eachFramePoint = *it;
                isFirstTry = false;
            }
            else {
                eachFramePoint += *it;
                if (eachFramePoint == 10) {
                    isSpare = true;                    
                }
                isFirstTry = true;
            }
            result += *it;
        }
        return result;
    }
private:
    vector<int> vPoints;
    int eachFramePoint;
    bool isFirstTry;
    bool isSpare;
};