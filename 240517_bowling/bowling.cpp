#include <vector>
using namespace std;

const int SPEICAL_POINT = 10;

class Game {
public:
    Game() :
        vPoints{ {} },
        eachFramePoint{ 0 },
        isFirstTry{ true },
        isSpare{ false },
        strikeCnt{ 0 }
    {

    }
    void Roll(int point) {
        vPoints.push_back(point);
    }

    bool checkStrike() {
        if (!strikeCnt) return false;

        strikeCnt++;
        if (strikeCnt == 3) 
            strikeCnt = 0;
        
        return true;
    }

    bool checkSpare() {
        if (!isFirstTry) return false;

        if (!isSpare) return false;

        isSpare = false;
        return true;
    }

    int getSpecialPoint(int point) {
        if (checkStrike()) return point;
        if (checkSpare()) return point;

        if (isFirstTry) {
            eachFramePoint = point;
            if (eachFramePoint == SPEICAL_POINT) {
                strikeCnt = 1;
            }
            isFirstTry = false;
        }
        else {
            eachFramePoint += point;
            isFirstTry = true;
            if (eachFramePoint == SPEICAL_POINT) {
                isSpare = true;
            }
        }
        return 0;
    }

    int Score() {
        int result = 0;
        for (auto it = vPoints.begin(); it != vPoints.end(); ++it) {
            if (*it == 0) continue;

            result += getSpecialPoint(*it);
            result += *it;
        }
        return result;
    }
private:
    vector<int> vPoints;
    int eachFramePoint;
    bool isFirstTry;
    bool isSpare;
    int strikeCnt;
};