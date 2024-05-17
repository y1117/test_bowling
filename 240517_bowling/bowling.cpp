#include <vector>
using namespace std;

const int SPEICAL_POINT = 10;

class Game {
public:
    Game() :
        vPoints{ {} },
        eachFramePoint{ 0 },
        isFirstTry{ true },
        isSpare { false },
        strikeCnt{ 0 }
    {

    }
    void Roll(int point) {
        vPoints.push_back(point);
    }

    int getSparePoint(int point) {
        int result = 0;
        if (strikeCnt) {
            result = point;
            strikeCnt++;
            if (strikeCnt == 3) 
                strikeCnt = 0;
        }
        if (isFirstTry) {
            eachFramePoint = point;
            if (eachFramePoint == SPEICAL_POINT) {
                strikeCnt = 1;
            }
            isFirstTry = false;
            if (isSpare) {
                isSpare = false;
                result = point;
                return result;
            }
        }
        else {
            eachFramePoint += point;
            isFirstTry = true;
            if (eachFramePoint == SPEICAL_POINT) {
                isSpare = true;
            }
        }
        return result;
    }

    int Score() {
        int result = 0;
        for (auto it = vPoints.begin(); it != vPoints.end(); ++it) {
            if (*it == 0) continue;

            result += getSparePoint(*it);
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