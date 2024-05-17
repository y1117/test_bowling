#include <vector>
using namespace std;

const int SPEICAL_POINT = 10;

class Game {
public:
    Game() :
        socre{0},
        current{0},
        rollNumber{ {} }
    {

    }
    void Roll(int point) {
        rollNumber[current] = point;
        current++;
    }
    int Score() {
        int result = 0;
        int frameIndex = 0;
        for (int frame = 0; frame < 10; frame++) {
            if (rollNumber[frameIndex] == 10) {
                result += 10;
                result += rollNumber[frameIndex+1] + rollNumber[frameIndex + 2];
                frameIndex += 1;
            }
            else if (isSpare(frameIndex)) {
                result += 10;
                result += rollNumber[frameIndex + 2];
                frameIndex += 2;
            }
            else {
                result += rollNumber[frameIndex] + rollNumber[frameIndex + 1];
                frameIndex += 2;
            }
        }
        return result;
    }
    bool isSpare(int frameIndex)
    {
        return rollNumber[frameIndex] + rollNumber[frameIndex + 1] == 10;
    }
private:
    int rollNumber[20];
    int current;
    int socre;
};